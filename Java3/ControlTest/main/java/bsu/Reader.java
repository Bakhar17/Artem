package bsu;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Reader {
    public static StudentArrayList initStudent(File file) {
        StudentArrayList arrayList = new StudentArrayList();
        Scanner scanner;
        try {
            scanner = new Scanner(file);
            int k = 0;
            while (scanner.hasNextLine()) {
                try {
                    StringTokenizer tokenizer = new StringTokenizer(scanner.nextLine(), " ", false);
                    String surname = tokenizer.nextToken();
                    int course = Integer.parseInt(tokenizer.nextToken());
                    double mark = Double.parseDouble(tokenizer.nextToken());
                    if (course > 0 && mark > 0) {
                        arrayList.add(new Student(surname, course, mark));
                        k++;
                    } else {
                        throw new NumberFormatException("Incorrect values!");
                    }
                } catch (NoSuchElementException | IllegalStateException | NumberFormatException |
                        NullPointerException e) {
                    System.out.println("String number " + k + " " + e.getMessage());
                    k++;
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("File wasn't opened!");
        }
        return arrayList;
    }

    public static ComArrayList<Double> initList(File file) {
        ComArrayList<Double> arrayList = new ComArrayList<>();
        try {
            Scanner scanner = new Scanner(file);
            StringTokenizer tokenizer = new StringTokenizer(scanner.nextLine(), " ", false);
            while (tokenizer.hasMoreTokens()) {
                try {
                    arrayList.add(Double.parseDouble(tokenizer.nextToken()));
                }  catch (NumberFormatException e) {
                    arrayList.add(0.0);
                }
            }
        } catch (FileNotFoundException e) {
            e.getStackTrace();
        }catch (NoSuchElementException e) {
            System.out.println(e.getMessage());
        }
        return arrayList;
    }
}
