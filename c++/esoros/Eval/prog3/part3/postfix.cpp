 /*  Eric Soros
  *  CS 33001
  *  April 10, 2011
  *  Prog3, Part3
  */ 
#include "String.hpp"
#include "asm.hpp"
#include <fstream>
#include <iostream>

//read in valid infix from file and
//convert to postfix and print out
//the assembly
int main()
{
	std::ifstream in;
	in.open("data3-1.txt");
	std::ofstream out;
	out.open("data.txt");
	while(!in.eof())
	{
		String line;
		line.resize(64);
		getLine(in,line);
		//The last time through, it is not EOF, so it stores,
		//a blank string
		if (!in.eof())
		{
			//Don't need the last semicolon and whitespace
			String exp = line.substr(0,line.length()-3);
			String postfix = infixToPostfix(exp);
			out <<"Infix: " << exp << std::endl;
			out <<"Postfix: " << postfix << std::endl;
			out << "\n";
			out << produceAsmPost(postfix) << std::endl;
		}
	}
	std::cout << "Writing output to data.txt.\n";
}
