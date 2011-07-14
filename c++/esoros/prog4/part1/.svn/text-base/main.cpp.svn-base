///////////////////////////////////////////////////
//
// File:        main.cpp of Lisp
//              Program 4 CS II
// Programmer:   
// Date:        04/11/2011
//
// Description: A simple LISP interpreter.
//              Uses sexpr.h, lispnode.h, and string.h
 /*  Eric Soros
  *  CS 33001
  *  April 17, 2011
  *  Prog 4, Part 1
  */ 
#include "sexpr.h"

int main() {
    sexpr  Lisp;
    sexpr  bye("bye");
    bool   done = false;

    std::cout << "Welcome to Lisp" << std::endl << std::endl;

    while (!done) {
        std::cout << "> ";
        std::cin >> Lisp;

        std::cout << "ECHO: " << Lisp << std::endl;  //FOR DEBUGGING -- REMOVE THIS LINE
                                                     // IN FINAL VERSION.

        std::cout << eval(Lisp) << std::endl;
        
        if (bye == eval(Lisp)) done = true; 

        Lisp.garbageCollection();
    }
    std::cout << std::endl << "Exiting Lisp..." << std::endl;
    return 0;
}

