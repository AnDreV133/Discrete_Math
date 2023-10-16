//
// Created by dmitr on 16.10.2023.
//


#include "Relation.h"



void updateBetween(vector<vector<bool>> A, vector<vector<bool>> B) {
    int maxX = max(A.size(), B.size());
    int maxY = max(A[0].size(), B[0].size());
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < maxY - A[i].size(); ++j)
            A[i].push_back(false);
    for (int i = 0; i < maxX - A.size(); ++i) {
        vector<bool> temp(maxY);
        A.push_back(temp);
    }
    for (int i = 0; i < B.size(); ++i)
        for (int j = 0; j < maxY - B[i].size(); ++j)
            B[i].push_back(false);
    for (int i = 0; i < maxX - B.size(); ++i) {
        vector<bool> temp(maxY);
        B.push_back(temp);
    }
}

int updateToSquare(vector<vector<bool>> A) {
    int maxMetric = max(A.size(), A[0].size());
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < maxMetric - A[i].size(); ++j)
            A[i].push_back(false);
    for (int i = 0; i < maxMetric - A.size(); ++i) {
        vector<bool> temp(maxMetric);
        A.push_back(temp);
    }
    return maxMetric;

}

bool inclusionOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            if (A[i][j] == 1 && B[i][j] == 0)
                return false;
        }
    }
    return true;
}

bool equalOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            if (A[i][j] != B[i][j])
                return false;
        }
    }
    return true;
}

bool strictInclusionOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);
    bool flag = false;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            if (A[i][j] == 1 && B[i][j] == 0)
                return false;
            if (A[i][j] != B[i][j])
                flag = true;
        }
    }
    return flag;
}

vector<vector<bool>> unionOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);
    vector<vector<bool>> C(A.size(), vector<bool>(A[0].size()));
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            C[i][j] = A[i][j] || B[i][j];
        }
    }
    return C;
}

vector<vector<bool>> intersectionOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);
    vector<vector<bool>> C(A.size(), vector<bool>(A[0].size()));
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            C[i][j] = A[i][j] && B[i][j];
        }
    }
    return C;
}

vector<vector<bool>> difOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);
    vector<vector<bool>> C(A.size(), vector<bool>(A[0].size()));
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            C[i][j] = A[i][j] && !B[i][j];
        }
    }
    return C;
}

vector<vector<bool>> symDifOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);
    vector<vector<bool>> C(A.size(), vector<bool>(A[0].size()));
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            C[i][j] = A[i][j] && !B[i][j] || !A[i][j] && B[i][j];
        }
    }
    return C;
}

vector<vector<bool>> additionOper(vector<vector<bool>> A) {
    int maxMetric = updateToSquare(A);
    vector<vector<bool>> C(maxMetric, vector<bool>(maxMetric));
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            C[i][j] = !A[i][j];
        }
    }
    return C;
}

vector<vector<bool>> inversionOper(vector<vector<bool>> A) {
    int maxMetric = updateToSquare(A);
    vector<vector<bool>> C(maxMetric, vector<bool>(maxMetric));
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            C[i][j] = A[j][i];
        }
    }
    return C;
}

vector<vector<bool>> compositionOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);
    int maxMetric1 = updateToSquare(A);
    int maxMetric2 = updateToSquare(B);
    int maxMetric = max(maxMetric1, maxMetric2);
    vector<vector<bool>> C(maxMetric, vector<bool>(maxMetric));
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A[i].size(); ++j)
            for (int k = 0; k < maxMetric; ++k)
                if (!C[i][j])
                    C[i][j] = A[i][k] && B[k][j];
                else
                    break;
    return C;
}

bool reflexivityOper(vector<vector<bool>> A) {
    updateToSquare(A);
    for (int i = 0; i < A.size(); ++i) {
        if (!A[i][i]) {
            failed = {i + 1, i + 1};
            return false;
        }
    }
    return true;
}
bool antiReflexivityOper(vector<vector<bool>> A) {
    updateToSquare(A);
    for (int i = 0; i < A.size(); ++i) {
        if (A[i][i]) {
            failed = {i + 1, i + 1};
            return false;
        }
    }
    return true;
    14
}
bool symmetryOper(vector<vector<bool>> A) {
    updateToSquare(A);
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A.size(); ++j)
            if (A[i][j] && !A[j][i]) {
                failed = {i + 1, j + 1};
                return false;
            }
    return true;
}
bool antiSymmetryOper(vector<vector<bool>> A) {
    updateToSquare(A);
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A.size(); ++j)
            if (A[i][j] && A[j][i]) {
                failed = {i + 1, j + 1};
                return false;
            }
    return true;
}
bool transitivityOper(vector<vector<bool>> A) {
    updateToSquare(A);
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A.size(); ++j)
            for (int k = 0; k < A.size(); ++k)
                if (A[i][k] && A[k][j] && !A[i][j]) {
                    failed = {i + 1, j + 1};
                    return false;
                }
    return true;
}
bool antiTransitivityOper(vector<vector<bool>> A) {
    updateToSquare(A);
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A.size(); ++j)
            for (int k = 0; k < A.size(); ++k)
                if (A[i][k] && A[k][j] && A[i][j]) {
                    failed = {i + 1, j + 1};
                    return false;
                }
    return true;
}
bool fullyOper(vector<vector<bool>> A) {
    updateToSquare(A);
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A.size(); ++j)
            if (i != j)
                if (!(A[i][j] || A[j][i])) {
                    failed = {i + 1, j + 1};
                    return false;
                    15
                }
    return true;
}
bool toleranceOper(vector<vector<bool>> A) {
    return reflexivityOper(A) && symmetryOper(A);
}
bool equalityOper(vector<vector<bool>> A) {
    return reflexivityOper(A) && symmetryOper(A) && transitivityOper(A);
}
bool orderOper(vector<vector<bool>> A) {
    return antiSymmetryOper(A) && transitivityOper(A);
}
bool looseOrderOper(vector<vector<bool>> A) {
    return orderOper(A) && reflexivityOper(A);
}
bool strictOrderOper(vector<vector<bool>> A) {
    return orderOper(A) && antiReflexivityOper(A);
}
bool linearOrderOper(vector<vector<bool>> A) {
    return orderOper(A) && fullyOper(A);
}
bool nonStrictLinearOrderOper(vector<vector<bool>> A) {
    return looseOrderOper(A) && fullyOper(A);
}
bool strictLinearOrderOper(vector<vector<bool>> A) {
    return strictOrderOper(A) && fullyOper(A);
}

