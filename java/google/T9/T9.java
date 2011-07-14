//Google Code Jam T9 problem
import java.util.HashMap;
import java.lang.StringBuilder;
import java.io.*;

public class T9
{
	public static void main(String [] args) throws IOException
	{
		//maps letters to the button sequence
		HashMap<Character,String> buttons = new HashMap<Character,String>();
		buttons.put('a',"2");
		buttons.put('b',"22");
		buttons.put('c',"222");

		buttons.put('d',"3");
		buttons.put('e',"33");
		buttons.put('f',"333");

		buttons.put('g',"4");
		buttons.put('h',"44");
		buttons.put('i',"444");

		buttons.put('j',"5");
		buttons.put('k',"55");
		buttons.put('l',"555");

		buttons.put('m',"6");
		buttons.put('n',"66");
		buttons.put('o',"666");

		buttons.put('p',"7");
		buttons.put('q',"77");
		buttons.put('r',"777");
		buttons.put('s',"7777");
		
		buttons.put('t',"8");
		buttons.put('u',"88");
		buttons.put('v',"888");
		
		buttons.put('w',"9");
		buttons.put('x',"99");
		buttons.put('y',"999");
		buttons.put('z',"9999");

		buttons.put(' ',"0");

		BufferedReader in = new BufferedReader(new FileReader("C-large-practice.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));

		int cases = Integer.parseInt(in.readLine());
		for(int cas = 1; cas <= cases; ++cas)
		{
			out.write("Case #"+cas+": ");
			String temp = in.readLine();
			if (temp == new Character((char)32).toString())
				System.out.println("found");
			out.write(toT9(temp,buttons).toString());
			out.write("\n");
		}
		out.close();
	}

	//go from text to t9
	//StringBuilder is more efficent than just doing +=
	public static StringBuilder toT9(String s, HashMap<Character,String> buttons)
	{
		StringBuilder result = new StringBuilder();
		char [] text = s.toCharArray();

		int i = 0;
		while (i < text.length-1)
		{
			char temp = text[i];
			result.append(buttons.get(temp));
			if (onSameButton(temp,text[i+1]))
				result.append(" ");
			++i;
		}
		if (s != "")
			result.append(buttons.get(text[i]));
		return result;
	}



	//are the two leters on the same button?
	public static boolean onSameButton(char current, char next)
	{
		boolean result = false;
		switch (next) {
			case 'a' : result = current == 'a' || current == 'b' || current == 'c'; break;
			case 'b' : result = current == 'a' || current == 'b' || current == 'c'; break;
			case 'c' : result = current == 'a' || current == 'b' || current == 'c'; break;

			case 'd' : result = current == 'd' || current == 'e' || current == 'f'; break;
			case 'e' : result = current == 'd' || current == 'e' || current == 'f'; break;
			case 'f' : result = current == 'd' || current == 'e' || current == 'f'; break;

			case 'g' : result = current == 'g' || current == 'h' || current == 'i'; break;
			case 'h' : result = current == 'g' || current == 'h' || current == 'i'; break;
			case 'i' : result = current == 'g' || current == 'h' || current == 'i'; break;

			case 'j' : result = current == 'j' || current == 'k' || current == 'l'; break;
			case 'k' : result = current == 'j' || current == 'k' || current == 'l'; break;
			case 'l' : result = current == 'j' || current == 'k' || current == 'l'; break;

			case 'm' : result = current == 'm' || current == 'n' || current == 'o'; break;
			case 'n' : result = current == 'm' || current == 'n' || current == 'o'; break;
			case 'o' : result = current == 'm' || current == 'n' || current == 'o'; break;

			case 'p' : result = current == 'p' || current == 'q' || current == 'r' || current == 's'; break;
			case 'q' : result = current == 'p' || current == 'q' || current == 'r' || current == 's'; break;
			case 'r' : result = current == 'p' || current == 'q' || current == 'r' || current == 's'; break;
			case 's' : result = current == 'p' || current == 'q' || current == 'r' || current == 's'; break;

			case 't' : result = current == 't' || current == 'v' || current == 'u'; break;
			case 'u' : result = current == 't' || current == 'v' || current == 'u'; break;
			case 'v' : result = current == 't' || current == 'v' || current == 'u'; break;

			case 'w' : result = current == 'w' || current == 'x' || current == 'y' || current == 'z'; break;
			case 'x' : result = current == 'w' || current == 'x' || current == 'y' || current == 'z'; break;
			case 'y' : result = current == 'w' || current == 'x' || current == 'y' || current == 'z'; break;
			case 'z' : result = current == 'w' || current == 'x' || current == 'y' || current == 'z'; break;

			case ' ' : result = current == ' '; break;
		}	
		return result;
	}

}
