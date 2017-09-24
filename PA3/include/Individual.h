#ifndef __INDIVIDUAL_H_
#define __INDIVIDUAL_H_

#include <vector>
#include <cstdlib>
#include <iostream>

#include "config.h"

using namespace std;

class Individual : public vector<bool> {
public:
    Individual();

    void generateRandom();
    void print() const;
    double fitness;
};

#endif