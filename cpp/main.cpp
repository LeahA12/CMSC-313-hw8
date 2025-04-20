#include "matrix.h"

int main(){
    Matrix A(2, 2);
    A.fill(0, 0, 6);
    A.fill(0, 1, 4);
    A.fill(1, 0, 8);
    A.fill(1, 1, 3);
    cout << "Matrix A:" << endl;
    A.print();

    Matrix B(2, 3);
    B.fill(0, 0, 1);
    B.fill(0, 1, 2);
    B.fill(0, 2, 3);
    B.fill(1, 0, 4);
    B.fill(1, 1, 5);
    B.fill(1, 2, 6);
    cout << "Matrix B:" << endl;
    B.print();

    Matrix C(2, 3);
    C.fill(0, 0, 2);
    C.fill(0, 1, 4);
    C.fill(0, 2, 6);
    C.fill(1, 0, 1);
    C.fill(1, 1, 3);
    C.fill(1, 2, 5);
    cout << "Matrix C:" << endl;
    C.print();

    cout << "(3 * B) = " << endl;
    Matrix B_scaled = B.scalarMultiply(3, B);
    B_scaled.print();

    cout << "C^T = " << endl;
    Matrix C_transposed = C.transpose(C);
    C_transposed.print();

    cout << "(3 * B) * C^T = " << endl;
    Matrix BC_product = B_scaled.multiply2(B_scaled, C_transposed);
    BC_product.print();

    cout << "D = A + (3 * B) * C^T = " << endl;
    Matrix D_sum = A.add2(A, BC_product);    
    D_sum.print();

    return 0;
}
