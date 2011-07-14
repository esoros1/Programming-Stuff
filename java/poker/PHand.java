import java.util.Scanner;
public class PHand extends Hand
{
	public PHand(Card [] cards)
	{
		super(cards);
	}
	//one turn
	//pass in the deck
	public void turn(Deck deck)
	{	
		Scanner in = new Scanner(System.in);
		System.out.println("Enter which cards you want to remove");
		System.out.println("1  2  3  4  5 ");
		System.out.println(this);
		String [] nums = in.nextLine().split(" ");
		Card [] cards = getHand();
		for(int i = 0; i < nums.length; ++i)
		{
			int num = Integer.parseInt(nums[i]);
			cards[num-1] = deck.draw();
		}
		
	}
}
