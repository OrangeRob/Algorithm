#include <iostream>
#include <iomanip>

#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Heap.h"

#include "TestHelper.h"

using std::cout;
using std::endl;

int main()
{	
	MaxHeap<int> maxHeap = MaxHeap<int>(100);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 50; i++)
		maxHeap.insert(rand() % 100);

	cout << maxHeap << endl;

	cout << "extract : ";
	while (!maxHeap.isEmpty())
		cout << std::setw(4) << maxHeap.extractMax() << " ";
	cout << endl;
	cout << endl;


	MinHeap<int> minHeap = MinHeap<int>(100);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 50; i++)
		minHeap.insert(rand() % 100);

	cout << minHeap << endl;

	cout << "extract : ";
	while (!minHeap.isEmpty())
		cout << std::setw(4) << minHeap.extractMin() << " ";

	return 0;
}
