package bsu;

import java.util.Comparator;

public class Student implements Comparable<Student> {
    private String surname;
    private int course;
    private double mark;
    public Student(String surname,int course,double mark){
        this.surname=surname;
        this.course=course;
        this.mark=mark;
    }

    public double getMark() {
        return mark;
    }

    public String getSurname() {
        return surname;
    }

    @Override
    public int compareTo(Student o) {
        return Comparator.comparing(Student::getMark).thenComparing(Student::getSurname).compare(this,o);
    }

    @Override
    public String toString() {
        StringBuffer student=new StringBuffer();
        student.append("Surname: ").append(surname).append(" Course: ").append(course).append(" Mark: ").append(mark);
        return new String(student);
    }
}
