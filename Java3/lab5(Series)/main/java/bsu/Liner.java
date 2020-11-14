package bsu;

import java.util.InputMismatchException;

public class Liner extends Series {
    public Liner(double first, double denominator) throws InputMismatchException {
        super(first, denominator);
    }

    @Override
    public double countElem(int j) throws IllegalArgumentException {
        if(j<=0) throw new IllegalArgumentException("Impossible to count!");
        return (first+(j-1)*denominator);
    }
}
