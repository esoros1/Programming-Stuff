#ifndef SUDOKU_H
#define SUDOKU_H

#include <fstream>
#include <deque>
#include <vector>
//represents a "point" on the board
class Point
{
	public:
		Point() {i = -1; j = -1;}
		Point(int x, int y) {i = x; j = y;}
		int i;
		int j;
};


//the puzzle
class Sudoku
{
	public:
		//are we making a new puzzle, or just solving
		Sudoku(bool);
		std::deque<int> getValidNums(int,int);
		void fillEmpties();
		void printEmpties();
		int getValue(int i, int j) {return board[i][j];}
		void setValue(int i, int j, int num) {board[i][j] = num;}
		bool check(int, int, int);
		bool checkGrid(int,int);
		bool checkVertical(int,int,int);
		bool checkHorizontal(int,int,int);
		Point getFirstEmpty();
		Point getNextEmpty(int,int);
		friend std::ostream& operator<<(std::ostream&, const Sudoku&);
		friend std::istream& operator>>(std::istream&, Sudoku&);
	private:
		//is it a new puzzle being generated?
		bool generate;
		//the puzzle
		int board [9][9];
		//is the space empty(chageable?)
		bool empties [9][9];
};

//convert a char to an int
int atoi(char c);
//retusn what grid the position is in
int getGrid(int,int);
//solve the puzzle
bool solve(Sudoku&, Point);
//generate a new puzzle
bool generateNewPuzzle(Sudoku&, Point);



#endif
