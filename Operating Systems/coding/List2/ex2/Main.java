package List2.ex2;

import java.util.Scanner;
import List2.Matrix;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rowsA, columnsA, rowsB, columnsB;

        System.out.print("Enter Matrix A rows size: ");
        rowsA = scanner.nextInt();
        System.out.printf("Enter Matrix A columns size: ");
        columnsA = scanner.nextInt();
        Matrix A = new Matrix(rowsA, columnsA);
        System.out.printf("Enter Matrix A values:%n");
        A.readMatrix();
        
        System.out.printf("%nEnter Matrix B rows size: ");
        rowsB = scanner.nextInt();
        System.out.printf("Enter Matrix B columns size: ");
        columnsB = scanner.nextInt();
        Matrix B = new Matrix(rowsB, columnsB);
        System.out.printf("Enter Matrix B values:%n");
        B.readMatrix();

        System.out.printf("%nMultiplying A x B... Result: %n");
        Matrix C = Matrix.multiplyMatrixes(A, B);
        C.printMatrix();

        scanner.close();
    }
}