package List2.ex5;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        if(args.length == 0)
            throw new IllegalArgumentException("Enter one or more numbers");

        int[] numbers = Arrays.stream(args).mapToInt(Integer::parseInt).toArray();
        quickSort(numbers);
        System.out.println(Arrays.toString(numbers));      
    }

    private static void quickSort(int[] array) {
        Thread thread = new Thread(new QuicksortThread(array, 0, array.length - 1));
        thread.start();

        try {
            thread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}