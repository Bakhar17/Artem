package bsu;

import org.w3c.dom.ls.LSOutput;

public class Main {

    public static void main(String[] args) {
        Data data = new Data();
        data.initA();
        data.initB();
        data.initC();
        data.initResult();
        double[] array = data.getArrayA();
        System.out.println("Array a");
        for (int i = 1; i < array.length; i++) {
            System.out.print(array[i] * -1 + " ");
        }
        System.out.println("\nArray b");
        array = data.getArrayB();
        for (int i = 0; i < array.length - 1; i++) {
            System.out.print(array[i] * (-1) + " ");
        }
        System.out.println("\nArray c");
        array = data.getArrayC();
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println("\nArray y");
        array = data.getResult();
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        Tech tech = new Tech(data);
        array = tech.getMatrix();
        System.out.println("\nArray f(A*y)");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        double[] array2 = tech.count();
        System.out.println("\nArray y*");
        for (int i = 0; i < array2.length; i++) {
            System.out.print(array2[i] + " ");
        }
        System.out.println("\ny norm");
        array = data.getResult();
        double yNorm = Math.abs(array[0] - array2[0]);
        for (int i = 1; i < array.length; i++) {
            if (yNorm < Math.abs(array[i] - array2[i])) yNorm = Math.abs(array[i] - array2[i]);
        }
        System.out.println(yNorm);
        System.out.println("Matrix norm");
        array = tech.getMatrix();
        data.setResult(array2);
        tech.setData(data);
        tech.multiplicativeMatrix();
        array2 = tech.getMatrix();
        double mNorm = Math.abs(array[0] - array2[0]);
        for (int i = 1; i < array.length; i++) {
            if (mNorm < Math.abs(array[i] - array2[i])) mNorm = Math.abs(array[i] - array2[i]);
        }
        System.out.println(mNorm);
    }
}
