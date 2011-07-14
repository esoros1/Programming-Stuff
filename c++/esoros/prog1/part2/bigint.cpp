#include "bigint.h"
#include <fstream>
#include <cassert>
#include <iostream>
 /*  Eric Soros
  *  CS 33001
  *  January 30, 2011
  *  Prog1, part2
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
int bigint::length() //returns the number of digits. length >= 1.
{
	int i = 0;
	while (digits[i] != -1) 
	{
		i++;
	}
	return i;
}
void bigint::print(std::ostream & out) //prints the bigint out to a stream. 80 chars per line. 
{
	out << std::endl;
	int cnt = 1;
	for (int i = length() -1; i>=0; i--)
	{
		if (cnt++ % 80 == 0) out<<std::endl;
		out <<digits[i];
	}
	out << std::endl;
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