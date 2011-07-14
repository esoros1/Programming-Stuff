#Make for program 4 Lisp

lisp : main.o sexpr.o
	g++ -Wall -o lisp main.o sexpr.o

test:  lisp_u.o sexpr.o
	g++ -Wall -o test lisp_u.o sexpr.o

lisp_u.o: lisp_u.cpp sexpr.h
	g++ -Wall -c lisp_u.cpp

main.o    : main.cpp sexpr.h
	g++ -Wall -c main.cpp
sexpr.o   : sexpr.cpp sexpr.h
	g++ -Wall -c sexpr.cpp
  
clean : 
	rm -f lisp test *.o
