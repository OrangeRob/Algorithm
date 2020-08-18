#ifndef __INSERTION_SORT_H__
#define __INSERTION_SORT_H__

template <typename T>
void insertionSort(T* arr, int n) {
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0 && arr[j -1] > arr[j]; j--)
			std::swap(arr[j - 1], arr[j]);
}

/* Optimization */
template <typename T>
void insertionSort_2(T* arr, int n) {
	for (int i = 1; i < n; i++) {
		int j;
		T e = arr[i];
		for (j = i; j > 0 && arr[j - 1] > e; j--)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
}

/* range in arr[l ... r] */
template <typename T>
void insertionSort(T* arr, int l, int r) {
	if (l >= r)
		return;

	for (int i = l + 1; i <= r; i++) {
		int j;
		T e = arr[i];
		for (j = i; j > l && arr[j - 1] > e; j--)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
}

#endif //__INSERTION_SORT_H__