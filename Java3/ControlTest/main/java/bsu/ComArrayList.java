package bsu;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class ComArrayList<T extends Comparable<T>> extends ArrayList<T> {
    public T getMax() {
        return Collections.max(this);
    }
    public  T getMin() {
       return Collections.min(this);
    }
}
