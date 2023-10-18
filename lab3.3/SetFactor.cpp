//
// Created by dmitr on 16.10.2023.
//

#include "SetFactor.h"

vector<int> getSetFactorInArray(const vector<vector<bool>> &equalityRelation) {
    vector<int> subArrayForBuildSetFactor(equalityRelation.size());
    int counterSubSets = 0;
    for (int i = 0; i < equalityRelation.size(); ++i) {
        if (subArrayForBuildSetFactor[i] != 0)
            continue;

        counterSubSets++;

        for (int j = i; j < equalityRelation.size(); ++j) {
            if (equalityRelation[i][j] && subArrayForBuildSetFactor[j] == 0)
                subArrayForBuildSetFactor[j] = counterSubSets;
        }
    }
    return subArrayForBuildSetFactor;
}

set<set<int>> getSetFactorInSet(const vector<int> &subArrayForBuildSetFactor) {
    set<set<int>> setFactor;

    bool hasInsert = false;
    for (int numOfSubSet = 1; numOfSubSet <= subArrayForBuildSetFactor.size(); ++numOfSubSet) {
        set<int> subSet;
        for (int i = 0; i < subArrayForBuildSetFactor.size(); ++i) {
            if (numOfSubSet == subArrayForBuildSetFactor[i]) {
                subSet.insert(i + 1);
                hasInsert = true;
            }
        }

        if (!hasInsert)
            break;

        setFactor.insert(subSet);
    }

    return setFactor;
}

set<set<int>> getSetFactorInSet(const vector<vector<bool>> &equalityRelation) {
    vector<int> setFactor = getSetFactorInArray(equalityRelation);

    return getSetFactorInSet(setFactor);
}

