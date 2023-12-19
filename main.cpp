#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include "Matrix.h"  //Include Matrix class definitions
using namespace std;

int main() {    //main function starts here.
	int manipulationJudge = -1;    //Initialize judge variable of manipulation
	bool flag = true;    //Flags user understood or not
	cout << "====================\n"
		<< "Read before use:\n"
		<< "This program is only capable for matrix smaller than 20*20.\n"
		<< "Follow the instructions when using the calculator.\n"
		<< "====================\n"
		<< "Understand? (type 'Y' for yes):";
	char uds = cin.get();   //understand
	if (uds == 'Y') {
		cout << "\nGet started!\n\n" << endl;
	}
	else {    //If not understand, quit the program.
		flag = false;
		cout << "\n\nProgram exited due to disagreement.\n\n" << endl;
		Sleep(1000);
	}
	while (flag == true) {   //Loop until manipulationJudge = -1
		cout << "====================\n" << "1: Transpose(转置)" << "\n2: Row-Minimalization(化为行最简形)" 
			<< "\n3: Addition(加法)" << "\n4: Subtraction(减法)"
			<< "\n5: Multiplication(乘法)" << "\n6: Inversion(求逆矩阵)" << "\n7: Determinant(求行列式)" 
			<< "\n8: Adjugate(求伴随矩阵)" << "\n9: Solve Linear Equations(求解线性方程组)" 
			<< "\n10: Eigenvalues & Eigenvectors(求特征值和特征向量)" << "\n-1: Exit" << endl;
		cout << "\nPlease select your manipulation: ";
		cin >> manipulationJudge;
		if (manipulationJudge == -1) {   //Exit
			flag = false;
			cout << "\n\n====================\n" << "Program exiting in 5 seconds...\n"
				<< "If you met any problem or you have some suggestions\n"
				<< "Please contact [QQ:9955161].\n\n" << endl;
			Sleep(5000);
			cout << "Exited successfully." << endl;
			Sleep(500);
			break;
		}

		else if (manipulationJudge == 1) {   //Transpose
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

		else if (manipulationJudge == 2) {    //row-minimalization
			int row, column;
			cout << "How many rows? Enter: "; cin >> row;
			cout << "How many columns? Enter: "; cin >> column;
			cout << "\nEnter your matrix: " << endl;
			Matrix myMatrix(row, column);
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++)
					cin >> myMatrix.matrixA[i][j];
			}
			myMatrix.rowMinimalize();
			cout << "\nThe result is: " << endl;
			myMatrix.printMatrix();
		}

		else if (manipulationJudge == 3) {   //Addition
			int row, column;
			array<array<double, 20>, 20> matrix1, matrix2;
			cout << "How many rows? Enter: "; cin >> row;
			cout << "How many columns? Enter: "; cin >> column;
			Matrix myMatrix(row, column);
			cout << "\nEnter your first matrix: " << endl;
			for (int i = 0; i < row; i++) {     //Input matrix1
				for (int j = 0; j < column; j++) {
					cin >> matrix1[i][j];
				}
			}
			cout << "Enter your second matrix: \n"
				<< "<ATTENTION>Your second matrix MUST have the same size as the first one." << endl;
			for (int i = 0; i < row; i++) {     //Input matrix2
				for (int j = 0; j < column; j++) {
					cin >> matrix2[i][j];
				}
			}
			myMatrix.matrixAddition(matrix1, matrix2, row, column);
			cout << "\nThe result is: " << endl;
			myMatrix.printMatrix();
		}

		else if (manipulationJudge == 4) {    //Subtraction
			int row, column;
			array<array<double, 20>, 20> matrix1, matrix2;
			cout << "How many rows? Enter: "; cin >> row;
			cout << "How many columns? Enter: "; cin >> column;
			Matrix myMatrix(row, column);
			cout << "\nEnter your first matrix: " << endl;
			for (int i = 0; i < row; i++) {    //Input matrix1
				for (int j = 0; j < column; j++) {
					cin >> matrix1[i][j];
				}
			}
			cout << "Enter your second matrix: \n"
				<< "<ATTENTION>Your second matrix MUST have the same size as the first one." << endl;
			for (int i = 0; i < row; i++) {    //Input matrix2
				for (int j = 0; j < column; j++) {
					cin >> matrix2[i][j];
				}
			}
			myMatrix.matrixSubtraction(matrix1, matrix2, row, column);
			cout << "\nThe result is: " << endl;
			myMatrix.printMatrix();
		}

		else if (manipulationJudge == 5) {    //Multiplication
			int row, column1, column2;
			array<array<double, 20>, 20> matrix1, matrix2;
			cout << "How many rows in the first matrix? Enter: "; cin >> row;
			cout << "How many columns in the first matrix? Enter: "; cin >> column1;
			//The left matrix's column should be equal to the right matrix's row
			cout << "So there are " << column1 << " rows in the second matrix." << endl;
			cout << "How many columns in the second matrix? Enter: "; cin >> column2;
			Matrix myMatrix(row, column2);
			cout << "\nEnter your first matrix: " << endl;
			for (int i = 0; i < row; i++) {    //Input matrix1
				for (int j = 0; j < column1; j++) {
					cin >> matrix1[i][j];
				}
			}
			cout << "Enter your second matrix: \n"
				<< "<ATTENTION>Your second matrix MUST have the same rows as the first one has in columns." << endl;
			for (int i = 0; i < column1; i++) {    //Input matrix2
				for (int j = 0; j < column2; j++) {
					cin >> matrix2[i][j];
				}
			}
			myMatrix.matrixMultiplication(matrix1, matrix2, row, column1, column2);
			cout << "\nThe result is: " << endl;
			myMatrix.printMatrix();
		}

		else if (manipulationJudge == 6) {    //Inversion
			int row;
			cout << "How many rows? Enter: "; cin >> row;
			Matrix myMatrix(row, row);
			//Only n * n matrix can have inverse matrix
			cout << "So there are " << row << " columns in the matrix." << endl;
			cout << "\nEnter your matrix: " << endl;
			for (int i = 0; i < row; i++) {    //Input matrix
				for (int j = 0; j < row; j++) {
					cin >> myMatrix.matrixA[i][j];
				}
			}
			//Double-check matrix determinant to clarify whether it is inversible
			if (myMatrix.matrixDeterminant() == 0)   //Not inversible
				cout << "Matrix not inversible!\n" << endl;
			else {      //Inversible
				myMatrix.inverseMatrix();
				cout << "\nThe result is: " << endl;
				myMatrix.printMatrix();
			}
		}

		else if (manipulationJudge == 7) {   //Determinant
			int row;
			cout << "How many rows? Enter: "; cin >> row;
			Matrix myMatrix(row, row);
			//Only n * n matrix can calculate determinant
			cout << "So there are " << row << " columns in the matrix." << endl;
			cout << "\nEnter your matrix: " << endl;
			for (int i = 0; i < row; i++) {    //Input matrix
				for (int j = 0; j < row; j++) {
					cin >> myMatrix.matrixA[i][j];
				}
			}
			cout << "\nThe result is: " << myMatrix.matrixDeterminant() << endl;
		}

		else if (manipulationJudge == 8) {   //Adjugate
			int row;
			cout << "How many rows? Enter: "; cin >> row;
			Matrix myMatrix(row, row);
			cout << "So there are " << row << " columns in the matrix." << endl;
			cout << "\nEnter your matrix: " << endl;
			for (int i = 0; i < row; i++) {    //Input matrix
				for (int j = 0; j < row; j++) {
					cin >> myMatrix.matrixA[i][j];
				}
			}
			myMatrix.adjugateMatrix();
			cout << "\nThe result is: " << endl;
			myMatrix.printMatrix();
		}

		else if (manipulationJudge == 9) {    //Linear system solutions
			int row;
			cout << "How many x's? Enter: "; cin >> row;
			vector<double> const_vec;
			const_vec.resize(row);
			Matrix myMatrix(row, row);
			cout << "Tips:" << endl;
			cout << "For example, if your equations are like this:" << endl;
			cout << "a11x1 + a12x2 + a13x3 = b1" << endl;
			cout << "a21x1 + a22x2 + a23x3 = b2" << endl;
			cout << "a31x1 + a32x2 + a33x3 = b3\n" << endl;
			cout << "Then you should enter:" << endl;
			cout << "a11 a12 a13 b1" << endl;
			cout << "a21 a22 a23 b2" << endl;
			cout << "a31 a32 a33 b3" << endl;
			cout << "\nEnter your augmented matrix: " << endl;
			for (int i = 0; i < row; i++) {     //Input augmented matrix
				for (int j = 0; j <= row; j++) {
					if (j < row) cin >> myMatrix.matrixA[i][j];
					else cin >> const_vec[i];
				}
			}
			int solutionType;   //0 for unsolvable; 1 for single solution; 2 for Ax=0 type; 3 for Ax=b but r(A)<n type
			any solutions = myMatrix.linearSolution(const_vec, solutionType);
			
			if (solutionType == 0)      //0 (unsolvable)
				cout << "\nThis linear system is unsolvable!\n" << endl;
			else if (solutionType == 1) {      //1 (single solution based on Cramer's rule)
				cout << "\nThe Solution is: " << endl;
				int count = 1;
				vector<double> solution = any_cast<vector<double>>(solutions);
				for (size_t i = 0; i < solution.size(); i++) {
					cout << "x" << count << " = " << solution[i] << endl;
					count++;
				}
				cout << endl;
			}
			else if (solutionType == 2) {    //2 (Ax=0 type) (inf)
				cout << "\nThe Basic Solutions are: " << endl;
				vector<vector<double>> solution = any_cast<vector<vector<double>>>(solutions);
				int count = 1;
				for (auto item : solution) {   //output basic solutions
					cout << "e" << count << " = (";
					for (auto element : item)
						cout << setw(8) << " " << element;
					cout << ");" << endl;
					count++;
				}
				cout << "So the general solution is: " << endl;   //general solution
				for (int i = 1; i < count - 1; i++)
					cout << "k" << i << "*e" << i << " + ";
				cout << "k" << count - 1 << "*e" << count - 1 << endl;
				cout << endl;
			}
			else {    //3 (Ax=b but r(A)<n type) (inf)
				cout << "\nThe Basic Solutions are: " << endl;
				vector<vector<double>> solution = any_cast<vector<vector<double>>>(solutions);
				vector<double> particular = solution[solution.size() - 1];
				solution.pop_back();
				int count = 1;
				for (auto item : solution) {
					cout << "e" << count << " = (";
					for (auto element : item)
						cout << setw(8) << " " << element;
					cout << ");" << endl;
					count++;
				}
				cout << "Particular solution: (";
				for (auto element : particular)
					cout << setw(8) << " " << element;
				cout << ")" << endl;
				cout << "So the general solution is: " << endl;   //general solution
				for (int i = 1; i < count; i++)
					cout << "k" << i << "*e" << i << " + ";
				cout << "Particular solution" << endl;
				cout << endl;
			}
		}

		else if (manipulationJudge == 10) {
			int row;
			cout << "How many rows? Enter: "; cin >> row;
			Matrix myMatrix(row, row);
			cout << "So there are " << row << " columns in the matrix." << endl;
			cout << "\nEnter your matrix: " << endl;
			for (int i = 0; i < row; i++) {    //Input matrix
				for (int j = 0; j < row; j++) {
					cin >> myMatrix.matrixA[i][j];
				}
			}
			myMatrix.eigenvector();   //call eigenvector function
		}
		else {    //Invalid manipulation input
			cout << "\nInvalid input! Try again.\n" << endl;
		}
		Sleep(1000);
	}
	return 0;
}
