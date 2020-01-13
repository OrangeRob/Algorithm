#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_

template<typename T>
void insertionSort(T arr[], int length) {
    
    for(int i = 1; i < length; i++) {
        T e = arr[i];
        int j;
        for(j = i; j > 0 && arr[j-1] > e; j--) 
            arr[j] = arr[j-1];
        arr[j] = e;
    }
}

template<typename T>
void insertionSort(T arr[], int left, int right) {
    
    for(int i = left + 1; i <= right; i++) {
        T e = arr[i];
        int j;
        for(j = i; j > left && arr[j-1] > e; j--) 
            arr[j] = arr[j-1];
        arr[j] = e;
    }
}


#endif // _INSERTION_SORT_H_