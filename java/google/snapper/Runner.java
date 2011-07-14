import java.util.BitSet;
import java.io.*;

public class Runner
{
	public static void main(String [] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader("A-small-practice.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));

		int numCases = Integer.parseInt(in.readLine());

		for(int cas = 1; cas <= numCases; ++cas)
		{
			out.write("Case #"+cas+": ");
			//data[o] = numSnappers
			//data[1] = snap
			String [] data = in.readLine().split(" ");

			int numSnappers = Integer.parseInt(data[0]);
			int snap = Integer.parseInt(data[1]);
			
			BitSet snappers = new BitSet(numSnappers);
			for(int i = 1; i <= snap; ++i)
			{	
				if (i <= numSnappers)
					snappers.flip(0,i);
				else
					snappers.flip(0,numSnappers-1);
			}
		
			if(snappers.get(numSnappers-1))
				out.write("ON\n");
			else out.write("OFF\n");
		}
		out.close();
	}	
}
