/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author ericsoros
 */
public class ClientConnectionInputThread extends Thread {
    
    ObjectInputStream in;
    
    public ClientConnectionInputThread(ObjectInputStream in)
    {
        this.in = in;
    }

    @Override
    public void run() 
    {
        //get input ftom the client
       Message message = null;
        while (true) {
            try {
                message = (Message) in.readObject();
            		ChatServer.messagesToSend.add(message);
            } catch (IOException ex) {
                System.out.println("Lost Connection to client");
                break;
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(ClientConnectionInputThread.class.getName()).log(Level.SEVERE, null, ex);
            }
        
        }
    }
}
