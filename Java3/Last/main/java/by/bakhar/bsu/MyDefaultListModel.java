package by.bakhar.bsu;

import javax.swing.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

public class MyDefaultListModel extends DefaultListModel<Student> implements Iterable<Student> {
    public void sort() {
        if (this.size() > 0) {
            ArrayList<Student> temp = Collections.list(this.elements());
            temp.sort(null);
            this.removeAllElements();
            for (Student student: temp){
                this.addElement(student);
            }
        }
    }


    @Override
    public Iterator<Student> iterator() {
        return new MyListIterator(this);
    }
}
