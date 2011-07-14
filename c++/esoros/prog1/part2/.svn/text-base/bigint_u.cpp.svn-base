#include <cassert>
#include <iostream>
#include <fstream>
#include "bigint.h"
 /*  Eric Soros
  *  CS 33001
  *  January 30, 2011
  *  Prog1, part2
  */ 
  //Testing for the bigint class.
  int main()
  {
	bigint test;  //testing the length() fuction.
	u_test(test);
	assert(test.length() == 1);
	test = ("123");
	assert(test.length() == 3);
	test = (123);
	assert (test.length() == 3);
	std::cout << "All Tests Passed, printing out to data.txt";
	
	std::ofstream file; //testing the print function. 
	file.open("data.txt");
	file << "This is a default constructor";
	test = bigint();
	test.print(file);
	
	file <<std::endl <<"Here are some bigints with an integer parameter";
	test = bigint(0);
	test.print(file);
	test = bigint(1);
	test.print(file);
	test = bigint(386543);
	test.print(file);
	test = bigint(76);
	test.print(file);
	
	file <<std::endl <<"Here are some bigints with an char[] parameter";
	test = bigint("0");
	test.print(file);
	test = bigint("1");
	test.print(file);
	test = bigint("3865433345345345345555345");
	test.print(file);
	test = bigint("7823748923748923748923748923748923748923748923748923748923748934534534534534534534534534534532374892347456456456456");
	test.print(file);
  }