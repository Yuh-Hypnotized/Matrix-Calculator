#include <iostream>
#include <Windows.h>
#include <iomanip>
#include "Matrix.h"
using namespace std;

int main() {    //main function starts here.
	int manipulationJudge = -1;
	bool flag = true;
	cout << "====================\n"
		<< "Read before use:\n"
		<< "This program is only capable for matrix smaller than 20*20.\n"
		<< "Follow the instructions when using the calculator.\n"
		<< "====================\n"
		<< "Understand? (type 'Y' for yes):";
	char uds = cin.get();
	if (uds == 'Y') {
		cout << "\nGet started!\n\n" << endl;
	}
	else {
		flag = false;
		cout << "\n\nProgram exited due to disagreement.\n\n" << endl;
		Sleep(1000);
	}
	while (flag == true) {
		cout << "====================\n" << "1: Transpose(转置)" << "\n2: Addition(加法)" << "\n3: Subtraction(减法)"
			<< "\n4: Multiplication(乘法)" << "\n5: Inverse(求逆矩阵)" << "\n6: Determinant(求行列式)" 
			<< "\n7: Adjugate(求伴随矩阵)" << "\n-1: Exit" << endl;
		cout << "\nPlease select your manipulation: ";
		cin >> manipulationJudge;
		if (manipulationJudge == -1) {
			flag = false;
			cout << "\n\n====================\n" << "Program exiting in 5 seconds...\n"
				<< "If you met any problem or you have some suggestions\n"
				<< "Please contact [QQ:9955161].\n\n" << endl;
			Sleep(5000);
			cout << "Exited successfully." << endl;
			Sleep(500);
			break;
		}
		else if (manipulationJudge == 1) {
			int row, column;
			cout << "How many rows? Enter: "; cin >> row;
			cout << "How many columns? Enter: "; cin >> column;
			cout << "\nEnter your matrix: " << endl;
			Matrix myMatrix(row, column);
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					cin >> myMatrix.matrixA[i][j];
				}
			}
			myMatrix.matrixTranspose();
			cout << "\nThe result is: " << endl;
			myMatrix.printMatrix();
		}
		else if (manipulationJudge == 2) {
			int row, column;
			double matrix1[20][20], matrix2[20][20];
			cout << "How many rows? Enter: "; cin >> row;
			cout << "How many columns? Enter: "; cin >> column;
			Matrix myMatrix(row, column);
			cout << "\nEnter your first matrix: " << endl;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					cin >> matrix1[i][j];
				}
			}
			cout << "Enter your second matrix: \n"
				<< "<ATTENTION>Your second matrix MUST have the same size as the first one." << endl;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					cin >> matrix2[i][j];
				}
			}
			myMatrix.matrixAddition(matrix1, matrix2, row, column);
			cout << "\nThe result is: " << endl;
			myMatrix.printMatrix();
		}
		else if (manipulationJudge == 3) {
			int row, column;
			double matrix1[20][20], matrix2[20][20];
			cout << "How many rows? Enter: "; cin >> row;
			cout << "How many columns? Enter: "; cin >> column;
			Matrix myMatrix(row, column);
			cout << "\nEnter your first matrix: " << endl;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					cin >> matrix1[i][j];
				}
			}
			cout << "Enter your second matrix: \n"
				<< "<ATTENTION>Your second matrix MUST have the same size as the first one." << endl;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					cin >> matrix2[i][j];
				}
			}
			myMatrix.matrixSubtraction(matrix1, matrix2, row, column);
			cout << "\nThe result is: " << endl;
			myMatrix.printMatrix();
		}
		else if (manipulationJudge == 4) {
			int row, column1, column2;
			double matrix1[20][20], matrix2[20][20];
			cout << "How many rows in the first matrix? Enter: "; cin >> row;
			cout << "How many columns in the first matrix? Enter: "; cin >> column1;
			cout << "So there are " << column1 << " rows in the second matrix." << endl;
			cout << "How many columns in the second matrix? Enter: "; cin >> column2;
			Matrix myMatrix(row, column2);
			cout << "\nEnter your first matrix: " << endl;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column1; j++) {
					cin >> matrix1[i][j];
				}
			}
			cout << "Enter your second matrix: \n"
				<< "<ATTENTION>Your second matrix MUST have the same rows as the first one has in columns." << endl;
			for (int i = 0; i < column1; i++) {
				for (int j = 0; j < column2; j++) {
					cin >> matrix2[i][j];
				}
			}
			myMatrix.matrixMultiplication(matrix1, matrix2, row, column1, column2);
			cout << "\nThe result is: " << endl;
			myMatrix.printMatrix();
		}
		else if (manipulationJudge == 5) {
			int row;
			cout << "How many rows? Enter: "; cin >> row;
			Matrix myMatrix(row, row);
			cout << "So there are " << row << " columns in the matrix." << endl;
			cout << "\nEnter your matrix: " << endl;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < row; j++) {
					cin >> myMatrix.matrixA[i][j];
				}
			}
			myMatrix.inverseMatrix();
			cout << "\nThe result is: " << endl;
			myMatrix.printMatrix();
		}
		else if (manipulationJudge == 6) {
			int row;
			cout << "How many rows? Enter: "; cin >> row;
			Matrix myMatrix(row, row);
			cout << "So there are " << row << " columns in the matrix." << endl;
			cout << "\nEnter your matrix: " << endl;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < row; j++) {
					cin >> myMatrix.matrixA[i][j];
				}
			}
			cout << "\nThe result is: " << myMatrix.matrixDeterminant() << endl;
		}
		else if (manipulationJudge == 7) {
			int row;
			cout << "How many rows? Enter: "; cin >> row;
			Matrix myMatrix(row, row);
			cout << "So there are " << row << " columns in the matrix." << endl;
			cout << "\nEnter your matrix: " << endl;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < row; j++) {
					cin >> myMatrix.matrixA[i][j];
				}
			}
			myMatrix.adjugateMatrix();
			cout << "\nThe result is: " << endl;
			myMatrix.printMatrix();
		}
		else {
			cout << "\nInvalid input! Try again.\n" << endl;
		}
		Sleep(1000);
	}
	return 0;
}

/*	The LAGACY of inverse matrix codes in v1.0

		double assistMatrix[20][20], resultMatrix[20][20];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				assistMatrix[i][j] = matrixA[i][j];
			}
		}
		for (int i = 0; i < row; i++) {    //(A+E)model
			for (int j = 0; j < row; j++) {
				if (i == j)
					assistMatrix[i][j + column] = 1;
				else
					assistMatrix[i][j + column] = 0;
			}
		}for (int i = 0; i < row; i++) {    //ri+=k*rj
			if (assistMatrix[i][i] == 0) {   //check for unexpected ?/0 problem
				int pin = i + 1;
				while (assistMatrix[pin][i] == 0 and pin!=i) {
					pin = (pin + 1) % row;
				}
				for (int k = 0; k < column + row; k++) {
					assistMatrix[i][k] += assistMatrix[pin][k];
				}
			}
			for (int j = 1; j < row; j++) {

				double ratio = assistMatrix[(i + j) % row][i] / assistMatrix[i][i];
				for (int k = 0; k < column + row; k++) {
					assistMatrix[(i + j) % row][k] -= assistMatrix[i][k] * ratio;
				}
			}
		}
		for (int i = 0; i < row; i++) {    //k*ri
			double ratio = assistMatrix[i][i];
			for (int k = 0; k < column + row; k++) {
				assistMatrix[i][k] /= ratio;
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				resultMatrix[i][j] = assistMatrix[i][j + row];
			}
		}
		setMatrixValue(resultMatrix, row, column);
*/
