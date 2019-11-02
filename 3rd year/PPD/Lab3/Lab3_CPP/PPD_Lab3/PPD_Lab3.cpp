
#include <iostream>
#include <chrono>
#include <algorithm>
#include <future>
#include "Matrix.h"
#include "ThreadPool.h"

using namespace std;

void multiplicationFuture(Matrix a, Matrix b, Matrix* res)
{
	vector<future<int>> tasks;

	for (int i = 0; i < a.rows; ++i)
	{
		for (int j = 0; j < a.cols; ++j)
		{
			tasks.push_back(async([](int line, int column, Matrix a, Matrix b, Matrix* res) {
				int result = 0;
				for (int k = 0; k < a.rows; ++k)
					result += a.matrix[line][k] * b.matrix[k][column];
				res->matrix[line][column] = result;
				return line;
			}, i, j, a, b, res));
		}
	}
}

void additionFuture(Matrix a, Matrix b, Matrix* res)
{
	vector<future<int>> tasks;

	for (int i = 0; i < a.rows; ++i)
		tasks.push_back(async([](int line, Matrix a, Matrix b, Matrix* res) {
		for (int j = 0; j < a.cols; ++j)
			res->matrix[line][j] = a.matrix[line][j] + b.matrix[line][j];
		return line;
	}, i, a, b, res));
}

void multiplicationThreadPool(Matrix a, Matrix b, Matrix* res, int noThreads)
{
	ThreadPool tp(noThreads);
	vector<future<int>> tasks;

	for (int i = 0; i < a.rows; ++i)
	{
		for (int j = 0; j < a.cols; ++j)
		{
			tasks.push_back(tp.enqueue([](int line, int column, Matrix a, Matrix b, Matrix* res) {
				int mul = 0;
				for (int k = 0; k < a.rows; ++k)
					mul += a.matrix[line][k] * b.matrix[k][column];
				res->matrix[line][column] = mul;
				return line;
			}, i, j, a, b, res));
		}
	}
}

void additionThreadPool(Matrix a, Matrix b, Matrix* res, int noThreads)
{
	ThreadPool tp(noThreads);
	vector<future<int>> tasks;

	for (int i = 0; i < a.rows; ++i)
		tasks.push_back(tp.enqueue([](int line, Matrix a, Matrix b, Matrix* res) {
		for (int j = 0; j < a.cols; ++j)
			res->matrix[line][j] = a.matrix[line][j] + b.matrix[line][j];
		return line;
	}, i, a, b, res));
}

/* Utility functions */

chrono::steady_clock::time_point now()
{
	return chrono::high_resolution_clock::now();
}

long long getDiffInMs(chrono::steady_clock::time_point start, chrono::steady_clock::time_point end)
{
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count() % 1000;
}

int main()
{
	Matrix a = Matrix(20, 20);
	Matrix b = Matrix(20, 20);
	Matrix c = Matrix(20, 20); // Result matrix
	chrono::steady_clock::time_point start, end; // Time start/end
	
	start = now();
	additionFuture(a, b, &c);
	end = now();
	cout << "Add future took: " << getDiffInMs(start, end) << " ms." << endl;
	
	start = now();
	additionThreadPool(a, b, &c, 8);
	end = now();
	cout << "Add threadpool (with 8 threads) took: " << getDiffInMs(start, end) << " ms." << endl;

	start = now();
	multiplicationFuture(a, b, &c);
	end = now();
	cout << "Multiplication future took: " << getDiffInMs(start, end) << " ms." << endl;

	start = now();
	multiplicationFuture(a, b, &c);
	end = now();
	cout << "Multiplication threadpool (with 8 threads) took: " << getDiffInMs(start, end) << " ms." << endl;

	return 0;
}
