#include <cassert>
#include <iostream>
#include <fstream>
#include "bigint.h"
 /*  Eric Soros
  *  CS 33001
  *  February 6, 2011
  *  Prog1, part3
  */ 
  //Testing for the bigint class.
  //prints some bigints to data.txt
  int main()
  {  
	bigint test;  //testing the length() and operator[]
	u_test(test);
	assert(test.length() == 1);
	assert(test[0] == 0);
	test = ("123");
	assert(test.length() == 3);
	assert(test[0] == 1 && test[1] == 2 && test[2] == 3);
	test = (123);
	assert (test.length() == 3);
	assert (test[0] == 1 && test[1] == 2 && test[2] == 3);
	std::cout << "Enter a Bigint (the digits followrd by a ';')";
	bigint input;
	std::cin >> input; //test >> operator
	std::cout << "All Tests Passed, printing out to data.txt";
	
	std::ofstream file; //testing the print function. 
	file.open("data.txt");
	file << "This is a default constructor"<<std::endl;
	test = bigint();
	file << test <<std::endl;
	
	file <<std::endl <<"Here are some bigints with an integer parameter"<<std::endl;
	test = bigint(0);
	file << test << std::endl;
	test = bigint(8);
	file << test << std::endl;
	test = bigint(386543);
	file << test << std::endl;
	test = bigint(76);
	file << test << std::endl;
	
	file <<std::endl <<"Here are some bigints with an char[] parameter"<<std::endl;
	test = bigint("0");
	file << test << std::endl;
	test = bigint("1");
	file << test << std::endl;
	test = bigint("3865433345345345345555345");
	file << test << std::endl;
	test = bigint("7823748923748923748923748923748923748923748923748923748923748934534534534534534534534534534532374892347456456456456");
	file << test << std::endl;
	
	file << std::endl << "Here is the bigint you entered"; //test >>
	file << std::endl << input;
	
	bigint a,b; //testing the scalar addition operators
	b = a + 8;
	assert(b[0] == 8 && b.length() == 1);
	b = 8 + a;
	assert(b[0] == 8 && b.length() == 1);
	
	a = bigint(12);
	b = a + 9;
	assert(b[0] == 2 && b[1] == 1 && b.length() == 2);
	b = 9 + a;
	assert(b[0] == 2 && b[1] == 1 && b.length() == 2);
	
	a = bigint(99);
	b = a + 3;
	assert(b[0] == 1 && b[1] == 0 && b[2]== 2 && b.length() == 3);
	b = 3 + a;
	assert(b[0] == 1 && b[1] == 0 && b[2]== 2 && b.length() == 3);
	
	a = bigint(0); // testing additon operator using two bigints
	b = bigint(0);
	bigint c = a + b;
	assert (c[0] == 0 && c.length() == 1);
	
	c = bigint(123) + bigint(190);
	assert(c[0] ==3 && c[1] == 1 && c[2] == 3 && c.length() == 3);

	c = bigint(3) + bigint(8);
	assert (c[0] == 1 && c[1] == 1 && c.length() == 2);
}
