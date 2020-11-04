#ifndef __BINARYSEARCH_H__
#define __BINARYSEARCH_H__

/**
 * @return: index of the search target, if it's contained in the array;
 *          otherwise, return -1
 */
template<typename T>
int binarySearch(T arr[], int n, T target) {
   /* find target in the range of arr[l...r] */
   int l = 0;
   int r = n - 1;
   while( l <= r ) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == target)
            return mid;

        if(arr[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
   }

   return -1;
}


template<typename T>
int __binarySearchR(T arr[], int l, int r, int target) {
    if(l > r)
        return -1;

    int mid = l + (r - l) / 2;
    if(arr[mid] == target)
        return mid;
    else if(arr[mid] > target)
        return __binarySearchR(arr, l, mid - 1, target);
    else
        return __binarySearchR(arr, mid + 1, r, target);
}

/**
 * Recursion Version
 * @return: index of the search target, if it's contained in the array;
 *          otherwise, return -1
 */
template<typename T>
int binarySearchR(T arr[], int n, T target) {
    return __binarySearchR(arr, 0, n - 1, target);
}

#endif //__BINARYSEARCH_H__
