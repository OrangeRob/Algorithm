#include <iostream>
#include <algorithm>
#include <string>

#include "Student.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "SortTestHelper.h"

using namespace std;
 
int main()
{
    int n = 100000;
    //int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);

    // Test O(n^2) Sort
    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);

    delete[] arr;
    delete[] arr2;

    return 0;
}
