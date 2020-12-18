package by.bsu.hometask;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void merge(ArrayList<Integer> result, ArrayList<Integer> b) {
        int pos = -1;
        int left;
        int right;
        boolean flag;
        for (Integer integer : b) {
            left = 0;
            right = result.size() - 1;
            flag = true;
            while (flag) {
                if (integer > result.get(right)) {
                    pos = right + 1;
                    break;
                }
                if (integer < result.get(left)) {
                    pos = left;
                    break;
                }
                pos = (left + right) / 2;
                if (integer < result.get(pos)) {
                    right = pos;
                } else if (integer > result.get(pos)) {
                    left = pos;
                }
                if (integer < result.get(right) && integer > result.get(left)) {
                    flag = false;
                }
            }
            result.add(pos, integer);
            pos = -1;
        }

    }

    public static void main(String[] args) {
        ArrayList<Integer> a = new ArrayList<>();
        a.add(1);
        a.add(3);
        a.add(5);
        ArrayList<Integer> b = new ArrayList<>();
        b.add(0);
        b.add(6);
        b.add(8);
        merge(a, b);
        System.out.println(Arrays.toString(a.toArray()));
    }
}