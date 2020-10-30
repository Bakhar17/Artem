package bsu;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Put the dimension of a square matrix: ");
        try {
            if (!sc.hasNextInt()) {
                throw new IllegalArgumentException("Don't even try to joke with me!\nTry again!");
            }
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
            return;
        }
        int n=sc.nextInt();
        Matrix matrix=new Matrix(n);
        matrix.init();
        double[][] temp=matrix.getMatrix();
        for (int i = 0; i <matrix.getDimension() ; i++) {
            for (int j = 0; j < matrix.getDimension(); j++) {
                System.out.print(temp[i][j]+" ");
            }
            System.out.print("\n");
        }
        temp= matrix.countReverseMatrix();
        for (int i = 0; i <matrix.getDimension() ; i++) {
            for (int j = 0; j < matrix.getDimension(); j++) {
                System.out.print(temp[i][j]+" ");
            }
            System.out.print("\n");
        }

        String hello="hello";
        String helloBack="hell";
        helloBack+="o";
        System.out.println(hello==helloBack);
    }
}
