import java.io.IOException;

public class ProcessBuilderTest {
    public static void main(String[] args) throws IOException {
        ProcessBuilder processBuilder = new ProcessBuilder("notepad.exe");
        processBuilder.start();
    }
}   