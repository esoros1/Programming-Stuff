using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using poker;

namespace pokerGUI
{
    public partial class Form1 : Form
    {
        private Deck deck;
        private Hand playerHand;
        private Chand computerHand;
        //how many times has the player been dealt cards?
        private int numTimesDealt = 0;
        
        public Form1()
        {
            deck = new Deck();
            deck.shuffle();
           
            //make the player's hand
            playerHand = new Hand(deck.draw(), deck.draw(), deck.draw(), deck.draw(), deck.draw());
            //make the computer's hand
            computerHand = new Chand(deck.draw(), deck.draw(), deck.draw(), deck.draw(), deck.draw());
            
            InitializeComponent();
            //draw the cards for the first time.
            //the other functions take care of the rest.
            player1UpdateCards();           
            //the computer's cards can just be the back of a card
            foreach(Control control in bottom.Controls)
            {
                if (control is Button)
                    control.BackgroundImage = Image.FromFile(Directory.GetCurrentDirectory() + "\\img\\back-blue-150-1.PNG");
            }
        }
        
        //Pre: C is a valid car
        //Post: a string is returned that matches c's coressponding PNG
        private Image cardToImage(Card c)
        {
            string result = Directory.GetCurrentDirectory()+"\\img\\";
            char suit = c.suit;
            if (suit == 'C')
                result += "clubs-";
            if (suit == 'H')
                result += "hearts-";
            if (suit == 'D')
                result += "diamonds-";
            if (suit == 'S')
                result += "spades-";

            int value = c.value;
            if (value >= 2 && value <= 10)
                result +=value.ToString()+"-150";
            if (value == 11)
                result += "j-150";
            if( value == 12)
                result += "q-150";
            if( value == 13)
                result += "k-150";
            if( value == 14)
                result += "a-150";
            Console.WriteLine(result);
            return Image.FromFile(result+".PNG");
        }

        private void player1UpdateCards()
        {
            //update the cards in the hand so they match the screen.
            //make them visible if not.
            button1.Visible = true;
            button1.BackgroundImage = cardToImage(playerHand[0]);

            button2.Visible = true;
            button2.BackgroundImage = cardToImage(playerHand[1]);

            button3.Visible = true;
            button3.BackgroundImage = cardToImage(playerHand[2]);

            button4.Visible = true;
            button4.BackgroundImage = cardToImage(playerHand[3]);

            button5.Visible = true;
            button5.BackgroundImage = cardToImage(playerHand[4]);
            //update the text next to the hand
            playerCardLabel.Text = Hand.getHandValue(playerHand);
        
        }
        
        //if the player clicks on a button, remove it
        //and replace the old card with a new one in hand
        private void button_Click(object sender, MouseEventArgs e)
        {
            //first, get rid of the button
            Button button = sender as Button;
            button.Visible = false;
            //next, find out which button it was and change the corresponding
            //card in the hand
            if (button == button1)
                playerHand[0] = deck.draw();
            else if (button == button2)
                playerHand[1] = deck.draw();
            else if (button == button3)
                playerHand[2] = deck.draw();
            else if (button == button4)
                playerHand[3] = deck.draw();
            else
                playerHand[4] = deck.draw();
        }

        //if clicked once or twice, than do nothing
        //if clicked three times, the game is over
        //disable everything, and calculate the total.
        private void draw_Click(object sender, EventArgs e)
        {
            player1UpdateCards();
            //have the computer make a turn
            computerHand.turn(deck, numTimesDealt++);
            //change the number of turns left
            drawButton.Text = "Draw: " + (3 - numTimesDealt).ToString() + " Turns left";
            if (numTimesDealt == 3)
                endGame();
        }
        //if end is clicked, disable everything, and calculate totals.
        //ends the game
        private void end_Click(object sender, EventArgs e)
        {
            //have the computer do their remaning turns.
            while (numTimesDealt < 3)
                computerHand.turn(deck, numTimesDealt++);
            endGame();
        }
        //disables all of the buttons, calculates the totals, and ends the game
        private void endGame()
        {
            //SHUT DOWN EVERYTHING!
            foreach (Control control in top.Controls)
                control.Enabled = false;

            foreach (Control control in middle.Controls)
                control.Enabled = false;

            foreach (Control control in bottom.Controls)
                control.Enabled = false;
            //flip over the computer's card
            //and calculate the total
            button6.BackgroundImage = cardToImage(computerHand[0]);
            button7.BackgroundImage = cardToImage(computerHand[1]);
            button8.BackgroundImage = cardToImage(computerHand[2]);
            button9.BackgroundImage = cardToImage(computerHand[3]);
            button10.BackgroundImage = cardToImage(computerHand[4]);
            computerCardLabel.Text = Hand.getHandValue(computerHand);

            string winnerText = "";
            const string captionText = "Game Over";
            if (Hand.won(playerHand, computerHand))
                winnerText = "Player 1 won!  Another Game?";
            else
                winnerText = "Computer won!  Another Game?";
            //show a message box saying who won
            DialogResult result = MessageBox.Show(winnerText, captionText, MessageBoxButtons.YesNo);

            //if they clicked yes, make another game
            //else, quit
            if (result == System.Windows.Forms.DialogResult.Yes)
            {
                deck = new Deck();
                deck.shuffle();

                //make the player's hand
                playerHand = new Hand(deck.draw(), deck.draw(), deck.draw(), deck.draw(), deck.draw());
                //make the computer's hand
                computerHand = new Chand(deck.draw(), deck.draw(), deck.draw(), deck.draw(), deck.draw());

                //draw the cards for the first time.
                //the other functions take care of the rest.
                player1UpdateCards();
                //the computer's cards can just be the back of a card
                foreach (Control control in bottom.Controls)
                {
                    if (control is Button)
                        control.BackgroundImage = Image.FromFile(Directory.GetCurrentDirectory() + "\\img\\back-blue-150-1.PNG");
                }
                //set the buttons in the middle to enables
                foreach (Control control in middle.Controls)
                    control.Enabled = true;
                //set all the buttons back to a default state
                numTimesDealt = 0;
                drawButton.Text = "Draw: " + (3 - numTimesDealt).ToString() + " Turns left";
                computerCardLabel.Text = "";
                playerCardLabel.Text = Hand.getHandValue(playerHand);
            }
            else
                this.Close();
        }

        
    }
}
