#ifndef DISCRETE_MATH_FLOYD_H
#define DISCRETE_MATH_FLOYD_H

#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> floyd(const vector<vector<int>> &g);
void outputMinimalCostTrees(const vector<vector<int>> &g);

#endif // DISCRETE_MATH_FLOYD_H
