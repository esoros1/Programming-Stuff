 /*  Eric Soros
  *  CS 33001
  *  April 10, 2011
  *  Prd pog3, Part3
  */ 
  
 This program reads in valid, paranthesized infix notation from a data file
 called "data3-1.txt", and processes it into either postfix or prefix notation,
 depending on useage, and outputs assemlbly code ,which is stored in "data.txt".
 
 To run the conversion to posfix and assembly, 
 type "make" in the directory, and then run ./postfix
 
 To run the conversion to prefix and assembly, 
 type "make prefix" in the directory, and then run ./prefixs 
 
 To test the conversion functions, type "make test", and then run ./test
 
 To test the Stack class, type "make stacktest", and then run ./stacktest
 
 EXTRA CREDIT:
 Converting from prefix to assembly required me to print out the assembly 
 in a different order than the prefix. The least significant operation is 
 calculated first, and then pushed on the bottom of the stack so it is 
 used last. The same result is in the register in both programs. 
