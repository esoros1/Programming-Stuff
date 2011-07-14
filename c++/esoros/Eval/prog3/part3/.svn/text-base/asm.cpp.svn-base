 /*  Eric Soros
  *  CS 33001
  *  April 10, 2011
  *  Prog3, Part3
  */ 
#include "Stack.h"
#include "String.hpp"
#include "asm.hpp"
#include <cassert>
#include <vector>
//Free functions that help convert infix to assembly

//Pre: Takes an int
//Post: returns a string of TMP+int
// getTMP(2) returns TMP2
String getTMP(int num)
{
	//ascii characters only go from 0-9, so we need a stack if we need  
	//TMP10  or greater. We use mod 10 and divide to get the digits
	//and they will be in the correct order when popped off of the stack.
	Stack<int> digits;
	while(num != 0)
	{
		digits.Push(num % 10);
		num = num / 10;
	}
	String result = "TMP";
	//while not empty, pop off of the stack	
	while(!digits.isEmpty())
	result = result + String(char(digits.Pop()+int('0')));
	
	return result;
}
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


//PRE: exp is a valid infix expression where the operands and 
//	operators are spererated by spaces
//	Example: "( ( AX + ( BY * C ) ) / ( D4 - E ) )"
//	exp.length() >= 5
//Post: Returns a String representing the prefix representation
//	of the expression.
//	prefix.isEmpty() at the end of the function
String infixToPrefix(const String& exp)
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
			postfix.Push(oper+" "+left+" "+right);
		}
		else if(token != "(" )
		{
			postfix.Push(token);
		}
	}
	//TOS is a valid postfix expression
	return postfix.Pop();
}
//Pre: Takes three Strings and an int, where lhs is the left operand, 
//	oper is the operator, and rhs is the operand. oper must
//	be a valid operator. The int is used to keep track of the temo
//	vairable.
//Post: Returns a String with three lines. One for loading lhs, 
// 	one for doing the operation, and one for storing the result.
//Example: produceAssembly(foo,+,bar,2) returns
//	LD foo
// 	AD bar
//  ST temp2
String evaluate(String lhs, String oper, String rhs, int temp)
{
	//proper formatting to get it in the correct columns
	String assembly = "   LD\t "+lhs+ "\n   "+getOperator(oper)+"\t "
	+rhs+"\t	\n   "+"ST\t "+getTMP(temp);
	return assembly;
}
//Pre: oper is a valid operator
//Post: Returns the correcr assembly code
String getOperator(String oper)
{
	assert(oper.length() == 1);
	if (oper == "+") return "AD";
	if (oper == "-") return "SB";
	if (oper == "*") return "ML";
    return "DV";
}
//Pre: exp is a valid postfix expression
//	exp.length() >= 3
//Post: returns a sring representing formatted assembly code
String produceAsmPost(const String & exp)
{
	//store how many times we went though evaluate
	String result;
	int tempCount = 1;
	std::vector<String> tokens = exp.split(' ');
	Stack<String> asembly;
	for (int i = 0; i < tokens.size(); ++i)
	{
		String token = tokens[i];
		//if token is an operator, pop and evaluate
		if (token == "*" || token == "+" || token == "-" || token == "/")
		{
			String oper = token;
			String rhs = asembly.Pop();
			String lhs = asembly.Pop();
			result = result + evaluate(lhs,oper,rhs,tempCount)+"\n";
			//push temp variable on to be used with other calculaitons
			asembly.Push(getTMP(tempCount));
			++tempCount;
		}
		else 
		{
			asembly.Push(token);
		}
	}
	return result;
}

String produceAsmPre(const String & exp)
{
	std::vector<String> tokens = exp.split(' ');
	Stack<String> asembly;
	//keep track of how many times something is evaluate
	int tempCount = 1;
	String result;
	for(int i = tokens.size()-1; i >= 0; --i)
	{
		String token = tokens[i];
		//if token is an operator, pop and evaluate
		if (token == "*" || token == "+" || token == "-" || token == "/")
		{
			String oper = token;
			String lhs = asembly.Pop();
			String rhs = asembly.Pop();
			result = result + evaluate(lhs,oper,rhs,tempCount)+"\n";
			//push temp variable on to be used with other calculaitons
			asembly.Push(getTMP(tempCount));
			++tempCount;
		}
		else
		{
			asembly.Push(token);
		}
	}
	return result;
}




