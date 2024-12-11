/*
 * EchoServer.java
 */
import java.net.*;
import java.io.*;

public class EchoServer {
    public static final Integer SERVER_PORT = 1050;
    public static final Integer TIMEOUT_SECONDS = 10 * 1000; 
    
    public static void main(String[] args) {
        Socket serverSocket;            // Socket TCP de comunicacao com o cliente
        
        try (ServerSocket serverListeningSocket = new ServerSocket(SERVER_PORT);){ // abre socket TCP de conexão listening do servidor
            serverListeningSocket.setSoTimeout(TIMEOUT_SECONDS);
            System.out.println("PORTA DO SOCKET DE ESCUTA DO SERVIDOR: " + serverListeningSocket.getLocalPort());

            while(true) {
                serverSocket = serverListeningSocket.accept();	// cria socket TCP de comunicacao do servidor com o cliente
                System.out.println("PORTA DO SOCKET CRIADO NO SERVIDOR PARA A PORTA DO SOCKET DO CIENTE: " + serverSocket.getPort() + ": " + serverSocket.getLocalPort()); 
                Thread thread = new Thread(new ClientSideOnServerThread(serverSocket));
                thread.start();   
            }

        } catch (IOException e) {
            System.err.println("Erro: " + e.getMessage());
        }         
    }
}