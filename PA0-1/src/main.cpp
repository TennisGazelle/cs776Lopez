// A simple hill climber
// std libs
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>

// external libraries
#include "mpi.h"

// personalized classes
#include "Key.h"

using namespace std;

extern double eval(int * pj);
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
    // if (i > 30) {
    //   key[i] = true;
    // }
    // if (i > 50) {
    //   key[i] = false;
    // }
  }
}

Key modify(Key first, int startingIndex, int windowSize, int boolAsNum) {
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

double bestFitnessFrom(const Key& startingKey, Key& bestKey) {
  Key key = startingKey;
  bestKey = key;
  double current = 0.0, best = 0.0;

  // window sizing
  for (int w = 3; w < 10; w++) {
    key = startingKey;
    for (int index = 0; index < (key.size() - w + 1); index++) {
      // do it for all iterations of windows size
      for (int i = 0; i < pow(2, w); i++) {
        key = modify(key, index, w, i);
        current = eval(key);
        if (current >= best) {
          best = current;
          bestKey = key;
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

struct Keypath {
  Key startingKey;
  Key endingKey;
  double bestKeyValue;
};

int main (int argc, char *argv[]) {
  int numTasks, taskId = 0, hostnameLength;
  char hostname[100];

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numTasks);
  MPI_Comm_rank(MPI_COMM_WORLD, &taskId);
  MPI_Get_processor_name(hostname, &hostnameLength);

  srand(time(NULL) + taskId);
  cout.precision(6);

  // init keys
  vector<Keypath> keys(10);
  Key bestKey;
  double bestFound = 0.0;
  for (Keypath key : keys) {
    getRandom(key.startingKey);
    key.bestKeyValue = bestFitnessFrom(key.startingKey, key.endingKey);
    if (bestFound < key.bestKeyValue) {
      bestFound = key.bestKeyValue;
      bestKey = key.endingKey;
    }
  }

  // display best
  cout << "best is: ";
  bestKey.print();
  cout << "best fitness = " << bestFound << endl;

  return 0;
}
