#include "Graph.h"

bool isWay(vector<vector<bool>> graph, vector<int> seq)
{
    int i = 0;
    while (i < (seq.size() - 1))
    {
        if (!(graph[seq[i] - 1][seq[i + 1] - 1]))
            return false;
        i++;
    }
    return true;
}

bool isChain(vector<vector<bool>> graph, vector<int> seq)
{
    int buf[MAX_SIZE_BUF] = {0};
    int i = 0;
    while (i < (seq.size() - 1))
    {
        if (!(graph[seq[i] - 1][seq[i + 1] - 1]) || buf[seq[i] - 1] == seq[i + 1])
            return false;

        buf[seq[i] - 1] = seq[i + 1];
        i++;
    }
    return true;
}

bool isSimpleChain(vector<vector<bool>> graph, vector<int> seq)
{
    int buf[MAX_SIZE_BUF] = {0};
    int i = 0;
    while (i < (seq.size() - 1))
    {
        if (!(graph[seq[i] - 1][seq[i + 1] - 1]) || buf[seq[i] - 1])
            return false;

        buf[seq[i] - 1] = 1;
        i++;
    }
    return true;
}

bool isCycle(vector<vector<bool>> graph, vector<int> seq)
{
    return isWay(graph, seq) && seq[0] == seq[seq.size() - 1];
}

bool isSimpleCycle(vector<vector<bool>> graph, vector<int> seq)
{
    return isSimpleChain(graph, seq) && seq[0] == seq[seq.size() - 1];
}

void outputWay(vector<int> way)
{
    for (int top : way)
        cout << top + 1 << ' ';
    cout << '\n';
}

vector<int> getAdjacentTops(vector<vector<bool>> graph, int i)
{
    vector<int> res;
    for (int x = 0; x < graph.size(); x++)
    {
        if (graph[x][i])
            res.push_back(x);
    }

    return res;
}

void outputWaysByLength(vector<vector<bool>> graph, int i, int startTop, int length)
{
    static vector<int> way(length, startTop - 1);
    for (int x : getAdjacentTops(graph, way[i]))
    {
        way[i + 1] = x;
        if (i + 1 == length - 1)
            outputWay(way);
        else
            outputWaysByLength(graph, i + 1, startTop, length);
    }
}