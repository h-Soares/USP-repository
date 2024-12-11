/*
 * EchoClient.java
 */
import java.io.*;
import java.net.*;
import java.util.Scanner;

public class EchoClient {
	public static final Integer SERVER_PORT = 1050;
    
    public static void main(String[] args) {
        
        DatagramSocket datagram;    	// socket de datagrama
        InetAddress address;        	// endereco IP do socket servidor
        DatagramPacket sendingPacket;   // pacote sendo enviado
        DatagramPacket responsePacket;  // pacote sendo recebido
        
		//Scanner stdIn;       		// leitura de dados
        byte[] buffer;              // buffer de dados
		String message;				// mensagem enviada/recebida
        
		// verifica quantidade de argumentos
        if (args.length != 1){
            System.err.println("Erro: informe o endereço IP do servidor");
            System.exit(0);
        }
            
        try (Scanner stdIn = new Scanner(System.in);) { // abre fluxo de entrada de dados via teclado 
			
			// abre socket de datagrama
			datagram = new DatagramSocket();

			// le mensagem de requisicao
			System.out.print("Mensagem -> ");
			message = stdIn.nextLine();

			// cria datagrama para armazenar mensagem de requisicao
			buffer = message.getBytes();
			address = InetAddress.getByName(args[0]);
			sendingPacket = new DatagramPacket(buffer, buffer.length, address, SERVER_PORT);

			// envia datagrama contendo mensagem de requisicao
			System.out.println("Envia requisicao...");
			datagram.send(sendingPacket);

			// cria datagrama para armazenar mensagem de resposta
			buffer = new byte[256];
			responsePacket = new DatagramPacket(buffer, buffer.length);
			
			// recebe datagrama contendo mensagem de resposta
			System.out.println("Recebe resposta...");
			datagram.receive(responsePacket);

			// imprime mensagem de resposta
			message = new String(responsePacket.getData()).trim();
			System.out.println("Resposta -> " + message);

			// fecha socket de datagrama
			datagram.close();
        } catch(IOException e){
            System.err.println("Erro: " + e);
        }
    }
}