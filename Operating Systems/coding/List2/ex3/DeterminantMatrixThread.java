package List2.ex3;

import java.util.concurrent.atomic.AtomicInteger;
import List2.Matrix;

public class DeterminantMatrixThread implements Runnable {
    private Matrix matrix;
    private AtomicInteger sum;
    private int j;
    
    public DeterminantMatrixThread(Matrix matrix, AtomicInteger sum, int j) {
        this.matrix = matrix;
        this.sum = sum;
        this.j = j;
    }

    @Override
    public void run() {
        sum.addAndGet((int) (matrix.getElement(0, j) * Math.pow(-1, j) * matrix.getSubmatrix(j).calculateDeterminant()));
    }
}