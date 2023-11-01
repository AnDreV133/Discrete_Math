#include "OrderedSet.h"

#include <utility>

vector<pair<int, int>> getPairByConditionByDotSet(bool (*condition)(pair<int, int>, pair<int, int>), vector<pair<int, int>> dotSet) {
    vector<pair<int, int>> res;
    for (auto& dot1: dotSet) {
    for (auto& dot2: dotSet) {
        if(condition(dot1, dot2)) {
            res.push_back() // todo 
        }
    } 
}
