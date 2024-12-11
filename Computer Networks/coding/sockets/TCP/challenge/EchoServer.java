/*
 * EchoServer.java
 */
import java.net.*;
import java.io.*;

public class EchoServer {
    public static final Integer SERVER_PORT = 1050;
    public static final Integer TIMEOUT_SECONDS = 10 * 1000;

    public static void main(String[] args) {
        
        Socket serverSocket;

        try (ServerSocket serverListeningSocket = new ServerSocket(SERVER_PORT);){
            serverListeningSocket.setSoTimeout(TIMEOUT_SECONDS);
            while(true) {
                serverSocket = serverListeningSocket.accept();	
                Thread clienThread = new Thread(new ClientSideInServer(serverSocket));
                clienThread.start();
            }   
        } catch (IOException e) {
            System.err.println("Erro: " + e.getMessage());
        }             
    }
}