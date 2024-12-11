/*
 * EchoServer.java
 */
import java.net.*;
import java.io.*;

public class EchoServer {
    public static final Integer SERVER_PORT = 1050;
    
    public static void main(String[] args) {
        
		// declaracao das variaveis
        Socket serverSocket;            // Socket TCP de comunicacao com o cliente
        String message;               	// Mensagem enviada pelo cliente
		BufferedReader in;				// Entrada(recepcao) formatada de dados
		PrintWriter out;				// Saida (envio) formatado de dados

        try (ServerSocket serverListeningSocket = new ServerSocket(SERVER_PORT);){
            serverSocket = serverListeningSocket.accept();	// cria socket TCP de comunicacao do servidor com o cliente
            
            // abre fluxos de entrada e saida de dados associados ao socket TCP de comunicacao com o cliente
            in = new BufferedReader(new InputStreamReader(serverSocket.getInputStream()));
            out = new PrintWriter(serverSocket.getOutputStream(), true);
            
            message = in.readLine();
            if (message != null) {
                Double value = doOperations(message);
                out.println(value);		// envia mensagem de volta para o cliente
            }
                
            // fecha fluxos de entrada e saida de dados
            out.close();
            in.close();

            // fecha sockets TCP de comunicacao do servidor com o cliente e TCP de conexão do servidor
            serverSocket.close();     
        } catch (IOException e) {
            System.err.println("Erro: " + e);
        }             
    }
    public static Double doOperations(String message) {
        String[] parts = message.split(" ");
        System.out.println("TESTANDO SE message MUDOU: " + message); //testar se message mudou

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