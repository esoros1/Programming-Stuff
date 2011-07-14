import java.util.ArrayList;
import java.util.Random;

public class Deck
{
	private ArrayList<Card> deck;

	public Deck()
	{
		deck = new ArrayList<Card>(52);
		for(int i = 0; i < 4; ++i)
		{
			char suit = ' '; 
			String value = "";
			if (i == 0)
				suit = 'C';
			if (i == 1)	
				suit = 'H';
			if (i == 2)
				suit = 'D';
			if (i == 3)
				suit = 'S';
			for(int j = 2; j <=14; j++)
			{
				if (j >= 2 && j <= 9)
					value = new Integer(j).toString();
				if (j == 10)
					value = "T";
				if (j == 11)
					value = "J";
				if (j == 12)
					value = "Q";
				if (j == 13)
					value = "K";
				if (j == 14)
					value = "A";
				deck.add(new Card(value+suit));
			}

		}
	}
	public void shuffle()
	{
		Random r = new Random();
		ArrayList<Card> newDeck = new ArrayList<Card>(52);
		while(!deck.isEmpty())
		{
			int rand = r.nextInt(deck.size());
			Card temp = deck.get(rand);
			deck.remove(temp);
			newDeck.add(temp);
		}
		deck = newDeck;
	}


	//return and remove the first card
	public Card draw()
	{
		Card result = deck.get(0);
		deck.remove(result);
		return result;
	}

	public String toString()
	{
		String result = "";
		for(Card c: deck)
		{
			result += c.toString()+"\n";
		}
		return result;
	}

}
