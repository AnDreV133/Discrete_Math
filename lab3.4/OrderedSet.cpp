#include "OrderedSet.h"
#include <algorithm>

map<int, pair<int, int>> getMapOfDot(vector<pair<int, int>> dotSet)
{
    map<int, pair<int, int>> res;
    for (int i = 0; i < dotSet.size(); i++)
    {
        res.insert({i, dotSet[i]});
    }

    return res;
}

vector<vector<bool>> getRelationByConditionByDotSet(
    bool (*condition)(pair<int, int>, pair<int, int>),
    vector<pair<int, int>> dotSet, map<int, pair<int, int>> mapOfDot)
{
    vector<vector<bool>> res;
    for (size_t x = 0; x < dotSet.size(); x++)
    {
        vector<bool> buf(dotSet.size());
        for (size_t y = 0; y < dotSet.size(); y++)
        {
            buf[y] = condition(mapOfDot[x], mapOfDot[y]);
        }
        res.push_back(buf);
    }

    return res;
}

vector<vector<bool>> getDominanceFromOrder(vector<vector<bool>> matrix)
{
    vector<vector<bool>> res = matrix;

    for (size_t i = 0; i < res.size(); i++)
        res[i][i] = 0;

    for (size_t x = 0; x < res.size(); x++)
    {
        for (size_t y = 0; y < res.size(); y++)
        {
            if (!res[x][y])
                continue;

            for (size_t z = 0; z < res.size(); z++)
            {
                if (res[x][z] && res[z][y])
                {
                    res[x][y] = 0;
                    break;
                }
            }
        }
    }

    return res;
}

bool areElemsNegative(vector<int> arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= 0)
            return false;
    }

    return true;
}

void outputResultByDots(vector<vector<int>> knotsByLevels, map<int, pair<int, int>> mapOfDot)
{
    for (auto level : knotsByLevels)
    {
        for (auto knot : level)
        {
            cout << "(" << mapOfDot[knot].first << "," << mapOfDot[knot].second << ") ";
            // cout << knot;
        }
        cout << "\n";
    }
}

vector<vector<int>> getTopologicalSort(vector<vector<bool>> matrix)
{
    std::vector<int> sumArr(matrix.size(), 0);

    for (int x = 0; x < matrix.size(); x++)
    {
        for (int y = 0; y < matrix.size(); y++)
        {
            sumArr[y] += matrix[x][y];
        }
    }

    int deepOfDiagram = 0;

    while (true)
    {
        std::vector<int> indicesOnZeroElems;

        // Поиск нулевых элементов и сохранение их индексов
        for (size_t i = 0; i < sumArr.size(); i++)
            {
                if (sumArr[i] == 0)
                    indicesOnZeroElems.push_back(i);
            }

        if (indicesOnZeroElems.empty())
            break;

        deepOfDiagram--;
        for (auto indexOnZeroElem : indicesOnZeroElems)
        {
            // Заменяем нулевой элемент
            sumArr[indexOnZeroElem] = deepOfDiagram;

            for (int i = 0; i < matrix[indexOnZeroElem].size(); i++)
            {
                bool element = matrix[indexOnZeroElem][i];
                sumArr[i] -= element;
            }
        }
    }

    std::vector<std::vector<int>> levels;
    for (int i = 0; i < matrix.size(); i++)
    {
        std::vector<int> level;

        for (int j = 0; j < matrix.size(); j++)
        {
            if (sumArr[j] == -(1 + i))
                level.push_back(j);
        }

        if (level.empty())
            break;

        levels.push_back(level);
    }

    return levels;
}