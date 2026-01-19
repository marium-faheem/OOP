#include"Matrix.h"
int main() {
    int A[3][3], B[3][3];
    int sum[3][3], product[3][3];

    cout << "Enter elements of first 3x3 matrix:\n";
    inputMatrix(A);

    cout << "Enter elements of second 3x3 matrix:\n";
    inputMatrix(B);

    addMatrix(A, B, sum);
    multiplyMatrix(A, B, product);

    cout << "\nAddition of matrices:\n";
    printMatrix(sum);

    cout << "\nMultiplication of matrices:\n";
    printMatrix(product);

    return 0;
}