#ifndef __INDIVIDUAL_CPP_
#define __INDIVIDUAL_CPP_

#include "Individual.h"

Individual::Individual() : vector<bool>(config.CHROMOSOME_SIZE){
}

void Individual::generateRandom() {
    for (bool b : *this) {
        b = (rand() % 2 == 0);
    }
}

void Individual::print() const {
    for (bool b : *this) {
        cout << b;
    }
    cout << endl;
}
#endif