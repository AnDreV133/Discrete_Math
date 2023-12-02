#ifndef DISCRETE_MATH_KRUSKAL_H
#define DISCRETE_MATH_KRUSKAL_H

#include <vector>
#include <iostream>

using namespace std;

typedef vector<vector<bool>> Grapf;

void outputMinSetOfVertex(Grapf &g, vector<vector<int>> &e);
vector<vector<int>> getMRows(Grapf &g);

#endif // DISCRETE_MATH_KRUSKAL_H
