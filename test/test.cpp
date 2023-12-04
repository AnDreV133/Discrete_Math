//
// Created by admin on 18.10.2023.
//

#include "test.h"
#include "../lab3.4/OrderedSet.h"
#include "../lab4.1/Graph.h"
#include "../lab4.2/GraphCheck.h"
#include "../lab4.3/Kruskal.h"
#include "../lab4.4/Dijkstra.h"
#include <ctime>

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

    outputWaysByLength(G1, 5, 3);
    cout << '\n';

    vector<vector<bool>> G2 = {
        {0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0}};

    outputWaysByLength(G2, 5, 3);
}

void run_lab_4_1_3()
{
    vector<vector<bool>> G1 = {
        {0, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0}};

    cout << getAmountWaysByLength(G1, 1) << '\n';

    vector<vector<bool>> G2 = {
        {0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0}};

    cout << getAmountWaysByLength(G2, 2) << '\n';
}

void run_lab_4_1_4()
{
    vector<vector<bool>> G1 = {
        {0, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0}};

    outputWaysByLengthByTops(G1, 5, 3, 4);
    cout << '\n';

    vector<vector<bool>> G2 = {
        {0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0}};

    outputWaysByLengthByTops(G2, 4, 1, 5);
}

void run_lab_4_1_5()
{
    vector<vector<bool>> G1 = {
        {0, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0}};

    outputSimpleMaxChains(G1, 4, 6);
    cout << '\n';

    vector<vector<bool>> G2 = {
        {0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0}};

    outputSimpleMaxChains(G2, 3, 6);
}

void run_lab_4_2_1()
{
    for (int n = 8; n <= 10; n++)
    {
        cout << "n  m\tEuler\t\tHamiltonian\t\tAll"
             << "\n";
        for (int m = n; m <= n * (n - 1) / 2; m++)
        {
            clock_t start = clock();
            size_t allGraphs = 0, eulerGraphs = 0, hamiltonianGraphs = 0;
            clock_t now = clock();
            while ((now - start) / CLOCKS_PER_SEC <= 10)
            {
                Graph G = generationGraphs(n, m);
                Graph incG = getIncidence(G);
                eulerGraphs += isEulerGraph(incG);
                hamiltonianGraphs += isHamiltonianGraph(incG);
                allGraphs += 1;
                now = clock();
            }
            cout << n << ' ' << m << "\t" << eulerGraphs << "\t\t"
                 << hamiltonianGraphs << "\t\t\t" << allGraphs << "\n";
        }
        cout << "\n";
    }
}

void run_lab_4_2_2()
{
    vector<int> a(7, 1);
    vector<vector<bool>> g = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {0, 0, 1, 1, 0}};

    auto subg = g;

    while (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] != 35)
    {
        bool flag = true;
        if (isCycle(g, a))
        {
            for (size_t i = 0; i < 6; i++)
            {
                subg[a[i] - 1][a[i + 1] - 1] = 0;
                subg[a[i + 1] - 1][a[i] - 1] = 0;
            }

            // outputMatrixBool(subg);

            for (size_t i = 0; i < 5; i++)
                for (size_t j = 0; j < 5; j++)
                    if (subg[i][j] == 1)
                        flag = false;

            subg = g;

            if (flag)
            {
                for (int ai : a)
                    cout << ai << ' ';
                cout << '\n';
            }
            // cout << '\n';
        }

        for (size_t i = 6; i >= 0; i--)
        {
            if (a[i] == 5)
                a[i] = 1;
            else
            {
                a[i]++;
                break;
            }
        }
    }
}

void run_lab_4_2_3()
{
    vector<int> a(5, 1);
    vector<vector<bool>> g = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}};

    auto subg = g;

    while (a[0] + a[1] + a[2] + a[3] + a[4] != 20)
    {
        bool flag = true;
        if (isCycle(g, a))
        {
            for (size_t i = 0; i < 4; i++)
            {
                subg[a[i] - 1][a[i + 1] - 1] = 0;
                subg[a[i + 1] - 1][a[i] - 1] = 0;
            }

            for (size_t i = 0; i < 4; i++)
                for (size_t j = 0; j < 4; j++)
                    if (subg[i][j] == 1)
                        flag = false;

            subg = g;

            if (flag)
            {
                for (int ai : a)
                    cout << ai << ' ';
                cout << '\n';
            }
        }

        for (size_t i = 4; i >= 0; i--)
        {
            if (a[i] == 4)
                a[i] = 1;
            else
            {
                a[i]++;
                break;
            }
        }
    }
}

void run_lab_4_3_1()
{
    Grapf g = {{0, 1, 1},
               {1, 0, 1},
               {1, 1, 0}};
    vector<vector<int>> g2 = getMRows(g);
    outputMinSetOfVertex(g, g2);
}

void run_lab_4_3_2()
{
    Grapf g = {
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {0, 0, 1, 0},
    };
    vector<vector<int>> g2 = getMRows(g);
    outputMinSetOfVertex(g, g2);
}

void run_lab_4_4()
{

    vector<vector<int>> g = {
        {0, 3, 6, 1, 0, 0, 0},
        {3, 0, 0, 0, 8, 10, 0},
        {6, 0, 0, 4, 4, 0, 0},
        {1, 0, 4, 0, 12, 0, 0},
        {0, 8, 4, 12, 0, 8, 1},
        {0, 10, 0, 0, 8, 0, 6},
        {0, 0, 0, 0, 1, 6, 0}
    };

    clearAmountsOfPasses(g.size());
    
    Dijkstra(g, 0, 4);
    cout << '\n';
    Dijkstra(g, 3, 0);
    cout << '\n';
    Dijkstra(g, 6, 0);
    cout << '\n';
    Dijkstra(g, 3, 5);
    cout << '\n';

    cout << "max vertex - " << getVertexOfMaxPasses();
}