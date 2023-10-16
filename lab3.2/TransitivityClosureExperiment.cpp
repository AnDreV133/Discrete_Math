//
// Created by dmitr on 16.10.2023.
//

#include "TransitivityClosureExperiment.h"

size_t numOfExecutions = 0;

vector<vector<bool>> unionOperInj(vector<vector<bool>> A, vector<vector<bool>> B) {
    vector<vector<bool>> C(A.size(), vector<bool>(A[0].size()));
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            numOfExecutions++;
            C[i][j] = A[i][j] || B[i][j];
        }
    }

    return C;
}

vector<vector<bool>> compositionOperInj(vector<vector<bool>> A, vector<vector<bool>> B) {
    int metric = A.size();
    vector<vector<bool>> C(metric, vector<bool>(metric));
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A[i].size(); ++j)
            for (int k = 0; k < metric; ++k) {
                numOfExecutions++;
                if (!C[i][j])
                    C[i][j] = A[i][k] && B[k][j];
                else
                    break;
            }
    return C;
}

vector<vector<bool>> getTransitiveClosureInj(vector<vector<bool>> &matrix) {
    numOfExecutions = 0;
    vector<vector<bool>> result = matrix;
    vector<vector<bool>> subMatrixForPow = matrix;

    for (int i = 1; i < matrix.size(); ++i) {
        subMatrixForPow = compositionOperInj(matrix, subMatrixForPow);
        result = unionOperInj(result, subMatrixForPow);
    }

    return result;
}

vector<vector<bool>> getTransitiveClosureByWarshellAlgorithmInj(vector<vector<bool>> &matrix) {
    numOfExecutions = 0;
    vector<vector<bool>> result = matrix;

    for (int z = 0; z < result.size(); ++z)
        for (int x = 0; x < result.size(); ++x) {
            if (result[x][z] == 0)
                continue;

            for (int y = 0; y < result.size(); ++y) {
                numOfExecutions++;
                result[x][y] = result[x][y] || result[x][z] && result[z][y];
            }
        }

    return result;
}

vector<vector<bool>> generateRelationByRandom(int powerOfSet, int amountPair) {
    if (amountPair > pow(2, powerOfSet)) {
        cerr << "amount pair bigger than power of set";
        return {};
    }

    vector<vector<bool>> result = vector<vector<bool>>(powerOfSet, vector<bool>(powerOfSet));
    srand(time(nullptr));

    int i = 0;
    while (i < amountPair) {
        int x = rand() % powerOfSet;
        int y = rand() % powerOfSet;

        if (!result[x][y])
            result[x][y] = true;
        else
            continue;

        i++;
    }

    return result;
}
size_t getFuncN2Div4(size_t n) {
    return (size_t) pow(n, 2) / 4;
}

size_t getFuncN2Div2(size_t n) {
    return (size_t) pow(n, 2) / 2;
}

size_t getFuncN2Mult2Div3(size_t n) {
    return (size_t) pow(n, 2) * 2 / 3;
}

size_t getFuncN2(size_t n) {
    return (size_t) pow(n, 2);
}

void
gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(ofstream &outpustStream, int powerOfSet, int amountPair,
                                                               vector<vector<bool>> (*operation)(
                                                                       vector<vector<bool>> &), string name) {
    size_t minNumOfExecutions = ULONG_LONG_MAX;
    size_t maxNumOfExecutions = 0;
    vector<vector<bool>> result;
    for (int i = 0; i < 1000; ++i) {
        vector<vector<bool>> generatedRelation
                = generateRelationByRandom(powerOfSet, amountPair);

        result = operation(generatedRelation);

        minNumOfExecutions = min(numOfExecutions, minNumOfExecutions);
        maxNumOfExecutions = max(numOfExecutions, maxNumOfExecutions);
    }

    outpustStream << "N = " << powerOfSet << "; "
                  << "amount pair = " << amountPair << "; "
                  << "min k = " << minNumOfExecutions << "; "
                  << "max k = " << maxNumOfExecutions << " res: "
                  << (transitivityOper(result) ? "COMP" : "ERR!")
                  << " - " << name << "\n";
}

int main_test() {
    ofstream fileStream("../testTransitiveClosure.txt");

    if (!fileStream.is_open()) {
        cerr << "File not open";
        exit(1);
    }

    for (int n = 5; n <= 15; n += 5) {
        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, 1, getTransitiveClosureInj, "union pow");
        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, 1, getTransitiveClosureByWarshellAlgorithmInj, "Warshall alg");

        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2Div4(n), getTransitiveClosureInj, "union pow");
        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2Div4(n), getTransitiveClosureByWarshellAlgorithmInj, "Warshall alg");

        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2Mult2Div3(n), getTransitiveClosureInj, "union pow");
        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2Mult2Div3(n), getTransitiveClosureByWarshellAlgorithmInj, "Warshall alg");

        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2Div2(n), getTransitiveClosureInj, "union pow");
        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2Div2(n), getTransitiveClosureByWarshellAlgorithmInj, "Warshall alg");

        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2(n), getTransitiveClosureInj, "union pow");
        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2(n), getTransitiveClosureByWarshellAlgorithmInj, "Warshall alg");
    }

    fileStream.close();

    return 0;
}
