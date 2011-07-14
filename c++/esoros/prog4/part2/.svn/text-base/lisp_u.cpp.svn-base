 /*  Eric Soros
  *  CS 33001
  *  April 24, 2011
  *  Prog 4, Part 2
  */ 


#include "sexpr.h"
#include <iostream>
#include <fstream>
#include <cassert>


//testing for the sepr classes
int main()
{
	
	//Read in test sexprsions from a file named "test.txt" in 
	//the root directory
	std::ifstream in;
	in.open("test.txt");
	
	lispnodeptr temp;
	
	//eval of nothing is a blank sexpr
	assert(eval(sexpr()) == sexpr());
	
	//(quote a) should return a sexpr with one atom
	assert(eval(getNextSexpr(in)) == sexpr("a"));
		
	//(quote(joe)) should return joe
	assert(eval(getNextSexpr(in)) == sexpr("joe"));
	
	//(quote(joe 1 a smith)) should return (joe 1 a smith)
	std::cout << eval(getNextSexpr(in)) << std::endl;
	
	//(quote(a)) should return (a)
	std::cout << eval(getNextSexpr(in)) << std::endl;
	
	//(quote(a b c)) should return (a b c)
	std::cout << eval(getNextSexpr(in)) << std::endl;
	
	//(quote((a))) should return ((a))
	std::cout << eval(getNextSexpr(in)) << std::endl;
	
	//(quote(a b (c) d)) should return (a b (c) d)
	std::cout << eval(getNextSexpr(in)) << std::endl;
	
	//(quote((a)(b c d))) should return ((a)(b c d))
	std::cout << eval(getNextSexpr(in)) << std::endl;
	
	//test the (bye) function
	//(bye) creates a lispnode with one atom.
	//we send that to the sexpr constructor and see that
	//it equals sexpr("bye")
	sexpr  bye("bye");
	
	temp = new lispnode();
	temp->identity = anAtom;
	temp->sym = "bye";
	sexpr byeTest(temp);
	assert(eval(byeTest) == bye);
	
	//testing for the length function
	
	//a blank sexpr better be zero.
	assert(length(sexpr()) == 0);
	
	//length(test) is one
	assert(length(getNextSexpr(in)) == 1);
	//length(a b c) is three
	assert(length(getNextSexpr(in)) == 3);
	
	//length((a b) c) is two
	assert(length(getNextSexpr(in)) == 2);
	
	//length((a b c)) is one
	assert(length(getNextSexpr(in)) == 1);
	
	//length((abc) e f)) is three
	assert(length(getNextSexpr(in)) == 3);
	
	//testing for the first function
	
	//first() is a blank sexpr
	assert(first(sexpr()) == sexpr());
	
	//first(a) is a
	assert(first(getNextSexpr(in)) == sexpr("a"));
	
	//first(a b c) is a
	assert(first(getNextSexpr(in)) == sexpr("a"));
	
	//first((a b c) d e) is (a b c)
	std::cout << first(getNextSexpr(in)) << std::endl;
	
	//testing for the rest function
	
	//rest(a b c) should be (b c)
	std::cout << rest(getNextSexpr(in)) << std::endl;
	
	//rest(a (b c)) shoud be ((bc))
	std::cout << rest(getNextSexpr(in)) << std::endl;
	
	//rest(a (b c) e g) should be ((b c) e g)
	std::cout << rest(getNextSexpr(in)) << std::endl;
	
	//some more complex functions
	
	//eval((first (rest (quote (a b c d))))) is b
	std::cout << eval(getNextSexpr(in)) << std::endl;
	
	//eval((first (rest (rest (quote (a b c d)))))) is c
	std::cout << eval(getNextSexpr(in)) << std::endl;
	
	//eval(rest(rest(quote((a b c) d e (f g))))) is (e (f g))
	std::cout << eval(getNextSexpr(in)) << std::endl;
	
	//eval(rest(first(quote(a b c) b c))) is (b c)
	std::cout << eval(getNextSexpr(in)) << std::endl;

	std::cout << "All tests passed\n";
	
	
	
	
}
