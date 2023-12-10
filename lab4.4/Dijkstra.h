#ifndef DISCRETE_MATH_DICSTRA_H
#define DISCRETE_MATH_DICSTRA_H

#include <vector>
#include <iostream>

using namespace std;

void Dijkstra(vector<vector<int>> weightedGraph, int startVertex);
void clearAmountsOfPasses(int n);
int getVertexOfMaxPasses();


#endif // DISCRETE_MATH_DICSTRA_H
