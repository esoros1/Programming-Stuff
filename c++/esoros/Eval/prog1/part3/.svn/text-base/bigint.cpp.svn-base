#include "bigint.h"
#include <fstream>
#include <cassert>
#include <iostream>
 /*  Eric Soros
  *  CS 33001
  *  February 6, 2011
  *  Prog1, part3
  */ 
 int char_to_int(char c) // pass in char '0'-'9', return int value. 
 {
	return int(c) - int('0');
 }
  bigint::bigint() //sets the bigint to zero. Default constructor.
{
	digits[0] = 0;
	digits[1] = -1;
}
bigint::bigint(int num) //sets the bigint from an int value. 
{
	int i = 0;
	while (num > 10)
	{
		digits[i++] = num %10;
		num = num /10;
	}
	digits[i++] = num;
	digits[i] = -1;
}
bigint::bigint(const char num []) //sets the bigint from a char[]
{								  // maxSize number of chars, cuts off rest
	int i = 0;
	int length = 0;
	while (num[length] != 0)
	{
		length++;
	}
	if (length > maxSize) length = maxSize -1; // chops off is the number of digits is greater than maxSize.
	else length = length -1;
	while (length >=0)
	{
		digits[i++] = char_to_int(num[length--]);
	}
	digits[i] = -1;
}
int bigint::length() const //returns the number of digits. length >= 1.
{
	int i = 0;
	while (digits[i] != -1) 
	{
		i++;
	}
	return i;
}
bigint bigint::operator+ (int rhs) const // adds a bigint and a number 0-9
{
	bigint result;
	int i = 0;
	while (digits[i] != -1)
	{
		if (digits[i] + rhs < 10)
		{
			result.digits[i] = digits[i] + rhs;
			rhs = 0;
		}
		if (digits[i] + rhs >= 10)
		{
			int temp = digits[i] + rhs;
			rhs = temp/10;
			result.digits[i] = temp % 10;
		}
		++i;
	}
	if (rhs > 0) result.digits[i++] = rhs;
	result.digits[i] = -1;
	return result;
}
bigint operator+ (int lhs, const bigint & rhs) //adds a bigint and a number 0-9
{
	bigint result;
	int i = 0;
	while (rhs.digits[i] != -1)
	{
		if (rhs.digits[i] + lhs < 10)
		{
			result.digits[i] = rhs.digits[i] + lhs;
			lhs = 0;
		}
		if (rhs.digits[i] + lhs >= 10)
		{
			int temp = rhs.digits[i] + lhs;
			lhs = temp/10;
			result.digits[i] = temp % 10;
		}
	    ++i;
	}
	if (lhs > 0) result.digits[i++] = lhs;
	result.digits[i] = -1;
	return result;
}
bigint bigint::operator+ (const bigint & rhs) const //adds two bigints
{
	bigint result;
	int i = 0;
	int carry = 0;
	while(digits[i] != -1 && rhs.digits[i] != -1)
	{
		int temp = digits[i] + rhs.digits[i] + carry;
		if (temp < 10) 
		{
			result.digits[i] = temp;
			carry = 0;
		}
		if (temp >= 10)
		{
			result.digits[i] = temp % 10;
			carry = temp/10;
		}
		++i;
	}
	if (digits[i] == -1 && rhs.digits[i] != -1)
	{
		while(rhs.digits[i] != -1)
		{
			int temp = rhs.digits[i] + carry;
			if (temp < 10)
			{
				result.digits[i] = temp;
				carry = 0;
			}
			if (temp >= 10)
			{
				result.digits[i] = temp % 10;
				carry = temp /10;
			}
			++i;
		}
	}
	else if (rhs.digits[i] == -1 && digits[i] != -1)
	{
		while(digits[i] != -1)
		{
			int temp = digits[i] + carry;
			if (temp < 10)
			{
				result.digits[i] = temp;
				carry = 0;
			}
			if (temp >= 10)
			{
				result.digits[i] = temp % 10;
				carry = temp /10;
			}
			++i;
		}	
	}
	else
	{
		if (carry > 0) result.digits[i++] = carry;
	}
	result.digits[i] = -1;
	return result;
}
std::ostream& operator<< (std::ostream& out, const bigint & bigint)
{
	int cnt = 1;
	for (int i = bigint.length()-1;i>=0;i--)
	{
		if (cnt++ % 80 == 0) out << std::endl;
		out << bigint.digits[i];
	}
	return out;
}
std::istream& operator>> (std::istream& in, bigint & rhs)
{
	int i = 0;
	char num;
	char data [maxSize];
	while(!in.eof() && i<maxSize && num != ';')
	{
		in.get(num);
		if(!in.eof() && num != ';' && num != '\n')
		{
			data[i++] = num;
		}
	}
	data[i] = 0;
	rhs = bigint(data);
	return in;
}
int bigint::operator[](int x) const //returns what the digit should be.
{									      // bigint (123); bigint[1] returns 2;
	assert (x >=0 && x < length());
	return digits[length()-1-x];
}
void u_test(bigint test) //tests the constructors. Pass in default constructor
{
	assert (test.digits[0] == 0);
	assert (test.digits[1] == -1);
	
	test = bigint("0");
	assert (test.digits[0] == 0);
	assert (test.digits[1] == -1);
	
	test = bigint(0);
	assert (test.digits[0] == 0);
	assert (test.digits[1] == -1);
	
	test = bigint(123);
	assert (test.digits[0] == 3 && test.digits[1] == 2 && test.digits[2] == 1 && test.digits[3] == -1);
	
	test = bigint("123");
	assert (test.digits[0] == 3 && test.digits[1] == 2 && test.digits[2] == 1 && test.digits[3] == -1);
}