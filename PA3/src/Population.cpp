#ifndef __POPULATION_CPP_
#define __POPULATION_CPP_

#include "Population.h"

Population::Population() : minFitness(0.0), maxFitness(0.0), averageFitness(0.0), bestIndividualIndex(0), worstIndividualIndex(0) {

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

void Population::print() const {
    cout << "Max Fitness:   " << maxFitness << endl;
    cout << "Min Fitness:   " << minFitness << endl;
    cout << "Avg Fitness:   " << averageFitness << endl;
    for (unsigned int i = 0; i < this->size(); i++) {
        cout << "[" << ((i < 10) ? "0" : "") << i << "] - ";
        at(i).print();
    }
}

void Population::evaluate() {
    for (int i = 0; i < this->size(); i++) {
        at(i).evaluate();
    }
}

#endif