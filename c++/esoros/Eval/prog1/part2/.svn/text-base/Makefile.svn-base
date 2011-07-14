bigint: bigint_u.o bigint.o
	g++ -Wall -o bigint bigint_u.o bigint.o
	
bigint_u.o: bigint_u.cpp bigint.h
	g++ -Wall -c bigint_u.cpp
	
bigint.o: bigint.cpp bigint.h
	g++ -Wall -c bigint.cpp
clean :
	rm -f  bigint *.o
