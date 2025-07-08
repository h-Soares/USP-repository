package List2.ex1;

import java.util.concurrent.atomic.AtomicInteger;

public class ReverseHelloDot1 implements Runnable {
    private AtomicInteger atomicInteger;
    
    public ReverseHelloDot1(AtomicInteger atomicInteger) {
        this.atomicInteger = atomicInteger;
    }

    @Override
    public void run() {
        if(atomicInteger.get() <= 50) {
            int currentThreadInt = atomicInteger.getAndIncrement();
            Thread thread = new Thread(new ReverseHelloDot1(atomicInteger));
            thread.start();

            try {
                thread.join();
                System.out.printf("Olá da Thread %d!!!%n", currentThreadInt);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}