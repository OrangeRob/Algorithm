#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include "InsertionSort.h"

/*
 * range : arr[l...r]
 * divided arr[l...r] to < v, == v, >v 3 parts
 */
template <typename T>
void __quickSort_3(T* arr, int l, int r) {
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}

	/* partition */
	std::swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	int lt = l;			// arr[l+1...lt] < v
	int gt = r + 1;		// arr[gt...r] > v
	int i = l + 1;		// arr[lt+1...i) == v
	
	while (i < gt) {
		if (arr[i] < v) {
			std::swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}
		else if(arr[i] > v) {
			std::swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else {	
			// arr[i] == v
			i++;
		}
	}

	std::swap(arr[l], arr[lt]);

	__quickSort_3(arr, l, lt - 1);
	__quickSort_3(arr, gt, r);
}

template <typename T>
void quickSort3Ways(T* arr, int n) {
	srand(static_cast<unsigned int>(time(NULL)));
	__quickSort_3(arr, 0, n - 1);
}

/*
 * range : arr[l...r]
 * return : index p
 * condition : arr[l ... p - 1] < arr[p] ; arr[p + 1 ... r] > arr[p]
 */
template <typename T>
int __partition_2(T* arr, int l, int r) {
	std::swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];

	/* arr[l+1...i) <= v ; arr(j...r] >= v */
	int i = l + 1;
	int j = r;
	while (true) {
		while (i <= r && arr[i] < v) i++;
		while (j >= l + 1 && arr[j] > v) j--;
		if (i > j) break;
		std::swap(arr[i++], arr[j--]);
	}

	std::swap(arr[l], arr[j]);
	return j;
}

template <typename T>
void __quickSort_2(T* arr, int l, int r) {
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}

	int p = __partition_2(arr, l, r);
	__quickSort_2(arr, l, p - 1);
	__quickSort_2(arr, p + 1, r);
}

template <typename T>
void quickSort2Ways(T* arr, int n) {
	srand(static_cast<unsigned int>(time(NULL)));
	__quickSort_2(arr, 0, n - 1);
}

/*
 * range : arr[l...r]
 * return : index p
 * condition : arr[l ... p - 1] < arr[p] ; arr[p + 1 ... r] > arr[p]
 */
template <typename T>
int __partition(T* arr, int l, int r) {

	std::swap(arr[l], arr[rand() % (r - l + 1) + l]);

	T v = arr[l];

	/* arr[l+1...j] < v ; arr[j+1...i) > v */
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < v) {
			std::swap(arr[++j], arr[i]);
		}
	}
	std::swap(arr[l], arr[j]);
	return j;
}

template <typename T>
void __quickSort(T* arr, int l, int r) {
	//if (l >= r)
	//	return;
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}

	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

template <typename T>
void quickSort(T* arr, int n) {
	srand(static_cast<unsigned int>(time(NULL)));
	__quickSort(arr, 0, n - 1);
}

#endif //__QUICK_SORT_H__