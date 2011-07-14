 /*  Eric Soros
  *  CS 33001
  *  April 10, 2011
  *  Prog3, Part3
  */ 
#include "String.hpp"
#include "Stack.h"
#include "asm.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
//testing for the asm functions
int main()
{
	String exp = "( ( AX + ( BY * C ) ) / ( D4 - E ) )";
	std::cout << "Infix: \n" << exp << std::endl;
	std::cout << "Postfix: \n" << infixToPostfix(exp) << std::endl;
	exp = " ( ( ( A + B ) + ( C + D ) ) + ( E + F ) )";
	std::cout << "Infix: \n" << exp << std::endl;
	std::cout << "Postfix: \n" << infixToPostfix(exp) << std::endl;
	exp = "( A + B )";
	std::cout << "Infix: \n" << exp << std::endl;
	std::cout << "Postfix: \n" << infixToPostfix(exp) << std::endl;
	exp = "( A + ( B + C ) )";
	std::cout << "Infix: \n" << exp << std::endl;
	std::cout << "Postfix: \n" << infixToPostfix(exp) << std::endl;
	
	//tetsing for infixToPrefix
	exp = "( ( AX + ( BY * C ) ) / ( D4 - E ) )";
	std::cout << "Infix: \n" << exp << std::endl;
	std::cout << "Prefix: \n" << infixToPrefix(exp) << std::endl;
	//testing for getTMP()
	for(int i = 1; i <= 10; ++i)
	std::cout << getTMP(i) << std::endl;
	std::cout << getTMP(1234) << std::endl;
	//testing for getOperand
	assert(getOperator("+") == "AD");
	assert(getOperator("-") == "SB");
	assert(getOperator("*") == "ML");
	assert(getOperator("/") == "DV");
	
	//testing for evaluate
	std::cout << evaluate("lhs","+","rhs",1) << std::endl;
	
	std::ofstream out;
	out.open("test.txt");
	
	//tetsing for produceASMPost
	std::cout << "Testing produce ASM\n";
  	std::cout << produceAsmPost("AX BY C * + D4 E - /")<<std::endl;
	std::cout << produceAsmPost("H A B C + D * + F * G * E * * J +")<<std::endl;
	std::cout << produceAsmPost("A B +") << std::endl;

	//testing for produceAsmPre
	std::cout << produceAsmPre("+ A B")<<std::endl;
	std::cout << produceAsmPre("/ + AX * BY C - D4 E")<<std::endl;
	

	
}
