#include <iostream>
#include "lab3.3/SetFactor.h"

bool condition(int x, int y) {
    return x < 11 && y < 11 && ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1));
}

int main() {
    vector<vector<bool>> relation = getRelationByCondition(condition, 10);

    cout << "condition:\n";

    for (auto a: getSetFactorInArray(relation))
        cout << a << " ";

    cout << '\n';

    for (const auto& a: getSetFactorInSet(relation)) {
        for (auto ai: a)
            cout << ai << " ";

        cout << "| ";
    }

    cout << '\n' << '\n';

    vector<vector<bool>> testRelation = {
            {1, 1, 0, 0, 0, 0, 0, 1, 1, 0},
            {1, 1, 0, 0, 0, 0, 0, 1, 1, 0},
            {0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
            {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
            {1, 1, 0, 0, 0, 0, 0, 1, 1, 0},
            {1, 1, 0, 0, 0, 0, 0, 1, 1, 0},
            {0, 0, 1, 0, 0, 0, 1, 0, 0, 1}
    };

    cout << "test condition:\n";

    for (auto a: getSetFactorInArray(testRelation))
        cout << a << " ";

    cout << '\n';

    for (const auto& a: getSetFactorInSet(testRelation)) {
        for (auto ai: a)
            cout << ai << " ";

        cout << "| ";
    }

    cout << '\n';

    return 0;
}

