#ifndef __CONFIG_H_
#define __CONFIG_H_

const double PROB_MUTATION = 0.001;
const double PROB_CROSSOVER = 0.2;

enum Function {
    DEJONG_1,
    DEJONG_2,
    DEJONG_3,
    DEJONG_4
};

struct Config {
    unsigned int CHROMOSOME_SIZE = 20;
    unsigned int POPULATION_SIZE = 100;
    Function function;
} config;



#endif