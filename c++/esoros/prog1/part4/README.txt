 /*  Eric Soros
  *  CS 33001
  *  February 13, 2011
  *  Prog1, part4
  */ 
README
First, this program reads a bigint and scalar on the next line, then it
reads two bigints at a time from data1-2.txt, and both of them out
along with the product of the two numbers.
finally, it prints out the challenge, which is 100!

If the number of bigints is not divisible by two, then the last one will be 
null, as it is supposed to read in two at a time. 

EXTRA CREDIT:
Becuase my array was stored backwards,(digits[0] corresponds with the 1's place, digits[i] is the 10's....etc)
all I had to do was count up the number of zeroes. The factorial funcion is just a for loop, but is reltively fast
(it calulates 100! is less than a seconds).
For any number n, the number of trailing 
zeroes is equal to the multiplicity of the prime factor of 5 in n!.
