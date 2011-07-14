 /*  Eric Soros
  *  CS 33001
  *  February 6, 2011
  *  Prog1, part3
  */ 
  //reads in two bigints at a time from data1-1.txt
  //writes the output to result.txt
#include <fstream>
#include <iostream>
#include "bigint.h"

int main()
{
	std::ifstream in;
	in.open("data1-1.txt");
	std::ofstream out;
	out.open("result.txt");
	int i = 0;
	char num;
	char data [maxSize];
	bigint temp;
	bigint temp1;
	while (!in.eof())
	{
		while(in.get(num) && num != ';') //while next char is not ';'
		{
			if (num != '\n') data[i++] = num;
		}
		data[i] = 0;
		temp = bigint(data);
		out << temp << std::endl <<'+'<<std::endl;
		for (int j = 0; j < i; j++) data[j] = 0; //clear the array for next use
		i = 0;
		while(in.get(num) && num != ';') //do it for the second bigint. 
		{
			if (num != '\n' && num!= ' ') data[i++] = num;
		}
		data[i] = 0;
		temp1 = bigint(data);
		out << temp1 << std::endl <<  '=' << std::endl;
		for (int j = 0; j < i; j++) data[j] = 0; //clear the array for next use
		i = 0;	
		out << temp + temp1 << std::endl << '\n';
		in.get(num); //kills while after last ;
	}
	std::cout << "Writing output to result.txt"<<std::endl;
}
