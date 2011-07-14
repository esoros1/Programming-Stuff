 /*  Eric Soros
  *  CS 33001
  *  April 10, 2011
  *  Prog3, Part3
  */ 
#include "Stack.h"
#include "String.hpp" 
#include <cassert> 
#include <iostream>

int main()
{
	//test node private dada
	Node<String> x("Node Test");
	std::cout << x.data << std::endl;
	assert(x.next == 0);
	//test Stack Constructors/private data
	Stack<String> test;
	assert(test.getTos() == 0);
	assert(test.isEmpty());
	test.Push("Test");
	test.Push("ABCDEFGH");
	test.Push("EFGH");
	std::cout << test << std::endl;
	assert(test.getTos()->data == "EFGH");
	assert(test.Pop() == "EFGH");
	std::cout << test << std::endl;
	assert(test.getTos()->data == "ABCDEFGH");
	assert(test.Pop() == "ABCDEFGH");
	std::cout << test << std::endl;
	assert(test.getTos()->data == "Test");
	assert(test.Pop() == "Test");
	assert(test.getTos() == 0);
	assert(test.isEmpty());
	//test copy constructor
	test.Push("ABCD");
	test.Push("CD");
	Stack<String> test1 = test;
	std::cout << test1 << std::endl;
	//test asingment operator
	test.Push("TEST!");
	std::cout << test1 << std::endl;
	test1 = test;
	std::cout << test1 << std::endl;
	std::cout << "All tests passed\n";
}
