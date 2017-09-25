#ifndef __GA_H_
#define __GA_H_

#include "config.h"
#include "Evaluator.h"
#include "Population.h"
#include "Individual.h"

class GA {
public:
    Population parentPop, childPop;
    Evaluator evaluator;
    void init();
    void run();
};

#endif