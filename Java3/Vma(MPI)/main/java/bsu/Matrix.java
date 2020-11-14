package bsu;

public class Matrix {
    private final double[][] matrix;
    private final double[][] matrixT;

    public double[][] getMatrixT() {
        return matrixT;
    }

    public double[][] getMatrix() {
        return matrix;
    }

    public Matrix() {
        matrix = new double[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                matrix[i][j] = ((int) (Math.random() * 2000)) / 100.0 - 10;
            }
        }
        matrixT = new double[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                matrixT[i][j] = matrix[j][i];
            }
        }

    }

    @Override
    public String toString() {
        StringBuffer buffer = new StringBuffer();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                buffer.append(String.format("%.2f ", matrix[i][j]));
            }
            buffer.append("\n");
        }
        return new String(buffer);
    }
    private double countIJ(int i,int j){
        double sum=0;
        for (int k = 0; k < 10; k++) {
            sum+=matrixT[i][k]*matrix[k][j];
        }
        return sum;
    }
    public double[][] transformMatrixGauss(){
        double[][] transformedMatrix=new double[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                transformedMatrix[i][j]=countIJ(i,j);
            }
        }
        return transformedMatrix;
    }
}
