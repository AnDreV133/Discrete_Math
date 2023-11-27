//
// Created by admin on 18.10.2023.
//

#include "test.h"
#include "../lab3.4/OrderedSet.h"
#include "../lab4.1/Graph.h"

void checkBoolFunc(bool b)
{
    cout << (b ? "COMPLETE" : "ERROR") << '\n';
}

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
    // for (size_t i = 0; i < mapOfDot1.size(); i++)
    // cout << i << "-(" << mapOfDot1[i].first << "," << mapOfDot1[i].second << ")\n";
    // cout << '\n';

    vector<vector<bool>> relationMatrix1 = getRelationByConditionByDotSet(predicate, M1, mapOfDot1);
    // outputMatrixBool(relationMatrix1);

    relationMatrix1 = getDominanceFromOrder(relationMatrix1);
    // outputMatrixBool(relationMatrix1);
    // cout << '\n';

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

void run_lab_4_1_1()
{
    vector<vector<int>> seqs = {
        {6, 2, 1, 7},
        {1, 2, 6, 5, 3, 6, 2},
        {1, 2, 6, 7, 1},
        {6, 7, 1, 2, 5, 1, 6},
        {1, 2, 6, 7, 2, 6, 3}};

    vector<vector<bool>> G1 = {
        {0, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0}};

    checkBoolFunc(isWay(G1, seqs[0]));
    checkBoolFunc(!isWay(G1, seqs[1]));
    checkBoolFunc(isWay(G1, seqs[2]));
    checkBoolFunc(isWay(G1, seqs[3]));
    checkBoolFunc(!isWay(G1, seqs[4]));
    cout << '\n';

    checkBoolFunc(isChain(G1, seqs[0]));
    checkBoolFunc(!isChain(G1, seqs[1]));
    checkBoolFunc(isChain(G1, seqs[2]));
    checkBoolFunc(isChain(G1, seqs[3]));
    checkBoolFunc(!isChain(G1, seqs[4]));
    cout << '\n';

    checkBoolFunc(isSimpleChain(G1, seqs[0]));
    checkBoolFunc(!isSimpleChain(G1, seqs[1]));
    checkBoolFunc(isSimpleChain(G1, seqs[2]));
    checkBoolFunc(!isSimpleChain(G1, seqs[3]));
    checkBoolFunc(!isSimpleChain(G1, seqs[4]));
    cout << '\n';

    checkBoolFunc(!isCycle(G1, seqs[0]));
    checkBoolFunc(!isCycle(G1, seqs[1]));
    checkBoolFunc(isCycle(G1, seqs[2]));
    checkBoolFunc(isCycle(G1, seqs[3]));
    checkBoolFunc(!isCycle(G1, seqs[4]));
    cout << '\n';

    checkBoolFunc(!isSimpleCycle(G1, seqs[0]));
    checkBoolFunc(!isSimpleCycle(G1, seqs[1]));
    checkBoolFunc(isSimpleCycle(G1, seqs[2]));
    checkBoolFunc(!isSimpleCycle(G1, seqs[3]));
    checkBoolFunc(!isSimpleCycle(G1, seqs[4]));
    cout << '\n';

    vector<vector<bool>> G2 = {
        {0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0}};

    checkBoolFunc(isWay(G2, seqs[0]));
    checkBoolFunc(!isWay(G2, seqs[1]));
    checkBoolFunc(isWay(G2, seqs[2]));
    checkBoolFunc(!isWay(G2, seqs[3]));
    checkBoolFunc(!isWay(G2, seqs[4]));
    cout << '\n';

    checkBoolFunc(isChain(G2, seqs[0]));
    checkBoolFunc(!isChain(G2, seqs[1]));
    checkBoolFunc(isChain(G2, seqs[2]));
    checkBoolFunc(!isChain(G2, seqs[3]));
    checkBoolFunc(!isChain(G2, seqs[4]));
    cout << '\n';

    checkBoolFunc(isSimpleChain(G2, seqs[0]));
    checkBoolFunc(!isSimpleChain(G2, seqs[1]));
    checkBoolFunc(isSimpleChain(G2, seqs[2]));
    checkBoolFunc(!isSimpleChain(G2, seqs[3]));
    checkBoolFunc(!isSimpleChain(G2, seqs[4]));
    cout << '\n';

    checkBoolFunc(!isCycle(G2, seqs[0]));
    checkBoolFunc(!isCycle(G2, seqs[1]));
    checkBoolFunc(isCycle(G2, seqs[2]));
    checkBoolFunc(!isCycle(G2, seqs[3]));
    checkBoolFunc(!isCycle(G2, seqs[4]));
    cout << '\n';

    checkBoolFunc(!isSimpleCycle(G2, seqs[0]));
    checkBoolFunc(!isSimpleCycle(G2, seqs[1]));
    checkBoolFunc(isSimpleCycle(G2, seqs[2]));
    checkBoolFunc(!isSimpleCycle(G2, seqs[3]));
    checkBoolFunc(!isSimpleCycle(G2, seqs[4]));
    cout << '\n';
}

void run_lab_4_1_2()
{
    vector<vector<bool>> G1 = {
        {0, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0}};

    outputWaysByLength(G1, 0, 5, 4);

    vector<vector<bool>> G2 = {
        {0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0}};

    outputWaysByLength(G2, 0, 5, 4);
}