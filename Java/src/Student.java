public class Student implements Comparable<Student> {
    private String name;
    private int score;

    public Student(String name, int score) {
        this.name = name;
        this.score = score;
    }

    @Override
    public int compareTo(Student otherStudent) {
        if(this.score < otherStudent.score)
            return -1;
        else if(this.score > otherStudent.score)
            return 1;
        else
            return this.name.compareTo(otherStudent.name);
    }

    @Override
    public String toString() {
        return String.format("Student %s : score = %d", this.name, this.score);
    }
}
