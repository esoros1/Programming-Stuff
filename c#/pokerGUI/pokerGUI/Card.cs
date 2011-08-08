using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace poker
{
    class Card
    {
        public int value;
        public char suit;
        //default constructor
        public Card()
        {
            value = -1;
            suit = ' ';
        }
        //parses a string
        public Card(string s)
        {
            char val = s[0];
            int temp = val - '0';
            if (temp >= 2 && temp <= 9)
                value = temp;
            else if (val == 'T')
                value = 10;
            else if (val == 'J')
                value = 11;
            else if (val == 'Q')
                value = 12;
            else if (val == 'K')
                value = 13;
            else if (val == 'A')
                value = 14;

            suit = s[1];
        }

        public override string ToString()
        {
            if (value >= 2 && value <= 9)
                return value.ToString() + suit;
            if (value == 10)
                return "T" + suit;
            if (value == 11)
                return "J" + suit;
            if (value == 12)
                return "Q" + suit;
            if (value == 13)
                return "K" + suit;
            if (value == 14)
                return "A" + suit;
            //we won't make it this far
            return "";
        }
	
    
    }
}
