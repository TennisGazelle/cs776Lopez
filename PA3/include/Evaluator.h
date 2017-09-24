#ifndef __EVALUATOR_H_
#define __EVALUATOR_H_

#include "Individual.h"
#include "config.h"

class Evaluator {
public:
    Evaluator();
    ~Evaluator();
    double eval(Individual i);
};

#endif