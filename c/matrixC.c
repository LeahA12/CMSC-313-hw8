#include "matrixC.h"

Matrix* create(int rows, int cols){
    // Allocate memory for matrix
    Matrix *matrixPtr = (Matrix*)malloc(sizeof(Matrix));
    // Check if memory allocation was successful
    if (matrixPtr == NULL){
        return NULL;
    }

    matrixPtr->rows = rows;
    matrixPtr->cols = cols;

    // Allocate memory for matrix's array of rows
    matrixPtr->data = (int**)malloc(rows * sizeof(int*));
    // Check if memory allocation was successful
    if (matrixPtr->data == NULL){
        free(matrixPtr);
        return NULL;
    }

    // Allocate memory for each matrix element
    for (int r = 0; r < rows; r++){
        // Allocate memory and initialize to zero for data in matrix's ith row
        matrixPtr->data[r] = (int*)calloc(cols, sizeof(int));
        // Check if memory allocation was successful
        if (matrixPtr->data[r] == NULL){
            for (int i = 0; i < r; i++){
                free(matrixPtr->data[i]);
            }
            free(matrixPtr->data);
            free(matrixPtr);
            return NULL;
        }
    }

    // When all memory allocations were successful
    return matrixPtr;
}

void fill(Matrix *matrixPtr, int row, int col, int val){
    matrixPtr->data[row][col] = val;
}

Matrix* transpose(Matrix *A){
    Matrix *result = create(A->cols, A->rows);
    for (int r = 0; r < A->rows; r++){
        for (int c = 0; c < A->cols; c++){
            fill(result, c, r, A->data[r][c]);
        }
    }
    return result;
}

Matrix* add2(Matrix *A, Matrix *B){
    Matrix *sum = create(A->rows, A->cols);
    for (int r = 0; r < A->rows; r++) {
        for (int c = 0; c < A->cols; c++) {
            fill(sum, r, c, A->data[r][c] + B->data[r][c]);
            }
        }
    return sum;
}

Matrix* multiply2(Matrix *A, Matrix *B){
    Matrix *product = create(A->rows, B->cols);
    if (A->cols == B->rows){
        for (int r = 0; r < A->rows; r++){
            for (int c = 0; c < B->cols; c++){
                int sum = 0;
                for (int i = 0; i < A->cols; i++){
                    sum += A->data[r][i] * B->data[i][c];
                }
                fill(product, r, c, sum);
            }
        }
    }
    return product;
}

Matrix* scalarMultiply(int scalar, Matrix *A){
    Matrix *product = create(A->rows, A->cols);
    for (int r = 0; r < A->rows; r++){
        for (int c = 0; c < A->cols; c++){
            fill(product, r, c, scalar * A->data[r][c]);
        }
    }    
    return product;
}

void print(Matrix *matrixPtr){
    for (int r = 0; r < matrixPtr->rows; r++){
        for (int c = 0; c < matrixPtr->cols; c++){
            printf("%d ", matrixPtr->data[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

void freeMatrix(Matrix *matrixPtr){
    if (matrixPtr != NULL){
        if (matrixPtr->data != NULL){
            for (int r = 0; r < matrixPtr->rows; r++){
                if (matrixPtr->data[r] != NULL){
                    free(matrixPtr->data[r]);
                }
            }
            free(matrixPtr->data);
        }
        free(matrixPtr);
    }
}