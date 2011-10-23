/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package chatclientgui;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
 
/**
 *
 * @author ericsoros
 */
public class ChatClientGUI {

    /**
     * @param args the command line arguments
     */
    public static ChatClientForm form;
    public static ObjectOutputStream out;
    public static String username;
    
    public static void main(String[] args) throws ClassNotFoundException, InterruptedException {
        
        //ObjectOutputStream out = null;
        //ObjectInputStream in = null;
        Socket socket = null;
        BufferedReader userInput = new BufferedReader(
			 	new InputStreamReader(System.in));
        
        ObjectInputStream in = null;
                
        //try to connect to the server
        try {
            socket = new Socket("127.0.0.1",4444);
            
            out = new ObjectOutputStream(socket.getOutputStream());
            in = new ObjectInputStream(socket.getInputStream());
          
            System.out.println("Succesfully Connected to the Server"); 
	    //get prompt for username from the server    
            System.out.println(in.readObject());           

            username = userInput.readLine();    
	    //write the Input to the server
	    out.writeObject(username);
	    out.flush();	
	  
            //client = new Client(username,in,out,socket.getInetAddress().toString());
            
            //make a thread for getting input from the server.
	    ChatClientMessageThread inputThread = new ChatClientMessageThread(in);
	    inputThread.start();
           
            //once everything is connected, than display the GUI
            System.out.println("Launching GUI....");
            form = new ChatClientForm();
            form.setVisible(true);
           
	  
	 } catch (IOException e) {
            System.out.println("Unable to Connect to host...");
            System.exit(-1);
        }
    
    }
}
