 /*  Eric Soros
  *  CS 33001
  *  April 17, 2011
  *  Prog 4, Part 1
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
	//temp = (lengh(quote(a))).lst
	 sexpr test = getNextSexpr(in);
	 assert(test.getIdentity() == aList);
	 temp = test.getLst();
	 assert(temp->sym == "length"); 
	 temp = getNextAtom(temp);
	 assert(temp->identity == aList);
	 temp = temp->sublist;
	 assert(temp->identity == anAtom && temp->sym == "quote");
	 //assert that eval(quote (a)) is a list
	 sexpr evalTest = eval(sexpr(temp));
	 assert(evalTest.getIdentity() == aList);
	 assert(evalTest.getLst()->sym == "a");
	 //assert length of (quote(a)) is one and it returns an atom
	 evalTest = length(evalTest);
	 assert(evalTest.getIdentity() == anAtom);
	 assert(evalTest.getSymbol() == "1");
	 //check the rest of the list
	 temp = getNextAtom(temp);
	 assert(temp->identity == aList);
	 temp = temp->sublist;
	 assert(temp->identity == anAtom && temp->sym == "a");
	 
	//(length(quote ((a) b c))) 	 
	test = getNextSexpr(in);
	assert(test.getIdentity() == aList);
	temp = test.getLst();
	assert(temp->identity == anAtom && temp->sym == "length");
	temp = getNextAtom(temp);
	assert(temp->identity == aList);
	temp = temp->sublist;
	//assert that eval(quote(a) b c) is a list
	assert(eval(sexpr(temp)).getIdentity() == aList);

	assert(temp->identity == anAtom && temp->sym == "quote");  
	temp = getNextAtom(temp);
	assert(temp->identity == aList);
	temp = temp->sublist;
	assert(temp->identity == aList && temp->sublist->sym == "a");
	temp = getNextAtom(temp);
	assert(temp->identity == anAtom && temp->sym == "b"); 
	temp = getNextAtom(temp);
	assert(temp->identity == anAtom && temp->sym == "c"); 
	 
	//test = (quote a) 
	test = getNextSexpr(in);
	test.garbageCollection();
	assert(test.getLst() == 0);
	
	//(list (list (quote a) (quote b)) (quote c)) 
	test = getNextSexpr(in);
	temp = test.getLst();
	assert(test.getIdentity() == aList);
	assert(temp->identity == anAtom && temp->sym == "list");
	temp = getNextAtom(temp);
	assert(temp->identity == aList);
	temp = temp->sublist;
	//(list(quote a)(quote b) == (a b)
	std::cout << eval(sexpr(temp)) << std::endl;
	assert( eval(sexpr(temp)).getIdentity() == aList);
	
	assert(temp->sym == "list" && temp->identity == anAtom);
	temp = getNextAtom(temp);
	assert(temp->identity == aList);
	//(quote a) is an atom
	assert( eval(sexpr(temp->sublist)).getIdentity() == anAtom);
	assert(temp->sublist->identity == anAtom && temp->sublist->sym == "quote");
	assert(getNextAtom(temp->sublist)->identity == anAtom && 
				getNextAtom(temp->sublist)->sym == "a");
	temp = getNextAtom(temp);
	//quote b is an atom
	assert( eval(sexpr(temp->sublist)).getIdentity() == anAtom);
	assert(temp->identity == aList);
	assert(temp->sublist->identity == anAtom && temp->sublist->sym == "quote");
	assert(getNextAtom(temp->sublist)->identity == anAtom && 
				getNextAtom(temp->sublist)->sym == "b");
	//(eval(test)) is a list
	test = eval(test);
	assert(test.getIdentity() == aList);
	// test == ((a b) c)
	std::cout << test << std::endl;

	//(first (cons (quote a) (quote (b c))))
	test = getNextSexpr(in);
	assert(test.getIdentity() == aList);
	temp = test.getLst();
	assert(temp->identity == anAtom && temp->sym == "first");
	temp = getNextAtom(temp);
	assert(temp->identity == aList);
	temp = temp->sublist;
	//eval(cons(quote a)(quote (b c)))) is (a b c)
	assert(eval(sexpr(temp)).getIdentity() == aList);
	std::cout << eval(sexpr(temp)) << std::endl;
        temp = getNextAtom(temp);
	assert (temp->identity == aList);
	//eval (quote a) == a
	assert(eval(sexpr(temp->sublist)).getIdentity() == anAtom);
	assert(eval(sexpr(temp->sublist)).getSymbol() == "a"); 
 	
	//eval(test) is an atom, which is a
	assert(eval(test).getIdentity() == anAtom);
	assert(eval(test).getSymbol() == "a");
        
	//(rest (cons (quote a) (quote (b c)))) 
	test = getNextSexpr(in);
	assert(test.getIdentity() == aList);
	temp = test.getLst();
	assert(temp->identity == anAtom && temp->sym == "rest");
	temp = getNextAtom(temp);
	assert(temp->identity == aList);
	temp = temp->sublist;
	assert(temp->identity == anAtom && temp->sym == "cons");
	//eval(cons(quote a) (quote(b c))) == (a b c)
	assert(eval(sexpr(temp)).getIdentity() == aList);
	std::cout << eval(sexpr(temp)) << std::endl;
	
	temp = getNextAtom(temp);
	assert(temp->identity == aList);
	//eval(quote a) == a
	temp = temp->sublist;
	assert(eval(sexpr(temp)).getIdentity() == anAtom);
	assert(eval(sexpr(temp)).getSymbol() == "a");
	
	//eval(test) = (b c)
	temp = eval(test).getLst();
	assert(temp->identity == anAtom && temp->sym == "b");
	temp = getNextAtom(temp);
	assert(temp->identity == anAtom && temp->sym == "c");
	
	//reverse(quote(a b c d)) == (d c b a)
	test = eval(getNextSexpr(in));
	assert(test.getIdentity() == aList);
	temp = test.getLst();
	assert(temp->sym == "d");
	temp = getNextAtom(temp);
	assert(temp->sym == "c");
	temp = getNextAtom(temp);
	assert(temp->sym == "b");
	temp = getNextAtom(temp);
	assert(temp->sym == "a");
	
	//(append (list (quote a) (quote b)) (list (quote c) (quote d))) 
	test = getNextSexpr(in);
	assert(test.getIdentity() == aList);
	temp = test.getLst();
	assert(temp->sym == "append");
	temp = getNextAtom(temp);
	assert(temp->identity == aList);
	//eval(list(quote a)(quote b) == (a b)
	sexpr result = eval(sexpr(temp->sublist));
	assert(result.getIdentity() == aList);
	assert(result.getLst()->sym == "a" && getNextAtom(result.getLst())->sym == "b");
	temp = getNextAtom(temp);
	//eval(list(quote c)(quote d) == (c d)
	result = eval(sexpr(temp->sublist));
	assert(result.getIdentity() == aList);
	assert(result.getLst()->sym == "c" && getNextAtom(result.getLst())->sym == "d");
	//eval(test) = (a b c d)
	result = eval(test);
	assert(result.getIdentity() == aList);
	temp = result.getLst();
	assert(temp->sym == "a");
	temp = getNextAtom(temp);
	assert(temp->sym == "b");
	temp = getNextAtom(temp);
	assert(temp->sym == "c");
	temp = getNextAtom(temp);
	assert(temp->sym == "d");
	temp = getNextAtom(temp);
	
	std::cout << "All Tests Passed\n";


		

}
