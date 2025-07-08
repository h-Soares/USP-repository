public class ConsumerThread1 implements Runnable {
    private BoundedBuffer<Integer> boundedBuffer;
    private int length;

    public ConsumerThread1(BoundedBuffer<Integer> boundedBuffer, int length) {
        this.boundedBuffer = boundedBuffer;
        this.length = length;
    }
    
    @Override
    public void run() {
        for(int i = 1; i <= length; i++)
            boundedBuffer.remove();
    }
}