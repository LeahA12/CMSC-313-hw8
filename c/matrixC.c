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
    if (row < 0 || row >= matrixPtr->rows || 
        col < 0 || col >= matrixPtr->cols){
        printf("Error: Matrix out of bounds.\n");
        exit(1);
    }
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

Matrix* add2(Matrix *A, Matrix *B, int *err){
    if (A->rows != B->rows || A->cols != B->cols){
        printf("Error: Matrix dimensions are incorrect for this operation (addition).\n");
        exit(1);
        *err = 1;
        return NULL;
    }
    Matrix *sum = create(A->rows, A->cols);
    if (sum == NULL){
        printf("Error: Memory allocation error for this operation (addition).\n");
        exit(1);
        *err = 1;
        return NULL;
    }
    *err = 0;
    for (int r = 0; r < A->rows; r++) {
        for (int c = 0; c < A->cols; c++) {
            fill(sum, r, c, A->data[r][c] + B->data[r][c]);
            }
        }
    return sum;
}

Matrix* multiply2(Matrix *A, Matrix *B, int *err){
    if (A->cols != B->rows){
        printf("Error: Matrix dimensions are incorrect for this operation (multiplication).");
        *err = 1;
        return NULL;
    }
    Matrix *product = create(A->rows, B->cols);
    if (product == NULL){
        printf("Error: Memory allocation error for this operation (multiplication).\n");
        exit(1);
        *err = 1;
        return NULL;
    }
    *err = 0;
    for (int r = 0; r < A->rows; r++){
        for (int c = 0; c < B->cols; c++){
            int sum = 0;
            for (int i = 0; i < A->cols; i++){
                sum += A->data[r][i] * B->data[i][c];
            }
            fill(product, r, c, sum);
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
