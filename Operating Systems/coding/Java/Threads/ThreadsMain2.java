public class ThreadsMain2 {
    //TO USE: Compile(javac) and Run (java)
    public static void main(String[] args) throws Exception {
        if(args.length <= 0)
            throw new IllegalArgumentException("One or more numbers!");

        Thread thread = null;
        for(int i = 0; i < args.length; i++) {
            thread = new Thread(new ThreadTest(Integer.parseInt(args[i])));
            thread.start();
        }
        System.out.println("Active threads: " + Thread.activeCount());
    }
}