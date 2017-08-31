// A simple hill climber
#include "Key.h"
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <ctime>

using namespace std;

extern double eval(int * pj);
double eval(Key& key) {
  return eval(&(key.toIntArray()[0]));
}
double eval(const Key& key) {
  return eval(&(key.toIntArray()[0]));
}

bool flipCoin() {
  return (rand() % 2 == 0);
}

void getRandom(Key& key) {
  for (int i = 0; i < key.size(); i++) {
    if (flipCoin()) {
      key[i] = !key[i];
    }
  }
}

double bestFitnessFrom(const Key& startingKey, Key& endingKey) {
  Key key = startingKey;
  double current = 0.0, best = 0.0;
  current = eval(startingKey);

  // method
  for (int i = 0; i < 100; i++) {
    key[i] = !key[i];
    current = eval(startingKey);
    if (current > best) {
      best = current;
      endingKey = key;
      cout << "updating" << endl;
    } else {
      key[i] = !key[i];
    }
  }

  return best;
}

int main (int argc, char *argv[]) {
  srand(time(NULL));
  cout.precision(6);
  Key key(100), bestKey(100);
  getRandom(key);
  cout << "started: ";
  key.print();

  double currentFitness = 0.0, bestFitness = 0.0;

  bestFitness = bestFitnessFrom(key, bestKey);

  cout << "best is: ";
  bestKey.print();

  cout << "best fitness = " << bestFitness << endl;
  return 0;
}
