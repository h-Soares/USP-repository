/*
 * EchoClient.java
 */
import java.util.Scanner;
import java.io.*;
import java.net.*;

public class EchoClient {
    public static final Integer SERVER_PORT = 1050;
   
    public static void main(String[] args) {

		// declaracao das variaveis
        Socket echoSocket;          // Socket TCP cliente
		BufferedReader in;			// Entrada(recepcao) formatada de dados
		PrintWriter out;			// Saida (envio) formatado de dados
        //Scanner stdIn;       		// Fluxo de entrada de dados via teclado
        String message;           	// Mensagem do usuario

		// verifica quantidade de argumentos
        if (args.length != 1){
            System.err.println("Erro: informe o endereço IP do servidor");
            System.exit(0);
        }
        
        try (Scanner stdIn = new Scanner(System.in);){ // abre fluxo de entrada de dados via teclado 
			
            // abre socket TCP cliente na porta 1050
            echoSocket = new Socket(args[0], SERVER_PORT);
            System.out.println("CLIENT SOCKET PORT: " + echoSocket.getLocalPort());

            // abre fluxos de entrada e saida de dados PARA O SOCKET
            in = new BufferedReader(new InputStreamReader(echoSocket.getInputStream()));
            out = new PrintWriter(echoSocket.getOutputStream(), true);
	
            // le mensagem de requisicao, envia mensagem de requisicao e recebe mensagem de resposta
            System.out.print("Para servidor -> ");
            message = stdIn.nextLine();
            if (message != null){
                out.println(message);
                System.out.println("Mensagem do servidor: " + in.readLine());
            }

            // fecha fluxos de entrada e saida de dados
            in.close();
            out.close();

            // fecha socket TCP cliente
            echoSocket.close();      
        } catch (IOException e) {
            System.err.println("Erro: " + e);
        }         
    }    
}