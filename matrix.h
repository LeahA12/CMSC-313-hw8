#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    public:
        Matrix(int rows, int cols);
        void fill(int row, int col, int val);
        Matrix transpose(Matrix A);
        Matrix add2(Matrix A, Matrix B);
        Matrix multiply2(Matrix A, Matrix B);
        Matrix scalarMultiply(int scalar, Matrix A);
        void print();
    private:
        int rows;
        int cols;
        vector<vector<int>> data;
};

#endif