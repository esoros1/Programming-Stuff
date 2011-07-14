 /*  Eric Soros
  *  CS 33001
  *  March 13, 2011
  *  prog2, part4
  */ 
#include "String.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
int main()
{
	//test constructors
	String a;
	u_test(a);
	//test output
	String b("This is a test");
	std::cout << b <<" "<< b.get_capacity()<<"\n";
	b.resize(20);
	std::cout << b <<" "<< b.get_capacity()<<"\n";
	b.resize(4);
	std::cout << b <<" "<< b.get_capacity()<<"\n";
    //test swap
	String c("ONE",7);
	String d("TWO");
	swap(c,d);
	std::cout << c <<" "<< c.get_capacity()<<"\n";
	std::cout << d <<" "<< d.get_capacity()<<"\n";
	
	String test;
	String f("TEST");
	swap(test,f);
	std::cout << test <<" "<< test.get_capacity()<<"\n";
	std::cout << f <<" "<< f.get_capacity()<<"\n";
	
	f = "This is a Test";
	std::cout << f <<" "<< f.get_capacity()<<"\n";
	
	//test equals operator
	d = c;
	std::cout << c <<" "<< c.get_capacity()<<"\n";
	std::cout << d <<" "<< d.get_capacity()<<"\n"; 
	String e = "The equals operator is being called";
	std::cout << e <<" "<< e.get_capacity()<<"\n";
	//test char[] accesor only
	String g = "ABC";
	assert(g[0] == 'A' && g[1] == 'B' && g[2] == 'C');
	//test char[] accesor/modifier
	g[0] = 'X';
	g[1] = 'Y';
	g[2] = 'Z';
	assert(g[0] == 'X' && g[1] == 'Y' && g[2] == 'Z');	
	
	//test comparisons
	assert(g == "XYZ");
	g.resize(20);
	assert(g == "XYZ");
	assert(String("ABC") == "ABC");
	assert(String() != "A");
	assert(String("ABC") == String("ABC",10));
	assert(String() == String());
	assert(String("ABC") != "AC");
	assert(String("AB") < "ABC");
	assert(String("AB",30) < "ABC");
	assert(String() < "A");
	assert(String("Hey") < "Hi");
	assert(String("A") < "a");
	assert(String("AB",10) > String("A"));
	assert(String("hi") > "hey");
	assert(String("z") > "a");
	assert(String("z",10) > "a");
	assert((String("ABC") + String("CBS")) != "ABCCBSD");
	
	//test + operator
	String i = "ABC" + String("XZYKASJ");
	std::cout << i <<" "<< i.get_capacity()<<"\n";
	assert(String("ABC") + "EFG" == "ABCEFG");
	assert(String()+"ABC" == "ABC");
	assert(String("ABC",10)+"" == "ABC");
	assert("ABC"+String() == "ABC");
	assert(""+String("ABC") == "ABC");
	assert("ABC"+String("FGH") == "ABCFGH");
	assert(""+String("ABC",10) == "ABC");
	assert("ABC"+String("FGH",10) == "ABCFGH");
	
	//test substr
	String test_sub = i.substr(3);
	std::cout << test_sub <<" "<< test_sub.get_capacity()<<"\n";
	test_sub = String("Hello, World!").substr(0,4);
	std::cout << test_sub <<" "<< test_sub.get_capacity()<<"\n";
	test_sub = String("Hello, World!").substr(7,12);
	std::cout << test_sub <<" "<< test_sub.get_capacity()<<"\n";
	test_sub = String("Hello, World!").substr(0);
	std::cout << test_sub <<" "<< test_sub.get_capacity()<<"\n";
	//test findchar
	assert(String("ABCD").findChar('A',0) == 0);
	assert(String("ABCD").findChar('A',1) == -1);
	assert(String("ABCD").findChar('a',0) == -1);
	assert(String("ABCD").findChar('D') == 3);
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
	std::cout<<"All tests passed\n";
	
	//testing the split function
	std::cout <<"Test the split function\n";
	
	String split = "This is a sentence. And we should split on spaces.";
	std::vector<String> v = split.split(' ');
	for (int i = 0; i < v.size(); ++i)
	std::cout << v[i] << std::endl;
	//10 words means 10 strings in the vector
	assert(v.size() == 10);
	
	split = "This:is:also:testing:the:split:function";
	v = split.split(':');
	for (int i = 0; i < v.size(); ++i)
	std::cout << v[i] << std::endl;
	assert(v.size() == 7);
	
	split = "asd,asd,asd,asdd,,fffasd";
	v = split.split(',');
	for (int i = 0; i < v.size(); ++i)
	std::cout << v[i] << std::endl;	
	
	split = "This should only return a vector with one string";
	v = split.split('!');
	for (int i = 0; i < v.size(); ++i)
	std::cout << v[i] << std::endl;
	assert(v.size() == 1);
	
	//test access log
	split = "131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] 'GET /~darci/ HTTP/1.0 200 5625";
	v = split.split(' ');
	//make sure that we have 10 strings.
	assert(v.size() == 10);
	
	split = "a";
	v = split.split(' ');
    for (int i = 0; i < v.size(); i++)
    std::cout << v[i] << std::endl;
    assert(v.size() == 1);	
}

