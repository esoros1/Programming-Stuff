
#include "Sudoku.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <cassert>
#include <time.h>
#include <stdio.h>

int getFirstThree(const Sudoku& s)
{
	return 100*s.getValue(0,0) + 10*s.getValue(0,1) + s.getValue(0,2);
}

bool solve(Sudoku& puzzle, int i, int j)
{
	if(i < 0 && j < 0)
		return true;

	std::queue<int> nums = puzzle.getValidNums(i,j);
	bool found = false;
	while(!found && !nums.empty())
	{
		puzzle.setValue(i,j,nums.front());
		nums.pop();
		//get the next empty to check
		Point next = puzzle.getNextEmpty(i,j);
		found = solve(puzzle,next.i,next.j);
		if (!found)
			puzzle.setValue(i,j,0);
	}
	return found;
}

int main()
{ 
	time_t start = time(NULL);
	
	std::string line;
	std::ifstream in;
	in.open("sudoku.txt");
	Sudoku x;
	int result = 0;
	for(int i = 0; i < 50; ++i)
	{
		getline(in,line);

		in >> x;
		Point p = x.getFirstEmpty();
		solve(x,p.i,p.j);
		
		std::cout << x << std::endl;
		result += getFirstThree(x);
	}

	std::cout << result << std::endl;
	printf("It took %d seconds\n", (time(NULL)-start));
	
}


