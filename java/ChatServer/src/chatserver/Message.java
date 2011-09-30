/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.Serializable;
import java.util.Date;

/**
 *
 * @author ericsoros
 */
public class Message implements Serializable {
    
    private String message;
    private String username;
    private Date date; 

    public Message(String message, String username, Date date)
    {
        this.message = message;
        this.username = username;
        this.date = date;
    }

    //if no date is provided, use the current time from the server
    public Message(String message, String username)
    {
        this.message = message;
        this.username = username;
        date = new Date();
    }

    public String toString()
    {
        return username+": "+message;
    }
    
}
