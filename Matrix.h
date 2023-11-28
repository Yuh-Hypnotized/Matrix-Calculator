class Matrix {
public:
	int row, column;
	double matrixA[20][20] = {};
	Matrix(int row_imput, int column_input);
	void setMatrixValue(double matrix_input[20][20], int row_input, int column_input);
	void printMatrix() const;
	void matrixTranspose();
	void matrixAddition(double matrix_input1[20][20], double matrix_input2[20][20], int row_input, int column_input);
	void matrixSubtraction(double matrix_input1[20][20], double matrix_input2[20][20], int row_input, int column_input);
	void matrixMultiplication(double matrix_input1[20][20], double matrix_input2[20][20], int row_input1, int column_input1, int column_input2);
	void inverseMatrix();
	double matrixDeterminant();
	double cofactor(int a, int b);
	void adjugateMatrix();
private:
};
