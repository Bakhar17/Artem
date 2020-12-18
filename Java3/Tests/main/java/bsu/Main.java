package bsu;

import java.io.File;
import java.io.FileNotFoundException;
import java.time.format.DateTimeParseException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        File file = new File("text.txt");
        MyArrayList students = new MyArrayList();
        Scanner scanner = null;
        try {
            scanner = new Scanner(file);
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }
        while (scanner.hasNextLine()) {
            try {
                String stud = scanner.nextLine();
                students.add(new Student(stud));
            } catch (NumberFormatException | NoSuchElementException | DateTimeParseException e) {
                System.out.println(e.getMessage());
            }
        }
/*        students.sort(null);
        System.out.println(students.toString());*/
        //System.out.println(students.getStudentGroup(1, 4));
        //System.out.println(students.getStudentOfFaculty(Faculty.FUN));
        System.out.println(students.getStudentsYoungerThan(1800));
        //System.out.println(students.getStudentOfFacultyAndCourse(Faculty.FAMCS, 2));
    }
}
