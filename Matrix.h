#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Matrix { //동적 할당을 이용한 행렬 클래스
	int rows, cols;
	int** mat;
public:
	Matrix(int r = 0, int c = 0) : rows(r), cols(c), mat(NULL) {
		mat = new int* [rows]; //동적 메모리 할당
		for (int i = 0; i < rows; i++)
			mat[i] = new int[cols]; //동적 메모리 할당
	}
	~Matrix() {
		if (mat != NULL) {
			for (int i = 0; i < rows; i++)
				delete[] mat[i]; //동적 메모리 해제
			delete[] mat; //동적 메모리 해제
		}
	}
	int& elem(int x, int y) { return mat[y][x]; }
	int Rows() { return rows; }
	int Cols() { return cols; }
	int** Data() { return mat; }
	void print(const char* str = "Mat") {
		cout << str << " " << rows << "x" << cols << endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				cout << setw(4) << mat[i][j];
			cout << "\n";
		}
	}
	void setRand(int val = 100) {
		if (mat != NULL) {
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					mat[i][j] = (rand() % val);
		}
	}
};