package by.bakhar.control;

import java.util.NoSuchElementException;
import java.util.Scanner;

public class LearnerArrayReader {
    public static LearnerArrayList<Student> readStudentArray(Scanner scanner) {
        LearnerArrayList<Student> student = new LearnerArrayList<>();
        while (scanner.hasNextLine()) {
            String name;
            String nameOfUniversity;
            double universityRate;
            double mark;
            int course;
            try {
                name = scanner.next();
                nameOfUniversity = scanner.next();
                universityRate = scanner.nextDouble();
                mark = scanner.nextDouble();
                course = scanner.nextInt();
                if(mark>0 && course>0){
                    student.add(new Student(name, nameOfUniversity, universityRate, mark, course));
                }
            } catch (NumberFormatException | NoSuchElementException e) {
                continue;
            }
        }
        return student;
    }

    public static LearnerArrayList<SchoolBoy> readSchoolBoy(Scanner scanner) {
        LearnerArrayList<SchoolBoy> schoolBoys = new LearnerArrayList<>();
        while (scanner.hasNextLine()) {
            String name;
            String nameOfUniversity;
            double universityRate;
            double mark;
            int form;
            Behavior behavior;
            try {
                name = scanner.next();
                nameOfUniversity = scanner.next();
                universityRate = scanner.nextDouble();
                mark = scanner.nextDouble();
                form = scanner.nextInt();
                behavior = Behavior.values()[scanner.nextInt()];
                schoolBoys.add(new SchoolBoy(name, nameOfUniversity, universityRate, mark, form, behavior));
            } catch (NumberFormatException | NoSuchElementException | IndexOutOfBoundsException e) {
                continue;
            }
        }
        return schoolBoys;
    }
}
