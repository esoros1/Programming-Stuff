/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.Serializable;

/**
 *
 * @author ericsoros
 */
public class MessageTest implements Serializable {
    
    public static void main (String [] args) {
        Message m = new Message("Hello World","testname");
        System.out.println(m);
    }
}
