package bsu;

public class Main {
    public static void main(String[] args) {
        Matrix matrix = new Matrix();
        System.out.println(matrix);
        Result result=new Result(matrix);
        System.out.println(result);
        double[][] transformedMatrix=matrix.transformMatrixGauss();
        double[] transformedVector=result.transformVectorGauss();
/*        for (int i = 0; i <10 ; i++) {
            for (int j = 0; j <10 ; j++) {
                System.out.print(transformedMatrix[i][j]+" ");
            }
            System.out.println();
        }*/
/*        MethodPI start=new MethodPI(transformedVector,transformedMatrix);
        System.out.println(start.chaseMethod());
        double[] x=start.getVectorX();
        for (int i = 0; i < 10; i++) {
            System.out.printf("%.2f ",x[i]);
        }*/
        MethodRelax start2=new MethodRelax(transformedMatrix,transformedVector);
        System.out.println("start");
        double[] x;
        double[] x1=result.getVectorX();
        x=start2.startRelax(0.2);
        System.out.println("\n"+start2.getK()+1);
        for (int i = 0; i < 10; i++) {
            System.out.println(x1[i]-x[i]);
        }
        x=start2.startRelax(0.5);
        System.out.println("\n"+start2.getK()+1);
        x=start2.startRelax(0.8);
        for (int i = 0; i < 10; i++) {
            System.out.println(x1[i]-x[i]);
        }
        System.out.println("\n"+start2.getK()+1);
        x=start2.startRelax(1);
        for (int i = 0; i < 10; i++) {
            System.out.println(x1[i]-x[i]);
        }
        System.out.println("\n"+start2.getK()+1);
        x=start2.startRelax(1.3);
        for (int i = 0; i < 10; i++) {
            System.out.println(x1[i]-x[i]);
        }
        System.out.println("\n"+start2.getK()+1);
        x=start2.startRelax(1.8);
        System.out.println("\n"+start2.getK()+1);
        for (int i = 0; i < 10; i++) {
            System.out.print(x1[i]-x[i]);
        }

    }
}
