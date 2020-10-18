package bsu;

public class Data {
    public void initA() {
        double[] array = new double[10];
        double rand;
        int min = -10;
        int max = 10;
        int diapason = max - min;
        array[0] = 0;
        for (int i = 1; i < array.length; i++) {
            rand = Math.random() * diapason - max;
            if (rand == 0) {
                while (rand == 0) {
                    rand = Math.random() * diapason - max;
                }
            }
            array[i] = Math.random() * 10;
        }
        arrayA = array;
    }

    public void initB() {
        double[] array = new double[10];
        double rand;
        int min = -10;
        int max = 10;
        int diapason = max - min;
        array[9] = 0;
        for (int i = 0; i < array.length - 1; i++) {
            rand = Math.random() * diapason - max;
            if (rand == 0) {
                while (rand == 0) {
                    rand = Math.random() * diapason - max;
                }
            }
            array[i] = Math.random() * 10;
        }
        arrayB = array;
    }

    public void initC() {
        double[] array = new double[10];
        double rand;
        for (int i = 0; i < array.length; i++) {
            rand = Math.random();
            if (rand == 0.0) {
                while (rand == 0.0) {
                    rand = Math.random();
                }
            }
            array[i] = (arrayA[i] + arrayB[i]) * (rand + 1);
        }
        arrayC = array;
    }

    public void initResult() {
        double[] array = new double[10];
        int min = -10;
        int max = 10;
        int diapason = max - min;
        for (int i = 0; i < array.length; i++) {

            array[i] = Math.random() * diapason - max;
        }
        result = array;
    }

    public double[] getArrayC() {
        return arrayC;
    }

    public double[] getArrayB() {
        return arrayB;
    }

    public double[] getResult() {
        return result;
    }

    public double[] getArrayA() {
        return arrayA;
    }

    private double[] arrayA;
    private double[] arrayC;
    private double[] arrayB;

    public void setResult(double[] result) {
        this.result = result;
    }

    private double[] result;
}
