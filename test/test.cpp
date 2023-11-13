//
// Created by admin on 18.10.2023.
//

#include "test.h"
#include "../lab3.4/OrderedSet.h"

vector<pair<int, int>> M1 = {
    {-1, 1},
    {0, 1},
    {1, 1},

    {-1, 0},
    {0, 0},
    {1, 0},

    {-1, -1},
    {0, -1},
    {1, -1}};

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
    map<int, pair<int, int>> mapOfDot1 = getMapOfDot(M1);
    for (size_t i = 0; i < mapOfDot1.size(); i++)
        cout << i << "-(" << mapOfDot1[i].first << "," << mapOfDot1[i].second << ")\n";
    cout << '\n';

    vector<vector<bool>> relationMatrix1 = getRelationByConditionByDotSet(predicate, M1, mapOfDot1);
    // outputMatrixBool(relationMatrix1);

    relationMatrix1 = getDominanceFromOrder(relationMatrix1);
    outputMatrixBool(relationMatrix1);
    cout << '\n';

    vector<vector<int>> sortedPoints1 = getTopologicalSort(relationMatrix1);
    outputResultByDots(sortedPoints1, mapOfDot1);

    cout << "\n--------------------------------\n\n";

    map<int, pair<int, int>> mapOfDot2 = getMapOfDot(M2);
    // for (size_t i = 0; i < mapOfDot2.size(); i++)
    //     cout << i << "-(" << mapOfDot2[i].first << "," << mapOfDot2[i].second << ")\n";
    // cout << '\n';

    vector<vector<bool>> relationMatrix2 = getRelationByConditionByDotSet(predicate, M2, mapOfDot2);
    // outputMatrixBool(relationMatrix2);

    relationMatrix2 = getDominanceFromOrder(relationMatrix2);
    // outputMatrixBool(relationMatrix2);
    // cout << '\n';

    vector<vector<int>> sortedPoints2 = getTopologicalSort(relationMatrix2);
    outputResultByDots(sortedPoints2, mapOfDot2);

    // vector<vector<bool>> testMatrixOrder = {
    //     {1, 1, 1, 1, 1, 1, 1, 1},
    //     {0, 1, 0, 0, 1, 1, 0, 1},
    //     {0, 0, 1, 0, 1, 0, 1, 1},
    //     {0, 0, 0, 1, 0, 1, 1, 1},
    //     {0, 0, 0, 0, 1, 0, 0, 1},
    //     {0, 0, 0, 0, 0, 1, 0, 1},
    //     {0, 0, 0, 0, 0, 0, 1, 1},
    //     {0, 0, 0, 0, 0, 0, 0, 1}
    // };

    // vector<vector<bool>> testMatrixDominance = getDominanceFromOrder(testMatrixOrder);

    // outputMatrix(testMatrixDominance);
    // cout << '\n';
}