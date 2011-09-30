/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author ericsoros
 */
public class ClientConnectionThread extends Thread {
    
   Socket clientSocket;
   int ID;
   String username;
   
   public ClientConnectionThread(Socket clientSocket, int ID) 
   {
       this.clientSocket = clientSocket;
       this.ID = ID;
   }
   
   public void run()
   {
       ObjectInputStream in = null;
       ObjectOutputStream out = null;
        
       try {
           
           in = new ObjectInputStream(clientSocket.getInputStream());
           out = new ObjectOutputStream(clientSocket.getOutputStream());
			
			//add the client's output stream to the list.        	
		   ChatServer.clientOutputs.add(out);
		   //prompt the user for a username
           out.writeObject("Enter a username");
		   out.flush();
           //get usernmae from the client
           username = (String) in.readObject();
           
           System.out.println("Client Accecpted: "+clientSocket.getInetAddress()+" "+ID+" "+username);
           ClientConnectionInputThread inputThread = new ClientConnectionInputThread(in);
           inputThread.start();
        
         } catch (ClassNotFoundException ex) {
            //Logger.getLogger(ClientConnectionThread.class.getName()).log(Level.SEVERE, null, ex);
         } catch (IOException ex) {
         Logger.getLogger(ClientConnectionThread.class.getName()).log(Level.SEVERE, null, ex);
            }
   }


}
