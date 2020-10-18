package bsu;

public class Tech {
    public Tech(Data data) {
        this.data = data;
        multiplicativeMatrix();
    }

    public double[] count() {
        countCoefficients();
        return countY();
    }

    private double[] coefficientA;
    private double[] coefficientB;
    private double[] matrix;
    private Data data;

    public void multiplicativeMatrix() {
        double[] matrixF = new double[10];
        double[] tempA = data.getArrayA();
        double[] tempB = data.getArrayB();
        double[] tempC = data.getArrayC();
        double[] tempResult = data.getResult();
        matrixF[0] = tempC[0] * tempResult[0] + tempB[0] * tempResult[1];
        for (int i = 1; i < matrixF.length - 1; i++) {
            matrixF[i] = tempA[i] * tempResult[i - 1] + tempC[i] * tempResult[i] + tempB[i] * tempResult[i + 1];
        }
        matrixF[matrixF.length - 1] = tempA[matrixF.length - 1] * tempResult[matrixF.length - 2] + tempResult[matrixF.length - 1] * tempC[matrixF.length - 1];
        matrix = matrixF;
    }

    public double[] getCoefficientB() {
        return coefficientB;
    }

    public double[] getCoefficientA() {
        return coefficientA;
    }

    public double[] getMatrix() {
        return matrix;
    }

    private void countCoefficients() {
        double[] tempA = data.getArrayA();
        double[] tempB = data.getArrayB();
        double[] tempC = data.getArrayC();
        coefficientA = new double[9];
        coefficientB = new double[10];
        coefficientA[0] = -1*tempB[0] / tempC[0];
        coefficientB[0] = matrix[0] / tempC[0];
        double denominator;
        for (int i = 1; i < 9; i++) {
            denominator = tempC[i] - (-1)*tempA[i] * coefficientA[i-1];
            coefficientA[i] = -1*tempB[i] / denominator;
            coefficientB[i] = (matrix[i] + (-1)*tempA[i] * coefficientB[i-1]) / denominator;
        }
        coefficientB[9] = (matrix[9] + (-1)*tempA[9] * coefficientB[8]) / (tempC[9] - (-1)*tempA[9] * coefficientA[8]);
    }

    private double[] countY() {
        double[] answer = new double[matrix.length];
        answer[9] = coefficientB[9];
        for (int i = 8; i >= 0; i--) {
            answer[i] = coefficientA[i] * answer[i + 1] + coefficientB[i];
        }
        return answer;
    }

    public Data getData() {
        return data;
    }

    public void setData(Data data) {
        this.data = data;
    }
}
