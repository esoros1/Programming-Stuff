/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package sockettest;

import java.net.Socket;
import java.util.Scanner;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class ChatClient {
    
    public static void main(String [] args) throws ClassNotFoundException {
        ObjectOutputStream out = null;
        ObjectInputStream in = null;
        Socket socket = null;
        BufferedReader userInput = new BufferedReader(
			 	new InputStreamReader(System.in));
        
        //try to connect to the server
        try {
            socket = new Socket("10.12.108.93",4444);
            out = new ObjectOutputStream(socket.getOutputStream());
            in = new ObjectInputStream(socket.getInputStream());
          
            System.out.println("Connected"); 
	       //get prompt for username from the server    
           System.out.println(in.readObject());           

            String username = userInput.readLine();    
	        //write the Input to the server
	  		 out.writeObject(username);
	  		 out.flush();	
	  
			//make a thread for getting input from te server.
			ChatClientInputThread inputThread = new ChatClientInputThread(in);
			inputThread.start();
           //get input from the server, and send it as a message to the server  
	   		while (true) {
	   			//System.out.println("Enter a message to send to the server");
				String s = userInput.readLine();
				out.writeObject(new Message(s,username));		
       	 		out.flush();
       		}
	
	  
	 } catch (IOException e) {
            System.out.println("Unable to Connect to host...");
            System.exit(-1);
        }
            
    }
}
