 /*  Eric Soros
  *  CS 33001
  *  February 20, 2011
  *  prog2, part1
  */ 
#include "String.h"
#include <cassert>
#include <ostream>
String::String() //Default Constructor
{
	s[0] = 0;
}
String::String(const char data)
{
	s[0] = data;
	s[1] = 0;
}
String::String(const char data[])
{
	int i = 0;
	while (data[i] != 0)
	{
		s[i] = data[i];
		i++;
	}
	s[i] = 0;
}
//returns the number of chars in the String
int String::length() const
{
	int length = 0;
	while (s[length] != 0)
	{
		length++;
	}
	return length;
}
//Requires: 0 <= n < length()
//insures:  returns s[n]
char String::operator[](int n) const
{
	assert (n >= 0);
	assert (n < length());
	return s[n];
}
//Requires: 0<= start <= end < length()
//Insures: s[start........stop]
//"ABCD".substr(0,2) returns "ABC"
String String::substr(int start, int stop) const
{
	assert(start >= 0);
	assert(stop <length());
	int i = 0;
	String result;
	while(start+i <= stop)
	{
		result.s[i] = s[start+i];
		++i;
	}
	result.s[i] = 0;
	return result;
}
//Requires: 0<= start < length()
//Insures: s[start........length()-1]
//returns the string from that point untill the end. 
String String::substr(int start) const
{
	return substr(start,length()-1);
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
//Requires: RHS[0] != 0
//Insures: returns i if s[i.......string.length()-1] == rhs
//		   else returns -1
int String::findSubstr(const String& rhs) const
{
	return(findSubstr(rhs,0));
	
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
//Requires:
//Insures: returns i if ch is in s[]
//         returns -1 if ch is not in s[]
int String::findChar(char ch) const
{
	return findChar(ch,0);
}
//Accesor/Modifier
//Requires 0 <= n < length()
//Insures: &s[n] is returned.
char& String::operator[](int n)
{
	assert(n >= 0);
	assert(n < length());
	return s[n];
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
String String::operator+(const String& rhs) const
{
	int i = 0;
	String result(s);
	while(rhs.s[i] != 0)
	{
		result.s[i+length()] = rhs.s[i];
		++i;
	}
	result.s[i+length()] = 0;
	return result;
}
String operator+(const char lhs[], const String& rhs)
{
	return String(lhs) + rhs;
}
std::ostream& operator<<(std::ostream& out, const String & rhs)
{
	out << rhs.s;
	return out;
}
std::istream& operator>>(std::istream& in, String & rhs)
{
	in >> rhs.s;
	return in;
}
std::istream& getLine(std::istream& in, String & rhs)
{
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
void u_test(const String & test)
{
	assert(test.s[0] == 0);
	String a('c');
	assert (a.s[0] == 'c' && a.s[1] == 0);
	a = String("abc");
	assert (a.s[0] == 'a' && a.s[1] == 'b' && a.s[2] == 'c' && a.s[3] == 0);
}
