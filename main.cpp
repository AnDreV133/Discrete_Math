#include <iostream>
#include "lab3.3/SetFactor.h"

bool condition(int x, int y) {
    return x < 11 && y < 11 && ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1));
}

int main() {
    vector <vector<bool>> relation = getRelationByCondition(condition, 10);

    vector <vector<bool>> testRelation = {
            {1,1,0,0,0,0,0,1,1,0},
            {1,1,0,0,0,0,0,1,1,0},
            {0,0,1,0,0,0,1,0,0,1},
            {0,0,0,1,1,0,0,0,0,0},
            {0,0,0,1,1,0,0,0,0,0},
            {0,0,0,0,0,1,0,0,0,0},
            {0,0,1,0,0,0,1,0,0,1},
            {1,1,0,0,0,0,0,1,1,0},
            {1,1,0,0,0,0,0,1,1,0},
            {0,0,1,0,0,0,1,0,0,1}
    };


//    outputMatrix(relation);

//    getSetFactor(relation);
    getSetFactor(testRelation);

    return 0;
}

