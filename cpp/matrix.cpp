#include "matrix.h"

Matrix::Matrix(int rows, int cols): rows(rows), cols(cols), data(rows, vector<int>(cols, 0)) {}

void Matrix::fill (int row, int col, int val){
    if (row < 0 or row >= rows or col < 0 or  col >= cols){
        throw out_of_range("Matrix out of bounds.");    
    }
    data[row][col] = val;
}

Matrix Matrix::transpose(Matrix A){
    Matrix result(A.cols, A.rows);
    for (int r = 0; r < A.rows; r++) {
        for (int c = 0; c < A.cols; c++) {
            result.fill(c, r, A.data[r][c]);
        }
    }
    return result;
}

Matrix Matrix::add2(Matrix A, Matrix B){
    if (A.rows != B.rows or A.cols != B.cols){
        throw invalid_argument("Matrix dimensions are incorrect for this operation (addition).");
    }
    Matrix sum(A.rows, A.cols);
    if (A.rows == B.rows and A.cols == B.cols){
        for (int r = 0; r < A.rows; r++){
            for (int c = 0; c < A.cols; c++){
                sum.fill(r, c, A.data[r][c] + B.data[r][c]);
            }
        }
    }
    return sum;
}

Matrix Matrix::multiply2(Matrix A, Matrix B){
    if (A.cols != B.rows){
        throw invalid_argument("Matrix dimensions are incorrect for this operation (multiplication).");
    }
    Matrix product(A.rows, B.cols);
    if (A.cols == B.rows){
        for (int r = 0; r < A.rows; r++){
            for (int c = 0; c < B.cols; c++){
                int sum = 0;
                for (int i = 0; i < A.cols; i++){
                    sum += A.data[r][i] * B.data [i][c];
                }
                product.fill(r, c, sum);
            }
        }
    }
    return product;
}

Matrix Matrix::scalarMultiply(int scalar, Matrix A){
    Matrix product(A.rows, A.cols);
    for (int r = 0; r < A.rows; r++){
        for (int c = 0; c < A.cols; c++){
            product.fill(r, c, scalar * A.data[r][c]);
        }
    }    
    return product;
}

void Matrix::print(){
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            cout << data[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
