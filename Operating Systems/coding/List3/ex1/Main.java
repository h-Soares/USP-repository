package List3.ex1;

public class Main {
    public static void main(String[] args) {
        BoundedBuffer<String> boundedBuffer = new BoundedBuffer<>(args.length);
        Thread producer = new Thread(new ProducerThread(boundedBuffer, args));
        Thread consumer = new Thread(new ConsumerThread(boundedBuffer, args.length));
        producer.start();
        consumer.start();
    }
}
