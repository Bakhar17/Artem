package bsu;

public class Result {
    private final double[] vectorX;

    public double[] getVectorX() {
        return vectorX;
    }

    private final double[] vectorF;
    private final Matrix matrix;
    public Result(Matrix matrix){
        this.matrix=matrix;
        vectorX = new double[10];
        for (int i = 0; i < 10; i++) {
            vectorX[i] = ((int) (Math.random() * 2000)) / 100.0 - 10;
        }
        vectorF= new double[10];
        double[][] matrix1= this.matrix.getMatrix();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                vectorF[i]+=matrix1[i][j]*vectorX[j];
            }
        }
    }
    public double[] transformVectorGauss(){
        double[][] matrixT=matrix.getMatrixT();
        double[] transformedToGauss=new double[10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                transformedToGauss[i]+=matrixT[i][j]*vectorF[j];
            }
        }
        return transformedToGauss;
    }


    @Override
    public String toString() {
        StringBuffer buffer=new StringBuffer();
        buffer.append("Vector x:\n");
        for (int i = 0; i < 10; i++) {
            buffer.append(String.format("%.2f ",vectorX[i]));
        }
        buffer.append("\nVector f:\n");
        for (int i = 0; i < 10; i++) {
            buffer.append(String.format("%.2f ",vectorF[i]));
        }
        buffer.append("\n");
        return new String(buffer);
    }
}
