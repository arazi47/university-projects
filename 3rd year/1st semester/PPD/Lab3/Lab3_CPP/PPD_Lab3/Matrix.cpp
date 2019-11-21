#include "Matrix.h"

Matrix::Matrix(int rows, int cols) : matrix(rows, vector<int>(cols)), rows{ rows }, cols{ cols }
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			this->matrix[i][j] = 1;
		}
	}
}

Matrix::~Matrix()
{
}

void Matrix::print()
{
	for (int i = 0; i < this->rows; ++i)
	{
		for (int j = 0; j < this->cols; ++j)
		{
			cout << this->matrix[i][j] << ' ';
		}

		cout << endl;
	}
}