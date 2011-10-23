/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Client {
    
    //Client class for the chat server. Basically servers as a wrapper class.
	private String username;
	private ObjectInputStream in;
	private ObjectOutputStream out;
	private String IP;

	public Client(String username, ObjectInputStream in, ObjectOutputStream out, String IP)
	{
		this.username = username;
		this.in = in;
		this.out = out;
		this.IP = IP;
	}

	public void setUsername(String username) {this.username = username;}
	public String getUsername() {return username;}
	public ObjectInputStream getInputStream() {return in;}
	public ObjectOutputStream getOutputStream() {return out;}
	public String getIP() {return IP; }
	public String toString() {return IP+" "+0+" "+username; }


}
