package List2.ex1;

import java.util.concurrent.atomic.AtomicInteger;

public class ReverseHello {
    private static final Integer INICIAL_VALUE = 1;
    public static void main(String[] args) {
        AtomicInteger atomicInteger = new AtomicInteger(INICIAL_VALUE);

        Thread thread = new Thread(new ReverseHelloDot1(atomicInteger));
        thread.start();
        try {
            thread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}