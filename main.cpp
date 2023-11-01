#include <iostream>
#include "lab3.2/TransitivityClosureExperiment.h"

int main() {
    vector<vector<bool>> relation = getRandomRelation(5, 25);

    for (const auto &a: relation) {
        for (auto ai: a)
            cout << ai << " ";

        cout << "\n";
    }

    cout << "\n";

//    for (const auto &a: getTransitiveClosureByWarshellAlgorithmInj(relation)) {
//        for (auto ai: a)
//            cout << ai << " ";
//
//        cout << "\n";
//    }

    return 0;
}

