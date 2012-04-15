main: main.o WeightedGraph.o DepthFirstSearch.o
	g++ -Wall -o main main.o WeightedGraph.o DepthFirstSearch.o

main.o: main.cpp WeightedGraph.h
	g++ -Wall -c main.cpp

WeightedGraph.o: WeightedGraph.cpp WeightedGraph.h
	g++ -Wall -c WeightedGraph.cpp

DepthFirstSearch.o: DepthFirstSearch.h DepthFirstSearch.cpp WeightedGraph.h
	g++ -Wall -c DepthFirstSearch.cpp
