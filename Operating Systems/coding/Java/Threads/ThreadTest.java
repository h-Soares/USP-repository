public class ThreadTest implements Runnable {

    private int number;

    public ThreadTest(int number) {
        this.number = number;
    }

    @Override
    public void run() {
        if(isPrime())
            System.out.println("%d is prime!".formatted(number));
        else
            System.out.println("%d is not prime!".formatted(number));
    }

    private boolean isPrime() {
        if (number <= 1) 
            return false;

        for (int i = 2; i <= Math.sqrt(number); i++) {
            if (number % i == 0)
                return false;
        }
        return true;
    }
}