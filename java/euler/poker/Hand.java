public class Hand
{
	private Card [] hand;
	//which hand is more valuable?
	private int total = 0;
	//what is the card of the total?
	private int totalValue = 0;

	public Hand()
	{
		hand = new Card[5];
	}
	//length of cards == 5
	//length of cards[i] == 2
	public Hand(String [] cards)
	{
		hand = new Card[5];
		for(int i = 0; i < 5; ++i)
		{
			hand[i] = new Card(cards[i]);
		}
		sort();
		calcTotal();
	}

	//sort the hand in descending order
	public void sort()
	{
		for(int i = 0; i < 5; ++i)
		{
			for(int j = i; j < 5; ++j)
			{
				if (hand[i].value < hand[j].value)
				{
					Card temp = hand[i];
					hand[i] = hand[j];
					hand[j] = temp;
				}
			}
		}
	}

	//do you have a royal flush?
	public boolean hasRoyalFlush()
	{
		return (hasFlush() > 0 && hand[0].value == 14 && hand[1].value == 13 && hand[2].value == 12
			&& hand[3].value == 11 && hand[4].value == 10);

	}
	//do you have a straight
	//sorted in decending order
	public int hasStraight()
	{
		if(hand[0].value -1 == hand[1].value && hand[1].value -1 == hand[2].value &&
				hand[2].value -1 == hand[3].value && hand[3].value -1 == hand[4].value)
							return hand[0].value;
		else if(hand[0].value == 14 && hand[1].value == 5 && hand[2].value == 4 && hand[3].value == 3
				&& hand[4].value == 2)
							return hand[0].value;
		return -1;
	}

	//do you have a straight flush
	public int hasStraightFlush()
	{
		if (hasFlush() > 0 && hasStraight() > 0)
			return hand[0].value;
		return -1;
	}

	//do you have four of a kind
	//sorted in decending order
	public int hasFour()
	{
		if(hand[0].value == hand[1].value && hand[1].value == hand[2].value && hand[2].value == hand[3].value)
			return hand[0].value;
		else if(hand[1].value == hand[2].value && hand[2].value == hand[3].value && hand[3].value == hand[4].value)
			return hand[1].value;
		return -1;
	}
	
	//do you have three of a kind?
	public int hasThree()
	{
		if(hand[0].value == hand[1].value && hand[1].value == hand[2].value)
			return hand[0].value;
		else if(hand[1].value == hand[2].value && hand[2].value == hand[3].value)
			return hand[1].value;
		else if(hand[2].value == hand[3].value && hand[3].value == hand[4].value)
			return hand[2].value;
		return -1;

	}

	//do you have one pair?
	public int hasPair()
	{
		for(int i = 0; i < 4; ++i)
		{
			if(hand[i].value == hand[i+1].value)
				return hand[i].value;
		}
		return -1;
	}

	//do you have a full house
	public int hasFullHouse()
	{
		if(hand[0].value == hand[1].value && hand[1].value == hand[2].value && hand[3].value == hand[4].value 
				&& hand[1].value != hand[4].value)
					return hand[0].value;
		else if(hand[0].value == hand[1].value && hand[2].value == hand[3].value && hand[3].value == hand[4].value 
				&& hand[1].value != hand[4].value)
					return hand[2].value;
		return -1;
	}
	

	//do you have two pairs?
	public int hasTwoPair()
	{
		if (hand[0].value == hand[1].value && hand[2].value == hand[3].value && hand[1].value != hand[2].value)
		{
			if(hand[0].value > hand[2].value)
				return hand[0].value;
			return hand[2].value;
		}
		else if (hand[1].value == hand[2].value && hand[3].value == hand[4].value && hand[1].value != hand[3].value)
		{
			if(hand[1].value > hand[3].value)
				return hand[1].value;
			return hand[3].value;
		}
		else if (hand[0].value == hand[1].value && hand[3].value == hand[4].value && hand[1].value != hand[3].value)
		{
			if(hand[0].value > hand[3].value)
				return hand[0].value;
			return hand[3].value;
		}
		return -1;
	}


	public void calcTotal()
	{
		int temp = 0;
		if ( hasRoyalFlush())
		{
			total = 9;
			return;
		}
		if ( (temp = hasStraightFlush()) > 0)
		{
			totalValue = temp;
			total = 8;
			return;
		}
		if( (temp = hasFour()) > 0)
		{
			totalValue = temp;
			total = 7;
			return;
		}
		if( (temp = hasFullHouse()) > 0)
		{
			totalValue = temp;
			total = 6;
			return;
		}
		if( (temp = hasFlush()) > 0)
		{
			totalValue = temp;
			total = 5;
			return;
		}
		if ( (temp = hasStraight()) > 0)
		{
			totalValue = temp;
			total = 4;
			return;
		}
		if ( (temp = hasThree()) > 0)
		{
			totalValue = temp;
			total = 3;
			return;
		}
		if ( (temp = hasTwoPair()) > 0)
		{
			totalValue = temp;
			total = 2;
			return;
		}
		if ( (temp = hasPair()) > 0)
		{
			totalValue = temp;
			total = 1;
			return;
		}
		//set totalValue to the highest card, return o
		totalValue = hand[0].value;
	}

	public int hasFlush()
	{
		char suit = hand[0].suit;
		int flush = 0;
		for(Card c : hand)
		{
			if (c.suit == suit)
				++flush;
		}
		if (flush == 5)
			return hand[0].value;
		return -1;
	}


	public boolean won(Hand rhs)
	{
		if(total != rhs.total)
			return total > rhs.total;
		//else, they are the same, check total value first
		if (totalValue != rhs.totalValue)
			return totalValue > rhs.totalValue;
		//else they are the same, and just check for the highest card
		for(int i = 0; i < 5; ++i)
		{
			if(hand[i].value != rhs.hand[i].value)
				return hand[i].value > rhs.hand[i].value;
		}
		//we shouldn't make it this far....
		return false;
	}


	public String toString()
	{
		String result = "";
		for(Card c : hand)
		{
			result += c.toString()+"\n";
		}
		result += total+"\n"+totalValue;
		return result;
	}
}
