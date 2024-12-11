import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class ClientSideOnServerThread implements Runnable {

    private Socket serverSocket;

    public ClientSideOnServerThread(Socket serverSocket) {
        this.serverSocket = serverSocket;
    }

    @Override
    public void run() {
            try {
                // abre fluxos de entrada e saida de dados associados ao socket TCP de comunicacao com o cliente
                BufferedReader in = new BufferedReader(new InputStreamReader(serverSocket.getInputStream()));
                PrintWriter out = new PrintWriter(serverSocket.getOutputStream(), true);
                
                // recebe mensagem de requisicao, escreve mensagem de requisicao e envia mensagem de resposta		
                System.out.println("Servidor pronto, cliente conectado ! PORTA DO CLIENTE: " + serverSocket.getPort() + ", porta do servidor: " + serverSocket.getLocalPort());
                String message = in.readLine();
                if (message != null) {
                    System.out.println("Mensagem do cliente -> " + message);
                    out.println(message.toUpperCase());		// envia mensagem de volta para o cliente
                }
                    
                // fecha fluxos de entrada e saida de dados
                out.close();
                in.close();

                // fecha sockets TCP de comunicacao do servidor com o cliente e TCP de conexão do servidor
                serverSocket.close();       
            }catch(IOException e) {
                System.out.println(e.getMessage());
            }
    }
}