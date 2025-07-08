package List3.ex1;
/*
 * BoundedBuffer.java
 * 
 */

import java.util.Objects;

public class BoundedBuffer<E> implements Buffer<E>{
    
    private int in;             // aponta para próxima posição livre
    private int out;            // aponta próxima posição cheia
    private E[] buffer;    		// buffer
    private MySemaphore full, empty, mutex;
    
    @SuppressWarnings("unchecked")
    public BoundedBuffer(int size){
        in = 0;
        out = 0;
        buffer = (E[]) new Object[size];
        full = new MySemaphoreImpl(0);
        empty = new MySemaphoreImpl(size);
        mutex = new MySemaphoreImpl(1);
    }

    public void insert(E item){
        empty.down();
        mutex.down();
        buffer[in] = item;
        in = (in + 1) % buffer.length;
        System.out.println("Item " + item + " inserted!");
        mutex.up();
        full.up();
    }
    
    public E remove(){
        E item = null;
        
        full.down();
        mutex.down();
        item = buffer[out];
        out = (out + 1) % buffer.length;
        System.out.println("Item " + item + " removed!");
        mutex.up();
        empty.up();

        if(Objects.isNull(item))
            throw new IllegalStateException("Item is null");
        return item;
    }
}