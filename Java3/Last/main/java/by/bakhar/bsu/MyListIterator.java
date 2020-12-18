package by.bakhar.bsu;

import javax.swing.*;
import java.util.Iterator;

public class MyListIterator implements Iterator<Student> {
    private int item = 0;
    private DefaultListModel<Student> data;

    public MyListIterator(DefaultListModel<Student> data) {
        this.data = data;
    }

    @Override
    public boolean hasNext() {
        if(data.isEmpty()){
            return false;
        }
        return (item != data.size());
    }

    @Override
    public Student next() {
        return data.get(item++);
    }
}
