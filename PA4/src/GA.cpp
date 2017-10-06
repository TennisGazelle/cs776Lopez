#ifndef __GA_CPP_
#define __GA_CPP_

#include "GA.h"
#include "config.h"

void GA::init() {
    parentPop.generate(config.POPULATION_SIZE);
    evaluator.init();
    for (unsigned int i = 0; i < parentPop.size(); i++) {
        parentPop[i].eval = &evaluator;
    }
    parentPop.evaluate();
    //parentPop.print();
}

void GA::makeNextGen() {
    childPop.clear();
    for(unsigned int i = 0; i < parentPop.size(); i++) {
        childPop.push_back(
            parentPop.proportionalSelect()
        );

        // if cross over probability, mess with individual i, and individual i _1
        if (i < (parentPop.size() - 1) && randomWithProbability(config.PROB_CROSSOVER)) {
            childPop[i].crossoverWith(parentPop[randIntBetween(i+1, parentPop.size())]);
        }
        // it mutation probabiltiy, mess with individual i
        if (randomWithProbability(config.PROB_MUTATION)) {
            childPop[i].mutate();
        }
    }
    childPop.evaluate();
    minTimeline.push_back(childPop.minFitness);
    maxTimeline.push_back(childPop.maxFitness);
    averageTimeline.push_back(childPop.averageFitness);
    if (bestIndividualEver.fitness < childPop.getBestIndividual().fitness) {
        bestIndividualEver = childPop.getBestIndividual();
    }
    //childPop.print();
}

void GA::run() {
    //string filename = "../out/" + getOutputFilename() + ".csv";
    //Logger logger (filename);
    //logger.log("# Reporting files for " + to_string(config.PROB_MUTATION) + " MUTATION AND " + to_string(config.PROB_CROSSOVER) + " CROSSOVER");
    for (int i = 0; i < config.ITERATION_SIZE; i++) {
        //cout << "Parent: " << i << endl;
        //parentPop.print();
        makeNextGen();
        parentPop = childPop;
        if (i % 100 == 0)
            cout << ".";
    }
    for (int i = 0; i < averageTimeline.size(); i++) {
        string log = to_string(minTimeline[i]) + "," +
                    to_string(averageTimeline[i]) + "," +
                    to_string(maxTimeline[i]) + ",";
        //logger.log(log);
        //cout << log << endl;
    }

    cout << "best - " << bestIndividualEver.fitness << endl;
}

#endif