package List3.ex3;

import List3.ex1.MySemaphoreImpl;

//I chose not to work with files...
public class PrintSpooler {
    private String spoolFile; //File to write jobs...
    private boolean is_open;
    private MySemaphoreImpl mutex;

    public PrintSpooler(String spoolFile) {
        this.spoolFile = spoolFile;
        this.is_open = false;
        mutex = new MySemaphoreImpl(1);
    }

    public boolean openPrintSpooler() {
        is_open = true;
        System.out.println("SPOOLER OPENED WITH THE FILE NAME: " + getSpoolFile());
        return is_open;
    }

    public void printJob(String jobName) {
        if(!is_open)
            throw new IllegalStateException("Spooler is not open!");

        mutex.down();
        System.out.println("Printing file " + jobName + "...");
        mutex.up();
    }

    public void closePrintSpooler() {
        is_open = false;
        System.out.println("SPOOLER " + getSpoolFile() + " CLOSED");
    }

    public String getSpoolFile() {
        return this.spoolFile;
    }
}