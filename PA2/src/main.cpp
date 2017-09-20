// A simple hill climber
// std libs
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <ctime>

// external libraries
#include "mpi.h"

// personalized classes
#include "Key.h"

using namespace std;

extern double eval(int * pj);
int numTasks, taskId = 0, hostnameLength;
double eval(Key& key) {
  return eval(&(key.toIntArray()[0]));
}
double eval(const Key& key) {
  return eval(&(key.toIntArray()[0]));
}

bool flipCoin() {
  return (rand() % 2 != 0);
}

void getRandom(Key& key) {
  for (unsigned int i = 0; i < key.size(); i++) {
    if (flipCoin()) {
      key[i] = !key[i];
    }
  }
}

Key substituteSubStringWith(Key first, int startingIndex, int windowSize, int boolAsNum) {
  int index, endingIndex = startingIndex + windowSize;
  // for (index = endingIndex; index >= startingIndex; index--) {
  //   first[index] = (boolAsNum & (1 << index)) != 0;
  // }
  for (index = endingIndex - 1; index >= startingIndex; index--) {
    first[index] = boolAsNum & 1;
    boolAsNum >>= 1;
  }
  return first;
}

int randBetween(int low, int high) {
  int range = high - low;
  return (rand() % range) + low;
}

double bestFitnessFrom(const Key& startingKey, Key& bestKey, std::vector<double>& currentHistory) {
  Key key = startingKey;
  bestKey = key;
  double current = 0.0, best = 0.0;

  // window sizing
  for (int w = 1; w < 20; w++) {
    //key = startingKey;
    cout << "[" << taskId << "] - increased window size to " << w << endl;
    for (int index = 0; index < (key.size() - w + 1); index++) {
      // do it for all iterations of windows size
      for (int i = 0; i < pow(2, w); i++) {
        key = substituteSubStringWith(key, index, w, i);
        current = eval(key);
        currentHistory.push_back(current);
        if (current >= best) {
          best = current;
          bestKey = key;
          //cout << "[" << taskId << "] - updated - ";
          // for (int j = 0; j < key.size(); j++) {
          //   if (j == index) {
          //     cout << "[";
          //   }
          //   cout << key[j];
          //   if (j == index + w) {
          //     cout << "]";
          //   }
          // }
          //cout << endl;
        } else {
          key = bestKey;
        }
      }
    }
  }

  // method
  // for (int i = 0; i < 200; i++) {
  //   int index = (i < 100) ? i : rand() % 50;
  //   key[index] = !key[index];
  //   current = eval(key);
  //   if (current >= best) {
  //     best = current;
  //     endingKey = key;
  //     //endingKey.print();
  //   } else {
  //     key[index] = !key[index];
  //   }
  // }

  return best;
}

void sendBoolArrayTo(const Key& sendingKey, int dest) {
  std::vector<int> buffer(MAX_KEY_SIZE);
  for (int i = 0; i < MAX_KEY_SIZE; i++) {
    buffer[i] = sendingKey[i] ? 1 : 0;
  }

  MPI_Send(&buffer[0], MAX_KEY_SIZE, MPI_INT, 0, 0, MPI_COMM_WORLD);
}

Key recvBoolArrayFrom(int src) {
  // convert from int array
  MPI_Status status;
  std::vector<int> buffer(MAX_KEY_SIZE);
  Key result;
  // receive
  MPI_Recv(&buffer[0], MAX_KEY_SIZE, MPI_INT, src, 0, MPI_COMM_WORLD, &status);
  //
  for (int i = 0; i < MAX_KEY_SIZE; i++) {
    result[i] = buffer[i] ? true : false;
  }
  return result;
}

struct Keypath {
  Key startingKey;
  Key endingKey;
  double bestKeyValue;
  std::vector<double> pathHistory;
};

int main (int argc, char *argv[]) {
  char hostname[100];

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numTasks);
  MPI_Comm_rank(MPI_COMM_WORLD, &taskId);
  MPI_Get_processor_name(hostname, &hostnameLength);

  srand(time(NULL) + taskId);
  cout.precision(6);

  // init keys
  vector<Keypath> keys(1000);
  Keypath bestKeyPath, worstKeyPath;

  for (Keypath key : keys) {
    getRandom(key.startingKey);
    //cout << "starting with - \t\t";
    //key.startingKey.print();
    key.bestKeyValue = bestFitnessFrom(key.startingKey, key.endingKey, key.pathHistory);
    if (bestKeyPath.bestKeyValue < key.bestKeyValue) {
      bestKeyPath = key;
    }
    if (worstKeyPath.bestKeyValue > key.bestKeyValue) {
      worstKeyPath = key;
    }
    //cout << "with value " << key.bestKeyValue << ", converged to \t";
    //key.endingKey.print();
    //cout << endl;
  }

  // print out each processors best and worst path
  std::string bestDataOutputFileName = "../data/" + std::string(hostname) + "_" + std::to_string(taskId);
  std::string worstDataOutputFileName = bestDataOutputFileName + "_worst.csv";
  bestDataOutputFileName += "_best.csv";
  std::ofstream bestOut(bestDataOutputFileName.c_str()), worstOut(worstDataOutputFileName.c_str());
  for (unsigned int i = 0; i < bestKeyPath.pathHistory.size(); i++) {
    bestOut << i << "," << bestKeyPath.pathHistory[i] << std::endl;
  }
  for (unsigned int i = 0; i < worstKeyPath.pathHistory.size(); i++) {
    worstOut << i << "," << worstKeyPath.pathHistory[i] << std::endl;
  }
  bestOut.close();
  worstOut.close();

  Keypath slaveBest;
  if (taskId == 0 && numTasks > 1) {
    // if master, get all children, and compare
    while (numTasks > 1) {
      slaveBest.startingKey = recvBoolArrayFrom(numTasks-1);
      slaveBest.endingKey = recvBoolArrayFrom(numTasks-1);
      slaveBest.bestKeyValue = eval(slaveBest.endingKey);
      // assign best over
      cout << "receiving from " << numTasks-1 << " - ";
      slaveBest.endingKey.print();
      cout << endl;
      if (slaveBest.bestKeyValue > bestKeyPath.bestKeyValue) {
        cout << "updated!" << endl;
        bestKeyPath = slaveBest;
      }
      numTasks--;
    }
  } else if (taskId != 0) {
    // if slave, send master the best
    sendBoolArrayTo(bestKeyPath.startingKey, 0);
    sendBoolArrayTo(bestKeyPath.endingKey, 0);
  }


  if (taskId == 0) {
    // display best
    cout << "best starting: ";
    bestKeyPath.startingKey.print();
    cout << "best solution: ";
    bestKeyPath.endingKey.print();
    cout << "best fitness = " << bestKeyPath.bestKeyValue << endl;
  }

  // safely stop mpi
  MPI_Finalize();
  return 0;
}
