#ifndef __SELECTION_SORT_H__
#define __SELECTION_SORT_H__

template <typename T>
void selectionSort(T* arr, int n) 
{
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		std::swap(arr[i], arr[minIndex]);
	}
}

#endif //__SELECTION_SORT_H__