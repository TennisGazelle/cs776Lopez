#ifndef __EVALUATOR_H_
#define __EVALUATOR_H_

class Individual;

#include <vector>

#include "config.h"
#include "Individual.h"

using namespace std;

struct Point {
    double x, y;
};

class Evaluator {
public:
    Evaluator();
    ~Evaluator();
    void evaluate(Individual &indiv);
    void init();
    void getBestSolution();

    vector<Point> pointsOfReference;

    Individual* bestSolution;
private:
    double getDistanceBetween(unsigned int startIndex, unsigned int endIndex);
};

#endif
