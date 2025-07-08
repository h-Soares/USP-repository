package List2.ex6;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class Main {
    public static void main(String[] args) {
        if(args.length == 0)
            throw new IllegalArgumentException("Enter one or more numbers");

        List<BigInteger> numbers = Arrays.stream(args).map(BigInteger::new).toList();
        ExecutorService executorService = Executors.newFixedThreadPool(args.length);

        numbers.forEach(number -> executorService.execute(new FactorialThread(number)));
        executorService.shutdown();
        try {
            executorService.awaitTermination(1, TimeUnit.MINUTES);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}