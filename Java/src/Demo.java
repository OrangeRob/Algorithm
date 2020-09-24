import algorithm.SelectionSort;

class Person {
    private String name;

    void setName(String name) { this.name = name; }
    String getName() { return name; }
}

public class Demo {
    public static void main(String[] args) {
        Student[] d = new Student[4];
        d[0] = new Student("D", 90);
        d[1] = new Student("C", 100);
        d[2] = new Student("B", 95);
        d[3] = new Student("A", 95);
        SelectionSort.sort(d);
        for( int i = 0 ; i < d.length ; i ++ )
            System.out.println(d[i]);
    }
}
