import java.io.*;

public class RPI
{
	public static void main(String [] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader("test.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));

		int numTeams = Integer.parseInt(in.readLine());
		Team [] teams = new Team [numTeams];
		//fill teams
		for(int i = 0; i < numTeams; ++i)
			teams[i] = new Team(in.readLine());
		//get the OWP
		for (int i = 0; i < teams.length; ++i)
		{
			char [] c = teams[i].schedule.toCharArray();
			double teamsPlayed = 0.0;
			double total = 0.0;
			for(int j = 0; j <  c.length; ++j)
			{
				if (c[j] != '.')
				{
					teamsPlayed++;
					total += teams[j].getWPMinus(i);
				}

			}
			teams[i].setOWP(total / teamsPlayed);	
		}
		//get the OOWP
		for(int i = 0; i < teams.length; ++i)
		{
			char [] c = teams[i].schedule.toCharArray();
			double teamsPlayed = 0.0;
			double total = 0.0;
			for(int j = 0; j < c.length; ++j)
			{
				if (c[j] != '.')
				{
					teamsPlayed++;
					total += teams[j].getOWP();
				}

			}
			teams[i].setOOWP(total / teamsPlayed);
		}

		for(Team t: teams)
		{
			System.out.println((t.getRPI());
		}
	}

}
