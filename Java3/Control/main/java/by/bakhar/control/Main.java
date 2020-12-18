package by.bakhar.control;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        File file = new File("input.txt");
        LearnerArrayList<SchoolBoy> boys = null;
        try {
            Scanner scanner = new Scanner(file);
            boys = LearnerArrayReader.readSchoolBoy(scanner);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println(boys);
        LearnerArrayList<Student> students=null;
        File file2=new File("input2.txt");
        try {
            Scanner scanner = new Scanner(file2);
            students = LearnerArrayReader.readStudentArray(scanner);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println(students);

        System.out.println(boys.getTwoBestLearners());


        students.sort();
        System.out.println(students);


        System.out.println(students.countMark("Gymnasium20"));
        System.out.println(students.countMark("Gymna"));
    }
}
