#include <iostream>

#include "test.h"

using std::cout;
using std::endl;

void getCplusplusVerison() {
    std::cout << "[C++ Version] : ";
    if (__cplusplus == 201703L) std::cout << "C++17" << std::endl;
    else if (__cplusplus == 201402L) std::cout << "C++14" << std::endl;
    else if (__cplusplus == 201103L) std::cout << "C++11" << std::endl;
    else if (__cplusplus == 199711L) std::cout << "C++98" << std::endl;
    else std::cout << "pre-standard C++" << std::endl;
}

int main()
{
    getCplusplusVerison();

    testUnionFind();

#if 0 // todo: ... heap sort
	IndexMaxHeap<int> indexHeap = IndexMaxHeap<int>(6);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 6; i++) {
		indexHeap.insert(i, rand() % 10);
		std::cout << indexHeap << std::endl;
	}

	//indexHeap.change(0, 99);

	while (!indexHeap.isEmpty()) {
		cout << "extract : " << indexHeap.extract() << endl;
		cout << indexHeap << endl;
	}
#endif

	
	/*int n = 1000000;
	std::cout << "Test for Random Array, size = " << n << ", random range [0, " << n << "]" << std::endl;
	int* arr1 = TestHelper::generateRandomArray(n, 0, n);
	int* arr2 = TestHelper::copyIntArray(arr1, n);
	int* arr3 = TestHelper::copyIntArray(arr1, n);
	int* arr4 = TestHelper::copyIntArray(arr1, n);
	int* arr5 = TestHelper::copyIntArray(arr1, n);
	int* arr6 = TestHelper::copyIntArray(arr1, n);

	TestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	TestHelper::testSort("Quick Sort", quickSort, arr2, n);
	TestHelper::testSort("Quick Sort 3Ways", quickSort3Ways, arr3, n);
	TestHelper::testSort("Heap Sort", heapSort_1, arr4, n);
	TestHelper::testSort("Heap Sort (heapify)", heapSort_2, arr5, n);
	TestHelper::testSort("Heap Sort (self)", heapSort_3, arr6, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	cout << endl;

	int swapTimes = 100;
	std::cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swapTimes << std::endl;
	arr1 = TestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = TestHelper::copyIntArray(arr1, n);
	arr3 = TestHelper::copyIntArray(arr1, n);
	arr4 = TestHelper::copyIntArray(arr1, n);
	arr5 = TestHelper::copyIntArray(arr1, n);
	arr6 = TestHelper::copyIntArray(arr1, n);

	TestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	TestHelper::testSort("Quick Sort", quickSort, arr2, n);
	TestHelper::testSort("Quick Sort 3Ways", quickSort3Ways, arr3, n);
	TestHelper::testSort("Heap Sort", heapSort_1, arr4, n);
	TestHelper::testSort("Heap Sort (heapify)", heapSort_2, arr5, n);
	TestHelper::testSort("Heap Sort (self)", heapSort_3, arr6, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	cout << endl;

	std::cout << "Test for Random Array, size = " << n << ", random range [0, 10]" << std::endl;
	arr1 = TestHelper::generateRandomArray(n, 0, 10);
	arr2 = TestHelper::copyIntArray(arr1, n);
	arr3 = TestHelper::copyIntArray(arr1, n);
	arr4 = TestHelper::copyIntArray(arr1, n);
	arr5 = TestHelper::copyIntArray(arr1, n);
	arr6 = TestHelper::copyIntArray(arr1, n);

	TestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	TestHelper::testSort("Quick Sort 2Ways", quickSort2Ways, arr2, n);
	TestHelper::testSort("Quick Sort 3Ways", quickSort3Ways, arr3, n);
	TestHelper::testSort("Heap Sort", heapSort_1, arr4, n);
	TestHelper::testSort("Heap Sort (heapify)", heapSort_2, arr5, n);
	TestHelper::testSort("Heap Sort (self)", heapSort_3, arr6, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;*/
	return 0;
}
