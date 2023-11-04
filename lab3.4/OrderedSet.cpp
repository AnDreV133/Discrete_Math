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
    for (size_t i = 0; i < dotSet.size(); i++)
    {
        vector<bool> buf(dotSet.size());
        for (size_t j = 0; j < dotSet.size(); j++)
        {
            buf[j] = condition(mapOfDot[i], mapOfDot[j]);
        }
        res.push_back(buf);
    }

    return res;
}
