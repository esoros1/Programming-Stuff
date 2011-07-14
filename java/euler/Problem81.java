import java.io.*;

public class Problem81
{
	public static final int NUM_ROWS = 5;

	public static void main(String [] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader("Problem81.txt"));
		int [][] myNums = new int [NUM_ROWS][NUM_ROWS];
		
		//fill the matrix
		for(int i = 0; i < NUM_ROWS; ++i)
		{
			String [] data = in.readLine().split(",");
			for(int j = 0; j < data.length; ++j)
				myNums[i][j] = Integer.parseInt(data[j]);
		}

		//start in the bottom left corner
		int i = NUM_ROWS -1;
		int j = NUM_ROWS -1;

		//make sure we can check both directions
		while(i > 0 && j > 0)
		{
			System.out.println(myNums[i][j]);
			//we can only move up and to the left, check which is bigger
			if (myNums[i][j-1] < myNums[i-1][j])
			{
				//change the value, and i and j
				myNums[i][j-1] += myNums[i][j];
				--j;
			}

			else
			{
				myNums[i-1][j] += myNums[i][j];
				--i;
			}
		}

		//if i == 0, than we can sum the rest in the row
		if ( i == 0)
		{
			while(j != 0)
			{
				System.out.println(myNums[i][j]);
				myNums[i][j-1] += myNums[i][j--];
			}
		}
		//else j == 0, and than we can sum the rest in the column
		else
		{
			while(i != 0)
			{
				System.out.println(myNums[i][j]);
				myNums[i-1][j] += myNums[i--][j];
			}	
		}
		System.out.println(myNums[i][j]);
	
	}
}
