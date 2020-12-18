package bsu;

import java.io.File;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        File file=new File("text.txt");
        File file2=new File("text2.txt");
        ComArrayList<Double> doubles =Reader.initList(file);
        System.out.println(doubles.toString());
        System.out.println();
        System.out.println(doubles.getMax());
        System.out.println(doubles.getMin());


        ComArrayList<Student> students=new ComArrayList<>();
        students.add(new Student("Goskw",3,9.6));
        students.add(new Student("Sfawf",1,9.6));
        students.add(new Student("Bakhar",2,9.6));
        students.add(new Student("Mark",1,3.5));
        students.add(new Student("Gord",3,6.7));
        students.add(new Student("Qwe",1,1.7));
        students.add(new Student("Abs",1,1.7));
        students.add(new Student("Bfg",1,1.7));
        System.out.println(students.getMax());
        System.out.println(students.getMin());
        System.out.println(students.toString());
        Collections.sort(students,null);
        System.out.println(students);
    }
}
