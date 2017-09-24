#ifndef __POPULATION_CPP_
#define __POPULATION_CPP_

#include "Population.h"

Population::Population() {

}

Population::~Population() {

}

void Population::generate(int n) {
    this->clear();
    for(int i = 0 ; i < n; i++) {
        Individual randIndividual;
        randIndividual.generateRandom();
        this->push_back(randIndividual);
    }
}

#endif