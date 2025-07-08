public class ProducerThread2 implements Runnable {
    private BoundedBuffer<String> boundedBuffer;
    private String[] stringArray;

    public ProducerThread2(BoundedBuffer<String> boundedBuffer, String[] stringArray) {
        this.boundedBuffer = boundedBuffer;
        this.stringArray = stringArray;
    }

    @Override
    public void run() {
        for(int i = 0; i < stringArray.length; i++)
            boundedBuffer.insert(stringArray[i]);
    }   
}