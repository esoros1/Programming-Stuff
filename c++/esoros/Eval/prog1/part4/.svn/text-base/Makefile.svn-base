bigint: main.o bigint.o
	g++ -Wall -o bigint main.o bigint.o
	
test: bigint_u.o bigint.o
	g++ -Wall -o test bigint_u.o bigint.o
	
bigint_u.o: bigint_u.cpp bigint.h
	g++ -Wall -c bigint_u.cpp

main.o: main.cpp bigint.h
	g++ -c main.cpp		
	
bigint.o: bigint.cpp bigint.h
	g++ -Wall -c bigint.cpp
clean :
	rm -f  bigint *.o

