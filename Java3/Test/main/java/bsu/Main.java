package bsu;

public class Main {
    public static int factorial(int k){
        if (k==1){
            return 1;
        }
        return k*factorial(k-1);
    }
    public static double row(double x,int k){
        return ((Math.pow(-1,k+1)*Math.pow(x,2)*Math.pow(4/3,4*k+2)))/factorial(2*k+1);
    }
    public static void main(String[] args) {
        try {
            if (args.length>2) {
                throw new IndexOutOfBoundsException("Invalid number of data\nRestart the Program!");
            }

        }catch (IndexOutOfBoundsException ex){
            System.out.println(ex);
            return;
        }
        try {
            Double.parseDouble(args[0]);
            Double.parseDouble(args[0]);
        }catch(NumberFormatException ex){
            System.out.println("Invalid data\nPlease, restart the Program");
            return;
        }
        double x=Double.parseDouble(args[0]);
        double error=Double.parseDouble(args[1]);
        System.out.println(x);
        System.out.println(error);
        double sum=0;
        double value=error+1;
        int k=1;
        while(Math.abs(value)>=Math.abs(error)){
            value=row(x,k);
            sum+=value;
            k++;
        }
        System.out.println(sum);
    }
}
