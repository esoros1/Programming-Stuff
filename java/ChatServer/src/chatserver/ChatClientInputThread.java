import java.io.IOException;
import java.io.ObjectInputStream;
import java.lang.ClassNotFoundException;

public class ChatClientInputThread extends Thread {

	private ObjectInputStream in;

	public ChatClientInputThread(ObjectInputStream in)
	{
		this.in = in;
	}

	@Override
	public void run() {
		try {
			Message m = null;

			while (true) {
				m = (Message) in.readObject();
				System.out.println(m);
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
