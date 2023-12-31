#include "Dijkstra.h"

#include <iostream>
#include <vector>
#include <ctime>
#include <stack>
#include <queue>

vector<int> amountsOfPasses;

void Dijkstra(vector<vector<int>> weightedGraph, int startVertex)
{
    bool visited[weightedGraph.size()];
    int D[weightedGraph.size()];
    int prev[weightedGraph.size()];
    for (int i = 0; i < weightedGraph.size(); i++)
    {
        D[i] = INT_MAX;
        visited[i] = false;
        prev[i] = -1;
    }
    D[startVertex] = 0;

    int minIndex = 0, u = 0;
    for (int _ = 0; _ < weightedGraph.size(); _++)
    {
        int min = INT_MAX;
        for (int i = 0; i < weightedGraph.size(); i++)
        {
            if (!visited[i] && D[i] < min)
            {
                min = D[i];
                minIndex = i;
            }
        }

        // if (minIndex == endVertex)
        // {
        //     break;
        // }

        if (D[minIndex] == INT_MAX)
            continue;

        u = minIndex;
        visited[u] = true;
        for (int i = 0; i < weightedGraph.size(); i++)
        {
            if (!visited[i] && weightedGraph[u][i] != 0 && (D[u] + weightedGraph[u][i]) < D[i])
            {
                D[i] = D[u] + weightedGraph[u][i];
                prev[i] = u;
            }
        }
    }

    for (size_t i = 0; i < weightedGraph.size(); i++)
    {
        if(i == startVertex)
            continue;

        u = i;
        stack<int> s;
        while (u != -1)
        {
            s.emplace(u);
            if (!amountsOfPasses.empty())
                amountsOfPasses[u]++;

            u = prev[u];
        }

        while (!s.empty())
        {
            cout << s.top() << ' ';
            s.pop();
        }
        cout << '\n';
    }
}

void clearAmountsOfPasses(int n)
{
    amountsOfPasses.assign(n, 0);
}

int getVertexOfMaxPasses()
{
    int res = 0;
    for (size_t i = 0; i < amountsOfPasses.size(); i++)
    {
        if (amountsOfPasses[i] > amountsOfPasses[res])
            res = i;
    }
     
    return res;
}