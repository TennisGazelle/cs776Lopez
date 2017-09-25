#ifndef __INDIVIDUAL_H_
#define __INDIVIDUAL_H_

#include <vector>
#include <cstdlib>
#include <iostream>
#include <cmath>

class Evaluator;

#include "config.h"
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

    double fitness;
    Evaluator *eval;

private:
    double getBinaryAsNumber(vector<bool> subset) const;
};



#endif