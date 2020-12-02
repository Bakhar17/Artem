package bsu;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.time.format.FormatStyle;
import java.util.Comparator;
import java.util.Locale;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class Student implements Comparable<Student> {
    private int id;
    private String surname;
    private String name;
    private LocalDate birthday;

    private Faculty faculty;

    private int course;
    private int group;

    public Student(String student) throws NumberFormatException, NoSuchElementException, DateTimeParseException {
        StringTokenizer tokenizer=new StringTokenizer(student," ",false);
        id=Integer.parseInt(tokenizer.nextToken());
        surname=tokenizer.nextToken();
        name=tokenizer.nextToken();
        DateTimeFormatter germanFormatter =
                DateTimeFormatter
                        .ofLocalizedDate(FormatStyle.MEDIUM)
                        .withLocale(Locale.GERMAN);
        birthday=LocalDate.parse(tokenizer.nextToken(),germanFormatter);
        int k= Integer.parseInt(tokenizer.nextToken());
        faculty=Faculty.values()[k];
        course=Integer.parseInt(tokenizer.nextToken());
        group=Integer.parseInt(tokenizer.nextToken());
    }

    public String getSurname() {
        return surname;
    }

    public LocalDate getBirthday() {
        return birthday;
    }

    public Faculty getFaculty() {
        return faculty;
    }

    public int getCourse() {
        return course;
    }

    public int getGroup() {
        return group;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        StringBuffer student=new StringBuffer();
        student.append("Id: ").append(id);
        student.append(" Surname: ").append(surname);
        student.append(" Name: ").append(name);
        student.append(" Birthday: ").append(birthday);
        student.append(" Faculty: ").append(faculty);
        student.append(" Course: ").append(course);
        student.append(" Group: ").append(group);
        return student.toString();
    }

    @Override
    public int compareTo(Student o) {
        return Comparator.comparing(Student::getSurname).thenComparing(Student::getName).compare(this,o);
    }
}
