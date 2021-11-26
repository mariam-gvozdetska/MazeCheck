#include "UnionFindSearch.h"
#include "Common.h"
#include <exception>

//getting top element of group, according to indexes array basing on assumption that all indexes are correct and contains no cycles
int getTopIndex(int index, int* const topArray) { 
	int result = topArray[index];
	while (result != topArray[result]) result = topArray[result];
	return result;
}

void merge(int index1, int index2, int* topArray, int* depthArray) {
	int top1 = getTopIndex(index1, topArray);
	int top2 = getTopIndex(index2, topArray);
	if (top1 != top2) {
		if ( (nullptr != depthArray) && (depthArray[top1] < depthArray[top2]) ) {
			topArray[top1] = top2;
			depthArray[top2] = max(depthArray[top2], depthArray[top1] + 1);
		}
		else
		{
			topArray[top2] = top1;
			if(nullptr != depthArray)
				depthArray[top1] = max(depthArray[top1], depthArray[top2] + 1);
		}
	}
}

bool UnionFindSearch::checkPath(const int** const matrix, int size1, int size2) {
	//filtering primary wrong cases
	if (!checkArrayConsistence2d(matrix, size1, size2)) return false;
	if (0 != matrix[0][0] || 0 != matrix[size1 - 1][size2 - 1]) return false;

	int size = size1 * size2;
	int* topArray = new(std::nothrow) int[size];
	int* depthArray = new(std::nothrow) int[size];

	if (topArray != nullptr) {
		int index1, index2, pos1, pos2;

		for (index1 = 0; index1 < size1; ++index1) {
			pos1 = pos2 = index1 * size2;
			for (index2 = 0; index2 < size2 && pos1 < size; ++index2) { //pos1 < size added to suppress C6386 warning
				if (0 == matrix[index1][index2]) {
					topArray[pos1] = pos2;
					if (nullptr != depthArray) {
						depthArray[pos1] = 1;
						if(pos2 < pos1)
							depthArray[pos2] = 2;
					}
				}
				else
				{
					topArray[pos1] = -1;
					pos2 = pos1 + 1;
					if (nullptr != depthArray) {
						depthArray[pos1] = 0;
					}
				}
				++pos1;
			}
		}

		for (index1 = 1; index1 < size1; ++index1) {
			pos1 = index1 * size2;
			for (index2 = 0; index2 < size2; ++index2) {
				if (matrix[index1 - 1][index2] == 0 && matrix[index1][index2] == 0) {
					merge(pos1 - size2, pos1, topArray, depthArray);
				}
				++pos1;
			}
		}

		bool result = getTopIndex(0, topArray) == getTopIndex(size - 1, topArray);
		if (nullptr != depthArray) delete[] depthArray;
		delete[] topArray;
		return result;
	}
	else {
		// need to handle no enough memory / error in allocate
		if (nullptr != depthArray) delete[] depthArray;
		return false;
	}
}