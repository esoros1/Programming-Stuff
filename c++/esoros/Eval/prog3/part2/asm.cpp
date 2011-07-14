 /*  Eric Soros
  *  CS 33001
  *  April 3, 2011
  *  Prog3, Part2
  */ 
#include "Stack.h"
#include "String.hpp"
#include <cassert>
#include <vector>
//Free functions that help convert infix to assembly


//PRE: exp is a valid infix expression where the operands and 
//	operators are spererated by spaces
//	Example: "( ( AX + ( BY * C ) ) / ( D4 - E ) )"
//	exp.length() >= 5
//Post: Returns a String representing the postfix representation
//	of the expression.
//	postfix.isEmpty() at the end of the function
String infixToPostfix(const String& exp)
{
	assert(exp.length() >= 5);
	std::vector<String> tokens = exp.split(' ');
	Stack<String> postfix;
	for(int i = 0;i < tokens.size(); i++)
	{
		String token = tokens[i];
		if (token == ")")
		{
			String right = postfix.Pop();
			String oper = postfix.Pop();
			String left = postfix.Pop();
			postfix.Push(left+" "+right+" "+oper);
		}
		else if(token != "(" )
		{
			postfix.Push(token);
		}
	}
	//TOS is a valid postfix expression
	return postfix.Pop();
}
