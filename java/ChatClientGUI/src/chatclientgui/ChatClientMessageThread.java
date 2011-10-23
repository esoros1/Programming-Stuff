/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package chatclientgui;

import java.io.IOException;
import java.io.ObjectInputStream;

/**
 *
 * @author ericsoros
 */
public class ChatClientMessageThread extends Thread{
    
    private ObjectInputStream in;

	public ChatClientMessageThread(ObjectInputStream in)
	{
		this.in = in;
	}

	@Override
	public void run() {
	//The server sends the messages' toString() to the client
        //so just update the chat area with that. 
            try {
                String s = null;
		while (true) {
                     s = (String) in.readObject();
                     ChatClientGUI.form.updateChatRoomText(s);
                } 
           } catch (IOException e) {
			System.out.println("Lost Connection To Server");
			//System.exit(-1);
	    } catch (ClassNotFoundException e) {
			System.out.println(e);
			System.exit(-1);
	    }
	}
}
