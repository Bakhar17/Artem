package bsu;

public class Main {
    public static double row(double x, double error) {
        double value;
        int k = 1;
        value = Math.pow(x, 2) * Math.pow(4.0 / 3, 6) / 6;
        double sum = value;
        while (Math.abs(value) >= Math.abs(error)) {
            k++;
            value *= (-1) * Math.pow(4.0 / 3, 4) / (2 * k * (2 * k + 1));
            sum += value;
        }
        return sum;
    }

    public static void main(String[] args) {
        double x, error;
        if (args.length != 2) {
            throw new IndexOutOfBoundsException("Invalid number of data");
        }
        try {
            x = Double.parseDouble(args[0]);
            error = Double.parseDouble(args[1]);
        } catch (NumberFormatException ex) {
            System.out.println("Invalid data\nDefault params");
            x = 2;
            error = 0.005;
        }
        System.out.println(x);
        System.out.println(error);
        System.out.println(row(x, error));
    }

}