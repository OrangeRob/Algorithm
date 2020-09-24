package algorithm;

public class SelectionSort {
    /** Suppresses default constructor, ensuring non-instantiable. */
    private SelectionSort() {}

    public static void sort(Comparable[] arr) {
        for(int i = 0; i < arr.length - 1; i++) {
            int minIndex = i;
            for(int j = i + 1; j < arr.length; j++) {
                if(arr[j].compareTo(arr[minIndex]) < 0) {
                    minIndex = j;
                }
            }
            SortUtils.swap(arr, i, minIndex);
        }
    }

    public static void main(String[] args) {
        int n = 10000;
        Integer[] arr = SortUtils.generateRandomArray(n, 0, n);
        SortUtils.testSort("algorithm.SelectionSort", arr);
        SortUtils.printArray(arr);
    }
}
