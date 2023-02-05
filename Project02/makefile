# Project02 Makefile -- CPE 212-01, Fall 2010

project02:  main.o card.o redcard.o blackcard.o heart.o diamond.o club.o spade.o
	g++  main.o card.o redcard.o blackcard.o heart.o diamond.o club.o spade.o  -o project02


main.o:  main.cpp card.h redcard.h blackcard.h heart.h diamond.h club.h spade.h
	g++ -c main.cpp


card.o:  card.cpp card.h
	g++ -c card.cpp


redcard.o:  redcard.cpp redcard.h card.h
	g++ -c redcard.cpp


blackcard.o:  blackcard.cpp blackcard.h card.h
	g++ -c blackcard.cpp


heart.o:  heart.cpp heart.h redcard.h card.h
	g++ -c heart.cpp


diamond.o:  diamond.cpp diamond.h redcard.h card.h
	g++ -c diamond.cpp


club.o:  club.cpp club.h blackcard.h card.h
	g++ -c club.cpp


spade.o:  spade.cpp spade.h blackcard.h card.h
	g++ -c spade.cpp


# Remove executable and all object files if they exist
clean:
	rm  *.o  project02


