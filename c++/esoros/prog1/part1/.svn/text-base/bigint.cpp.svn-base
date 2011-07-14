#include "bigint.h"
#include <fstream>
 /*  Eric Soros
  *  CS 33001
  *  January 23, 2011
  *  Prog1, part2
  */ 
bigint::bigint() // set the bigint to zero. 
{
	digits[0] = '0';
	digits[1] = '\0';
}
bigint::bigint(const char data []) //sets a bigint to a char[], cuts short if given more than maxSize
{
	int i;
	for (i = 0; data[i] != 0; i++)
	{
		digits[i] = data[i];
		if ( i == maxSize) break;
	}
	digits[i] = '\0';
}
void bigint::print(std::ostream & out) //prints the bigint out to a stream. 80 chars per line. 
{
	int i = 0;
	while (digits[i] != 0) 
	{
		if (i % 79 == 0) out << std::endl;
		out <<digits[i++];
	}
}
