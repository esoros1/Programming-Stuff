test: String.o String_u.o
	g++ -Wall -o test String.o String_u.o
	
String.o: String.cpp String.h
	g++ -Wall -c String.cpp

String_u.o: String_u.cpp String.h
	g++ -Wall -c String_u.cpp

