/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.List;
import java.util.LinkedList;
import java.io.ObjectOutputStream;
/**
 *
 * @author ericsoros
 */
public class ChatServer {

    /**
     * @param args the command line arguments
     */
    public static LinkedBlockingQueue<Message> messagesToSend = new LinkedBlockingQueue();
    public static List<ObjectOutputStream> clientOutputs = new LinkedList<ObjectOutputStream>();

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        ServerSocket server = null;
        Socket clientSocket = null;
        
        server = new ServerSocket(4444);
        System.out.println("Listening for clients on port 4444");

        //start the output thread
		ChatServerOutputThread outputThread = new ChatServerOutputThread();
		outputThread.start();
        
        int ID = 0;
        //look for clients trying to connect
        while (true) {
            
            clientSocket = server.accept();
            ClientConnectionThread thread = new ClientConnectionThread(clientSocket,++ID);
            thread.start();
        }
    
    }
}
