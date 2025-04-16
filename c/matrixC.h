#ifndef MATRIX_H_C
#define MATRIX_H_C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix* create(int rows, int cols);
void fill(Matrix *matrixPtr, int row, int col, int val);
Matrix* transpose(Matrix *A);
Matrix* add2(Matrix *A, Matrix *B);
Matrix* multiply2(Matrix *A, Matrix *B);
Matrix* scalarMultiply(int scalar, Matrix *A);
void print(Matrix *matrixPtr);
void freeMatrix(Matrix *matrixPtr);

#endif