#ifndef __EVALUATOR_CPP_
#define __EVALUATOR_CPP_

#include "Evaluator.h"
#include "Config.h"

Evaluator::Evaluator() {

}

Evaluator::~Evaluator() {

}

double gauss(int mu, int sd) {
    return 0.0;
}

double Evaluator::evaluate(Individual *i) {
    vector<double> x = i->getAsValues();
    if (config.function == DEJONG_1) {
        double sum = 0.0;
        for (double d : x) {
            sum += pow(d, 2);
        }
        return sum;
    } else if (config.function == DEJONG_2) {
        double result = pow(pow(x[0], 2) - x[1], 2);
        result = 100*result + pow(1 - x[0], 2);
        return result;
    } else if (config.function == DEJONG_3) {
        double result = 0.0;
        for (int i = 0; i < 5; i++) {
            result += ceil(x[i]);
        }
        return result;
    } else if (config.function == DEJONG_4) {
        double result = 0.0;
        for (int i = 0; i < 30; i++) {
            result += (i+1) * pow(x[i], 4);
            result += gauss(0, 1);
        }
        return result;
    } else if (config.function == DEJONG_5) {
        double result = 0.0;
        for (int j = 0; j < 25; j++) {
            double sum = double(j);
            for (int i = 0; i < 2; i++) {
                sum += pow(x[i] - A[i][j], 6);
            }
            result += 1.0 / sum;
        }
        return result + 0.002;
    }
    return 0.0;
    //return config.function == DEJONG_1 ? 20.0 : 40.0;
}

#endif