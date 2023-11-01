//
// Created by admin on 18.10.2023.
//

#include "test.h"
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> M1 = {
    {-1, 1}, {0, 1}, {1, 1},
    {-1, 0}, {0, 0}, {1, 0}, 
    {-1, -1}, {0, -1}, {1, -1}};



vector<pair<int, int>> M2 = {
    {0, 2},
    {-1, 1}, {0, 1},{1, 1},
    {-2, 0}, {-1, 0}, {0, 0}, {1, 0}, {2, 0},
    {-1, -1}, {0, -1}, {1, -1},
    {0, -2}};

bool predicate(pair<int, int> a, pair<int, int> b) {
    return (a.first + b.second) > (b.first + a.second);
}

void run_lab_3_4()
{
}