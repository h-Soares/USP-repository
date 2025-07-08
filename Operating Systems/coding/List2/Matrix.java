package List2;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;
import List2.ex2.MultiplyMatrixThread;
import List2.ex3.DeterminantMatrixThread;

public class Matrix {
    
    private int[][] matrix;
    private int rowsSize, columnsSize;
    
    /**
     * Construtor que gera uma matriz vazia
     * @param rowsSize número de linhas 
     * @param columnsSize número de colunas
     */
    public Matrix(int rowsSize, int columnsSize){
        this.rowsSize = rowsSize;
        this.columnsSize = columnsSize;
        matrix = new int[rowsSize][columnsSize];
    }
    
    /**
     * Construtor que gera uma matriz quadrada vazia
     * @param rowsSize número de linhas/colunas
    */
    public Matrix(int rowsSize){
        this.rowsSize = rowsSize;
        this.columnsSize = rowsSize;
        matrix = new int[rowsSize][rowsSize];
    }

    public static Matrix multiplyMatrixes(Matrix A, Matrix B) {
        if(A.getColumnsSize() != B.getRowsSize())
            throw new IllegalArgumentException("Multiply not allowed");

        ExecutorService executorService = Executors.newFixedThreadPool(A.getRowsSize() * B.getColumnsSize());
        Matrix C = new Matrix(A.getRowsSize(), B.getColumnsSize());

        for(int i = 0; i < C.getRowsSize(); i++) {
            List<Integer> rowNumbers = getRowNumbers(A, i);
            for(int j = 0; j < C.getColumnsSize(); j++) {
                List<Integer> columnNumbers = getColumnNumbers(B, j);
                executorService.execute(new MultiplyMatrixThread(C, rowNumbers, columnNumbers, i, j));
            }
        }
        
        executorService.shutdown();
        try {
            executorService.awaitTermination(1, TimeUnit.MINUTES);
            return C;
        } catch (InterruptedException e) {
            throw new RuntimeException("ERROR: " + e.getMessage());
        }
    }

    public static List<Integer> getRowNumbers(Matrix matrix, int row) {
        List<Integer> rowNumbers = new ArrayList<>();
        
        for(int j = 0; j < matrix.getColumnsSize(); j++)
            rowNumbers.add(matrix.getElement(row, j));
        return rowNumbers;
    }

    public static List<Integer> getColumnNumbers(Matrix matrix, int column) {
        List<Integer> columnNumbers = new ArrayList<>();
        
        for(int i = 0; i < matrix.getRowsSize(); i++)
            columnNumbers.add(matrix.getElement(i, column));
        return columnNumbers;
    }

    // OK, está certo, mas é um pouco complexo de se entender...
    public int calculateDeterminant() { //By Laplace method. Chosen row: 0
        if(rowsSize != columnsSize)
            throw new IllegalArgumentException("Matrix must be square to calcule the determinant");

        if(rowsSize == 2)
            return getElement(0, 0) * getElement(1, 1) - getElement(1, 0) * getElement(0, 1);

        AtomicInteger sum = new AtomicInteger(0);
        ExecutorService executorService = Executors.newCachedThreadPool();
        for(int j = 0; j < columnsSize; j++) {
            Thread thread = new Thread(new DeterminantMatrixThread(this, sum, j));
            executorService.execute(thread);
        }

        executorService.shutdown();
        try {
            executorService.awaitTermination(1, TimeUnit.MINUTES);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return sum.get();
    }
	      
    /**
     * Preenche a matriz a partir dos valores inseridos pelo usuário
     */
    public void readMatrix() {
        String line;
        Scanner sc = new Scanner(System.in);
 
        try {
            for(int i = 0; i < rowsSize; i++) {
                for(int j = 0; j < columnsSize; j++) {
                    System.out.print("Element m[" + i + "]["
                        + j + "]: ");
                    line = sc.nextLine();
                    matrix[i][j] = Integer.parseInt(line);
                }
            }
        } catch(NumberFormatException nfe) {
            System.err.println(nfe);
			System.exit(0);
        }        
    }
    
    /**
     * Imprime os valores da matriz
     */
    public void printMatrix(){
        for (int i = 0; i < matrix.length; i++) {
            System.out.print("[ ");
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }            
            System.out.println(" ]");
        }
    }
    
    /**
     * Retorna o valor de um elemento da matriz
     * @param i linha
     * @param j coluna
     * @return valor do elemento[i][j]
     */
    public int getElement(int i, int j) {
        return matrix[i][j];
    }
      
    /**
     * Modifica o valor do elemento[i][j] da matriz
     * @param i índice da linha (a partir do zero)
     * @param j índice da coluna (a partir do zero)
     * @param value 
     */
    public void setElement(int i, int j, int value) {
        matrix[i][j] = value;
    }
    
    /**
     * Gera uma submatriz retirando a linha 0 e coluna j1
     * @param j1 coluna que será removida para gerar a nova matriz
     * @return 
     */
    public Matrix getSubmatrix(int j1){
        Matrix submatrix;

		submatrix = new Matrix(getRowsSize() - 1);
        
        for (int i=1; i < getRowsSize() ; i++)
        {
            int j2=0;
            for (int j=0; j< getRowsSize() ; j++)
            {
                if(j != j1) {
                    submatrix.setElement(i-1, j2, getElement(i,j));
                    j2++;
                }
            }
        }
        return submatrix;
    }
    
    /**
     * Retorna o número de linhas da matriz
     * @return 
     */
    public int getRowsSize(){
        return rowsSize;
    }
    
    /**
     * Retorna o número de colunas da matriz
     * @return 
     */
    public int getColumnsSize(){
        return columnsSize;
    }
}
