test: String_U.o String.o
	g++ -Wall -o test String_U.o String.o
	
String.o: String.cpp String.hpp
	g++ -Wall -c String.cpp
	
String_U.o: String_U.cpp String.hpp
	g++ -Wall -c String_U.cpp
