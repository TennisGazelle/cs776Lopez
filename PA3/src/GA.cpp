#ifndef __GA_CPP_
#define __GA_CPP_

#include "GA.h"

void GA::init() {
    parentPop.generate(20);
    for (unsigned int i = 0; i < parentPop.size(); i++) {
        parentPop[i].eval = &evaluator;
        //parentPop[i].evaluate();
    }
    parentPop.evaluate();
    parentPop.print();
}

#endif