 /*  Eric Soros
  *  CS 33001
  *  March 13, 2011
  *  prog2, part4
  */ 
#include "String.hpp"
#include "logentry.hpp"
#include <iostream>
//Includes testing for the logEntry, Time, and Date classes.
int main()
{
	logEntry test;
	Log_utest(test);
	Date x;
	Date_utest(x);
	Time y;
	Time_utest(y);
	x = Date(String("A"),String("B"),String("C"));
	std::cout << x << std::endl;
	std::cout << "All tests passed\n";
	
	std::ifstream in;
	in.open("access_log.txt");
	std::vector<logEntry> entries = parse(in);
	std::cout << byteCount(entries) << std::endl;
}
