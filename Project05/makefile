# Project06 makefile
# To disable the gcov options use a # to comment out the
# following line and uncomment the line below it
#CC = g++ -fprofile-arcs -ftest-coverage
CC = g++

project05: main.o  student.o
	$(CC)  main.o student.o  -o project05

main.o: main.cpp bstree.h
	$(CC) -c main.cpp

student.o: student.cpp student.h
	$(CC) -c student.cpp

clean:
	rm *.o  *.gcda *.gcno *.gcov project05


