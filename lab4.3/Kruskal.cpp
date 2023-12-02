#include "Kruskal.h"

#include <iostream>
#include <vector>
#include <ctime>
#include <stack>

int kruskal(Grapf &g)
{
    vector<int> num(g.size());
    for (size_t i = 0; i < g.size(); i++)
        num[i] = i;
    int count = g.size();

    for (size_t i = 0; i < g.size(); i++)
        for (size_t j = 0; j < g[0].size(); j++)
            if (g[i][j] && num[i] != num[j] && --count)
                num[j] = num[i];

    return count;
}

void getMinSetOfVertex_(Grapf &g, const vector<vector<int>> &e, vector<pair<int, int>> tree, const size_t i, const int b, bool &isFindMinSet)
{
    for (size_t j = b; j <= e[0].size() - tree.size() + i; j++)
    {
        tree[i] = make_pair(e[0][j], e[1][j]);
        g[e[0][j]][e[1][j]] = 0;
        g[e[1][j]][e[0][j]] = 0;

        if (i != tree.size() - 1)
            getMinSetOfVertex_(g, e, tree, i + 1, j + 1, isFindMinSet);
        else if (kruskal(g) == 2)
        {
            cout << "{";
            for (auto least : tree)
                cout << "(" << least.first + 1 << " " << least.second + 1 << ") ";
            cout << "\b}\n";

            isFindMinSet = true;
        }

        g[e[0][j]][e[1][j]] = 1;
        g[e[1][j]][e[0][j]] = 1;
    }
}

void outputMinSetOfVertex(Grapf &g, vector<vector<int>> &e)
{
    bool isFindMinSet = false;
    int treeSize = 1;
    while (treeSize < g.size() && !isFindMinSet)
    {
        vector<pair<int, int>> tree(treeSize);
        getMinSetOfVertex_(g, e, tree, 0, 0, isFindMinSet);
        treeSize++;
    }
}

vector<vector<int>> getMRows(Grapf &g)
{
    vector<vector<int>> e(2, vector<int>((g.size() * g.size() - g.size()) / 2));
    int count = 0;
    for (size_t i = 0; i < g.size(); i++)
        for (size_t j = i; j < g[0].size(); j++)
            if (g[i][j])
            {
                e[0][count] = i;
                e[1][count] = j;

                count++;
            }

    for (size_t i = 0; i < e[0].size() - count; i++)
    {
        e[0].pop_back();
        e[1].pop_back();
    }

    return e;
}