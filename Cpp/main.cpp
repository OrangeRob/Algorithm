// main.cpp : Defines the entry point for the application.
//

#include <iostream>

#include "test.h"

#include "TestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"

#define ARRAY_SIZE(x) ( sizeof(x)/sizeof(x[0]) )

int main()
{
	
	return 0;
}

/**
 * Item : Merge & MergeBottomUp Sort
 * Case : Random Array & Nearly Ordered Array
 */
void testMergeSort(void)
{
	int n = 100000;
	std::cout << "Test for Random Array, size = " << n << ", random range [0, " << n << "]" << std::endl;
	int* arr1 = TestHelper::generateRandomArray(n, 0, n);
	int* arr2 = TestHelper::copyIntArray(arr1, n);
	int* arr3 = TestHelper::copyIntArray(arr1, n);
	int* arr4 = TestHelper::copyIntArray(arr1, n);

	TestHelper::testSort("Insertion Optimization", insertionSort_2, arr1, n);
	TestHelper::testSort("Merge", mergeSort, arr2, n);
	TestHelper::testSort("MergeBottomUP", mergeSortBottomUp, arr3, n);
	TestHelper::testSort("MergeBottomUP Optimization", mergeSortBottomUp_2, arr4, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	int swapTimes = 10;
	std::cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swapTimes << std::endl;
	arr1 = TestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = TestHelper::copyIntArray(arr1, n);
	arr3 = TestHelper::copyIntArray(arr1, n);
	arr4 = TestHelper::copyIntArray(arr1, n);

	TestHelper::testSort("Insertion Optimization", insertionSort_2, arr1, n);
	TestHelper::testSort("Merge", mergeSort, arr2, n);
	TestHelper::testSort("MergeBottomUP", mergeSortBottomUp, arr3, n);
	TestHelper::testSort("MergeBottomUP Optimization", mergeSortBottomUp_2, arr4, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
}

/**
 * Item : Selection & Insertion Sort
 * Case : Random Array & Nearly Ordered Array
 */
void testBasicSort(void)
{
	int n = 100000;

	std::cout << "[Random Array Test]" << std::endl;
	int* arr = TestHelper::generateRandomArray(n, 0, n);
	int* arr2 = TestHelper::copyIntArray(arr, n);
	int* arr3 = TestHelper::copyIntArray(arr, n);

	TestHelper::testSort("Selection", selectionSort, arr, n);
	TestHelper::testSort("Insertion", insertionSort, arr2, n);
	TestHelper::testSort("Insertion Optimization", insertionSort_2, arr3, n);

	delete[] arr;
	delete[] arr2;
	delete[] arr3;

	std::cout << "[Nearly Ordered Array Test]" << std::endl;
	arr = TestHelper::generateNearlyOrderedArray(n, 100);
	arr2 = TestHelper::copyIntArray(arr, n);
	arr3 = TestHelper::copyIntArray(arr, n);

	TestHelper::testSort("Selection", selectionSort, arr, n);
	TestHelper::testSort("Insertion", insertionSort, arr2, n);
	TestHelper::testSort("Insertion Optimization", insertionSort_2, arr3, n);

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
}
