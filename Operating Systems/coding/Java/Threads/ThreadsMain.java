public class ThreadsMain {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(new ThreadTest(10));

        System.out.println("Testing1");
        System.out.println(Thread.activeCount());

        thread.start();
        System.out.println(Thread.activeCount());
        System.out.println(Thread.activeCount());

        System.out.println("Testing2");
        System.out.println(Thread.activeCount());
    }
}