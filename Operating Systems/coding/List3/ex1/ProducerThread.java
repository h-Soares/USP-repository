package List3.ex1;

public class ProducerThread implements Runnable {
    private BoundedBuffer<String> boundedBuffer;
    private String[] stringArray;

    public ProducerThread(BoundedBuffer<String> boundedBuffer, String[] stringArray) {
        this.boundedBuffer = boundedBuffer;
        this.stringArray = stringArray;
    }

    @Override
    public void run() {
        for(int i = 0; i < stringArray.length; i++)
            boundedBuffer.insert(stringArray[i]);
    }   
}