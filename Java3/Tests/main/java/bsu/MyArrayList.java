package bsu;

import java.util.ArrayList;
import java.util.Comparator;

public class MyArrayList extends ArrayList<Student> {
    public MyArrayList getStudentOfFaculty(Faculty faculty) {
        MyArrayList arrayFaculty = new MyArrayList();
        forEach(s -> {
            if (s.getFaculty().equals(faculty))
                arrayFaculty.add(s);
        });
        return arrayFaculty;
    }

    public MyArrayList getStudentOfFacultyAndCourse(Faculty faculty, int course) {
        MyArrayList arrayFaculty = new MyArrayList();
        forEach(s -> {
            if (s.getFaculty().equals(faculty) && s.getCourse() == (course))
                arrayFaculty.add(s);
        });
        return arrayFaculty;
    }

    public MyArrayList getStudentsYoungerThan(int year) {
        MyArrayList arrayDate = new MyArrayList();
        if (year > 0) {
            forEach(s -> {
                if (s.getBirthday().getYear() > year)
                    arrayDate.add(s);
            });
        }
        arrayDate.sort(new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                if(!o1.getFaculty().equals(o2.getFaculty())) {
                    return o1.getFaculty().compareTo(o2.getFaculty());
                }
                return o1.getSurname().compareTo(o2.getSurname());
/*                if(o1.getFaculty().equals(o2.getFaculty())){
                    return o1.getSurname().compareTo(o2.getSurname());
                }
                return o1.getFaculty().compareTo(o2.getFaculty());*/
            }
        });
        return arrayDate;
    }

    public MyArrayList getStudentGroup(int course, int group) {
        MyArrayList arrayGroup = new MyArrayList();
        if (group > 0 && course>0) {
            forEach(s -> {
                if (s.getCourse() == course && s.getGroup() == group)
                    arrayGroup.add(s);
            });
        }
        return arrayGroup;
    }

    @Override
    public String toString() {
        StringBuffer array=new StringBuffer();
        forEach(student -> array.append(student).append("\n"));
        return array.toString();
    }
}
