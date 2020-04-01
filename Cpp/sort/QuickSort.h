#ifndef _QUICK_SORT_H
#define _QUICK_SORT_H

#include <algorithm>
#include <ctime>
#include "InsertionSort.h"

// arr[l...p-1] < arr[p] < arr[p+1...r]
template <typename T>
int __partition(T arr[], int l, int r) {
    swap( arr[l], arr[rand()%(r-l+1)+l] );

    T v = arr[l];

    // arr[l+1...j] < v; arr[j+1...)i > v
    int j = l;
    for(int i = l + 1; i <= r; i++) {
        if(arr[i] < v) {
            std::swap(arr[i], arr[j+1]);
            j++;
        }
    }

    std::swap(arr[l], arr[j]);
    return j;
}

template <typename T>
void __quickSort(T arr[], int l, int r) {
//    if(l >= r)
//        return;
    if(r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

template <typename T>
void quickSort(T arr[], int n) {
    srand(time(NULL));

    // [0...n-1], size: n
    __quickSort(arr, 0, n - 1);
}

/*
 * Quick Sort 2 Ways
 */
// arr[l...p-1] < arr[p] < arr[p+1...r]
template <typename T>
int __partition2Ways(T arr[], int l, int r) {
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];

    /*
     * arr[l+1...i) <= v
     * arr(j...r]   >= v
     * arr[i...j]   == v
     */
    int i = l+1;
    int j = r;
    while( true ) {
        while(i <= r && arr[i] < v) i++;
        while(j >= l && arr[j] > v) j--;
        if(i > j) break;
        swap(arr[i++], arr[j--]);
    }
    swap(arr[l], arr[j]);
    return j;
}

template <typename T>
void __quickSort2Ways(T arr[], int l, int r) {
    if(r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition2Ways(arr, l, r);
    __quickSort2Ways(arr, l, p - 1);
    __quickSort2Ways(arr, p + 1, r);
}

template <typename T>
void quickSort2Ways(T arr[], int n) {
    srand(time(NULL));

    // [0...n-1], size: n
    __quickSort2Ways(arr, 0, n - 1);
}

/*
 * Quick Sort 3 Ways
 */
template <typename T>
void __quickSort3Ways(T arr[], int l, int r) {
    if(r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    /* Partition */
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];

    int lt = l;     // arr[l+1...lt] < v
    int gt = r + 1; // arr[gt...r] > v
    int i = l + 1;  // arr[lt+1...i) == v

    while( i < gt ) {
        if( arr[i] < v ) {
            std::swap( arr[i], arr[lt+1] );
            lt++;
            i++;
        }
        else if( arr[i] > v ) {
            std::swap( arr[i], arr[gt-1] );
            gt--;
        }
        else { // arr[i] == v
            i++;
        }
    }

    swap( arr[l], arr[lt] );
    __quickSort3Ways(arr, l, lt - 1);
    __quickSort3Ways(arr, gt, r);
}

template <typename T>
void quickSort3Ways(T arr[], int n) {
    srand(time(NULL));
    __quickSort3Ways(arr, 0, n - 1);
}

#endif // _QUICK_SORT_H
