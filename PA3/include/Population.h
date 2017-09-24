#ifndef __POPULATION_H_
#define __POPULATION_H_

#include <vector>

#include "Individual.h"

using namespace std;

class Population : public vector<Individual> {
public:
    Population();
    ~Population();
    
    void generate(int n = 100);

    double minFitness, maxFitness, averageFitness;
    int bestIndividualIndex, worstIndividualIndex;
};

#endif