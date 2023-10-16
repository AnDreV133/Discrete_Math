//
// Created by dmitr on 16.10.2023.
//

#ifndef DISCRETE_MATH_TRANSITIVITYCLOSUREEXPERIMENT_H
#define DISCRETE_MATH_TRANSITIVITYCLOSUREEXPERIMENT_H

#include "../lab3.1/Relation.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <iostream>

extern size_t numOfExecutions;

vector<vector<bool>> getTransitiveClosureInj(vector<vector<bool>> &matrix);

vector<vector<bool>> getTransitiveClosureByWarshellAlgorithmInj(vector<vector<bool>> &matrix);

vector<vector<bool>> generateRelationByRandom(int powerOfSet, int amountPair);

void
gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(ofstream &outputStream, int powerOfSet, int amountPair,
                                                               vector<vector<bool>> (*operation)(
                                                                       vector<vector<bool>> &), const string& name);

int main_test();


#endif //DISCRETE_MATH_TRANSITIVITYCLOSUREEXPERIMENT_H
