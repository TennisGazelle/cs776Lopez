#include <iostream>
#include <ctime>

#include "config.h"
#include "Logger.h"
#include "Population.h"
#include "Individual.h"
#include "Evaluator.h"
#include "GA.h"

using namespace std;

void getAverageValues(vector<GA> gas, vector<double>& avgMin, vector<double>& avgMax, vector<double>&avgAvg) {
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
    config = config_test;
    srand(time(NULL));

    vector<GA> runs(30);
    vector<double> mins, maxs, avgs;
    for (int i = 0; i < 30; i++) {
        cout << "running GA " << i << "..." << endl;
        runs[i].init();
        runs[i].run();
    }
    getAverageValues(runs, mins, avgs, maxs);
    for (int i = 0; i < mins.size(); i++) {
        cout << mins[i] << '\t' << avgs[i] << '\t' << maxs[i] << endl;
    }
    // GA ga;
    // ga.init();
    // ga.run();

    return 0;
}
