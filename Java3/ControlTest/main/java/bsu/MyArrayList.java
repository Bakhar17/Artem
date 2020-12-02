package bsu;

import java.util.ArrayList;

public class MyArrayList extends ArrayList<Double> {
    public Double getMax() {
        Double max;
        try {
            max = get(0);
            for (Double t : this) {
                if (t.compareTo(max) > 0)
                    max = t;
            }
        }catch (IndexOutOfBoundsException e){
            max=0.;
        }
        return max;
    }
    public Double getMin() {
        Double min;
        try {
            min = get(0);
            for (Double t : this) {
                if (t.compareTo(min) < 0)
                    min = t;
            }
        }catch (IndexOutOfBoundsException e){
            min=0.;
        }
        return min;
    }
}
