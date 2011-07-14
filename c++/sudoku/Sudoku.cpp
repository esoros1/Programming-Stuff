#include "Sudoku.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <deque>
#include <algorithm>

//Seed for the random number generator.
ptrdiff_t myrandom (ptrdiff_t i) { return rand()%i;}

//pointer object to it:
ptrdiff_t (*p_myrandom)(ptrdiff_t) = myrandom;


//converts a char to an int
int atoi(char c)
{
	return c - '0';
}

Sudoku::Sudoku(bool generate_p)
{
	for(int i = 0; i < 9; ++i)
		for(int j = 0; j < 9; ++j)
			board[i][j] = 0;
	fillEmpties();
	generate = generate_p;
}

//print out the puzzle
std::ostream& operator<<(std::ostream& out, const Sudoku& rhs)
{
	for(int i = 0; i < 9; ++i)
	{
		out << std::endl;
		for(int j = 0; j < 9; ++j)
		{
			out << rhs.board[i][j] << " ";
		}
	}
	return out;
}


std::istream& operator>>(std::istream& in, Sudoku& rhs)
{
	for(int i = 0; i < 9; ++i)
	{
		std::string line;
		getline(in,line);

		for(int j = 0; j < line.size(); ++j)
		{
			rhs.board[i][j] = atoi(line[j]);
		}
	}
	rhs.fillEmpties();
	return in;
}

//check to see if the number occurs in the same column
bool Sudoku::checkVertical(int i, int j, int num)
{
	for(int row = 0; row < 9; ++row)
	{
		if (board[row][j] == num)
			return false;
	}
	return true;
}

//check to see if the number occurs in the same row
bool Sudoku::checkHorizontal(int i, int j, int num)
{
	for(int col = 0; col < 9; ++col)
	{
		if (board[i][col] == num)
			return false;
	}
	return true;
}

//check to see if num can be placed in the grid
bool Sudoku::checkGrid(int grid, int num)
{
	bool result = true;
	
		if(grid == 0)
			for(int i = 0; i <= 2; ++i)
				for(int j = 0; j <= 2; ++j)
					if (board[i][j] == num)
						result = false;
		if(grid == 1)
			for(int i = 0; i <= 2; ++i)
				for(int j = 3; j <= 5; ++j)
					if (board[i][j] == num)
						result = false;
		if(grid == 2)
			for(int i = 0; i <= 2; ++i)
				for(int j = 6; j <= 8; ++j)
					if (board[i][j] == num)
						result = false;
		if(grid == 3)
			for(int i = 3; i <= 5; ++i)
				for(int j = 0; j <= 2; ++j)
					if (board[i][j] == num)
						result = false;
		if(grid == 4)
			for(int i = 3; i <= 5; ++i)
				for(int j = 3; j <= 5; ++j)
					if (board[i][j] == num)
						result = false;
		if (grid == 5)
			for(int i = 3; i <= 5; ++i)
				for(int j = 6; j <= 8; ++j)
					if (board[i][j] == num)
						result = false;
		if (grid == 6)
			for(int i = 6; i <= 8; ++i)
				for(int j = 0; j <= 2; ++j)
					if (board[i][j] == num)
						result = false;
		if (grid == 7)
			for(int i = 6; i <= 8; ++i)
				for(int j = 3; j <= 5; ++j)
					if (board[i][j] == num)
						result = false;
		if (grid == 8)
			for(int i = 6; i <= 8; ++i)
				for(int j = 6; j <= 8; ++j)
					if (board[i][j] == num)
						result = false;
		return result;
	

}
//return what grid the position is in
// 0 <= result <= 8
int getGrid(int row, int column)
{
	int result = -1;
	if (row >= 0 && row <= 2 && column >= 0 && column <= 2)
		result =  0;
	if (row >= 0 && row <= 2 && column >= 3 && column <= 5)
		result = 1;
	if (row >= 0 && row <= 2 && column >= 6 && column <= 8)
		result =  2;
	if (row >= 3 && row <= 5 && column >= 0 && column <= 2)
		result = 3;
	if (row >= 3 && row <= 5 && column >= 3 && column <= 5)
		result =  4;
	if (row >= 3 && row <= 5 && column >= 6 && column <= 8)
		result =  5;
	if (row >= 6 && row <= 8 && column >= 0 && column <= 2)
		result = 6;
	if (row >= 6 && row <= 8 && column >= 3 && column <= 5)
		result = 7;
	if (row >= 6 && row <= 8 && column >= 6 && column <= 8)		
		result = 8;
	return result;
}
//check if we can put num at board[i][j]
bool Sudoku::check(int i, int j, int num)
{
	return (checkGrid(getGrid(i,j),num) && checkVertical(i,j,num) && checkHorizontal(i,j,num));
}

//returns a queue of numbers that could go at board[i][j]
std::deque<int> Sudoku::getValidNums(int i, int j)
{
	std::deque<int> result;
	for(int num = 1; num <= 9; ++num)
		if(check(i,j,num))
			result.push_back(num);
	//if we are creating a new puzzle, than shuffle the order
	if(generate)
	{
		srand (unsigned (time (NULL) ));
		std::random_shuffle(result.begin(),result.end(),p_myrandom);
	}
	return result;
			
}

//fill which are empty
void Sudoku::fillEmpties()
{
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{
			if(board[i][j] == 0)
				empties[i][j] = true;
			else
				empties[i][j] = false;
		}
	}
}

//get the next empty point on the board
//returns (-1,-1) if there are no more empties left
Point Sudoku::getNextEmpty(int i, int j)
{
	Point result;
	int row = i;
	int col = j + 1;
	if (col == 9)
	{
		col = 0;
		row += 1;
	}
	while(row < 9)
	{
		while(col < 9)
		{
			if (empties[row][col] == true)
			{
				result.i = row;
				result.j = col;
				return result;
			}
			++col;
		}
		++row;
		col = 0;
	}
	return result;
}

//get the first empty space
Point Sudoku::getFirstEmpty()
{
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{
			if(empties[i][j] == true)
			{
				return Point(i,j);
			}
		}
	}
	return Point();
}

void Sudoku::printEmpties()
{
	for(int i = 0; i < 9; ++i)
	{
		std::cout << std::endl;
		for(int j = 0; j < 9; ++j)
		{
			std::cout << empties[i][j] << " ";
		}
	}

}

//solve the puzzle
bool solve(Sudoku& puzzle, Point p)
{
	int i = p.i;
	int j = p.j;
	
	if(i < 0 && j < 0)
		return true;

	std::deque<int> nums = puzzle.getValidNums(i,j);
	bool found = false;
	while(!found && !nums.empty())
	{
		puzzle.setValue(i,j,nums.front());
		nums.pop_front();
		//get the next empty to check
		Point next = puzzle.getNextEmpty(i,j);
		found = solve(puzzle,next);
		if (!found)
			puzzle.setValue(i,j,0);
	}
	return found;
}


