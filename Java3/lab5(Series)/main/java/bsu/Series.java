package bsu;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public abstract class Series {
    protected double first;
    protected double denominator;

    public double getDenominator() {
        return denominator;
    }

    public void setDenominator(double denominator) {
        this.denominator = denominator;
    }

    public double getFirst() {
        return first;
    }

    public void setFirst(double first) {
        this.first = first;
    }

    public Series(double first, double denominator) {
        this.first = first;
        this.denominator = denominator;
    }

    public abstract double countElem(int j) throws IllegalArgumentException;

    public double countSum(int n) {
        double sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += countElem(i);
        }
        return sum;
    }

    @Override
    public String toString() {
        final int n = 10;
        StringBuffer temp = new StringBuffer();
        temp.append(first);
        for (int i = 2; i <= n; i++) {
            temp.append(", ");
            temp.append(String.format("%.2f",countElem(i)));
        }
        return new String(temp);
    }

    public void saveToFile(File file) throws IOException {
        FileWriter writer = new FileWriter(file, true);
        writer.write(this.toString());
        writer.append("\n");
        writer.close();
    }
}


