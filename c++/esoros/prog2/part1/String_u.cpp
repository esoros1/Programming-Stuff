 /*  Eric Soros
  *  CS 33001
  *  February 20, 2011
  *  prog2, part1
  */ 
#include "String.h"
#include <iostream>
#include <fstream>
#include <cassert>
int main()
{
	//test constructors
	String test;
	u_test(test);

	//test length function
	assert(test.length() == 0);
	String a('c');
	assert(a.length() == 1);
	a = String("c");
	assert(a.length() == 1);
	a = String("ABC");
	assert(a.length() == 3);
    //test print
	std::cout << a << std::endl;
	a = String('c');
	std::cout << a << std::endl;
	
	
	//testing >> operator
	//reads string from test.txt, prints out to screen
	std::ifstream in;
	in.open("test.txt");
	in >> a;
	std::cout << "Reading a String from test.txt: "<<std::endl<<a<<std::endl;
	in.close();
	//test acessor[]
	a = String("ABC");
	assert(a[0] == 'A' && a[1] == 'B' && a[2] == 'C');
	
	//test  modifier[]
	a[0] = 'x';
	a[1] = 'y';
	a[2] = 'z';
	assert(a[0] == 'x' && a[1] == 'y' && a[2] == 'z');
	//test ==  and != operators
	a = String();
	String b;
	assert(a == b);
	
	a = String("abc");
	b = String("abc");
	assert(a == b);
	
	a = String("abcd");
	b = String("abc");
	assert(a != b);
	
	a = String("abc");
	b = String("abcd");
	assert(a != b);
	
	a = String();
	b = String();
	assert(a == b);
	assert(String() != String("ASJK"));
	//test <
	assert(String("ABC") < String("abc"));
	assert(String("Hey") < String("Hi"));
	assert(String() < String("A"));
	assert(String("abc") < String("bc"));
	assert(!(String() < String()));
	//test <=
	assert(String("abc") <= String("abc"));
	assert(String('a') < String("bcd"));
	assert(String("axv") < String("z"));
	assert(String() <= String());
	//test >
	assert(String("xyz") > String("a"));
	assert(String("abc") > String());
	assert(String("bcd") > String("bc"));
	assert(String("hi") > String("hey"));
	std::cout << "All tests passed" << std::endl;
	//test >=
	assert(String("bcd") > String("bc"));
	assert(String("hi") > String("hey"));
	assert(String("abc") >= String("abc"));
	//test operator+
	std::cout << String("abc") + String("def")<<std::endl;
	std::cout << String()+String("ABC")<<std::endl;
	std::cout << String("ABC") + String()<<std::endl;
	std::cout << String("abc") + 's'<<std::endl;
	std::cout << String("def")+ "abc"<<std::endl;
	std::cout << "ABCDEF" + String("GHJ")<< std::endl;
	std::cout << "ABCDEF" + String()<< std::endl;
	//test substr
	std::cout << String("abcdef").substr(0,2) <<std::endl;
	std::cout << String("abcdef").substr(3,3) << std::endl;
	std::cout << String("abcdef").substr(0,5)<< std::endl;
	a = String("This is a test");
	std::cout << a.substr(5)<<std::endl;
	//test findchar
	assert(String("abcdef").findChar('c',0) == 2);
	assert(String("abc").findChar('a',0) == 0);
	assert(String("xyz").findChar('z',1) == 2);
	assert(String("xyz").findChar('z',2) == 2);
	assert(String("xyz").findChar('c',0) == -1);
	assert(String("xyz").findChar('x',1) == -1);
	assert(String("abcda").findChar('a') == 0);
	//test findSubstr
	a = String("ABCDEFG");
	assert(a.findSubstr("ABC",0) == 0);
	assert(a.findSubstr("EFG",0) == 4);
	assert(a.findSubstr("D",0) == 3);
	assert(a.findSubstr("CD",0) == 2);
	assert(a.findSubstr("EFG",4) == 4);
	assert(a.findSubstr("BCD",1) == 1);
	assert(a.findSubstr("EFG",5) == -1);
	assert(a.findSubstr("D",5) == -1);
	assert(a.findSubstr("D") == 3);
	assert(a.findSubstr("CDE") == 2);
	assert(a.findSubstr("Z") == -1);
	assert(a.findSubstr("ABc") == -1);
	assert(String("ABCDEF ").findSubstr(" ") == 6);
	a = String("John doe was here");
	assert(a.findSubstr("was here") == 9);
	assert(a.findSubstr(" was here") == 8);
	assert(a.findSubstr("John doe was here") == 0);
	
	//reading a file using getLine(), checking for EOF()
	std::cout << "Reading using getLine(), checking for eof() \n";
	in.open("test.txt");
	while (!in.eof())
	{
		getLine(in,a);
		std::cout << a << std::endl;
	}
}

