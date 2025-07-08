package List3.ex3;

import java.util.concurrent.ThreadLocalRandom;

public class JobThread implements Runnable {
    private String jobName;
    private PrintSpooler printSpooler;

    public JobThread(String jobName, PrintSpooler printSpooler) {
        this.jobName = jobName;
        this.printSpooler = printSpooler;
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
        printSpooler.printJob(jobName);
    }    
}