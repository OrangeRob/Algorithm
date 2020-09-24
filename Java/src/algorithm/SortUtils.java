package algorithm;

import java.lang.reflect.Method;

public class SortUtils {
    /** Suppresses default constructor, ensuring non-instantiable. */
    private SortUtils() {}

    /**
     * Swaps x[a] with x[b].
     */
    public static void swap(Object[] x, int a, int b) {
        Object t = x[a];
        x[a] = x[b];
        x[b] = t;
    }

    public static Integer[] generateRandomArray(int n, int rangeL, int rangeR) {
        if(rangeL > rangeR)
            throw new IllegalArgumentException(String.format("set range invalid. require rangeL <= rangeR)", rangeL, rangeR));

        Integer[] arr = new Integer[n];
        for(int i = 0; i < n; i++)
            arr[i] = Integer.valueOf((int) (Math.random() * (rangeR - rangeL + 1) + rangeL));

        return arr;
    }

    public static void printArray(Object[] arr) {
        for(int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    private static boolean isSorted(Comparable[] arr) {
        for(int i = 0; i < arr.length - 1; i++)
            if(arr[i+1].compareTo(arr[i]) < 0)
                return false;
        return true;
    }

    public static void testSort(String className, Comparable[] arr) {
        try {
            Class sortClass = Class.forName(className);
            Method sortMethod = sortClass.getMethod("sort", new Class[] { Comparable[].class });
            Object[] params = new Object[] { arr };

            long startTime = System.nanoTime();
            sortMethod.invoke(null, params);
            long endTime = System.nanoTime();

            if(!isSorted(arr)) {
                throw new IllegalArgumentException("isn't sorted.");
            }

            System.out.println( sortClass.getSimpleName() + " : " + (double)(endTime - startTime) / 1000000000.0 + " s" );

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
