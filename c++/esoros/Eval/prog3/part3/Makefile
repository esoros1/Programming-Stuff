postfix: String.o asm.o postfix.o
	g++ -o postfix String.o asm.o postfix.o

postfix.o: postfix.cpp Stack.h String.hpp asm.hpp
	g++ -c postfix.cpp

prefix: String.o asm.o prefix.o
	g++ -o prefix String.o asm.o prefix.o

prefix.o: postfix.cpp Stack.h String.hpp asm.hpp
	g++ -c postfix.cpp

test: String.o asm.o asm_u.o
	g++ -Wall -o test String.o asm.o asm_u.o

stacktest: Stack_u.o String.o
	g++ -Wall -o stacktest Stack_u.o String.o

asm_u.o: asm_u.cpp Stack.h String.hpp
	g++ -c asm_u.cpp

asm.o: asm.cpp Stack.h String.hpp asm.hpp
	g++ -c asm.cpp

Stack_u.o: Stack_u.cpp Stack.h String.hpp
	g++ -Wall -c Stack_u.cpp
	
String.o: String.cpp String.hpp
	g++ -Wall -c String.cpp


