#include <iostream>
#include "lab3.3/Set_Factor.h"

bool condition(int x, int y) {
    return x < 11 && y < 11 && ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1));
}

int main() {
    vector <vector<bool>> relation = getRelationByCondition(condition, 10);

    outputMatrix(relation);

    return 0;
}