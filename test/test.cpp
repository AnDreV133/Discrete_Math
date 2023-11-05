//
// Created by admin on 18.10.2023.
//

#include "test.h"

vector<pair<int, int>> M1 = {
    {-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {0, 0}, {1, 0}, {-1, -1}, {0, -1}, {1, -1}};

vector<pair<int, int>> M2 = {
    {0, 2},
    {-1, 1},
    {0, 1},
    {1, 1},
    {-2, 0},
    {-1, 0},
    {0, 0},
    {1, 0},
    {2, 0},
    {-1, -1},
    {0, -1},
    {1, -1},
    {0, -2}};

bool predicate(pair<int, int> a, pair<int, int> b)
{
    return (a.first + b.second) > (b.first + a.second);
}

void run_lab_3_4()
{
    map<int, pair<int, int>> mapOfdot1 = getMapOfDot(M1);
    vector<vector<bool>> relationMatrix1 = getRelationByConditionByDotSet(predicate, M1, mapOfdot1);

    outputMatrix(relationMatrix1);

    map<int, pair<int, int>> mapOfdot2 = getMapOfDot(M2);
    vector<vector<bool>> relationMatrix2 = getRelationByConditionByDotSet(predicate, M2, mapOfdot2);

    outputMatrix(relationMatrix2);

    vector<vector<bool>> testMatrixOrder = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 0, 0, 1, 1, 0, 1},
        {0, 0, 1, 0, 1, 0, 1, 1},
        {0, 0, 0, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1}
    };

    vector<vector<bool>> testMatrixDominance = getDominanceFromStrictOrder(testMatrixOrder);

    outputMatrix(testMatrixDominance);

}