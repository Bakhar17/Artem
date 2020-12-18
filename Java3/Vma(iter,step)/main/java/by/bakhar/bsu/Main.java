package by.bakhar.bsu;

import java.util.Arrays;

public class Main {
    private static double findNorm(double[] y) {
        double norm = 0;
        for (double x : y) {
            norm += Math.pow(x, 2);
        }
        return Math.sqrt(norm);
    }

    private static void normVector(double[] y) {
        double norm = findNorm(y);
        for (int i = 0; i < y.length; i++) {
            y[i] = y[i] / norm;
        }
    }

    private static double[] multiplicationMatrix(double[][] matrix, double[] y) {
        double[] y1 = new double[6];
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                y1[i] += matrix[i][j] * y[j];
            }
        }
        return y1;
    }

    private static boolean checkNorm(double[] l, double[] l1) {
        for (int i = 0; i < 6; i++) {
            if (Math.abs(l[i] - l1[i]) >= 0.000001) {
                return false;
            }
        }
        return true;
    }
    private static double multVector(double[] first,double[] second){
        double result=0;
        for (int i = 0; i <6 ; i++) {
            result+=first[i]*second[i];
        }
        return result;
    }

    public static void main(String[] args) {
        final double[][] matrix = new double[6][6];
        for (int i = 0; i < 6; i++) {
            matrix[i][i] = 1.342;
        }
        matrix[0][1] = matrix[1][0] = 0.432;
        matrix[0][2] = matrix[2][0] = -0.599;
        matrix[0][3] = matrix[3][0] = 0.202;
        matrix[0][4] = matrix[4][0] = 0.603;
        matrix[0][5] = matrix[5][0] = -0.202;
        matrix[1][2] = matrix[2][1] = 0.256;
        matrix[1][3] = matrix[3][1] = -0.599;
        matrix[1][4] = matrix[4][1] = 0.204;
        matrix[1][5] = matrix[5][1] = 0.304;
        matrix[2][3] = matrix[3][2] = 0.532;
        matrix[2][4] = matrix[4][2] = 0.101;
        matrix[2][5] = matrix[5][2] = 0.506;
        matrix[3][4] = matrix[4][3] = 0.106;
        matrix[3][5] = matrix[5][3] = -0.311;
        matrix[4][5] = matrix[5][4] = 0.102;

        matrix[0][0] += 2 * 0.05;
        matrix[1][1] += 2 * 0.03;
        matrix[2][2] += 2 * 0.02;
        matrix[3][3] += 2 * 0.04;
        matrix[4][4] += 2 * 0.06;
        matrix[5][5] += 2 * 0.07;

        for (double[] strokes : matrix) {
            for (double d : strokes) {
                System.out.printf("%.3f ", d);
            }
            System.out.println();
        }


        double[] y = {1, 1, 1, 1, 1, 1};
        double[] l = {1, 1, 1, 1, 1, 1};


        double[] l1 = new double[6];
        double[] y1;


        int k = 0;
        while (true) {
            k++;
            normVector(y);
            y1 = multiplicationMatrix(matrix, y);
            for (int i = 0; i < 6; i++) {
                l1[i] = y1[i] / y[i];
            }
            if (checkNorm(l, l1)) {
                normVector(y1);
                break;
            }
            y = y1.clone();
            l = l1.clone();
        }
        System.out.println(k);
        double result = 0;
        for (double d : l1) {
            result += d;
        }
        result /= 6;
        System.out.println(Arrays.toString(y1));
        System.out.println(result);
        double[] x = multiplicationMatrix(matrix, y1);
        double[] test = new double[6];
        for (int i = 0; i < 6; i++) {
            test[i] = result * y1[i];
        }
        for (int i = 0; i < 6; i++) {
            System.out.println(x[i] - test[i]);
        }



        for (int i = 0; i < 6; i++) {
            y[i]=1;
        }
        double ls=1;
        double lk;
        k=0;
        while (true){
            k++;
            normVector(y);
            y1=multiplicationMatrix(matrix,y);
            lk=multVector(y1,y)/multVector(y,y);
            if(Math.abs(lk-ls)<=0.000001){
                normVector(y1);
                break;
            }
            y=y1.clone();
            ls=lk;
        }
        System.out.println();
        System.out.println(lk);
        System.out.println(Arrays.toString(y1));
        System.out.println(k);
        x = multiplicationMatrix(matrix, y1);
        for (int i = 0; i < 6; i++) {
            test[i] = lk * y1[i];
        }
        for (int i = 0; i < 6; i++) {
            System.out.println(x[i] - test[i]);
        }
    }
}
