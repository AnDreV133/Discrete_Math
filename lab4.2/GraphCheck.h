#ifndef DISCRETE_MATH_GRAPHCHECK_H
#define DISCRETE_MATH_GRAPHCHECK_H

#include <vector>
#include <iostream>

using namespace std;

typedef vector<vector<int>> Graph;

Graph generationGraphs(const int n, const int m);
int getEdgeCount(Graph &v);
Graph getIncidence(Graph &g);
bool isHamiltonianGraph(const Graph &g);
bool isEulerGraph(const Graph &g);

#endif // DISCRETE_MATH_GRAPHCHECK_H
