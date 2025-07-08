package List2.ex3;

import java.util.Scanner;
import List2.Matrix;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rowsA, columnsA;

        System.out.print("Enter Matrix A rows size: ");
        rowsA = scanner.nextInt();
        System.out.printf("Enter Matrix A columns size: ");
        columnsA = scanner.nextInt();
        Matrix A = new Matrix(rowsA, columnsA);
        System.out.printf("Enter Matrix A values:%n");
        A.readMatrix();
        
        System.out.println(A.calculateDeterminant());

        scanner.close();
    }
}