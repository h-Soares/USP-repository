public class ProducerThread1 implements Runnable {
    private BoundedBuffer<Integer> boundedBuffer;
    private int length;

    public ProducerThread1(BoundedBuffer<Integer> boundedBuffer, int length) {
        this.boundedBuffer = boundedBuffer;
        this.length = length;
    }

    @Override
    public void run() {
        for(int i = 1; i <= length; i++) {
            Integer min = 1;
            Integer max = length; 
            Double number = Math.floor(Math.random() *(max - min + 1) + min);
            boundedBuffer.insert(number.intValue()); 
        }
    }
}