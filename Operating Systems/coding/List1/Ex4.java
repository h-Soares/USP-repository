package List1;

import java.io.IOException;
import java.util.List;

public class Ex4 {
    public static void main(String[] args) throws IOException {
        try {
            List<String> list = List.of(args);
            ProcessBuilder processBuilder = new ProcessBuilder(list);
            processBuilder.inheritIO();
            processBuilder.start();
        }catch(IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
