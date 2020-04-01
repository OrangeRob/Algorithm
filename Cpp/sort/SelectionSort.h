#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_

template<typename T>
void selectionSort(T arr[], int length) {
    for(int i = 0; i < length; i++) {
        int minIndex = i;
        for(int j = i + 1; j < length; j++)
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
                
        swap(arr[i], arr[minIndex]);
    }
}

#endif // _SELECTION_SORT_H_