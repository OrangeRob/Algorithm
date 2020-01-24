#include <iostream>
#include <algorithm>
#include <string>

#include "Student.h"

// O(N^2)
#include "sort/SelectionSort.h"
#include "sort/InsertionSort.h"

// O(NlogN)
#include "sort/MergeSort.h"
#include "sort/QuickSort.h"

// Utils
#include "sort/SortTestHelper.h"

using namespace std;

void testRandomArraySort(int n) {
    /* [rangeL, rangeR] */
    int rangeL = 0;
    int rangeR = n;

    cout << "Test for random array, size = " << n << ", random range [" << rangeL << ", " << rangeR << "]" << endl;
    int *arr = SortTestHelper::generateRandomArray(n, rangeL, rangeR);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    int *arr3 = SortTestHelper::copyIntArray(arr, n);
    int *arr4 = SortTestHelper::copyIntArray(arr, n);
    int *arr5 = SortTestHelper::copyIntArray(arr, n);
    int *arr6 = SortTestHelper::copyIntArray(arr, n);
    int *arr7 = SortTestHelper::copyIntArray(arr, n);

    //SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    //SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr3, n);
    SortTestHelper::testSort("Merge Sort Bottom UP", mergeSortBottomUp, arr4, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr5, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2Ways, arr6, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr7, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
}

void testNearlyOrderedArraySort(int n) {
    int swapTimes = 100;
    assert( swapTimes >= 0 );

    cout << "Test for nearly ordered array, size = " << n <<", swap time = "<< swapTimes << endl;
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    int *arr3 = SortTestHelper::copyIntArray(arr, n);
    int *arr4 = SortTestHelper::copyIntArray(arr, n);
    int *arr5 = SortTestHelper::copyIntArray(arr, n);
    int *arr6 = SortTestHelper::copyIntArray(arr, n);
    int *arr7 = SortTestHelper::copyIntArray(arr, n);

    //SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr3, n);
    SortTestHelper::testSort("Merge Sort Bottom UP", mergeSortBottomUp, arr4, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr5, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2Ways, arr6, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr7, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
}

void testLimitedRangeArraySort(int n) {
    /* [rangeL, rangeR] */
    int rangeL = 0;
    int rangeR = 10;

    cout << "Test for random array, size = " << n << ", random range [" << rangeL << ", " << rangeR << "]" << endl;
    int *arr = SortTestHelper::generateRandomArray(n, rangeL, rangeR);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    int *arr3 = SortTestHelper::copyIntArray(arr, n);
    int *arr4 = SortTestHelper::copyIntArray(arr, n);
    int *arr5 = SortTestHelper::copyIntArray(arr, n);
    int *arr6 = SortTestHelper::copyIntArray(arr, n);
    int *arr7 = SortTestHelper::copyIntArray(arr, n);

    //SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr3, n);
    SortTestHelper::testSort("Merge Sort Bottom UP", mergeSortBottomUp, arr4, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr5, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2Ways, arr6, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr7, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
}
 
int main()
{
    int n = 1000000;

    cout << "\n--------------------\n" << endl;
    testRandomArraySort(n);
    cout << "\n--------------------\n" << endl;
    testNearlyOrderedArraySort(n);
    cout << "\n--------------------\n" << endl;
    testLimitedRangeArraySort(n);


    return 0;
}
