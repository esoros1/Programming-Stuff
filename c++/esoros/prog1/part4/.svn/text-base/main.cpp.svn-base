 /*  Eric Soros
  *  CS 33001
  *  February 13, 2011
  *  Prog1, part4
  */ 
  //reads in two bigints at a time from data1-1.txt
  //writes the output to result.txt
#include <fstream>
#include <iostream>
#include "bigint.h"

int main()
{
	std::ifstream in;
	in.open("data1-2.txt");
	std::ofstream out;
	out.open("result.txt");
	int i = 0;
	char scalar;
	bigint temp;
	bigint temp1;
	while (!in.eof())
	{
	    out << std::endl;
	    //read bigint and scalar
	    in >> temp >> scalar;
	    if (in.eof()) break;
	    out << temp<<std::endl<<"*" << std::endl << scalar << std::endl;
	    out << "="<<std::endl<< temp * (scalar - 48)<< std::endl;
	  
		//read in two bigints at a time
		in >> temp >> temp1;
		out << std::endl<<temp << std::endl << "*" << std::endl << temp1 << std::endl;
		out << "=" <<std::endl<< temp * temp1 << std::endl;
		//The while loop is going over the EOF and I have no idea why.
	}
	std::cout << "Writing output to result.txt"<<std::endl;
	std::cout << "Extra Credit: Number of trailing zeroes on 100!: ";
	std::cout <<factorial(100).num_trail_zeroes();
}
