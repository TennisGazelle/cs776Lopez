#ifndef __EVALUATOR_H_
#define __EVALUATOR_H_

class Individual;

#include "config.h"
#include "Individual.h"

double gauss(int mu, int sd);
const int A[2][25] = {
    {-32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32},
    {-32, -32, -32, -32, -32, -16, -16, -16, -16, -16, 0, 0, 0, 0, 0, 16, 16, 16, 16, 16, 32, 32, 32, 32, 32}
};

class Evaluator {
public:
    Evaluator();
    ~Evaluator();
    double evaluate(Individual *i);
};

#endif