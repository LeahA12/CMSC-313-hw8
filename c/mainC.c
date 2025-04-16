#include "matrixC.h"

int main() {
    printf("Matrix A:\n");
    Matrix *A = create(2, 2);
    fill(A, 0, 0, 6);
    fill(A, 0, 1, 4);
    fill(A, 1, 0, 8);
    fill(A, 1, 1, 3);
    print(A);
    
    printf("Matrix B:\n");
    Matrix *B = create(2, 3);
    fill(B, 0, 0, 1);
    fill(B, 0, 1, 2);
    fill(B, 0, 2, 3);
    fill(B, 1, 0, 4);
    fill(B, 1, 1, 5);
    fill(B, 1, 2, 6);
    print(B);

    printf("Matrix C:\n");
    Matrix *C = create(2, 3);
    fill(C, 0, 0, 2);
    fill(C, 0, 1, 4);
    fill(C, 0, 2, 6);
    fill(C, 1, 0, 1);
    fill(C, 1, 1, 3);
    fill(C, 1, 2, 5);
    print(C);

    printf("(3 * B) =\n");
    Matrix *B_scaled = scalarMultiply(3, B);
    print(B_scaled);

    printf("C^T =\n");
    Matrix *C_transposed = transpose(C);
    print(C_transposed);

    printf("(3 * B) * C^T =\n");
    Matrix *BC_product = NULL;
    BC_product = multiply2(B_scaled, C_transposed);
    print(BC_product);
    
    printf("D = A + (3 * B) * C^T =\n");
    Matrix *D_sum = NULL;
    D_sum = add2(A, BC_product);
    print(D_sum);

    // freeMatrix allocated memory
    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C);
    freeMatrix(B_scaled);
    freeMatrix(C_transposed);
    freeMatrix(BC_product);
    freeMatrix(D_sum);

    return 0;
}