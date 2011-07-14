 /*  Eric Soros
  *  CS 33001
  *  February 20, 2011
  *  prog2, part1
  */ 
#ifndef INCLUDE_STRING_H_
#define INCLUDE_STRING_H_
//Class INV: s[length] = 0;
#include <iostream>
const int MAX = 150;
class String
{
	public:
		String();
		String(const char);
		String(const char []);
		
		String substr(int, int) const; //substring between two points
		String substr(int) const; //get the string from that point to the end
		int findChar(char ch, int pos) const; //find the char starting at pos
		int findChar(char ch) const; //find the char starting at beginning of String
		int findSubstr(const String&, int pos) const;
		int findSubstr(const String&) const;
		
		String operator+(const String&) const;
		char operator[](int) const; //Accessor
		char& operator[] (int); // Accesor/modifier 
		
		bool operator==(const String&) const;
		bool operator!=(const String&) const;
		bool operator<(const String&) const;
		bool operator<=(const String&) const;
		bool operator>(const String&) const;
		bool operator>=(const String&) const;
		
		int length() const; //returns the number of chars
		
		friend void u_test(const String &); //checks constructor
		friend std::ostream& operator<<(std::ostream&, const String&);
		friend std::istream& operator>>(std::istream&, String &);
		friend std::istream& getLine(std::istream&, String &);
	private:
		char s[MAX];
};
String operator+(const char[], const String&);
#endif
