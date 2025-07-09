import java.util.Objects;

public class SimpleSingleton {
    private static SimpleSingleton simpleSingleton;
    private int value;

    private SimpleSingleton(int value) {
        this.value = value;
    }

    public static SimpleSingleton getInstance(int value) {
        if(Objects.isNull(simpleSingleton))
            simpleSingleton = new SimpleSingleton(value);
        return simpleSingleton;
    }  
    
    public int getValue() {
        return value;
    }
}