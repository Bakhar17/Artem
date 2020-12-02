package by.bsu.hometask;

import java.util.Arrays;
import java.util.function.Predicate;

public class Main {
    public static Predicate<Double> moreThan10 = e -> (e > 10);


    public static void main(String[] args) {
        Double[] array = new Double[10];
        Double[] array1 = new Double[0];
        for (int i = 0; i < array.length; i++) {
            array[i] = Math.random() * 200 - 100;
        }
        System.out.println(Arrays.toString(array));
        System.out.println(MyFunction.countSum(array));
        try {
            System.out.println(MyFunction.countAverage(array1));
        } catch (MyException e) {
            System.out.println(e.toString());
        }
        System.out.println(MyFunction.countByPredicate(array, moreThan10));

        System.out.println(MyFunction.countByPredicate(array, new MyPredicate(0)));
        System.out.println(MyFunction.countByPredicate(new Integer[]{1, 2, 3}, o -> o % 2 == 0));
        System.out.println(MyFunction.countByPredicate(new String[]{"asdw", "ad", "asdwdad"}, s -> s.length()>3));
    }
}
