package bsu;

public class MethodPI {
    private final double[] vectorB;
    private final double[][] matrixB;


    private double[] vectorX;

    public double[] getVectorX() {
        return vectorX;
    }

    public MethodPI(double[] vectorF, double[][] matrixA) {
        vectorB = new double[10];
        double norma=countMatrixNorm(matrixA);
        for (int i = 0; i < 10; i++) {
            vectorB[i] = vectorF[i] / norma;
        }
        matrixB = new double[10][10];
        for (int i = 0; i < 10; i++) {
            matrixB[i][i]=1;
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                matrixB[i][j]=matrixB[i][j]- (matrixA[i][j]/norma);
            }
        }
        vectorX = new double[10];
        System.arraycopy(vectorB, 0, vectorX, 0, 10);
    }

    private double countStroka(double[] vector) {
        double result = 0;
        for (int i = 0; i < 10; i++) {
            result += Math.abs(vector[i]);
        }
        return result;
    }

    private double countMatrixNorm(double[][] matrix) {
        double max = countStroka(matrix[0]);
        for (int i = 1; i < 10; i++) {
            if(max<countStroka(matrix[i])){
                max=countStroka(matrix[i]);
            }
        }
        return max;

    }

    private double checkNorm(double[] vector) {
        double max = Math.abs(vector[0]);
        for (int i = 1; i < vector.length; i++) {
            if (max < Math.abs(vector[i])) {
                max = Math.abs(vector[i]);
            }
        }
        return max;
    }

    private double[] countVector(double[] vector) {
        double[] temp = new double[10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                temp[i] += matrixB[i][j] * vector[j];
            }
            temp[i] += vectorB[i];
        }
        return temp;
    }

    public int chaseMethod() {
        double[] norm = new double[10];
        double[] vectorX2;
        boolean flag = true;
        int k = 0;
        while (flag) {
            vectorX2 = countVector(vectorX);
            for (int i = 0; i < 10; i++) {
                norm[i] = vectorX2[i] - vectorX[i];
            }
            k++;
            if (checkNorm(norm) <= 0.00001) {
                flag = false;
            }
            vectorX = vectorX2;
        }
        return k;
    }

}
