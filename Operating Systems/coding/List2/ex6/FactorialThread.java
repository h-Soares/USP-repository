package List2.ex6;

import java.math.BigInteger;

public class FactorialThread implements Runnable {
    private BigInteger number;

    public FactorialThread(BigInteger number) {
        this.number = number;
    }

    @Override
    public void run() {
        System.out.printf("Thread %d: %s! = %s%n", Thread.currentThread().getId(), number, factorial(number));     
    }

    private BigInteger factorial(BigInteger number) {
        if(number.compareTo(BigInteger.ZERO) == 0 || number.compareTo(BigInteger.ONE) == 0)
            return BigInteger.ONE;
        return number.multiply(factorial(number.subtract(BigInteger.ONE)));
    } 
}