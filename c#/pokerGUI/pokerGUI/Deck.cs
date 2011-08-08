using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace poker
{
    class Deck
    {
        private List<Card> deck;
        //make a standard deck in order
        public Deck()
        {
            deck = new List<Card>(52);
            for (int i = 0; i < 4; ++i)
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
                for (int j = 2; j <= 14; j++)
                {
                    if (j >= 2 && j <= 9)
                        value = j.ToString();
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
                    deck.Add(new Card(value + suit));
                }
            }
        }

       //return the size of the deck
        public int size() { return deck.Count; }
        
        //shuffle the deck. deck is changed
        public void shuffle()
        {
            List<Card> result = new List<Card>(52);
            Random r = new Random();
            while (deck.Count != 0)
            {
                int rand = r.Next(deck.Count);
                Card temp = deck[rand];
                deck.Remove(temp);
                result.Add(temp);
            }
            deck = result;
        }
        //Remove and return the first Card in the list. 
        public Card draw()
        {
            Card result = deck[0];
            deck.Remove(result);
            return result;
        }
        
        //ToString.....
        public override string ToString()
	    {
		    String result = "";
		    foreach(Card c in deck)
		    {
			    result += c.ToString()+"\n";
		    }
		    return result;
	    }
    }
}
