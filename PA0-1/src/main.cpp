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
    if (i > 30) {
      key[i] = true;
    }
    if (i > 50) {
      key[i] = false;
    }
  }
}

double bestFitnessFrom(const Key& startingKey, Key& endingKey) {
  Key key = startingKey;
  double current = 0.0, best = 0.0;

  // method
  for (int i = 0; i < 200; i++) {
    int index = (i < 100) ? i : rand() % 50;
    key[index] = !key[index];
    current = eval(key);
    if (current >= best) {
      best = current;
      endingKey = key;
      //cout << "i = " << i << " index = " << index << " updated key to ";
      //endingKey.print();
    } else {
      key[index] = !key[index];
    }
  }

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
  vector<Keypath> keys(10000);
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

  // get sub processes
  if (taskId == 0) { // MASTER
    // receive best value
    // receive best array

    // update as needed

    // print and die
  } else {
    // send best value
    // send best array
  }

  // display best
  cout << "best is: ";
  bestKey.print();
  cout << "best fitness = " << bestFound << endl;

  return 0;
}
