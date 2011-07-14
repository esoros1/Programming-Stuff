 /*  Eric Soros
  *  CS 33001
  *  April 3, 2011
  *  Prog3, Part2
  */ 
#include "String.hpp"
#include "Stack.h"
#include "asm.hpp"
#include <iostream>
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
	
	exp ="( ( H * ( ( ( ( A + ( ( B + C ) * D ) ) * F ) * G ) * E ) ) + J )";
	std::cout << "Infix: \n" << exp << std::endl;
	std::cout << "Postfix: \n" << infixToPostfix(exp) << std::endl;
}
