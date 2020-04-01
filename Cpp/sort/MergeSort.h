#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include "sort/InsertionSort.h"

using namespace std;

// merge arr[l...mid] and arr[mid+1...r]
template<typename T>
void __merge(T arr[], int left, int mid, int right) {
    T aux[ right - left + 1 ];
    for(int i = left; i <= right; i++)
        aux[i-left] = arr[i];

    int i = left;
    int j = mid + 1;
    for(int k = left; k <= right; k++) {
        if(i > mid) {
            arr[k] = aux[j-left];
            j++;
        }
        else if(j > right) {
            arr[k] = aux[i-left];
            i++;
        }
        else if(aux[i-left] < aux[j-left]) {
            arr[k] = aux[i-left];
            i++;
        }
        else {
            arr[k] = aux[j-left];
            j++;
        }
    }
}

// sort arr[l  ... r]
template<typename T>
void __mergeSort(T arr[], int l, int r) {
    //if( l >= r )
    //    return;

    if( r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }
        
    int mid = l + (r - l)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);

    if(arr[mid] > arr[mid+1]);
        __merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int length) {
    __mergeSort(arr, 0, length - 1);
}

template<typename T>
void mergeSortBottomUp(T arr[], int length) {
    for( int size = 1;  size <= length; size += size) {
        for(int i = 0; i + size < length; i += size + size ) {
            // merge arr[i..i+size-1] and arr[i+size ... i+2*size-1]
            __merge(arr, i, i + size -1, min(i + size + size -1, length - 1) );
        }
    }
}

#endif // _MERGE_SORT_H_