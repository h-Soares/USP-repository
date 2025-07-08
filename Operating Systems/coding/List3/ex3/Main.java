package List3.ex3;

import java.util.LinkedList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        PrintSpooler printSpooler = new PrintSpooler("spooler-file.txt");
        List<Thread> threads = new LinkedList<>();
        int jobsNumber = 5;

        if(!printSpooler.openPrintSpooler())
            throw new IllegalStateException("Error opening");

        for(int i = 1; i <= jobsNumber; i++) {
            Thread thread = new Thread(new JobThread("file" + i + ".txt", printSpooler));
            threads.add(thread);
            thread.start();
        }

        for(Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        printSpooler.closePrintSpooler();
    }
}