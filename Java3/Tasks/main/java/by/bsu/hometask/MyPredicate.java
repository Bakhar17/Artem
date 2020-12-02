package by.bsu.hometask;


import java.util.function.Predicate;

public class MyPredicate implements Predicate<Number> {
    private double lowBound;

    public MyPredicate(double lowBound) {
        this.lowBound = lowBound;
    }

    @Override
    public boolean test(Number o) {
        return Double.compare(o.doubleValue(), lowBound) > 0;
    }
}
