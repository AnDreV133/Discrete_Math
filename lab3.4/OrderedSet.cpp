#include "OrderedSet.h"

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

vector<vector<int>> getTopologicalSort(vector<vector<bool>> matrix)
{
    vector<int> sumArr;
    for (size_t y = 0; y < matrix.size(); y++)
    {
        int count = 0;
        for (size_t x = 0; x < matrix.size(); x++)
        {
            if (matrix[x][y])
                count++;
        }
        sumArr.push_back(count);
    }

    vector<vector<int>> res;
    while (true)
    {
        for (size_t layer = 1; layer <= sumArr.size(); layer++)
        {
            vector<int> buf;
            int equalElem = -1;
            for (size_t i = 0; i < sumArr.size(); i++)
            {
                if (sumArr[i] == 0)
                {
                    int x = 0;
                    while (x < matrix.size() && equalElem < 0)
                    {
                        if (matrix[x][i] == 1)
                        {
                            equalElem = x;
                            break;
                        }

                        x++;
                    }
                    x = 0;
                    while (x < matrix.size())
                    {
                        if (matrix[x][i] && x == equalElem || equalElem < 0)
                        {
                            buf.push_back(i);
                            sumArr[i] = -1;
                            break;
                        }

                        x++;
                    } // todo не выводятся некоторые элементы
                }
            }

            if (!buf.empty())
                res.push_back(buf);

            for (size_t i = 0; i < sumArr.size(); i++)
            {

                if (sumArr[i] == layer)
                    sumArr[i] = 0;
            }
        }

        if (areElemsNegative(sumArr))
            break;

        for (size_t i = 0; i < sumArr.size(); i++)
        {
            sumArr[i]--;
        }
    }

    return res;
}

void outputResultByDots(vector<vector<int>> knotsByLevels, map<int, pair<int, int>> mapOfDot)
{
    for (auto level : knotsByLevels)
    {
        for (auto knot : level)
        {
            cout << "(" << mapOfDot[knot].first << "," << mapOfDot[knot].second << ") ";
        }
        cout << "\n";
    }
}