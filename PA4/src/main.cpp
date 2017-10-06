#include <iostream>
#include <ctime>
#include <pthread.h>

#include "config.h"
#include "Logger.h"
#include "Population.h"
#include "Individual.h"
#include "Evaluator.h"
#include "GA.h"

using namespace std;

void getAverageValues(vector<GA> gas, vector<double>& avgMin, vector<double>& avgMax, vector<double>& avgAvg) {
    // iterate
    int vecSize = gas[0].averageTimeline.size();
    for (int i = 0; i < vecSize; i++) {
        double sumMin = 0.0, sumAvg = 0.0, sumMax = 0.0;
        for (int gaIndex = 0; gaIndex < gas.size(); gaIndex++) {
            sumMin += gas[gaIndex].minTimeline[i];
            sumAvg += gas[gaIndex].averageTimeline[i];
            sumMax += gas[gaIndex].maxTimeline[i];
        }
        avgMin.push_back(sumMin/double(gas.size()));
        avgAvg.push_back(sumAvg/double(gas.size()));
        avgMax.push_back(sumMax/double(gas.size()));
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    if (argc >= 2) {
        switch(atoi(argv[1])) {
            case 1:
                config = config_1;
                cout << "working on config_1" << endl;
                break;
            case 2:
                config = config_2;
                cout << "working on config_2" << endl;
                break;
            case 3:
                config = config_3;
                cout << "working on config_3" << endl;
                break;
            case 4:
                config = config_4;
                cout << "working on config_4" << endl;
                break;
            case 5:
                config = config_5;
                cout << "working on config_5" << endl;
                break;
            case 6:
                config = config_6;
                cout << "working on config_6" << endl;
                break;
            default:
                cout << "not lol..." << endl;
                config = config_test;
                break;
        }
    } else {
        config = config_test;
    }
    cout << "dataset: " << to_string(config.city) << endl;

    pair<double, double> probabilityCombinations[] = {
        {0.01,    0.2},
        {0.01,    0.67},
        {0.01,    0.99},
        {0.001,   0.2},
        {0.001,   0.67},
        {0.001,   0.99},
        {0.0001,  0.2},
        {0.0001,  0.67},
        {0.0001,  0.99}
    };

    Individual bestIndividual;
    pair<double, double> bestCombo;
    for (auto combo : probabilityCombinations) {
        // set the combo testing
        config.PROB_MUTATION = combo.first;
        config.PROB_CROSSOVER = combo.second;
        cout << "now testing the configuration:  " << combo.first << " " << combo.second << endl;

        // set the config and set up file
        Logger logger(getOutputFilename() + ".tsv");
    
        // run the 30 iterations
        vector<GA> runs(config.TOTAL_GAS_SIZE);
        vector<double> mins, maxs, avgs;
        for (int i = 0; i < config.TOTAL_GAS_SIZE; i++) {
            cout << "running GA " << i << "..." << endl;
            runs[i].init();
            runs[i].run();
            if (runs[i].bestIndividualEver.fitness > bestIndividual.fitness) {
                bestIndividual = runs[i].bestIndividualEver;
                bestCombo = combo;
            }
        }
    
        // compile and log averagaes
        getAverageValues(runs, mins, avgs, maxs);
        for (int i = 0; i < mins.size(); i++) {
            //cout << mins[i] << '\t' << avgs[i] << '\t' << maxs[i] << endl;
            string log = to_string(i) + "\t" +
                        to_string(mins[i]) + "\t" +
                        to_string(avgs[i]) + "\t" +
                        to_string(maxs[i]) + "\t";
            logger.log(log);
        }
    }
    cout << "The best individual I ever saw" << endl;
    bestIndividual.print();


    return 0;
}
