#include "Floyd.h"

#include <iostream>
#include <vector>
#include <ctime>
#include <stack>
#include <queue>

vector<vector<int>> floyd(const vector<vector<int>> &g)
{
    vector<vector<int>> res = g;
    for (size_t i = 0; i < res.size(); i++)
        for (size_t j = 0; j < res.size(); j++)
        {
            if (i == j)
                continue;

            for (size_t k = 0; k < res.size(); k++)
                if (res[i][k] != 0 && res[k][j] != 0)
                    res[i][j] = std::min(res[i][j] != 0 ? res[i][j] : INT_MAX, res[k][j] + res[i][k]);
        }

    return res;
}

template <typename T>
bool isMatrixEquals(const vector<vector<T>> &m1, const vector<vector<T>> &m2)
{
    if (m1.size() != m2.size() || m1[0].size() != m2[0].size())
        return false;

    for (size_t i = 0; i < m1.size(); i++)
        for (size_t j = 0; j < m1[0].size(); j++)
            if (m1[i][j] != m2[i][j])
                return false;

    return true;
}

template <typename T>
long long getSumArr(vector<T> arr)
{
    long long res = 0;
    for (size_t i = 0; i < arr.size(); i++)
        res += arr[i];

    return res;
}

void outputMinimalCostTrees(const vector<vector<int>> &g)
{
    auto prevMatrixTrees = floyd(g);
    auto matrixTrees = floyd(prevMatrixTrees);
    while (!isMatrixEquals<int>(prevMatrixTrees, matrixTrees))
    {
        prevMatrixTrees = matrixTrees;
        matrixTrees = floyd(matrixTrees);
    }

    for (size_t i = 0; i < g.size(); i++)
    {
        long long sum = getSumArr<int>(matrixTrees[i]);
        if (!sum)
            continue;

        cout << "cost(root=" << i + 1 << ", ways={";
        for (size_t j = 0; j < g.size(); j++)
            if (i != j && matrixTrees[i][j])
                cout << "(" << i + 1 << "," << j + 1 << ")[" << matrixTrees[i][j] << "], ";

        cout << "\b\b}) = " << sum << '\n';
    }
}