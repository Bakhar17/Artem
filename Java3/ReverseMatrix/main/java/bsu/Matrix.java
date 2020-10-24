package bsu;

import java.util.Scanner;

public class Matrix {
    public Matrix(int n) {
        dimension = n;
        unitarian = new double[dimension][dimension];
        for (int i = 0; i < dimension; i++) {
            unitarian[i][i] = 1;
        }
    }

    public double[][] getMatrix() {
        return matrix;
    }

    public int getDimension() {
        return dimension;
    }

    public void init() {
        Scanner sc = new Scanner(System.in);
        double[][] matrix = new double[dimension][dimension];
        try {
            for (int i = 0; i < dimension; i++) {
                for (int j = 0; j < dimension; j++) {
                    if (!sc.hasNextDouble()) {
                        throw new IllegalArgumentException("Invalid data!\nTry again!");
                    }
                    matrix[i][j] = sc.nextDouble();
                }
            }
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
            return;
        }
        this.matrix = matrix;
    }

    private double countDet() {
        double det = 1;
        for (int i = 0; i < dimension; i++) {
            det *= matrix[i][i];
        }
        return det;
    }

    public double[][] countReverseMatrix() {
        double[][] temp = matrix;
        double[][] unitarianism = unitarian;
        double k;
        for (int j = 0; j < dimension - 1; j++) {
            for (int i = j; i < dimension - 1; i++) {
                k = matrix[i + 1][j] / matrix[j][j];
                for (int q = j; q < dimension; q++) {
                    matrix[i + 1][q] -= k * matrix[j][q];
                }
                for (int q = 0; q < dimension; q++) {
                    unitarianism[i + 1][q] -= k * unitarianism[j][q];
                }
            }
        }
        if (countDet() == 0) {
            throw new ArithmeticException("detA = 0\nReverse matrix doesn't exist");
        }
        for (int j = dimension - 1; j > 0; j--) {
            for (int i = j; i > 0; i--) {
                k = matrix[i - 1][j] / matrix[j][j];
                matrix[i - 1][j] -= k * matrix[j][j];
                for (int q = 0; q < dimension; q++) {
                    unitarianism[i - 1][q] -= k * unitarianism[j][q];
                }
            }
        }
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                unitarianism[i][j] /= matrix[i][i];
            }
        }
        matrix = temp;
        return unitarianism;
    }

    private double[][] matrix;
    private int dimension;
    private double[][] unitarian;

}
