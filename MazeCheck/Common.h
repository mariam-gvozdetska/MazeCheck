#pragma once
inline const int max(int const a, int const b) {
	return a > b ? a : b;
}

//short check 2d array for consistence
bool checkArrayConsistence2d(const int** const array, int size1, int size2);