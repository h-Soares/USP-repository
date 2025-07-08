public class ConsumerThread2 implements Runnable {
    private BoundedBuffer<String> boundedBuffer;
    private int toConsumeLength;

    public ConsumerThread2(BoundedBuffer<String> boundedBuffer, int toConsumeLength) {
        this.boundedBuffer = boundedBuffer;
        this.toConsumeLength = toConsumeLength;
    }

    @Override
    public void run() {
        for(int i = 1; i <= toConsumeLength; i++)
            boundedBuffer.remove();
    }   
}
