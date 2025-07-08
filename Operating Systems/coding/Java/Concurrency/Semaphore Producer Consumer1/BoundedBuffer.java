/*
 * BoundedBuffer.java
 * 
 */

import java.util.concurrent.Semaphore;

public class BoundedBuffer<E> implements Buffer<E>{
    
    private int in;             // aponta para próxima posição livre
    private int out;            // aponta próxima posição cheia
    private E[] buffer;    		// buffer
    private Semaphore empty;
    private Semaphore mutex;
    private Semaphore full;
    
    @SuppressWarnings("unchecked")
    public BoundedBuffer(int size){
        in = 0;
        out = 0;
        buffer = (E[]) new Object[size];
        empty = new Semaphore(size);
        mutex = new Semaphore(1);
        full = new Semaphore(0);
    }

    public void insert(E item){
        try {
            empty.acquire();
            mutex.acquire();
            buffer[in] = item;
            in = (in + 1) % buffer.length;
            System.out.println("Inserted item: %s".formatted(item));
            mutex.release();
            full.release();  
        }catch(InterruptedException e) {
            e.printStackTrace();
        }
    }
    
    public E remove(){
        E item;
        
        try {
            full.acquire();
            mutex.acquire();
            item = buffer[out];
            out = (out + 1) % buffer.length;
            System.out.println("Removed item: %s".formatted(item)); 
            mutex.release();
            empty.release(); 
            return item;  
        }catch(InterruptedException e) {
            throw new IllegalAccessError(e.getMessage());
        }
    }
}