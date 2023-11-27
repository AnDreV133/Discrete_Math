#ifndef DISCRETE_MATH_GRAPH_H
#define DISCRETE_MATH_GRAPH_H

#include <vector>
#include <iostream>

#define MAX_SIZE_BUF 20

using namespace std;

bool isWay(vector<vector<bool>> graph, vector<int> seq);
bool isChain(vector<vector<bool>> graph, vector<int> seq);
bool isSimpleChain(vector<vector<bool>> graph, vector<int> seq);
bool isCycle(vector<vector<bool>> graph, vector<int> seq);
bool isSimpleCycle(vector<vector<bool>> graph, vector<int> seq);

void outputWaysByLength(vector<vector<bool>> graph, int i, int startTop, int length);
void outputWay(vector<int> way, int length);

#endif // DISCRETE_MATH_GRAPH_H
