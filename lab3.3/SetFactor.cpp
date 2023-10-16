//
// Created by dmitr on 16.10.2023.
//

#include "SetFactor.h"

set<set<int>> getSetFactor(const vector<vector<bool>> &equalityRelation) {
    set<set<int>> setFactor;

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

    for (auto a: subArrayForBuildSetFactor)
        cout << a << " ";

    // todo разделить ф-ии, сделать вывод того и другого множества

    return setFactor;
}

