#ifndef __INDIVIDUAL_H_
#define __INDIVIDUAL_H_

#include <vector>
#include <cstdlib>
#include <iostream>
#include <cmath>

class Evaluator;

#include "Evaluator.h"

using namespace std;

class Individual : public vector<bool> {
public:
    Individual();

    void generateRandom();
    void print() const;
    void init();
    void evaluate();
    vector<double> getAsValues() const;

    void crossoverWith(Individual& other);
    void mutate();

    double fitness;
    double normalizedProb;
    Evaluator *eval;

private:
    double getBinaryAsNumber(vector<bool> subset) const;
};



#endif