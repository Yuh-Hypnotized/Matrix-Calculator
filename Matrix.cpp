//Matrix class definitions
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include "Matrix.h"
//define values for finding eigenvalue
#define MIN_FIND -20
#define MAX_FIND 20
#define STEP 0.01
#define ERROR 0.00001

using namespace std;
Matrix::Matrix(int row_input, int column_input)   //Class Initializations
	:row(row_input), column(column_input) {}

//Function that can set a 2D-array to matrixA
void Matrix::setMatrixValue(array<array<double, 20>, 20> matrix_input, int row_input, int column_input) {
	row = row_input;
	column = column_input;
	for (int i = 0; i < row; i++) {   //Copy 2D-array
		for (int j = 0; j < column; j++) {
			matrixA[i][j] = matrix_input[i][j];
		}
	}
}

//Function that can print matrixA
void Matrix::printMatrix() const {
	for (int i = 0; i < row; i++) {  //Traverse through matrixA
		for (int j = 0; j < column; j++) {
			cout << setw(8) << matrixA[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n\n" << endl;  //line space
}

//Function that can transpose matrix
void Matrix::matrixTranspose() {
	array<array<double, 20>, 20> assistMatrix1 = {};
	for (int i = 0; i < row; i++) {   //Define assist matrix with swapped row and column indices
		for (int j = 0; j < column; j++) {
			assistMatrix1[j][i] = matrixA[i][j];
		}
	}
	for (int i = 0; i < column; i++) {   //Copy matrix
		for (int j = 0; j < row; j++) {
			matrixA[i][j] = assistMatrix1[i][j];
		}
	}
	int a; a = row; row = column; column = a;  //Swap row and column
}

//Addtion function
void Matrix::matrixAddition(array<array<double, 20>, 20> matrix_input1, array<array<double, 20>, 20> matrix_input2, int row_input, int column_input) {
	array<array<double, 20>, 20> resultMatrix = {};
	for (int i = 0; i < row_input; i++) {  //Add matched element during traversal
		for (int j = 0; j < column_input; j++) {
			resultMatrix[i][j] = matrix_input1[i][j] + matrix_input2[i][j];
		}
	}
	setMatrixValue(resultMatrix, row_input, column_input);
}

//Subtraction function
void Matrix::matrixSubtraction(array<array<double, 20>, 20> matrix_input1, array<array<double, 20>, 20> matrix_input2, int row_input, int column_input) {
	array<array<double, 20>, 20> resultMatrix = {};
	for (int i = 0; i < row_input; i++) {   //Subtract matched element during traversal
		for (int j = 0; j < column_input; j++) {
			resultMatrix[i][j] = matrix_input1[i][j] - matrix_input2[i][j];
		}
	}
	setMatrixValue(resultMatrix, row_input, column_input);
}

//Multiplication function
void Matrix::matrixMultiplication(array<array<double, 20>, 20> matrix_input1, array<array<double, 20>, 20> matrix_input2, int row_input1, int column_input1, int column_input2) {
	array<array<double, 20>, 20> resultMatrix = {};
	for (int i = 0; i < row_input1; i++) {
		for (int j = 0; j < column_input2; j++) {
			resultMatrix[i][j] = 0;
			for (int k = 0; k < column_input1; k++) {
				resultMatrix[i][j] += matrix_input1[i][k] * matrix_input2[k][j];  //summation
			}
		}
	}
	setMatrixValue(resultMatrix, row_input1, column_input2);
}

//Matrix inversion fuction ft.A^-1 = A*/det(A)
void Matrix::inverseMatrix() {
	double determinant = matrixDeterminant();
	adjugateMatrix();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			matrixA[i][j] /= determinant;
		}
	}
}

//Function for determinant calculation
double Matrix::matrixDeterminant() {
	if (row == 2) {   //2 * 2 matrix's determinant
		return matrixA[0][0] * matrixA[1][1] - matrixA[0][1] * matrixA[1][0];
	}
	else if (row > 2) {   //Use recursion to decrese matrix width till 2
		double sum = 0;
		for (int i = 0; i < row; i++) {
			Matrix assistMatrix(row - 1, row - 1);
			for (int j = 1; j < row; j++) {
				int flag = 0;
				for (int k = 0; k < row; k++) {
					if (k == i) {
						k += 1;   //Passes 'i'th column
						flag = 1;  //Flags if the row index hit 'i'
					}
					assistMatrix.matrixA[j - 1][k - flag] = matrixA[j][k];
				}
			}
			//summation
			sum += matrixA[0][i] * pow(-1, i) * assistMatrix.matrixDeterminant();
		}
		return sum;
	}
	else return matrixA[0][0];  //1 * 1 matrix's determinant
}

//cofactor function
double Matrix::cofactor(int a, int b) {
	Matrix cofactorMatrix(row - 1, column - 1);
	int rowFlag = 0;
	for (int i = 0; i < row; i++) {
		if (i == a - 1) {
			i++;    //Passes 'a-1'th column
			rowFlag = 1;  //Flags if the row index hit 'a-1'
		}
		int columnFlag = 0;
		for (int j = 0; j < row; j++) {
			if (j == b - 1) {
				j++;    //Passes 'b-1'th row
				columnFlag = 1;  //Flags if the column index hit 'b-1'
			}
			cofactorMatrix.matrixA[i - rowFlag][j - columnFlag] = matrixA[i][j];
		}
	}
	return cofactorMatrix.matrixDeterminant() * pow(-1, a + b);  //multiply with (-1)^(a+b)
}

//adjugate function
void Matrix::adjugateMatrix() {
	array<array<double, 20>, 20> assist = {};
	for (int i = 0; i < row; i++) {  //basic definition
		for (int j = 0; j < column; j++) {
			assist[i][j] = cofactor(j + 1, i + 1);
		}
	}
	setMatrixValue(assist, row, row);
}

//solve linear equations
//"any" return type because there are various type of needed return type in different situations
any Matrix::linearSolution(vector<double> const_vec, int& solutionType) {
	bool constVectorZeroFlag = true;    //Flags if the const vector is 0
	for (auto item : const_vec)
		if (item != 0) constVectorZeroFlag = false;

	if (matrixDeterminant() != 0) {    //solution type = 1
		//single solution based on Cramer's rule
		vector<double> solution;
		solution.resize(row);
		Matrix assistMatrix(row, row);
		for (int i = 0; i < row; i++) {
			//Re-generate assist matrix
			for (int j = 0; j < row; j++) {      //j travels through row indexs
				for (int k = 0; k < row; k++) {      //k travels through column indexs
					if (k == i) k += 1;     //Skips the i'th column
					assistMatrix.matrixA[j][k] = matrixA[j][k];
				}
			}
			for (int j = 0; j < row; j++)    //fills the i'th column with const vector
				assistMatrix.matrixA[j][i] = const_vec[j];

			solution[i] = assistMatrix.matrixDeterminant() / matrixDeterminant();
		}
		solutionType = 1;
		return solution;
	}
	else if (constVectorZeroFlag) {    //solution type = 2 --- the matrix is singular and its Ax=0
		vector<bool> free = rowMinimalize();    //row-minimalize based on Guass's rule
		int freeCount = 0;
		for (auto item : free)
			if (item == true) freeCount++;    //counts how many free-x's
		vector<vector<double>> solutions;    //create solution vector & initialize
		solutions.resize(freeCount);
		for (int i = 0; i < freeCount;i++) {
			solutions[i].resize(row);
		}
		int index_of_solutions = 0;    //track solution count (index)
		for (int i = 0; i < row; i++) {
			if (free[i] == true) {
				solutions[index_of_solutions][i] = 1;
				int rowCount = 0;
				for (int j = 0; j < i; j++) {
					//if 'j' isn't a free value, calculate it out
					if (free[j] == false) {
						solutions[index_of_solutions][j] = -matrixA[rowCount][i];
						rowCount++;
					}
				}
				index_of_solutions++;
			}
		}
		solutionType = 2;   //define the solution type as 2
		return solutions;
	}
	else {    //solution type = 3 --- singular but Ax=b type
		Matrix augmented(row, column + 1);    //operate Guass's transition as augmented matrix
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < row; j++)
				augmented.matrixA[i][j] = matrixA[i][j];
			augmented.matrixA[i][row] = const_vec[i];
		}    //init over
		vector<bool> free = augmented.rowMinimalize();   //row-minimalize
		//ignore the 'true' value at the const place in free vec
		free[free.size() - 1] = false;
		int freeCount = 0;
		for (auto item : free)
			if (item == true) freeCount++;   //free-x's count
		//measure solvability (check if it's "0 0 0 ... d" type)
		bool flag_for_solvability = true;
		for (int i = row - freeCount; i < row; i++) {
			if (augmented.matrixA[i][row] != 0)
				flag_for_solvability = false;
		}
		if (!flag_for_solvability) {    //unsolvable
			solutionType = 0;
			return 0;
		}
		else {    //solvable
			vector<vector<double>> solutions;
			solutions.resize(freeCount);
			for (int i = 0; i < freeCount; i++) {
				solutions[i].resize(row);
			}
			//basically similar to the previous situation
			int index_of_solutions = 0;
			for (int i = 0; i < row; i++) {
				if (free[i] == true) {
					solutions[index_of_solutions][i] = 1;
					int rowCount = 0;
					for (int j = 0; j < i; j++) {
						if (free[j] == false) {
							//calculate solutions
							solutions[index_of_solutions][j] = -augmented.matrixA[rowCount][i];
							rowCount++;
						}
					}
					index_of_solutions++;
				}
			}
			vector<double> particular;  //calculate particular solution
			particular.resize(row);
			int rowCount = 0;
			for (int i = 0; i < row; i++) {
				if (!free[i]) {
					particular[i] = augmented.matrixA[rowCount][row];
					rowCount++;
				}
			}
			solutions.push_back(particular); //push together for return
			solutionType = 3;
			return solutions;
		}
		
	}

	
}

//row minimalize (mainly for the solution of linear equations)
vector<bool> Matrix::rowMinimalize() {
	int columnIndex = 0;
	int rowIndex = 0;
	vector<bool> free;    //free vector to mark which column should be a free 'x'
	for (int i = 0; i < column; i++)
		free.push_back(false);       //Initialize free vector as all-false

	while (columnIndex < column && rowIndex < row) {    //finish loop when every column is solved OR every row has been traveled
		if (matrixA[rowIndex][columnIndex] == 0) {     //IF the head number is 0
			bool flag = true;
			int k = 0;
			for (int i = rowIndex + 1; i < row; i++) {      //check if the other item at this column are all 0
				if (matrixA[i][columnIndex] != 0) {
					flag = false;
					k = i;
					break;
				}
			}
			if (flag) {      // situation 1: all 0, so set it as a free 'x' and skip to next column
				free[columnIndex] = true;
				columnIndex++;
				continue;
			}
			else {     // situation 2: not all 0, swap the non-0 row to the rowIndex place
				for (int i = 0; i < column; i++) {    //swap 
					int assist = matrixA[rowIndex][i];
					matrixA[rowIndex][i] = matrixA[k][i];
					matrixA[k][i] = assist;
				}
			}
		}
		//mark the orignal number of [rI,cI] for division use
		double origH = matrixA[rowIndex][columnIndex];
		for (int i = columnIndex; i < column; i++)
			matrixA[rowIndex][i] /= origH;     //set [rI,cI] to 1 by k*ri operation
		//clear the rest rows by doing ri+=k*rj operation
		for (int i = 0; i < row; i++) {
			if (i == rowIndex)   //skip the rowIndex'th row
				continue;
			origH = matrixA[i][columnIndex];  //mark
			for (int j = 0; j < column; j++)
				matrixA[i][j] -= matrixA[rowIndex][j] * origH;
		}
		//end this loop and add 1 on columnIndex & rowIndex
		columnIndex++;
		rowIndex++;
	}
	return free;   //return the free-vector for solutions uses
}

//dumb search method to find eigenvalues and eigenvectors
//feature: output in function
void Matrix::eigenvector() {
	vector<double> eigenvalues;
	vector<double> zero_vec;    //claim zero_vec for augment use
	for (int i = 0; i < row; i++)
		zero_vec.push_back(0);
	int count = 1;
	bool foundFlag = false;
	for (double num = MIN_FIND; num <= MAX_FIND; num += STEP) {   //basic serach
		for (double er = -20; er <= 20; er++)     //debug the unexpected float issue
			if (fabs(er - num) < ERROR) num = er;
		//assist matrix = A - lmbdaE
		Matrix assistMatrix(row, column);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (i == j) assistMatrix.matrixA[i][j] = matrixA[i][j] - num;
				else assistMatrix.matrixA[i][j] = matrixA[i][j];
			}
		}
		//error < 0.00001 would be considered correct -> eigenvalue
		if (fabs(assistMatrix.matrixDeterminant()) < ERROR) {
			foundFlag = true;   //flags if any eigenvalue is found
			eigenvalues.push_back(num);
			cout << "Eigenvalue " << count << ": " << num << endl;
			count++;
			int solutionType;
			any solutions = assistMatrix.linearSolution(zero_vec, solutionType);
			if (solutionType == 2) {  //basic solutions found
				vector<vector<double>> solution = any_cast<vector<vector<double>>>(solutions);
				cout << "Matched eigenvectors: " << endl;
				int solCount = 1;
				for (auto item : solution) {   //output basic solutions
					cout << "e" << solCount << " = (";
					for (auto element : item)
						cout << setw(8) << " " << element;
					cout << ");" << endl;
					solCount++;
				}
			}
			else cout << "No matched eigenvector!" << endl;   //only all-0 solution
			cout << endl;
		}
	}
	//no eigenvalue situation
	if (!foundFlag) cout << "\nNo eigenvalue found!" << endl;
	cout << "\n\n";
}
