public class MultithreadedApp2 {
    public static void main(String[] args) {
        System.out.println("Se ocorrer o mesmo valor: SINGLETON FUNCIONOU!");
        System.out.println("Se ocorrerem valores diferentes: PROBLEMA!");

        Thread thread1930 = new Thread(new Thread1930());
        Thread thread1910 = new Thread(new Thread1910());
        thread1930.start();
        thread1910.start();
    }

    static class Thread1930 implements Runnable {
        
        @Override
        public void run() {
            MultithreadedSingleton singleton = MultithreadedSingleton.getInstance(1930);
            System.out.println(singleton.getValue());
        }   
    }

    static class Thread1910 implements Runnable {

        @Override
        public void run() {
            MultithreadedSingleton singleton = MultithreadedSingleton.getInstance(1910);
            System.out.println(singleton.getValue());
        }   
    }
}