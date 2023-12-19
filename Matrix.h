//Matrix class declarations
#include <array>  //array included
#include <vector>  //vector included
#include <any>   //any included
class Matrix {
public:
	int row, column;
	std::array<std::array<double, 20>, 20> matrixA = {};
	Matrix(int row_imput, int column_input);
	void setMatrixValue(std::array<std::array<double, 20>, 20> matrix_input, int row_input, int column_input);
	void printMatrix() const;
	void matrixTranspose();
	void matrixAddition(std::array<std::array<double, 20>, 20> matrix_input1, std::array<std::array<double, 20>, 20> matrix_input2, int row_input, int column_input);
	void matrixSubtraction(std::array<std::array<double, 20>, 20> matrix_input1, std::array<std::array<double, 20>, 20> matrix_input2, int row_input, int column_input);
	void matrixMultiplication(std::array<std::array<double, 20>, 20> matrix_input1, std::array<std::array<double, 20>, 20> matrix_input2, int row_input1, int column_input1, int column_input2);
	void inverseMatrix();
	double matrixDeterminant();
	double cofactor(int a, int b);
	void adjugateMatrix();
	std::any linearSolution(std::vector<double> const_vec, int& solutionType);
	std::vector<bool> rowMinimalize();
	void eigenvector();
private:
};
