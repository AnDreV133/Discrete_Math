//
// Created by dmitr on 16.10.2023.
//

#ifndef DISCRETE_MATH_ORDEREDSET_H
#define DISCRETE_MATH_ORDEREDSET_H

#include "../lab3.1/Relation.h"
#include <utility>
#include <map>

map<int, pair<int, int>> getMapOfDot(vector<pair<int, int>> dotSet);
vector<vector<bool>> getRelationByConditionByDotSet(
    bool (*condition)(pair<int, int>, pair<int, int>),
    vector<pair<int, int>> dotSet, map<int, pair<int, int>> mapOfDot);

#endif // DISCRETE_MATH_ORDEREDSET_H
