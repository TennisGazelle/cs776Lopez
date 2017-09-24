#ifndef __GA_H_
#define __GA_H_

#include "Population.h"

class GA {
public:
    Population *parentPop, *childPop;
    void init();
};

#endif