# Project04 makefile

project04: list.o main.o
	g++ list.o main.o -o  project04

list.o: list.h list.cpp
	g++ -c list.cpp

main.o: list.h main.cpp
	g++ -c main.cpp

clean:
	rm *.o  project04


