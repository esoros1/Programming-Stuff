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
    
   int ID;
   Client client;
   
   //parse a Socket and make a client class. 
   //the username is default and will be changed if the connection to the server is successful. 
   public ClientConnectionThread(Socket clientSocket, int ID) 
   {
	   try {
       client = new Client("default",new ObjectInputStream(clientSocket.getInputStream()), 
       									new ObjectOutputStream(clientSocket.getOutputStream()),
       										clientSocket.getInetAddress().toString());
       this.ID = ID;
	   } catch (IOException e) {
	   	 System.out.println("Problem making connection to Client..");
		 //stop the thread. I'm not sure if this is safe
		 //Actually, I'm almost certain this isn't safe
		 stop();
	  }

   }
   
   public void run()
   {
       ObjectInputStream in = client.getInputStream();
       ObjectOutputStream out = client.getOutputStream();
        
       try {
           	
			//add the client's output stream to the list.        	
		   ChatServer.clients.add(client);
		   //prompt the user for a username
           out.writeObject("Enter a username");
		   out.flush();
           //get usernmae from the client
           String username = (String) in.readObject();
		   client.setUsername(username);
           //Print out information about the connection, and than start a thread that looks for inputs. 
           System.out.println("Client Accecpted: "+client);

		  //look for messages being sent from the client
		  Message message = null;
		  while (true) {
				message = (Message) in.readObject();				
				ChatServer.messagesToSend.add(message);
		  }
           
         } catch (ClassNotFoundException ex) {
            //Logger.getLogger(ClientConnectionThread.class.getName()).log(Level.SEVERE, null, ex);
         } catch (IOException ex) {
         	System.out.println("Lost Connection to Client...");
         	//remove the client from the list of clients
         	ChatServer.clients.remove(client);
         }
   }


}
