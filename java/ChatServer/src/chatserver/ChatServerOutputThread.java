import java.io.*;
import java.lang.InterruptedException;
import java.util.List;
import java.util.LinkedList;

public class ChatServerOutputThread extends Thread {

	private LinkedBlockingQueue<Message> messages;
	private List<ObjectOutputStream> clientOutputs;

	public void run() 
	{
		try {
			//check to see if there are any new messages that need sent out	
			while (true) {
				if(ChatServer.messagesToSend.size() != 0) {
					for (ObjectOutputStream out : ChatServer.clientOutputs) {
						for (Message m : ChatServer.messagesToSend) {
							out.writeObject(m);
							out.flush();
							ChatServer.messagesToSend.remove(m);
						}
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
