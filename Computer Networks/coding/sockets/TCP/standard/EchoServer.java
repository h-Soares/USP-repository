/*
 * EchoServer.java
 */
import java.net.*;
import java.io.*;

public class EchoServer {
    public static final Integer SERVER_PORT = 1050;
    
    public static void main(String[] args) {
        
		// declaracao das variaveis
        ServerSocket serverListeningSocket;      // Socket TCP servidor (para conexao)
        Socket serverSocket;            // Socket TCP de comunicacao com o cliente
        String message;               	// Mensagem enviada pelo cliente
		BufferedReader in;				// Entrada(recepcao) formatada de dados
		PrintWriter out;				// Saida (envio) formatado de dados

        /* COM WHILE-TRUE NÃO FUNCIONA PORQUE ESSE PROCESSO É UM PROCESSO DE APENAS UMA THREAD, E SÓ IRA TRATAR DE OUTRAS 
        REQUISIÇÕES QUANDO VOLTAR DO LOOP E ATINGIR serverSocket = serverListeningSocket.accept() !!! 
        ENTÃO: USAR THREADS. PARECE QUE ESCUTA MAS DIRECIONA TUDO PARA APENAS UM SOCKET: O SOCKET DE ESCUTA (????) 
        AO QUE PARECE SER: O SOCKET DE ESCUTA APENAS ESCUTA EM UMA PORTA PARA CRIAR UM SOCKET NESSA PORTA AO ACEITAR */
        try {
            // abre socket TCP de conexão do servidor
            serverListeningSocket = new ServerSocket(SERVER_PORT);
            System.out.println("PORTA DO SOCKET DE ESCUTA DO SERVIDOR: " + serverListeningSocket.getLocalPort());

            // espera por requisicao de conexao enviada pelo socket cliente
            serverSocket = serverListeningSocket.accept();	// cria socket TCP de comunicacao do servidor com o cliente
            System.out.println("PORTA DO SOCKET CRIADO NO SERVIDOR PARA A PORTA DO SOCKET DO CIENTE: " + serverSocket.getPort() + ": " + serverSocket.getLocalPort());

            // abre fluxos de entrada e saida de dados associados ao socket TCP de comunicacao com o cliente
            in = new BufferedReader(new InputStreamReader(serverSocket.getInputStream()));
            out = new PrintWriter(serverSocket.getOutputStream(), true);
            
			// recebe mensagem de requisicao, escreve mensagem de requisicao e envia mensagem de resposta		
            System.out.println("Servidor pronto, cliente conectado ! PORTA DO CLIENTE: " + serverSocket.getPort());
            System.out.println(serverSocket.getLocalPort());
            message = in.readLine();
            if (message != null) {
                System.out.println("Mensagem do cliente -> " + message);
                out.println(message.toUpperCase());		// envia mensagem de volta para o cliente
            }
                
            // fecha fluxos de entrada e saida de dados
            out.close();
            in.close();

            // fecha sockets TCP de comunicacao do servidor com o cliente e TCP de conexão do servidor
            serverSocket.close();
            //serverListeningSocket.close();      
        } catch (IOException e) {
            System.err.println("Erro: " + e);
        }             
    }
}