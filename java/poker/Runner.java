import java.io.*;

public class Runner
{
	public static void main(String [] args) throws IOException
	{
		Deck deck = new Deck();
		deck.shuffle();
  
		Card [] c = new Card [5];
		for(int i = 0; i < 5; ++i)
			c[i] = deck.draw();

		PHand h = new PHand(c);
		h.turn(deck);
		System.out.println(h);
	}
}
