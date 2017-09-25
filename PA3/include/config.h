#ifndef __CONFIG_H_
#define __CONFIG_H_

const double PROB_MUTATION = 0.001;
const double PROB_CROSSOVER = 0.2;

enum Function {
    DEJONG_1,
    DEJONG_2,
    DEJONG_3,
    DEJONG_4,
    DEJONG_5
};

struct Config {
    Config(unsigned int subdiv_size, unsigned int x_vec_size, unsigned int pop_size, Function incomingFunc) {
        CHROMOSOME_SUBDIVISION_SIZE = subdiv_size;
        CHROMOSOME_SIZE = CHROMOSOME_SUBDIVISION_SIZE * x_vec_size;
        POPULATION_SIZE = pop_size;
        function = incomingFunc;
    }
    unsigned int CHROMOSOME_SUBDIVISION_SIZE;
    unsigned int CHROMOSOME_SIZE;
    unsigned int POPULATION_SIZE;
    Function function;
};

const Config config_1(10, 3, 100, DEJONG_1);
const Config config_2(14, 2, 100, DEJONG_2);
const Config config_3(10, 5, 100, DEJONG_3);
const Config config_4(8, 30, 100, DEJONG_4);
const Config config_5(16, 2, 100, DEJONG_5);
const Config config = config_5;

#endif