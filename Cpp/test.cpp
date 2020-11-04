#include <iostream>

#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Heap.h"

#include "BinarySearch.h"

#include "test.h"
#include "TestHelper.h"

using std::cout;
using std::endl;

/** testHeapInstance : Heap Object test */
void testHeapInstance(void)
{
	MaxHeap<int> maxHeap = MaxHeap<int>(100);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 50; i++)
		maxHeap.insert(rand() % 100);

	cout << maxHeap << endl;

	cout << "extract : ";
	while (!maxHeap.isEmpty())
		cout << std::setw(4) << maxHeap.extract() << " ";
	cout << endl;
	cout << endl;


	MinHeap<int> minHeap = MinHeap<int>(100);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 50; i++)
		minHeap.insert(rand() % 100);

	cout << minHeap << endl;

	cout << "extract : ";
	while (!minHeap.isEmpty())
		cout << std::setw(4) << minHeap.extract() << " ";
}

/**
 * Item : QuickSort & QuickSort2Ways & QuickSort3Ways
 * Case : Random Array & Nearly Ordered Array
 */
void testQuickSort(void)
{
	int n = 1000000;
	std::cout << "Test for Random Array, size = " << n << ", random range [0, " << n << "]" << std::endl;
	int* arr1 = TestHelper::generateRandomArray(n, 0, n);
	int* arr2 = TestHelper::copyIntArray(arr1, n);
	int* arr3 = TestHelper::copyIntArray(arr1, n);
	int* arr4 = TestHelper::copyIntArray(arr1, n);

	TestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	TestHelper::testSort("Quick Sort", quickSort, arr2, n);
	TestHelper::testSort("Quick Sort 2Ways", quickSort2Ways, arr3, n);
	TestHelper::testSort("Quick Sort 3Ways", quickSort3Ways, arr4, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	int swapTimes = 100;
	std::cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swapTimes << std::endl;
	arr1 = TestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = TestHelper::copyIntArray(arr1, n);
	arr3 = TestHelper::copyIntArray(arr1, n);
	arr4 = TestHelper::copyIntArray(arr1, n);

	TestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	TestHelper::testSort("Quick Sort", quickSort, arr2, n);
	TestHelper::testSort("Quick Sort 2Way", quickSort2Ways, arr3, n);
	TestHelper::testSort("Quick Sort 3Ways", quickSort3Ways, arr4, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	std::cout << "Test for Random Array, size = " << n << ", random range [0, 10]" << std::endl;
	arr1 = TestHelper::generateRandomArray(n, 0, 10);
	arr2 = TestHelper::copyIntArray(arr1, n);
	arr3 = TestHelper::copyIntArray(arr1, n);
	arr4 = TestHelper::copyIntArray(arr1, n);

	TestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	//TestHelper::testSort("Quick Sort", quickSort, arr2, n);
	TestHelper::testSort("Quick Sort 2Way", quickSort2Ways, arr3, n);
	TestHelper::testSort("Quick Sort 3Ways", quickSort3Ways, arr4, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
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

/**
 * Item : Binary Search & Binary Search Recursion
 * Case : Ordered Array
 */
void testBinarySearch(void)
{
    int n = 1000000;
    int* arr = TestHelper::generateOrderedArray(n);

    std::cout << "[Binary Search Test]" << std::endl;
    TestHelper::testSearch("Binary Search", binarySearch, arr, n);
    TestHelper::testSearch("Binary Search (Recursion)", binarySearchR, arr, n);

    delete arr;
}