package JAVA;

import java.io.IOException;

public class Processes {
    public static void main(String[] args) {
        //FAZER PARA CHAMAR FIBO !
        ProcessBuilder pb = new ProcessBuilder("ls", "-l");
        try {
            pb.inheritIO(); //filho herdará entrada/saída padrão como sendo as do pai (escreverá resultado no terminal)
            Process process = pb.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}