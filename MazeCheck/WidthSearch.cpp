#include "WidthSearch.h"
#include <queue>
#include "Common.h"

int WidthSearch::findPath(const int** const matrix, int size1, int size2, int*& path, int start1, int start2, int end1, int end2)
{
	if (!checkArrayConsistence2d(matrix, size1, size2)) return 0;
	if (0 > start1 || 0 > start2 || 0 > end1 || 0 > end2 || size1 <= start1 || size2 <= start2 || size1 <= end1 || size2 <= end2) return 0;
	if (0 != matrix[start1][start2] || 0 != matrix[end1][end2]) return 0;

	int size = size1 * size2;
	int result = 0;
	std::queue<int> items;
	int* way = new(std::nothrow) int[size];
	if (way != nullptr) {
		int index, next, pos1, pos2, start = start1 * size2 + start2, end = end1 * size2 + end2;
		index = 0;
		for (pos1 = 0; pos1 < size1; ++pos1) {
			for (pos2 = 0; pos2 < size2; ++pos2) {
				way[index] = matrix[pos1][pos2] == 0 ? -1 : size;
				++index;
			}
		}
		way[start] = start;

		items.push(start);
		while (!items.empty() && end != (index = items.front()))
		{
			items.pop();
			// check right
			next = index + 1;
			if (next % size2 && way[next] < 0) {
				way[next] = index;
				items.push(next);
			}
			// check bottom
			next = index + size2;
			if (next < size && way[next] < 0) {
				way[next] = index;
				items.push(next);
			}
			// check left
			next = index - 1;
			if (index % size2 && way[next] < 0) {
				way[next] = index;
				items.push(next);
			}
			// check top
			next = index - size2;
			if (next >= 0 && way[next] < 0) {
				way[next] = index;
				items.push(next);
			}
		}
		if (end == index) {
			next = 1;
			while (index != start)
			{
				index = way[index];
				++next;
			}
			if (nullptr != path) delete[] path;
			path = new(std::nothrow) int[next];
			result = next;
			if (nullptr != path) {
				index = end;
				while (index != start) {
					path[--next] = index;
					index = way[index];
				}
				path[0] = start;
			}
		}
		delete[] way;
	}
	return result;
}