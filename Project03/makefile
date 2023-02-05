# Project03 makefile

project03: stack.o main.o
	g++ stack.o main.o -o project03

stack.o: stack.h stack.cpp
	g++ -c stack.cpp

main.o: stack.h main.cpp
	g++ -c main.cpp

clean:
	rm *.o project03


