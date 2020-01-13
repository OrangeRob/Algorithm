#include <iostream>
#include <algorithm>
#include <string>

#include "Student.h"

// O(N^2)
#include "SelectionSort.h"
#include "InsertionSort.h"

// O(NlogN)
#include "MergeSort.h"

#include "SortTestHelper.h"

using namespace std;
 
int main()
{
    int n = 100000;
    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    int *arr3 = SortTestHelper::copyIntArray(arr, n);
    int *arr4 = SortTestHelper::copyIntArray(arr, n);

    //SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    //SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr3, n);
    SortTestHelper::testSort("Merge Sort Bottom UP", mergeSortBottomUp, arr4, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    cout << "--------------------" << endl;

    int swapTimes = 100;
    assert( swapTimes >= 0 );

    cout << "Test for nearly ordered array, size = " << n <<", swap time = "<< swapTimes << endl;
    arr = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr, n);
    arr3 = SortTestHelper::copyIntArray(arr, n);
    arr4 = SortTestHelper::copyIntArray(arr, n);

    //SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    //SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr3, n);
    SortTestHelper::testSort("Merge Sort Bottom UP", mergeSortBottomUp, arr4, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    return 0;
}
