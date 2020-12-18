package by.bakhar.bsu;

import java.util.HashMap;
import java.util.Objects;

public class Student implements Comparable<Student>{
    private int indicator;
    private String surname;
    private HashMap<String, Double> results=new HashMap<>();

    public void setIndicator(int indicator) {
        this.indicator = indicator;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public Student() {
    }

    public Student(int indic, String surname){
        indicator=indic;
        this.surname=surname;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return indicator == student.indicator &&
                surname.equals(student.surname);
    }

    @Override
    public int hashCode() {
        return Objects.hash(indicator, surname);
    }

    public void addResult(String subject, Double mark){
        results.put(subject,mark);
    }

    public int getIndicator() {
        return indicator;
    }

    public String getSurname() {
        return surname;
    }

    @Override
    public String toString() {
        return  indicator +
                " " + surname +
                " " + results ;
    }

    public HashMap<String, Double> getResults() {
        return results;
    }

    @Override
    public int compareTo(Student o) {
        return surname.compareTo(o.surname);
    }
}
