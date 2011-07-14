 /*  Eric Soros
  *  CS 33001
  *  March 6, 2011
  *  prog2, part3
  */ 
#ifndef STRING_H
#define STRING_H
#include <ostream>
#include <vector>
//Class INV: prt[length()] = 0
class String
{
	public:
		String(); //default constructor
	    String(const char []); //default size of 64
		String(const char[], int);// sets size to int
		String(const String&); //copy constructor
		~String(); //destructor
	
		void resize(int new_cap); //make the string bigger or smaller.If smaller, save what you can
		int length() const; //returns number of chars
		int get_capacity() const; //returns capacity
		
		String substr(int, int) const; //substring between two points
		String substr(int) const; //get the string from that point to the end
		int findChar(char ch, int pos) const; //find the char starting at pos
		int findChar(char ch) const; //find the char starting at beginning of String
		int findSubstr(const String&, int pos) const;
		int findSubstr(const String&) const;
		
		String operator+(const String&) const;
		char operator[](int n) const;//Accesor only
		char& operator[](int n); //Accesor/Modifier
		String& operator=(String);//sets string equal to another string
		
		friend void swap(String&, String&); //swap two strings
		friend void u_test(const String&);//test constructor
		
		bool operator==(const String&) const;
		bool operator!=(const String&) const;
		bool operator<(const String&) const;
		bool operator<=(const String&) const;
		bool operator>(const String&) const;
		bool operator>=(const String&) const;
		
		std::vector<String> split(char) const;//splits the string on a char
		
		friend std::ostream& operator<<(std::ostream&,const String&);
		friend std::istream& operator>>(std::istream&,String&);
		friend std::istream& getLine(std::istream&, String&);
	private:
		char *s;
		//The String can hold capacity chars.	
		int capacity;
};
 String operator+(const char [], const String&);
#endif
