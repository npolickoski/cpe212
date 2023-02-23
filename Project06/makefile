# Project06 makefile


project06: graph.o main.o 
	g++ graph.o main.o  -o project06

graph.o: graph.h graph.cpp
	g++ -c graph.cpp

main.o: graph.h main.cpp
	g++ -c main.cpp

clean:
	rm *.o  project06

