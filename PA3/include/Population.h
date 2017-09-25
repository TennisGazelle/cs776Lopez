#ifndef __POPULATION_H_
#define __POPULATION_H_

#include <vector>

#include "config.h"
#include "Individual.h"

using namespace std;

class Population : public vector<Individual> {
public:
    Population();
    ~Population();
    
    void generate(int n = 100);
    void print() const;
    void evaluate();

    double minFitness, maxFitness, averageFitness;
    int bestIndividualIndex, worstIndividualIndex;
};

#endif