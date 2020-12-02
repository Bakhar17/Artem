package by.bsu.hometask;

import java.util.function.Predicate;

public class MyFunction {
    public static <T extends Number> double countSum(T[] data){
        double sum=0;
        for(T aDouble: data){
            sum+=aDouble.doubleValue();
        }
        return sum;
    }
    public static <T extends Number> double countAverage(T[] data) throws MyException {
        if(data.length==0) throw new MyException("Empty");
        return countSum(data)/data.length;
    }
    public static <T> int countByPredicate(T[] data, Predicate<T> predicate) {
        int k = 0;
        for (int i = 0; i < data.length; i++) {
            if (predicate.test(data[i])) {
                k++;
            }
        }
        return k;
    }
}
