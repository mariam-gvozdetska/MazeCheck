/*
Task
Implement a function that takes as an input a two-dimensional square matrix consisting of 0 and 1 and outputs a boolean.
The input matrix is in fact a maze where 1 means that the route is available while 0 means that it is not.
Diagonal route paths are not allowed, only horizontal and vertical.
The function output is True or False depending on the fact if there is a way from the top left corner of the matrix to the lowest right one.
The maximum matrix dimension is 50x50 while the minimum one is 2x2. There is no need to output the route(s) itself,
just the boolean corresponding to its existence.
1. Implement the function itself (e.g., applying Union-Find algorithm to maze-solving task), including error handling of the incorrect input format.
2. Cover the implementation with an extensive set of unit tests providing the example mazes
as inputs and the corresponding outputs to make sure that the implementation has no pitfalls.
*/

#include <iostream>
#include "UnionFindSearch.h"
#include "gtest/gtest.h"

int main()
{
	int a1[] = { 0,1,0,0,1,0,0,1,0,0,1,0,0,1,0 };
	int a2[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int a3[] = { 1,0,1,1,1,1,0,1,1,1,1,1,1,0,1 };
	int a4[] = { 1,0,0,0,1,0,0,1,0,0,0,0,0,0,1 };
	int a5[] = { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
	int b6[] = { 0,1,1,1,1,1,1,0,1,1,1,1,1,0,0 };
	int b7[] = { 0,0,0,0,0,0,0,1,1,1,1,1,0,0,0 };
	int b8[] = { 0,0,0,1,1,1,1,0,0,0,1,1,1,1,0 };
	int b9[] = { 1,1,0,0,0,1,1,0,0,0,1,1,0,0,0 };
	int b10[] = { 1,1,0,0,0,1,1,0,0,0,1,1,0,0,0 };
	int* testArr[] = {a1,a2,a3,a4,a5,b6,b7,b8,b9,b10};
	std::cout << UnionFindSearch::checkPath(testArr, 10, 15);

	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}