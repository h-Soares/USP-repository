package List3.ex1;

public class MySemaphoreImpl implements MySemaphore {
    private int counter;

    public MySemaphoreImpl(int counter) {
        this.counter = counter;
    }

    @Override
    public synchronized void down() {
        while(counter <= 0) {
            try {
                wait();
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
                System.exit(-1);
            }
        }
        counter--;
    }

    @Override
    public synchronized void up() {
        counter++;
        notifyAll();
    }   
}