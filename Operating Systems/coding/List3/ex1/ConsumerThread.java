package List3.ex1;

public class ConsumerThread implements Runnable {
    private BoundedBuffer<String> boundedBuffer;
    private int toConsumeLength;

    public ConsumerThread(BoundedBuffer<String> boundedBuffer, int toConsumeLength) {
        this.boundedBuffer = boundedBuffer;
        this.toConsumeLength = toConsumeLength;
    }

    @Override
    public void run() {
        for(int i = 1; i <= toConsumeLength; i++)
            boundedBuffer.remove();
    }   
}