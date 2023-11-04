#include "alg.h"

template <typename T>
void outputMatrix(vector<vector<T>> matrix) {
    for (auto ai : relationMatrix)
    {
        for (auto aij : ai)
            cout << aij << " ";

        cout << '\n';
    }
}