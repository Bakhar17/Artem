package bsu;

public class Main {
    public static void main(String[] args) {
        Matrix matrix = new Matrix();
        System.out.println(matrix);
        Result result=new Result(matrix);
        System.out.println(result);
        double[][] transformedMatrix=matrix.transformMatrixGauss();
        double[] transformedVector=result.transformVectorGauss();
        MethodPI start=new MethodPI(transformedVector,transformedMatrix);
        System.out.println(start.chaseMethod());
        double[] x=start.getVectorX();
        for (int i = 0; i < 10; i++) {
            System.out.printf("%.2f ",x[i]);
        }

    }
}
