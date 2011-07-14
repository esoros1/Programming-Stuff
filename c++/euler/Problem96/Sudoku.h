#ifndef SUDOKU_H
#define SUDOKU_H

#include <fstream>
#include <queue>
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
		Sudoku();
		std::queue<int> getValidNums(int,int);
		void fillEmpties();
		std::ostream& printEmpties(std::ostream&);
		int getValue(int i, int j) const {return board[i][j];};
		void setValue(int i, int j, int num) {board[i][j] = num;};
		bool check(int, int, int);
		bool checkGrid(int,int);
		bool checkVertical(int,int,int);
		bool checkHorizontal(int,int,int);
		Point getFirstEmpty();
		Point getNextEmpty(int,int);
		friend std::ostream& operator<<(std::ostream&, const Sudoku&);
		friend void operator>>(std::istream&, Sudoku&);
	private:
		//the puzzle
		int board [9][9];
		//is the space empty(chageable?)
		bool empties [9][9];
};

//convert a char to an int
int atoi(char c);
//retusn what grid the position is in
int getGrid(int,int);


#endif
