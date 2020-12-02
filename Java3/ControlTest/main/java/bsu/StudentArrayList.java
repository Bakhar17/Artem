package bsu;

import java.util.ArrayList;
import java.util.Comparator;

public class StudentArrayList extends ArrayList<Student> {

    public StudentArrayList getMax() {
        StudentArrayList arrayMax = new StudentArrayList();
        StudentArrayList temp= (StudentArrayList) clone();
        if (size() != 0) {
            temp.sort((e, w) -> -1 * Double.compare(e.getMark(), w.getMark()));
            Student student = temp.get(0);
            for (Student stud : temp) {
                if (student.getMark() == stud.getMark()) {
                    arrayMax.add(stud);
                }else{
                    break;
                }
            }
        }
        return arrayMax;
    }
    public StudentArrayList getMin() {
        StudentArrayList arrayMin = new StudentArrayList();
        StudentArrayList temp= (StudentArrayList) clone();
        if (size() != 0) {
            temp.sort(Comparator.comparingDouble(Student::getMark));
            Student student = temp.get(0);
            for (Student stud : temp) {
                if (student.getMark() == stud.getMark()) {
                    arrayMin.add(stud);
                }else{
                    break;
                }
            }
        }
        return arrayMin;
    }
}
