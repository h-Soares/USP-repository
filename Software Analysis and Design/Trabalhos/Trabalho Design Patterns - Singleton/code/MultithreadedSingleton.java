import java.util.Objects;

public class MultithreadedSingleton {
    private static MultithreadedSingleton multithreadedSingleton;
    private int value;

    private MultithreadedSingleton(int value) {
        this.value = value;
    }

    public static synchronized MultithreadedSingleton getInstance(int value) {
        if(Objects.isNull(multithreadedSingleton))
            multithreadedSingleton = new MultithreadedSingleton(value);
        return multithreadedSingleton;
    }  

    public int getValue() {
        return value;
    }
}