import java.io.*;

public class Problem11
{
	public static void main(String [] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader("11.txt"));
		int [][] table = new int [20][20];
		//fill the array from the text file
		for(int i = 0; i < 20; ++i)
		{
			String [] data = in.readLine().split(" ");
			for(int j = 0; j < data.length; ++j)
				table[i][j] = Integer.parseInt(data[j]);
		}
		
		System.out.println(DiagLR(table));
	}

	public static int maxHori(int [][] myNums)
	{
		int result = 0;
		for(int i = 0; i < 20; ++i)
		{
			for(int j = 0; j < 17; ++j)
			{
				int temp = myNums[i][j] * myNums[i][j+1] * myNums[i][j+2] * myNums[i][j+3];
				if (temp > result) result = temp;
			}
		}
		return result;
	}

	public static int maxVert(int [][] myNums)
	{
		int result = 0;
		for(int i = 0; i < 20; ++i)
		{
			for(int j = 0; j < 17; ++j)
			{
				System.out.println(myNums[j][i]+" "+myNums[j+1][i]+" "+myNums[j+2][i]+" "+myNums[j+3][i]);
				int temp = myNums[j][i] * myNums[j+1][i] * myNums[j+2][i] * myNums[j+3][i];
				if (temp > result) result = temp;
			}
		}
		return result;
	}


	//Lucky for me, the answer was on this side, so I didn't have to hack 
	//together the other side
	//WORST CODE EVER!
	public static int DiagLR(int [][] myNums)
	{
		int result = 0;

		int startI = 3;
		int startJ = 0;

		while(startI < 20)
		{
			int i = startI;
			int j = startJ;
			while( i-3 >= 0)
			{
				int temp = myNums[i][j] * myNums[i-1][j+1] * myNums[i-2][j+2] * myNums[i-3][j+3];
				if (temp > result) result = temp;
				i--;
				j++;
			}
			++startI;
		}

		startI = 19;
		startJ = 1;
		while(startJ < 20)
		{
			int i = startI;
			int j = startJ;
			while( j+3 < 20)
			{
				int temp = myNums[i][j] * myNums[i-1][j+1] * myNums[i-2][j+2] * myNums[i-3][j+3];
				if (temp > result) result = temp;
				i--;
				j++;
			}
			++startJ;
		}
		
		return result;
	}


}	



