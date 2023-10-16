//
// Created by dmitr on 16.10.2023.
//

#ifndef DISCRETE_MATH_RELATION_H
#define DISCRETE_MATH_RELATION_H

#include <vector>

using namespace std;

pair<int, int> failed;

bool inclusionOper(vector<vector<bool>> A, vector<vector<bool>> B);

bool equalOper(vector<vector<bool>> A, vector<vector<bool>> B);

bool strictInclusionOper(vector<vector<bool>> A, vector<vector<bool>> B);

vector<vector<bool>> unionOper(vector<vector<bool>> A, vector<vector<bool>> B);

vector<vector<bool>> intersectionOper(vector<vector<bool>> A, vector<vector<bool>> B);

vector<vector<bool>> difOper(vector<vector<bool>> A, vector<vector<bool>> B);

vector<vector<bool>> symDifOper(vector<vector<bool>> A, vector<vector<bool>> B);

vector<vector<bool>> additionOper(vector<vector<bool>> A);

vector<vector<bool>> inversionOper(vector<vector<bool>> A);

vector<vector<bool>> compositionOper(vector<vector<bool>> A, vector<vector<bool>> B);

bool reflexivityOper(vector<vector<bool>> A);

bool antiReflexivityOper(vector<vector<bool>> A);

bool symmetryOper(vector<vector<bool>> A);

bool antiSymmetryOper(vector<vector<bool>> A);

bool transitivityOper(vector<vector<bool>> A);

bool antiTransitivityOper(vector<vector<bool>> A);

bool fullyOper(vector<vector<bool>> A);

bool toleranceOper(vector<vector<bool>> A);

bool equalityOper(vector<vector<bool>> A);

bool orderOper(vector<vector<bool>> A);

bool looseOrderOper(vector<vector<bool>> A);

bool strictOrderOper(vector<vector<bool>> A);

bool linearOrderOper(vector<vector<bool>> A);

bool nonStrictLinearOrderOper(vector<vector<bool>> A);

bool strictLinearOrderOper(vector<vector<bool>> A);


#endif //DISCRETE_MATH_RELATION_H
