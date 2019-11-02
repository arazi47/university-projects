#pragma once

#include <vector>
#include <iostream>

using namespace std;

class Matrix
{
public:
	Matrix(int rows, int cols);
	~Matrix();

	void print();

// I'm too lazy to declare getters & setters
//private:
	vector<vector<int>> matrix;
	int rows;
	int cols;
};

