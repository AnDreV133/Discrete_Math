#include "alg.h"

template <typename T>
void outputMatrix(vector<vector<T>> matrix)
{
    for (auto ai : matrix)
    {
        for (auto aij : ai)
            cout << aij << "\t";

        cout << '\n';
    }
}

void outputMatrixBool(vector<vector<bool>> matrix)
{
    outputMatrix<bool>(matrix);
}

void outputMatrixInt(vector<vector<int>> matrix)
{
    outputMatrix<int>(matrix);
}