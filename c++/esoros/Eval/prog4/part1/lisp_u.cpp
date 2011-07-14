 /*  Eric Soros
  *  CS 33001
  *  April 17, 2011
  *  Prog 4, Part 1
  */ 


#include "sexpr.h"
#include <iostream>
#include <cassert>

//testing for the sepr classes
int main()
{
	
	//Yes, there is a memory leak. I haven't implemented the garbage 
	//collection function yet. 
	
	lispnodeptr temp;
	
	//eval of nothing is a blank sexpr
	assert(eval(sexpr()) == sexpr());
	
	
	//(quote a) should return a sexpr with one atom
	temp = new lispnode(anAtom);
	temp->sym = "quote";
		
	temp->next = new lispnode(anAtom);
	temp->next->sym = "a";
	assert(eval(sexpr(temp)) == sexpr("a"));
	
	//(quote(joe)) should return joe
	temp = new lispnode(anAtom);
	temp->sym = "quote";
		
	temp->next = new lispnode(anAtom);
	temp->next->sym = "joe";
	assert(eval(sexpr(temp)) == sexpr("joe"));
	
	//(quote(a)) should return (a)
	temp = new lispnode(anAtom);
	temp->sym = "quote";
	temp->next = new lispnode(aList);
	temp->next->sublist = new lispnode(anAtom);
	temp->next->sublist->sym = "a";
	
	std::cout << eval(sexpr(temp)) << std::endl;
	
	//(quote(a b c)) should return (a b c)
	temp = new lispnode(anAtom);
	temp->sym = "quote";
	temp->next = new lispnode(aList);
	temp->next->sublist = new lispnode(anAtom);
	temp->next->sublist->sym = "a";
	temp->next->sublist->next = new lispnode(anAtom);
	temp->next->sublist->next->sym = "b";
	temp->next->sublist->next->next = new lispnode(anAtom);
	temp->next->sublist->next->next->sym = "c";
	
	std::cout << eval(sexpr(temp)) << std::endl;
	
	//(quote((a))) should return ((a))
	temp = new lispnode(anAtom);
	temp->sym = "quote";
	temp->next = new lispnode(aList);
	temp->next->sublist = new lispnode(aList);
	temp->next->sublist->sublist = new lispnode(anAtom);
	temp->next->sublist->sublist->sym = 'a';
	
	std::cout << eval(sexpr(temp)) << std::endl;
	
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
	
	std::cout << "All tests passed\n";
	
	
	
	
}
