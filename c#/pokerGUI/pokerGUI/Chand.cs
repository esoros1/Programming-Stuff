using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace poker
{
    //the computer's hand. Basically the same thing, but with a different turn function
    class Chand : Hand
    {
        public Chand() { }
        public Chand(Card[] cards) { this.hand = cards; }
        public Chand(Card card1, Card card2, Card card3, Card card4, Card card5)
        {
            hand[0] = card1;
            hand[1] = card2;
            hand[2] = card3;
            hand[3] = card4;
            hand[4] = card5;
        }
        
        //return a tuple which has the suit that has the most amount in the hand, and how many
        public TwoTuple<char, int> flushToTuple()
        {
            int heartsCount = 0;
            int spadesCount = 0;
            int diamondsCount = 0;
            int clubsCount = 0;
            foreach(Card c in hand)
            {
                switch (c.suit)
                {
                    case 'D':
                        ++diamondsCount;
                        break;

                    case 'S':
                        ++spadesCount;
                        break;

                    case 'H':
                        ++heartsCount;
                        break;

                    case 'C':
                        ++clubsCount;
                        break;
                }
            }
            TwoTuple<char, int>[] tuples = {new TwoTuple<char,int>('S',spadesCount),
                                            new TwoTuple<char,int>('D',diamondsCount),
                                            new TwoTuple<char,int>('H',heartsCount),
                                            new TwoTuple<char,int>('C',clubsCount)};
            //sort the tuples, and return the first one
            for (int i = 0; i < 4; ++i)
            {
                for (int j = i + 1; j < 4; ++j)
                {
                    if (tuples[i].getSecond() < tuples[j].getSecond())
                    {
                        TwoTuple<char, int> temp = tuples[i];
                        tuples[i] = tuples[j];
                        tuples[j] = temp;
                    }
                }
            }
            return tuples[0];
        }

        //returns a TwoTuple of items that make up the near straight
        //and a List of the poistions which need to be removed
        public TwoTuple<int, List<int>> straightToTuple()
        {
            TwoTuple<int, List<int>> result = new TwoTuple<int, List<int>>(0, new List<int>());
            //loop through all the cards and see which one has the highest straight
            //result is the first one we come by that is the greatest
            for (int i = 0; i < 5; ++i)
            {
                int straightCheck = hand[i].value;
                int numStraight = 0;
                List<int> positions = new List<int>();
                for (int j = 0; j < 5; ++j)
                {
                    //if the card is within four, than it could be apart of a straight. 
                    if (hand[j].value <= straightCheck && hand[j].value >= straightCheck - 4)
                        ++numStraight;
                    else
                        positions.Add(j);
                }
                if (numStraight > result.getFirst())
                {
                    result.setFirst(numStraight);
                    result.setSecond(positions);
                }
            }
            return result;
        }

        public void turn(Deck deck, int turn)
        {
            sort();
            calcTotal();
            //If the computer has a straight, than do nothing. 
            if (handTotal <= 3)
            {
                TwoTuple<char,int> flushTuple = flushToTuple();
                TwoTuple<int, List<int>> straightTuple = straightToTuple();
                //if they have two pair, get rid of the one that doesn't match
                //try to get a fullhouse
                if (handTotal == 2)
                {
                    if (hand[0].value == hand[1].value && hand[2].value == hand[3].value)
                        hand[4] = deck.draw();
                    if (hand[0].value == hand[1].value && hand[3].value == hand[4].value)
                        hand[2] = deck.draw();
                    if (hand[1].value == hand[2].value && hand[3].value == hand[4].value)
                        hand[0] = deck.draw();
                }
                 //if they have three out of five, and it's the first turn, go for a flush
                else if (flushTuple.getSecond() >= 3 && turn == 0)
                {
                    for (int i = 0; i < 5; ++i)
                        if (hand[i].suit != flushTuple.getFirst())
                            hand[i] = deck.draw();
                }
                //if it's any other turn, they need four to go for a flush
                else if (flushTuple.getSecond() == 4)
                {
                    for (int i = 0; i < 5; ++i)
                        if (hand[i].suit != flushTuple.getFirst())
                            hand[i] = deck.draw();
                }
                //if four out of five make a straight, go fot it
                else if (straightTuple.getFirst() >= 4)
                {
                    foreach(int i in straightTuple.getSecond())
                        hand[i] = deck.draw();
                }
                 //if three out of five make a straight, and it's the second or third turn, go for it
                else if (straightTuple.getFirst() >= 3 && turn == 0)
                {
                    foreach (int i in straightTuple.getSecond())
                        hand[i] = deck.draw();
                }
                //if they have three of a kind, remove the other three
                else if (handTotal == 3)
                {
                    for (int i = 0; i < 5; ++i)
                        if (hand[i].value != highestCardValue)
                            hand[i] = deck.draw();
                }
                //if they have two pair, remove the one that isn't a part of a pair
                else if (handTotal == 2)
                {
                    if (hand[0].value == hand[1].value && hand[2].value == hand[3].value)
                        hand[4] = deck.draw();
                    else if (hand[0].value == hand[1].value && hand[3].value == hand[4].value)
                        hand[2] = deck.draw();
                    else
                        hand[0] = deck.draw();
                }
                //if they have a pair, remove everything but the pair
                else if (handTotal == 1)
                {
                    for (int i = 0; i < 5; ++i)
                    {
                        if (hand[i].value != highestCardValue)
                            hand[i] = deck.draw();
                    }
                }
                //else, choose three random numbers, and replace them
                else
                {
                    HashSet<int> nums = new HashSet<int>();
                    Random r = new Random();
                    
                    while (nums.Count < 3)
                        nums.Add(r.Next(5));
                    
                    foreach (int i in nums)
                        hand[i] = deck.draw();
                }
            
            }
        }
    
    }
}
