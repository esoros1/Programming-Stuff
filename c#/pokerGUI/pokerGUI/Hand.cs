using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace poker
{
    public class Hand
    {
        protected Card[] hand;
        //which hand is more valuable?
        protected int handTotal = 0;
       //which has the highest card?
        protected int highestCardValue = 0;
        
        //default constructor
        public Hand()
        {
            hand = new Card[5];
        }
        //constructor. takes an array of 5 cards.
        public Hand(Card[] cards)
        {
            hand = new Card[5];
            for (int i = 0; i < 5; ++i)
            {
                hand[i] = cards[i];
            }
        }    
        //constructor, takes 5 cards
        public Hand(Card card1, Card card2, Card card3, Card card4, Card card5)
        {
            hand = new Card[5];
            hand[0] = card1;
            hand[1] = card2;
            hand[2] = card3;
            hand[3] = card4;
            hand[4] = card5;
        }
        
        //return the card[]
        public Card[] getHand() { return hand; }
        
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
        //get the cool [] looking thing. 
        public Card this[int index]
        {
            get
            {
                return hand[index];
            }

            set
            {
                hand[index] = value;
            }
        }
           
        //do you have a royal flush?
	    public bool hasRoyalFlush()
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
			    handTotal = 9;
			    return;
		    }
		    if ( (temp = hasStraightFlush()) > 0)
		    {
			    highestCardValue = temp;
			    handTotal = 8;
			    return;
		    }
		    if( (temp = hasFour()) > 0)
		    {
			    highestCardValue = temp;
			    handTotal = 7;
			    return;
		    }
		    if( (temp = hasFullHouse()) > 0)
		    {
			    highestCardValue = temp;
			    handTotal = 6;
			    return;
		    }
		    if( (temp = hasFlush()) > 0)
		    {
			    highestCardValue = temp;
			    handTotal = 5;
			    return;
		    }
		    if ( (temp = hasStraight()) > 0)
		    {
			    highestCardValue = temp;
			    handTotal = 4;
			    return;
		    }
		    if ( (temp = hasThree()) > 0)
		    {
			    highestCardValue = temp;
			    handTotal = 3;
			    return;
		    }
		    if ( (temp = hasTwoPair()) > 0)
		    {
			    highestCardValue = temp;
			    handTotal = 2;
			    return;
		    }
		    if ( (temp = hasPair()) > 0)
		    {
			    highestCardValue = temp;
			    handTotal = 1;
			    return;
		    }
		    //set totalValue to the highest card, return o
		    highestCardValue = hand[0].value;
	    }

	    public int hasFlush()
	    {
		    char suit = hand[0].suit;
		    int flush = 0;
		    foreach(Card c in hand)
		    {
			    if (c.suit == suit)
				    ++flush;
		    }
		    if (flush == 5)
			    return hand[0].value;
		    return -1;
	    }
        //returns true if lhs won
        //else return false
	    public static bool won(Hand t_lhs,Hand t_rhs)
	    {
		    //We don't want to chage the order of the cards in the program, 
            //so we need some temp hands.
            Hand lhs = new Hand(t_lhs.hand);
            lhs.sort();
            lhs.calcTotal();
            Hand rhs = new Hand(t_rhs.hand);
            rhs.sort();
		    rhs.calcTotal();

		    if(lhs.handTotal != rhs.handTotal)
			    return lhs.handTotal > rhs.handTotal;
		    //else, they are the same, check total value first
		    if (lhs.highestCardValue != rhs.highestCardValue)
			    return lhs.highestCardValue > rhs.highestCardValue;
		    //else they are the same, and just check for the highest card
		    for(int i = 0; i < 5; ++i)
		    {
			    if(lhs.hand[i].value != rhs.hand[i].value)
				    return lhs.hand[i].value > rhs.hand[i].value;
		    }
		    //we shouldn't make it this far....
		    return false;
	    }
        
        //static so we don't change the order of the cards in the program
        //returns a string representing the hand that is passed in 
        //pair of two;s, three aces, king high......
        public static string getHandValue(Hand t_h)
        {
            //sort and calc total so that total and totalValue are assigned
            Hand h = new Hand(t_h.hand);
            h.sort();
            h.calcTotal();
            //check to see what hand the hand contains
            //3 high, 4 high.....etc....
            if (h.handTotal == 0)
            {
                if (h.highestCardValue >= 2 && h.highestCardValue <= 10)
                    return h.highestCardValue.ToString() + " High";
                else if (h.highestCardValue == 11)
                    return "Jack High";
                else if (h.highestCardValue == 12)
                    return "Queen High";
                else if (h.highestCardValue == 13)
                    return "King High";
                else if (h.highestCardValue == 14)
                    return "Ace High";
            }
            //pair of two's, pair of king's......
            else if (h.handTotal == 1)
            {
                if (h.highestCardValue >= 2 && h.highestCardValue <= 10)
                    return "Pair of " + h.highestCardValue.ToString() + "'s";
                if (h.highestCardValue == 11)
                    return "Pair of Jacks";
                if (h.highestCardValue == 12)
                    return "Pair of Jacks";
                if (h.highestCardValue == 13)
                    return "Pair of Jacks";
                if (h.highestCardValue == 14)
                    return "Pair of Jacks";
            }
            //just do two pair
            else if (h.handTotal == 2)
                return "Two Pair";
            //Three 9's...etc....
            else if (h.handTotal == 3)
            {
                if (h.highestCardValue >= 2 && h.highestCardValue <= 10)
                    return "Three " + h.highestCardValue.ToString() + "'s";
                else if (h.highestCardValue == 11)
                    return "Three Jacks";
                else if (h.highestCardValue == 12)
                    return "Three Queens";
                else if (h.highestCardValue == 13)
                    return "Three Kings";
                else if (h.highestCardValue == 14)
                    return "Three Aces";
            }
            //Straight, 8 high.....etc....
            else if (h.handTotal == 4)
            {
                if (h.highestCardValue >= 2 && h.highestCardValue <= 10)
                    return "Straight, " + h.highestCardValue.ToString() + " High";
                else if (h.highestCardValue == 11)
                    return "Straight, Jack High";
                else if (h.highestCardValue == 12)
                    return "Straight, Queen High";
                else if (h.highestCardValue == 13)
                    return "Straight, King High";
                else if (h.highestCardValue == 14)
                    return "Straight, Ace High";
            }
            else if (h.handTotal == 5)
            {
                if (h.highestCardValue >= 2 && h.highestCardValue <= 10)
                    return "Flush, " + h.highestCardValue.ToString() + " High";
                else if (h.highestCardValue == 11)
                    return "Flush, Jack High";
                else if (h.highestCardValue == 12)
                    return "Flush, Queen High";
                else if (h.highestCardValue == 13)
                    return "Flush, King High";
                else if (h.highestCardValue == 14)
                    return "Flush, Ace High";
            }
            else if (h.handTotal == 6)
                return "Full House";
            //Four 6's.
            else if (h.handTotal == 7)
            {
                if (h.highestCardValue >= 2 && h.highestCardValue <= 10)
                    return "Four " + h.highestCardValue.ToString() + "'s";
                else if (h.highestCardValue == 11)
                    return "Four Jacks";
                else if (h.highestCardValue == 12)
                    return "Four Queens";
                else if (h.highestCardValue == 13)
                    return "Four Kings";
                else if (h.highestCardValue == 14)
                    return "Four Aces";
            }
            else if (h.handTotal == 8)
                return "Has Straight Flush";
            else if (h.handTotal == 9)
                return "HOLY FUCKING SHIT ROYAL FLUSH";
            //we won't make it this far
            return "Something went wrong...";
        }     
        
        public override String ToString()
	    {
		    String result = "";
		    foreach(Card c in hand)
		    {
			    result += c.ToString()+" ";
		    }
		    return result;
	    }
     }
  }

