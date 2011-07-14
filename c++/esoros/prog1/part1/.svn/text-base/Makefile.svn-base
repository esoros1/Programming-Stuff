bigint: main.o bigint.o
	g++ -Wall -o bigint main.o bigint.o
	
main.o: main.cpp bigint.h
	g++ -Wall -c main.cpp
	
bigint.o: bigint.cpp bigint.h
	g++ -Wall -c bigint.cpp
clean :
	rm -f  bigint *.o