package List2.ex5;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class QuicksortThread implements Runnable {
    private int[] arrayInt;
    private int left, right;

    public QuicksortThread(int[] arrayInt, int left, int right) {
        this.arrayInt = arrayInt;
        this.left = left;
        this.right = right;
    }

    @Override
    public void run() {
        quickSort(arrayInt, left, right);
    }

    private void quickSort(int array[], int left, int right) {
        int i, j, x, y;
        ExecutorService executorService = Executors.newCachedThreadPool();
    
        i = left;
        j = right;
        x = array[(left + right) / 2];
    
        while (i <= j) {
            while (array[i] < x && i < right) {
                i++;
            }
            while (array[j] > x && j > left) {
                j--;
            }
            if (i <= j) {
                y = array[i];
                array[i] = array[j];
                array[j] = y;
                i++;
                j--;
            }
        }
    
        if (j > left) {
            executorService.execute(new Thread(new QuicksortThread(array, left, j)));
        }
    
        if (i < right) {
            executorService.execute(new Thread(new QuicksortThread(array, i, right)));
        }
        
        executorService.shutdown();
        try {
            executorService.awaitTermination(1, TimeUnit.MINUTES);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }        
    }   
}