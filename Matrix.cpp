#include <iostream>
#include <iomanip>
#include <cmath>
#include "Matrix.h"
using namespace std;
Matrix::Matrix(int row_input, int column_input)
	:row(row_input), column(column_input) {}
void Matrix::setMatrixValue(double matrix_input[20][20], int row_input, int column_input) {
	row = row_input;
	column = column_input;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			matrixA[i][j] = matrix_input[i][j];
		}
	}
}
void Matrix::printMatrix() const {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << setw(8) << matrixA[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n\n" << endl;
}
void Matrix::matrixTranspose() {
	double assistMatrix1[20][20];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			assistMatrix1[j][i] = matrixA[i][j];
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			matrixA[i][j] = 0;
		}
	}
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			matrixA[i][j] = assistMatrix1[i][j];
		}
	}
	int a; a = row; row = column; column = a;
}
void Matrix::matrixAddition(double matrix_input1[20][20], double matrix_input2[20][20], int row_input, int column_input) {
	double resultMatrix[20][20];
	for (int i = 0; i < row_input; i++) {
		for (int j = 0; j < column_input; j++) {
			resultMatrix[i][j] = matrix_input1[i][j] + matrix_input2[i][j];
		}
	}
	setMatrixValue(resultMatrix, row_input, column_input);
}
void Matrix::matrixSubtraction(double matrix_input1[20][20], double matrix_input2[20][20], int row_input, int column_input) {
	double resultMatrix[20][20];
	for (int i = 0; i < row_input; i++) {
		for (int j = 0; j < column_input; j++) {
			resultMatrix[i][j] = matrix_input1[i][j] - matrix_input2[i][j];
		}
	}
	setMatrixValue(resultMatrix, row_input, column_input);
}
void Matrix::matrixMultiplication(double matrix_input1[20][20], double matrix_input2[20][20], int row_input1, int column_input1, int column_input2) {
	double resultMatrix[20][20];
	for (int i = 0; i < row_input1; i++) {
		for (int j = 0; j < column_input2; j++) {
			resultMatrix[i][j] = 0;
			for (int k = 0; k < column_input1; k++) {
				resultMatrix[i][j] += matrix_input1[i][k] * matrix_input2[k][j];
			}
		}
	}
	setMatrixValue(resultMatrix, row_input1, column_input2);
}
void Matrix::inverseMatrix() {
	double determinant = matrixDeterminant();
	adjugateMatrix();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			matrixA[i][j] /= determinant;
		}
	}
}
double Matrix::matrixDeterminant() {
	if (row == 2) {
		return matrixA[0][0] * matrixA[1][1] - matrixA[0][1] * matrixA[1][0];
	}
	else if (row > 2) {
		double sum = 0;
		for (int i = 0; i < row; i++) {
			Matrix assistMatrix(row - 1, row - 1);
			for (int j = 1; j < row; j++) {
				int flag = 0;
				for (int k = 0; k < row; k++) {
					if (k == i) {
						k += 1;
						flag = 1;
					}
					assistMatrix.matrixA[j - 1][k - flag] = matrixA[j][k];
				}
			}
			sum += matrixA[0][i] * pow(-1, i) * assistMatrix.matrixDeterminant();
		}
		return sum;
	}
	else return matrixA[0][0];
}
double Matrix::cofactor(int a, int b) {
	Matrix cofactorMatrix(row - 1, column - 1);
	int rowFlag = 0;
	for (int i = 0; i < row; i++) {
		if (i == a - 1) {
			i++;
			rowFlag = 1;
		}
		int columnFlag = 0;
		for (int j = 0; j < row; j++) {
			if (j == b - 1) {
				j++;
				columnFlag = 1;
			}
			cofactorMatrix.matrixA[i - rowFlag][j - columnFlag] = matrixA[i][j];
		}
	}
	return cofactorMatrix.matrixDeterminant() * pow(-1, a + b);
}
void Matrix::adjugateMatrix() {
	double assist[20][20];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			assist[i][j] = cofactor(j + 1, i + 1);
		}
	}
	setMatrixValue(assist, row, row);
}
