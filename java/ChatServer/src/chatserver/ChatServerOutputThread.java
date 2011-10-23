import java.io.*;
import java.lang.InterruptedException;
import java.util.List;
import java.util.LinkedList;

public class ChatServerOutputThread extends Thread {

	public void run() 
	{
		try {
			//check to see if there are any new messages that need sent out	
			while (true) {
			    String s;
				while ( (s = ChatServer.messagesToSend.poll()) != null) {
					for (Client client : ChatServer.clients) {
							ObjectOutputStream out = client.getOutputStream();
							out.writeObject(s);
							out.flush();
						}
					}
					//sleep for 10 miliseconds, and than look for new messages
					Thread.sleep(10);
				}
		} catch (IOException e) {
			System.out.println("Problem sending to clients....");
			System.exit(-1);
		} catch (InterruptedException e) {}
	}
}
