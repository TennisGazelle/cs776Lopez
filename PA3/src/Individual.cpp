#ifndef __INDIVIDUAL_CPP_
#define __INDIVIDUAL_CPP_

#include "Individual.h"
#include "config.h"

Config config;

Individual::Individual() : vector<bool>(config.CHROMOSOME_SIZE), fitness(0.0), normalizedProb(0.0), eval(NULL) {
}

void Individual::init() {

}

void Individual::generateRandom() {
    for (unsigned int i = 0; i < this->size(); i++) {
        (*this)[i] = (rand() % 2 == 0);
    }
}

void Individual::print() const {
    for (int i = 0; i < this->size(); i++) {
        if (i != 0 && i % config.CHROMOSOME_SUBDIVISION_SIZE == 0) {
            cout << "|";
        }
        cout << at(i);
    }
    cout << " - [fitness: " << fitness << "]"<< endl;
}

void Individual::evaluate() {
    fitness = eval->evaluate(this);
}

vector<double> Individual::getAsValues() const {
    vector<double> result(0);
    for (int i = 0; i < config.CHROMOSOME_SIZE; i += config.CHROMOSOME_SUBDIVISION_SIZE) {
        vector<bool> subset(begin()+i, begin()+i+config.CHROMOSOME_SUBDIVISION_SIZE);
        double num = getBinaryAsNumber(subset);
        switch(config.function) {
            case DEJONG_1:
            case DEJONG_3:
                num = (num - 512.0) / 100.0;
                break;
            case DEJONG_2:
                num = (num - 2048.0) / 1000;
                break;
            case DEJONG_4:
                num = (num - 256.0) / 100.0;
            case DEJONG_5:
                num = (num - 65536.0) / 1000.0;
            default:
                break;
        }
        result.push_back(num);
    }
    return result;
}

double Individual::getBinaryAsNumber(vector<bool> subset) const {
    unsigned int power = subset.size()-1;
    unsigned int sum = 0;
    for (unsigned int i = 0; i < subset.size(); i++) {
        sum += subset[i] * pow(2, power--);
    }
    return sum;
}

void Individual::crossoverWith(Individual& other) {
    // pick random index
    int index = randIntBetween(0, size());
    // get the two subsets
    vector<bool> lSubset(begin() + index, end()), rSubset(other.begin() + index, other.end());
    // assign them back
    for (int i = index; i < size(); i++) {
        (*this)[i] = rSubset[i - index];
        other[i] = lSubset[i - index];
    }
}

void Individual::mutate() {
    // pick a random index
    int index = randIntBetween(0, size());

    // flip it!
    (*this)[index] = !at(index);
}

#endif