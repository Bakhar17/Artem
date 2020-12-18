package by.bakhar.control;

public class Student  extends Learner{
    private int course;

    public Student(String name, String university, double universityRate, double mark,int course) {
        super(name,university,universityRate,mark);
        this.course = course;
    }

    @Override
    public String toString() {
        return super.toString()+" course="+course;
    }
}
