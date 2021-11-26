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
	const int* testArr[] = {a1,a2,a3,a4,a5,b6,b7,b8,b9,b10};
	std::cout << UnionFindSearch::checkPath(testArr, 10, 15);

	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}