#include "Graph.h"
#include <set>
#include <algorithm>

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

void outputWaysByLength_(vector<vector<bool>> graph, vector<int> way, int i, int length)
{
    for (int x : getAdjacentTops(graph, way[i]))
    {
        if (i + 1 == length)
            outputWay(way);
        else
        {
            way[i + 1] = x;
            outputWaysByLength_(graph, way, i + 1, length);
        }
    }
}

void outputWaysByLength(vector<vector<bool>> graph, int startTop, int length)
{
    vector<int> way(length);
    way[0] = startTop - 1;

    outputWaysByLength_(graph, way, 0, length);
}

vector<vector<int>> getMatrixInPow(vector<vector<int>> matrix, int exp)
{
    vector<vector<int>> res = matrix; // todo сделать умножение и возведение в степень соотвественно
    for (size_t e = 2; e <= exp; e++)
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix.size(); ++j)
                for (int k = 0; k < matrix.size(); ++k)
                    res[i][j] += res[i][k] * matrix[k][j];

    return res;
}

vector<vector<int>> getMatrixOfAmountWays(vector<vector<bool>> graph, int lengthWays)
{
    vector<vector<int>> matrix;
    for (size_t i = 0; i < graph.size(); i++)
    {
        vector<int> buf;
        for (size_t j = 0; j < graph.size(); j++)
        {
            buf.push_back(graph[i][j]);
        }

        matrix.push_back(buf);
    }

    return getMatrixInPow(matrix, lengthWays);
}

long long getAmountWaysByLength(vector<vector<bool>> graph, int lengthWays)
{
    vector<vector<int>> matrixOfAmountWays = getMatrixOfAmountWays(graph, lengthWays);
    long long sum = 0;
    for (size_t i = 0; i < matrixOfAmountWays.size(); i++)
        for (size_t j = 0; j < matrixOfAmountWays.size(); j++)
            sum += matrixOfAmountWays[i][j];

    return sum;
}

void outputWaysByLengthByTops_(vector<vector<bool>> graph, vector<int> way, int i, int length)
{
    for (int x : getAdjacentTops(graph, way[i]))
    {
        if (i + 1 == length)
        {
            if (x == way[i + 1])
                outputWay(way);
        }
        else
        {
            way[i + 1] = x;
            outputWaysByLengthByTops_(graph, way, i + 1, length); 
        }
    }
}

void outputWaysByLengthByTops(vector<vector<bool>> graph, int startTop, int endTop, int length)
{
    vector<int> way(length);
    way[0] = startTop - 1;
    way[length - 1] = endTop - 1;

    outputWaysByLengthByTops_(graph, way, 0, length - 1);
}

void outputSimpleMaxChains_(vector<vector<bool>> &graph, vector<int> &way, int i, int length, set<int> &includedTops)
{
    auto adjacentTops = getAdjacentTops(graph, way[i]);
    set<int> remainingVertices;
    set_difference(adjacentTops.begin(), adjacentTops.end(),
                   includedTops.begin(), includedTops.end(),
                   inserter(remainingVertices, remainingVertices.begin()));
    if (i + 1 == length)
        outputWay(way);
    else
        for (const auto &x : remainingVertices)
        {
            way[i + 1] = x;
            includedTops.insert(x);
            outputSimpleMaxChains_(graph, way, i + 1, length, includedTops);
            includedTops.erase(x);
        }
}

void outputSimpleMaxChains(vector<vector<bool>> graph, int top, int length)
{
    vector<int> way(length);
    way[0] = top - 1;
    set<int> includedTops = {top - 1};
    outputSimpleMaxChains_(graph, way, 0, length, includedTops);
}
