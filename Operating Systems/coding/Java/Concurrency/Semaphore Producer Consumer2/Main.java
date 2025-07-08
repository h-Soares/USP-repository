public class Main {
    public static void main(String[] args) {
        BoundedBuffer<String> boundedBuffer = new BoundedBuffer<>(args.length);
        Thread producer = new Thread(new ProducerThread2(boundedBuffer, args));
        Thread consumer = new Thread(new ConsumerThread2(boundedBuffer, args.length));
        producer.start();
        consumer.start();
    }
}
