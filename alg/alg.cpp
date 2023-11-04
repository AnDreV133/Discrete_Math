#include "alg.h"

// template <typename T>
void outputMatrix(vector<vector<bool>> matrix) {
    for (auto ai : matrix)
    {
        for (auto aij : ai)
            cout << aij << " ";

        cout << '\n';
    }
}