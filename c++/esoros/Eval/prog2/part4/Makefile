main: String.o logentry.o main.o
	g++ -Wall -o main String.o logentry.o main.o
	
logentry_test: String.o logentry.o logentry_u.o
	g++ -Wall -o logentry_test String.o logentry.o logentry_u.o

string_test: String_U.o String.o
	g++ -Wall -o string_test String_U.o String.o

main.o: main.cpp String.hpp logentry.hpp
	g++ -Wall -c main.cpp
	
String.o: String.cpp String.hpp
	g++ -Wall -c String.cpp
	
String_U.o: String_U.cpp String.hpp
	g++ -Wall -c String_U.cpp

logentry.o: logentry.cpp logentry.hpp
	g++ -Wall -c logentry.cpp

logentry_u.o: logentry_u.cpp logentry.hpp
	g++ -Wall -c logentry_u.cpp
