////////////////////////////////////////
//		Brainfuck Interpreter	     //	
//							         //
///////////////////////////////////////

#include <string>
#include <iostream>
#include <stack>
#include <cassert>
#include <cstdlib> 
#include <fstream>

//find the matching bracket, where start is the braket to match
//return -1 if no match found
int findMatchingBracket(int start,const std::string& exp)
{
	assert(exp[start] == '[');
	//make sure the start is correct, than move i over one
	start++;
	int numBrackets = 0;
	while(start < exp.length())
	{
		char token = exp[start];
		if (token == ']')
		{
			if (numBrackets == 0) 
				return start;
			else numBrackets--;
		}
		//check for a nested while loop
		if (token == '[') 
			numBrackets++;
		start++;
	}
	return -1;
}

//returns a string which represents the file
std::string getFile(std::istream& in)
{
	std::string result;
	while (!in.eof())
	{
		std::string buffer;
		getline(in,buffer);
		//append bufer to result
		//last time through, file is EOF and returns \n
		if (!in.eof())
			result += buffer;
	}
	return result;
}


//returns a sting which represents the out put of the program
std::string execute(const std::string& program)
{
	std::string result;
	std::stack<int> counters;
	int tape [300];
	int tapePtr = 0;

	int programCounter = 0;
	while(programCounter < program.length())
	{
		char token = program[programCounter];
		switch (token)
		{
			//increment the data at the cell by one point
			case '+':
				tape[tapePtr] += 1;
				++programCounter;
				break;

			//decrement the data at the cell by one point
			case '-':
				tape[tapePtr] -= 1;
				++programCounter;
				break;

			//move the tape pointer to the next cell
			case '>':
				++tapePtr;
				++programCounter;
				break;

			//move the tape pointer back to the previous cell
			case '<':
				--tapePtr;
				++programCounter;
				break;

			case '[':
			//if zero, skip past the loop
				if(tape[tapePtr] == 0)
					programCounter = findMatchingBracket(programCounter,program);
			//else enter the looop, and store the programCounter
				else
					counters.push(programCounter);
				++programCounter;
				break;

			case ']':
				//if zero, break the loop and pop the progam counter
				if (tape[tapePtr] == 0)
					counters.pop();
				//else, continue with the loop
				else
					programCounter = counters.top();
				++programCounter;
				break;

			case '.':
				result += char(tape[tapePtr]);
				++programCounter;
				break;
				
			default:
				++programCounter;
		}
	}
	return result;	
}

int main(int argc, char ** argv)
{
	//default mode is interactive
	if (argc == 1)
	{
		std::cout << "--------------------------------------\n";
		std::cout << "|                                    |\n";
		std::cout << "|                                    |\n";
		std::cout << "|     Brainfuck Interpreter          |\n";
		std::cout << "|                                    |\n";
		std::cout << "|                                    |\n";
		std::cout << "--------------------------------------\n";
		std::cout << "To quit, type quit\n";

		std::string exp;
		while (exp != "quit")
		{
			std::cout << "Please Enter Valid Brainfuck:\n>> ";	
			getline(std::cin,exp);
			//if quit, terminate the program
			if (exp == "quit")
			{
				std::cout << "Goodbye!"<<std::endl;
				exit(0);
			}
			std::cout << execute(exp) << std::endl;
		}
	}
	//if argc is two, then read in from file and execute
	if (argc == 2)
	{
		std::ifstream in;
		in.open(argv[1]);
		std::cout << execute(getFile(in))<< std::endl;
	}
}

