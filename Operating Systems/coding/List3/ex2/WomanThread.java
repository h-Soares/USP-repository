package List3.ex2;

import java.util.concurrent.ThreadLocalRandom;

public class WomanThread implements Runnable {
    private Toalete toalete;
    private String name;

    public WomanThread(Toalete toalete, String name) {
        this.toalete = toalete;
        this.name = name;
    }

    @Override
    public void run() {
        long seconds = ThreadLocalRandom.current().nextLong(1, 4) * 1000;
        try {
            Thread.sleep(seconds);
        } catch (InterruptedException e) {
            e.printStackTrace();
            System.exit(-1);
        }
        toalete.mulherQuerEntrar(name);

        seconds = ThreadLocalRandom.current().nextLong(1, 4) * 1000;
        try {
            Thread.sleep(seconds);
        } catch (InterruptedException e) {
            e.printStackTrace();
            System.exit(-1);
        }
        toalete.mulherSaiToalete(name);
    }    
}