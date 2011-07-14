public class Team
{
	public String schedule; 
	private double WP;
	private double OWP;
	private double OOWP;
	
	public Team() {schedule = "";};
	public Team(String s) 
	{
		schedule = s;
		//calculate the WP
		double gamesPlayed = 0;
		 double gamesWon = 0;
		for (char c : schedule.toCharArray())
		{

			if (c != '.')
			{
				gamesPlayed++;
				if(c == '1')
					gamesWon++;
			}
		}
		WP = gamesWon / gamesPlayed;
	}

	public void setOWP(double OWP) {this.OWP = OWP;};
	public void setOOWP(double OOWP) {this.OOWP = OOWP;};

	public double getWPMinus(int n)
	{
		char [] c = schedule.toCharArray();
		double gamesPlayed = 0.0;
		double gamesWon = 0.0;
		for(int i = 0; i < c.length; ++i)
		{
			if (c[i] != '.' && i != n)
			{
				gamesPlayed++;
				if (c[i] == '1')
					gamesWon++;
			}

		}
		return gamesWon / gamesPlayed;
	}


	public double getWP() {return WP;};
	public double getOWP() {return OWP;};
	public double getOOWP() {return OOWP;};

	public double getRPI()
	{
		return 0.25 * WP + 0.50 * OWP + 0.25 * OOWP;

	}

	public String toString()
	{
		return schedule;
	}

}
