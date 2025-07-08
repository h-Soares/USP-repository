public class Main {
    public static void main(String[] args) {
        int size = 10;
        BoundedBuffer<Integer> boundedBuffer = new BoundedBuffer<>(size);

        for(int i = 1; i <= 3; i++) {
            Thread producer = new Thread(new ProducerThread1(boundedBuffer, size));
            Thread consumer = new Thread(new ConsumerThread1(boundedBuffer, size));
            producer.start();
            consumer.start();
        }
    }
}