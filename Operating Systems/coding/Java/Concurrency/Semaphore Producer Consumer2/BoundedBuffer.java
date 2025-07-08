/*
 * BoundedBuffer.java
 * 
 */

import java.util.Objects;
import java.util.concurrent.Semaphore;

public class BoundedBuffer<E> implements Buffer<E>{
    
    private int in;             // aponta para próxima posição livre
    private int out;            // aponta próxima posição cheia
    private E[] buffer;    		// buffer
    private Semaphore full, empty, mutex;
    
    @SuppressWarnings("unchecked")
    public BoundedBuffer(int size){
        in = 0;
        out = 0;
        buffer = (E[]) new Object[size];
        full = new Semaphore(0);
        empty = new Semaphore(size);
        mutex = new Semaphore(1);
    }

    public void insert(E item){
        try {
            empty.acquire();
            mutex.acquire();
            buffer[in] = item;
            in = (in + 1) % buffer.length;
            System.out.println("Item " + item + " inserted!");
            mutex.release();
            full.release();
        } catch(InterruptedException e) {
            System.out.println(e.getMessage());
        }
    }
    
    public E remove(){
        E item = null;
        
        try {
            full.acquire();
            mutex.acquire();
            item = buffer[out];
            out = (out + 1) % buffer.length;
            System.out.println("Item " + item + " removed!");
            mutex.release();
            empty.release();
        } catch(InterruptedException e) {
            System.out.println(e.getMessage());
            System.exit(0);
        }

        if(Objects.isNull(item))
            throw new IllegalStateException("Item is null");
        return item;
    }
}