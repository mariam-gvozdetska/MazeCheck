#include "Common.h"

bool checkArrayConsistence2d(const int** const array, int size1, int size2) {
	if (nullptr == array) return false;
	if (size1 <= 0 || size2 <= 0) return false;
	int index1, index2;
	try {
		for (index1 = 0; index1 < size1; ++index1) {
			if (array[index1] == nullptr) return false;
			for (index2 = 0; index2 < size2; ++index2) {
				if (array[index1][index2] < 0 || array[index1][index2] > 1) return false;
			}
		}
	}
	catch (...) { //get acces error, like out of bounds exception
		return false;
	}
	return true;
}