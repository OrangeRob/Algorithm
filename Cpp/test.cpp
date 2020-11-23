#include <iostream>
#include <vector>
#include <algorithm>

#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Heap.h"

#include "BinarySearch.h"
#include "BinarySearchTree.h"
#include "SequenceSearchTree.h"

#include "test.h"
#include "TestHelper.h"
#include "FileUtils.h"
#include "UnionFindTestHelper.h"

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

/**
 * Item : Binary Search Tree & Sequence Search Tree
 * Case : bible.txt
 */
void testBST(void)
{
    std::string filePath = "../asset/bible.txt";
    std::vector<std::string> words;
    if( FileUtils::readFile(filePath, words) ) {

        cout << "There are totally " << words.size() << " words in " << filePath << endl;
        cout << endl;

        time_t startTime = clock();

        /** Binary Search Tree */
        BinarySearchTree<std::string, int> bst = BinarySearchTree<std::string, int>();
        for (std::vector<std::string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }


        if(bst.contain("god"))
            cout << "'god' : " << *bst.search("god") << endl;
        else
            cout << "No word 'god' in " << filePath << endl;

        time_t endTime = clock();

        cout << "[BinarySearchTree] time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;


        /** Sequence Search Tree */
        startTime = clock();
        SequenceSearchTree<std::string, int> sst = SequenceSearchTree<std::string, int>();
        for (std::vector<std::string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }

        if(sst.contain("god"))
            cout << "'god' : " << *sst.search("god") << endl;
        else
            cout << "No word 'god' in " << filePath << endl;

        endTime = clock();

        cout << "[SequenceSearchTree] time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
    }
}

/**
 * Item : Binary Search Tree & Sequence Search Tree
 * Case : communist.txt
 */
void testBST2(void)
{
    std::string filePath = "../asset/communist.txt";
    std::vector<std::string> words;
    if( FileUtils::readFile(filePath, words) ) {

        cout << "There are totally " << words.size() << " words in " << filePath << endl;
        cout << endl;

        /** Binary Search Tree */
        time_t startTime = clock();
        BinarySearchTree<std::string, int> bst = BinarySearchTree<std::string, int>();
        for (std::vector<std::string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }

        if(bst.contain("unite"))
            cout << "'unite' : " << *bst.search("unite") << endl;
        else
            cout << "No word 'unite' in " << filePath << endl;
        time_t endTime = clock();
        cout << "[BinarySearchTree] time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

        /** Sequence Search Tree */
        startTime = clock();
        SequenceSearchTree<std::string, int> sst = SequenceSearchTree<std::string, int>();
        for (std::vector<std::string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }

        if(sst.contain("unite"))
            cout << "'unite' : " << *sst.search("unite") << endl;
        else
            cout << "No word 'unite' in " << filePath << endl;
        endTime = clock();
        cout << "[SequenceSearchTree] time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;


        /** Binary Search Tree (insert Ordered) */
        std::sort(words.begin(), words.end());

        startTime = clock();
        BinarySearchTree<std::string, int> bst2 = BinarySearchTree<std::string, int>();
        for (std::vector<std::string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst2.search(*iter);
            if (res == NULL)
                bst2.insert(*iter, 1);
            else
                (*res)++;
        }

        if(bst.contain("unite"))
            cout << "'unite' : " << *bst2.search("unite") << endl;
        else
            cout << "No word 'unite' in " << filePath << endl;
        endTime = clock();
        cout << "[BinarySearchTree (Ordered)] time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;
    }
}

/**
 * Item : UnionFind 1, UnionFind 2, UnionFind3, UnionFind4
 * Case :
 */
void testUnionFind(void)
{
    int n = 10000;
    UnionFindTestHelper::testUF1(n);
    UnionFindTestHelper::testUF2(n);
    UnionFindTestHelper::testUF3(n);
    UnionFindTestHelper::testUF4(n);

    cout << endl;

    n = 1000000;
    UnionFindTestHelper::testUF3(n);
    UnionFindTestHelper::testUF4(n);
}