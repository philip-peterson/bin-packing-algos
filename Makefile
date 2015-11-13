# Name : Philip Peterson
# UF ID: 2229-7681
# Gator ID: ppeterson@ufl.edu
# Discussion section # : 1087

# vim: set noexpandtab:

CC=g++
CFLAGS=-std='c++0x' -g -Wall

MDEPS=MaxWinnerTree.o MaxWinnerTree_Node.o BinPacking.o BinaryTree_Node.o BinaryTree.o myException.o main.o

all: main

main: $(MDEPS)
	$(CC) $(CFLAGS) $(MDEPS) -o main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

myException.o: myException.cpp
	$(CC) $(CFLAGS) -c myException.cpp

#MaxWinnerTree.o
BinPacking.o: BinPacking.cpp BinPacking.h BinaryTree.o MaxWinnerTree.o
	$(CC) $(CFLAGS) -c BinPacking.cpp

BinaryTree.o: BinaryTree.cpp BinaryTree.h BinaryTree_Node.o
	$(CC) $(CFLAGS) -c BinaryTree.cpp

BinaryTree_Node.o: BinaryTree_Node.cpp BinaryTree_Node.h
	$(CC) $(CFLAGS) -c BinaryTree_Node.cpp

MaxWinnerTree.o: MaxWinnerTree.cpp MaxWinnerTree.h MaxWinnerTree_Node.o
	$(CC) $(CFLAGS) -c MaxWinnerTree.cpp

MaxWinnerTree_Node.o: MaxWinnerTree_Node.cpp MaxWinnerTree_Node.h
	$(CC) $(CFLAGS) -c MaxWinnerTree_Node.cpp

.PHONY: tar

tar:
	tar cvf PhilipPeterson_22297681.tar *.cpp *.h Makefile

.PHONY: clean

clean:
	rm -f *.gch main a.out *.o *.tar
