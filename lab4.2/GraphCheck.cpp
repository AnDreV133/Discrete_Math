#include "GraphCheck.h"

#include <iostream>
#include <vector>
#include <ctime>
#include <stack>

Graph generationGraphs(const int n, const int m)
{
    Graph G(n, vector<int>(n, 0));
    for (int _ = 0; _ < m; _++)
    {
        int i = rand() % n;
        int j = rand() % n;
        G[i][j] = G[j][i] = i != j and !G[i][j];
    }

    return G;
}

int getEdgeCount(Graph &v)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
        for (int j = i + 1; j < v[i].size(); j++)
            if (v[i][j])
                count++;

    return count;
}

Graph getIncidence(Graph &g)
{
    Graph incidence(g.size(), vector<int>(getEdgeCount(g), 0));
    int column = 0;
    for (int i = 0; i < g.size(); i++)
        for (int j = i + 1; j < g[i].size(); j++)
            if (g[i][j])
            {
                incidence[j][column] = incidence[i][column] = 1;
                column++;
            }

    return incidence;
}

bool isHamiltonianGraph(const Graph &g)
{
    for (auto &row : g)
    {
        int s = 0;
        for (auto elem : row)
            s += elem;
        if (s < g.size() / 2)
            return false;
    }
    return true;
}

bool isEulerGraph(const Graph &g)
{
    for (int i = 0; i < g.size(); i++)
    {
        int counter = 0;
        for (int elem : g[i])
            counter += elem;
        if (counter % 2 != 0)
            return false;
    }
    return true;
}

void search_euler(int v, vector<vector<int>> &D, vector<int> &c)
{
    for (int i = 0; i < D[v].size(); ++i)
        if (D[v][i]) // если ребро есть
        {
            // проходим по нему
            D[v][i] = 0;
            D[i][v] = 0;
            search_euler(i, D, c);
        }
    c.push_back(v);
}
void euler(vector<vector<int>> D, vector<int> &c)
{
    int i, j;
    int n = D.size();
    c.clear();

    // вычисляем степени вершин
    vector<int> degree(n, 0);
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            if (D[i][j])
                ++degree[i];

    // проверяем существует ли в данном графе эйлеров цикл
    int count = 0; // количество степеней не кратных двум
    j = 0;         // начальная вершина
    for (i = 0; i < n; ++i)
        if (degree[i] % 2 != 0)
        {
            ++count;
            if (count > 2)
                return;
            j = i;
        }

    // находим цикл, проходящий по всем рёбрам только один раз
    search_euler(j, D, c);
}