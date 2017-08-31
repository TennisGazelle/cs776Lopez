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
  return (rand() % 5 != 0);
}

void getRandom(Key& key) {
  for (unsigned int i = 0; i < key.size(); i++) {
    if (flipCoin()) {
      key[i] = !key[i];
    }
  }
}

double bestFitnessFrom(const Key& startingKey, Key& endingKey) {
  Key key = startingKey;
  double current = 0.0, best = 0.0;

  // method
  for (int i = 0; i < 100; i++) {
    key[i%100] = !key[i%100];
    current = eval(key);
    if (current > best) {
      best = current;
      endingKey = key;
      cout << "i = " << i << " index = " << i%100 << " updated key to ";
      endingKey.print();
    } else {
      key[i%100] = !key[i%100];
    }
  }

  return best;
}

struct Keychain {
  Key startingKey;
  Key endingKey;
  double bestKey;
};

int main (int argc, char *argv[]) {
  int numTasks, taskId, hostnameLength;
  char hostname[100];
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numTasks);
  MPI_Comm_rank(MPI_COMM_WORLD, &taskId);
  MPI_Get_processor_name(hostname, &hostnameLength);

  srand(time(NULL) + taskId);
  cout.precision(6);

  // init keys
  Key key(100), bestKey(100);
  getRandom(key);
  //cout << "started: ";
  //key.print();

  // calc boundaries
  double bestFitness = bestFitnessFrom(key, bestKey);

  // display best
  //cout << "best is: ";
  //bestKey.print();

  cout << "best fitness = " << bestFitness << endl;
  return 0;
}
