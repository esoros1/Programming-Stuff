
#include "Sudoku.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <cassert>
#include <time.h>
#include <stdio.h>
#include <string>

int main(int argc, char ** argv)
{ 

	std::string arg1(argv[1]);
	if (argc != 2)
	{
		std::cout << "Usage, "<< argv[0]<<" |generate|solve|\n";
		exit(-1);
	}

	time_t start = time(NULL);
	if(arg1 == "generate")
	{
		Sudoku s(true);
		solve(s,s.getFirstEmpty());
		std::cout << s << std::endl;
		printf("Generated new puzzle in %ld seconds\n",time(NULL)-start);
	}
	
  	else if(arg1 == "solve")
  	{
		Sudoku s(false);
		std::ifstream in;
		in.open("puzzle.txt");

		in >> s;
		solve(s,s.getFirstEmpty());

		std::cout << s << std::endl;
		printf("Solved puzzle in %ld seconds\n",time(NULL)-start);
	}

	else
	{
		std::cout << "Usage, "<< argv[0]<<" |generate|solve|\n";
		exit(-1);
	}
}




