 /*  Eric Soros
  *  CS 33001
  *  March 6, 2011
  *  prog2, part4
  */ 
#include "String.hpp"
#include <cassert>
#include <ostream>
#include <iostream> 
#include <vector> 
//Destructor
String::~String()
{
  delete [] s;
}
//default constructor
//creates a char[] of 1 to hold null character.
String::String()
{
	s = new char[1];
	s[0] = 0;
	capacity = 0;
}
//set the String to as many chars as needed with one
//left over for the null char.
String::String(const char data [])
{
	int templength = 0;
	while (data[templength]!= 0) templength++;
     
    s = new char[templength+1];
	int i = 0;
	while(data[i] != 0)
	{
		s[i] = data[i];
		++i;
	}
	capacity = templength;
	s[i] = 0;
	capacity = templength;
}
//sets capacity to cap, String to data[]
String::String(const char data[], int cap)
{
	s = new char[cap+1];
	capacity = cap;
	int i = 0;
	while(data[i] != 0)
	{
		if (i == cap) break;
		s[i] = data[i];
		++i;
	}
	s[i] = 0;
}
//copy constructor
String::String(const String& actual)
{
	capacity = actual.capacity;
	//plus 1 for the null
	s = new char [capacity+1];
	int i;
	for (i = 0; i<actual.length();i++)
	{
		s[i] = actual.s[i];
	}
	s[i] = 0;
}
//returns the total capacity
int String::get_capacity() const
{
	return capacity;
}
int String::length() const
{
	int length = 0;
	while (s[length] != 0)
	{
		length++;
	}
	return length;
}
//makes the String bigger or smaller. Saves what it can if smaller
void String::resize(int new_cap)
{
	char * temp = new char [new_cap+1];
	int i;
	for (i = 0; ((i<new_cap) && (i < capacity));++i)
	{
		temp[i] = s[i];
	}
	//Set the last element to 0, truncates string. 
	temp[i] = 0;
	delete [] s;
	s = temp;
	capacity = new_cap;
}
String& String::operator=(String rhs)
{
	swap(*this,rhs);
	return *this;
}
//Accesor Only
//Requires: 0 <= n < length() 
//Insures: returns s[n]
char String::operator[](int n) const
{
	assert(n >= 0 && n < length());
	return s[n];
}
//Accesor/Modifier
//Requires: 0<= n < length()
//Insures: refernce to s[n] is returned
char& String::operator[](int n)
{
	assert(n >= 0 && n < length());
	return s[n];
}
String String::operator+(const String& rhs) const
{
	int i = 0;
	//make the String as long as needed
	//No buffer will be left over
	String result(s,length()+rhs.length());
	while(rhs.s[i] != 0)
	{
		result.s[i+length()] = rhs.s[i];
		++i;
	}
	result.s[i+length()] = 0;
	return result;
}
String operator+(const char rhs [], const String& lhs)
{
	return String(rhs)+lhs;
}
void swap(String& a, String& b)
{
	//swap pointers
	char * temp = a.s;
	a.s = b.s;
	b.s = temp;
	//swap capacities
	int temp1 = a.capacity;
	a.capacity = b.capacity;
	b.capacity = temp1;
}
std::ostream& operator<<(std::ostream& out,const String& rhs)
{
	//make sure we aren't trying to print null pointer......
	if (rhs.s != 0)out << rhs.s;
	return out;
}
std::istream& operator>>(std::istream& in, String& rhs)
{
	//if default constructor, then resize string to 64.
	if(rhs.s == 0) rhs.resize(64);
	in >> rhs.s;
	return in;
}
//Set rhs equal to the current line
std::istream& getLine(std::istream& in, String & rhs)
{
	
	if (rhs.s == 0) rhs.resize(256);
	int i = 0;
	char ch;
	in.get(ch);
	while((!in.eof()) && (ch!='\n') && (ch != '\r'))
	{
		rhs.s[i] = ch;
		++i;
		in.get(ch);
	}
	rhs.s[i] = 0;
	return in;
}
//ABC < BCD
//AB < ABC
bool String::operator<(const String& rhs) const
{
	int i = 0;
	while(s[i] != 0 && rhs.s[i] != 0)
	{
		if (s[i] < rhs.s[i]) return true;
		if (s[i] > rhs.s[i]) return false;
		++i;
	}
	assert(s[i] == 0 || rhs.s[i] == 0);
	if (s[i] == 0 && rhs.s[i] == 0) return false;
	return rhs.s[i] != 0;
}
bool String::operator==(const String& rhs) const
{
	int i = 0;
	while(s[i] != 0)
	{
		if(s[i] != rhs.s[i]) return false;
		i++;
	}
	return rhs.s[i] == 0;
}
bool String::operator!=(const String& rhs) const
{
	return !(operator==(rhs));
}
bool String::operator<=(const String& rhs) const
{
	return(operator==(rhs) || operator<(rhs));
}
bool String::operator>(const String& rhs)const
{
	return !operator<=(rhs);
}
bool String::operator>=(const String& rhs) const
{
	return (operator>(rhs) || operator==(rhs));
}
//Requires: 0 <= start <= stop < length()
//Insures: returns s[start.......stop]
String String::substr(int start, int stop) const
{
	assert(start >= 0);
	assert(stop <length());
	int i = 0;
	//There is no buffer.
	char temp [(stop-start)+2];
	while(start+i <= stop)
	{
		temp[i] = s[start+i];
		++i;
	}
	temp[i] = 0;
	//The string has no extra memory left over
	return String(temp,(stop-start)+1);
}
//Requires: 0<= start < length()
//Insures: s[start........length()-1]
//returns the string from that point untill the end. 
String String::substr(int start) const
{
	return substr(start,length()-1);
}
//Rrequires: 0<= pos < length()
//Insures: returns i if ch[i] is in s[pos.....length()-1]
//		   returns -1 if ch[i] is not in s[pos...length()-1]
int String::findChar(char ch, int pos) const
{
	while(s[pos] != 0)
	{
		if(s[pos] == ch) return pos;
		++pos;
	}
	return -1;
}
int String::findChar(char ch) const
{
	return findChar(ch,0);
}
//Rrequires: 0<= pos < length()
// Length() >= rhs.length()
//rhs.length() != 0
//Insures: returns i if rhs is in s[pos....length()-s], where i is starting point of rhs
//		   returns -1 if rhs is not in s[pos...length()-1].
int String::findSubstr(const String& rhs, int pos) const
{
	assert(rhs.length() > 0);
	for (int i = 0; ((pos+i)+rhs.length()-1)<length();i++)
	{
		if (substr(pos+i,rhs.length()-1+i+pos) == rhs) return i+pos;
	}
	return -1;
}
int String::findSubstr(const String& rhs) const
{
	return findSubstr(rhs,0);
}
//Pre: Takes a char that is used to split the string. 
//      If length() == 0, return empty vector
//Post: returns a vector of strings that are split on ch.
//"ABC DEF GH".split(' ') would return a vector with "ABC","DEF",and"GH"
// If ch is not in the string, the original string will be put in the vector.
// strings.size() > 0
std::vector<String> String::split(char ch) const
{
	std::vector<String> strings;
	//return empty vector if length() == 0
	if (length() == 0) return strings;
	int start_split = 0;
	//look for the split char
	for (int i = 0; i < length(); ++i)
	{
		if (s[i] == ch)
		{
			strings.push_back(substr(start_split,i-1));
			start_split = i+1;
		}
	}
	//get the last substr
	strings.push_back(substr(start_split,length()-1));
	return strings;
}
void u_test(const String& test) //pass in default constructor
{
	assert(test.s[0] == 0 && test.capacity == 0);
	String a("ABCD");
	assert(a.s[0] = 'A' && a.s[1] == 'B');
	assert(a.s[2] == 'C' && a.s[3] == 'D');
	assert(a.s[4] == 0 && a.capacity == 4);
	String b("ABC",10);
	assert(b.s[0] == 'A' && b.s[1] == 'B');
	assert(b.s[2] == 'C' && b.capacity == 10);
	//test copy constructor
	String c(b);
	assert(c.s[0] == 'A' && c.s[1] == 'B');
	assert(c.s[2] == 'C' && c.capacity == 10);
}
