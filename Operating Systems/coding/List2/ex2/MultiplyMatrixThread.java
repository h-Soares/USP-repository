package List2.ex2;

import java.util.List;
import List2.Matrix;

public class MultiplyMatrixThread implements Runnable {
    private Matrix matrix;
    private List<Integer> rowNumbers, columnNumbers;
    private int i, j;

    public MultiplyMatrixThread(Matrix matrix, List<Integer> rowNumbers, List<Integer> columnNumbers, int i, int j) {
        this.matrix = matrix;
        this.rowNumbers = rowNumbers;
        this.columnNumbers = columnNumbers;
        this.i = i;
        this.j = j;
    }

    @Override
    public void run() {
        if(rowNumbers.size() != columnNumbers.size())
            throw new IllegalArgumentException("Multiply now allowed");
            
        int size = rowNumbers.size(), sum = 0;
        for(int i = 0; i < size; i++)
            sum += rowNumbers.get(i) * columnNumbers.get(i);
        matrix.setElement(i, j, sum);
    }
}