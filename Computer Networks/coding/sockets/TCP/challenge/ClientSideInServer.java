import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class ClientSideInServer implements Runnable {

    private Socket serverSocket;

    public ClientSideInServer(Socket serverSocket) {
        this.serverSocket = serverSocket;
    }

    @Override
    public void run() {
        try {
            System.out.println("SERVIDOR: " + serverSocket.getLocalAddress() + " PORTA NO SERVIDOR: " + serverSocket.getLocalPort());
            System.out.println("CLIENTE: " + serverSocket.getInetAddress() + " PORTA NO CLIENTE: " + serverSocket.getPort());

            BufferedReader in = new BufferedReader(new InputStreamReader(serverSocket.getInputStream()));
            PrintWriter out = new PrintWriter(serverSocket.getOutputStream(), true);
                
            String message = in.readLine();
            while(message != null && !message.toLowerCase().equals("exit")) {
                Double value = doOperations(message);
                out.println(value);
                message = in.readLine();
            }

            out.close();
            in.close();

            serverSocket.close();       
        } catch(IOException e) {
            System.out.println(e.getMessage());
        }
    }   

    public Double doOperations(String message) {
        String[] parts = message.split(" ");

        if(parts.length != 3) {
            System.err.println("Erro: entre com uma operação correta! ");
            System.exit(0);
        }

        switch(parts[1].toLowerCase()) {
            case "plus":
                return Double.parseDouble(parts[0]) + Double.parseDouble(parts[2]);
            case "div":
                return Double.parseDouble(parts[0]) / Double.parseDouble(parts[2]);
            case "minus":
                return Double.parseDouble(parts[0]) - Double.parseDouble(parts[2]);
            case "times":
                return Double.parseDouble(parts[0]) * Double.parseDouble(parts[2]);
            default:
                throw new IllegalArgumentException("Erro: entre com uma operação correta! ");
        }
    }
}