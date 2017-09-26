#ifndef __CONFIG_H_
#define __CONFIG_H_

#include <cstdlib>
#include <string>
using namespace std;

enum Function {
    DEJONG_1,
    DEJONG_2,
    DEJONG_3,
    DEJONG_4,
    DEJONG_5
};

struct Config {
    Config() {}
    Config(unsigned int subdiv_size, unsigned int x_vec_size, unsigned int pop_size, Function incomingFunc) {
        CHROMOSOME_SUBDIVISION_SIZE = subdiv_size;
        CHROMOSOME_SIZE = CHROMOSOME_SUBDIVISION_SIZE * x_vec_size;
        POPULATION_SIZE = pop_size;
        function = incomingFunc;
    }
    Config& operator=(const Config& other) {
        if (this == &other) {
            return *this;
        }
        this->PROB_MUTATION = other.PROB_MUTATION;
        this->PROB_CROSSOVER = other.PROB_CROSSOVER;
        this->CHROMOSOME_SUBDIVISION_SIZE = other.CHROMOSOME_SUBDIVISION_SIZE;
        this->CHROMOSOME_SIZE = other.CHROMOSOME_SIZE;
        this->POPULATION_SIZE = other.POPULATION_SIZE;
        return *this;
    }
    double PROB_MUTATION = 0.01; // 0.01, 0.001, 0.0001
    double PROB_CROSSOVER = 0.2;  // 0.2, 0.67, 0.99
    unsigned int CHROMOSOME_SUBDIVISION_SIZE;
    unsigned int CHROMOSOME_SIZE;
    unsigned int POPULATION_SIZE;
    Function function;
};

const Config config_1(10, 3, 1000, DEJONG_1);
const Config config_2(14, 2, 1000, DEJONG_2);
const Config config_3(10, 5, 1000, DEJONG_3);
const Config config_4(8, 30, 1000, DEJONG_4);
const Config config_5(16, 2, 1000, DEJONG_5);
const Config config_test(4, 3, 10, DEJONG_1);

extern Config config;

static string to_string(Function func) {
    switch(func) {
        case DEJONG_1:
            return string("Dejong_1");
        case DEJONG_2:
            return string("Dejong_2");
        case DEJONG_3:
            return string("Dejong_3");
        case DEJONG_4:
        default:
            return string("Dejong_4");
    }
}

static bool randomWithProbability(double prob) {
    // assuming prob = (0,1]...
    double shot = double(rand())/double(RAND_MAX);
    return (shot <= prob);
}

static int randIntBetween(int low, int high) {
    return (rand() % (high - low)) + low;
}

static string getOutputFilename() {
    string result = to_string(config.function) + "_" + to_string(config.PROB_MUTATION) + "_" + to_string(config.PROB_CROSSOVER);
    return result;
}

#endif