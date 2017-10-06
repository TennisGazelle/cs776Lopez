#ifndef __EVALUATOR_CPP_
#define __EVALUATOR_CPP_

#include <fstream>

#include "Evaluator.h"
#include "config.h"

Evaluator::Evaluator() {

}

Evaluator::~Evaluator() {

}

void Evaluator::init() {
    // check the config
    string solutionFilename, bufferString;
    unsigned int lineNumber;
    ifstream fin;
    Point tempPoint;
    
    // get filename
    pointsOfReference.clear();
    fin.clear();
    fin.open(config.INPUT_FILENAME.c_str());
    // ignore the initial fluff
    for (int i = 0; i < 6; i++) {
        getline(fin, bufferString);
    }
    // variables
    for (int i = 0; i < config.CITY_TOUR_SIZE; i++) {
        fin >> lineNumber >> tempPoint.x >> tempPoint.y;
        pointsOfReference.push_back(tempPoint);
    }

    fin.close();

    // // find and save the solution file, just for giggles.
    // solutionFilename = "../in/solution/burma52.opt.tour";
    // fin.clear();
    // fin.open()
}

double Evaluator::evaluate(Individual &indiv) {
    double sum = 0.0;
    for (int i = 0; i < indiv.size()-1; i++) {
        sum += getDistanceBetween(indiv[i], indiv[i+1]);
    }
    sum += getDistanceBetween(indiv[0], indiv[indiv.size()-1]);
    indiv.distance = sum;
    switch(config.city) {
        case BURMA:
            return 1000.0/sum;
        case BERLIN:
            return 100000.0/sum;
        case ELI_51:
            return 100000.0/sum;
        case ELI_76:
            return 100000.0/sum;
        case LIN_105:
            return 10000000.0/sum;
        case LIN_318:
            return sum;
        default:
            return 1.0/sum;
    }
}

double Evaluator::getDistanceBetween(unsigned int startIndex, unsigned int endIndex) {
    // delta x squared + delta y squareds
    //cout << pointsOfReference[startIndex].x << "--" << pointsOfReference[startIndex].y << endl;
    double deltaX = pointsOfReference[startIndex].x - pointsOfReference[endIndex].x;
    deltaX = pow(deltaX, 2);
    double deltaY = pointsOfReference[startIndex].y - pointsOfReference[endIndex].y;
    deltaY = pow(deltaY, 2);

    //TODO: remove the sqrt for faster processings
    return sqrt(deltaX + deltaY);
    return (deltaX + deltaY);
}

#endif
