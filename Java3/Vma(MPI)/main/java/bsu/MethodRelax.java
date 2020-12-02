package bsu;

public class MethodRelax {
    double[][] matrixA;
    double[] vectorF;
    double[] vectorX;

    public int getK() {
        return k;
    }

    int k=0;

    public MethodRelax(double[][] matrixA, double[] vectorF) {
        this.matrixA = matrixA;
        this.vectorF = vectorF;
    }

    public double[] startRelax(double w) {
        vectorX=vectorF.clone();
        for (int i = 0; i < 10; i++) {
            vectorX[i]/=matrixA[i][i];
        }
        double[] vectorForNorm;
        boolean flag = true;
        while (flag) {
            k++;
            vectorForNorm = vectorX.clone();
            for (int i = 0; i < 10; i++) {
                vectorX[i] = ((1 - w) * vectorX[i] + (w / matrixA[i][i]) * (vectorF[i] - countI(i)));
            }
            for (int i = 0; i < 10; i++) {
                vectorForNorm[i] = vectorX[i] - vectorForNorm[i];
            }
            if (checkNorm(vectorForNorm) < 0.00001) {
                System.out.println(checkNorm(vectorForNorm));
                flag = false;
            }
        }
        return vectorX;
    }

    private double countI(int i) {
        double sum = 0;
        for (int j = 0; j < 10; j++) {
            if(i==j){
                continue;
            }
            sum += matrixA[i][j] * vectorX[j];
        }
        return sum;
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

}
