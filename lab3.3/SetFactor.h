//
// Created by dmitr on 16.10.2023.
//

#ifndef DISCRETE_MATH_SETFACTOR_H
#define DISCRETE_MATH_SETFACTOR_H

#include "../lab3.1/Relation.h"
#include <set>

vector<int> getSetFactorInArray(const vector<vector<bool>> &equalityRelation);

set<set<int>> getSetFactorInSet(const vector<int> &subArrayForBuildSetFactor);

set<set<int>> getSetFactorInSet(const vector<vector<bool>> &equalityRelation);


#endif //DISCRETE_MATH_SETFACTOR_H
