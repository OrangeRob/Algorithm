#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

#include "InsertionSort.h"

/* merge arr[l...mid] and arr[mid+1 ... r] into one */
template <typename T>
void __merge(T* arr, T* tmp, int l, int mid, int r) {
	
	for (int i = l; i <= r; i++)
		tmp[i] = arr[i];

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {
			arr[k] = tmp[j++];
		} else if (j > r) {
			arr[k] = tmp[i++];
		} else if (tmp[i] < tmp[j]) {
			arr[k] = tmp[i++];
		} else {
			arr[k] = tmp[j++];
		}
	}
}

/* range : arr[l ... r] */
template <typename T>
void __mergeSort(T* arr, T* tmp, int l, int r) {
	//if (l >= r)
	//	return;

	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}

	int mid = (r - l) / 2 + l;
	__mergeSort(arr, tmp, l, mid);
	__mergeSort(arr, tmp, mid + 1, r);
	if(arr[mid] > arr[mid + 1])
		__merge(arr, tmp, l, mid, r);
}

template <typename T>
void mergeSort(T* arr, int n) {
	/* range [0 ... n - 1] */
	T* tmp = new T[n];
	__mergeSort(arr, tmp, 0, n - 1);
	delete[] tmp;
}

template <typename T>
void mergeSortBottomUp(T* arr, int n) {
	T* tmp = new T[n];
	for (int sz = 1; sz <= n; sz += sz) {
		for (int i = 0; i < n; i += sz + sz)
			__merge(arr, tmp, i, i + sz - 1, std::min(i + sz + sz - 1, n - 1));
	}
	delete[] tmp;
}

/* Optimization */
template <typename T>
void mergeSortBottomUp_2(T* arr, int n) {
	T* tmp = new T[n];
	for (int i = 0; i < n; i += 16)
		insertionSort(arr, i, std::min(i + 15, n - 1));

	for (int sz = 16; sz <= n; sz += sz) {
		for (int i = 0; i < n; i += sz + sz) {
			if(arr[i + sz - 1] > arr[i + sz])
				__merge(arr, tmp, i, i + sz - 1, std::min(i + sz + sz - 1, n - 1));
		}
	}
	delete[] tmp;
}

#endif // __MERGE_SORT_H__