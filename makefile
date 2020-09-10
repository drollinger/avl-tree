main: main.o avlTree.o input.o trim.o
	g++ -o main main.o avlTree.o input.o trim.o

main.o: main.cpp main.h avlTree.o input.o
	g++ -c main.cpp

input.o: input.cpp input.h trim.h
	g++ -c input.cpp

avlTree.o: avlTree.cpp avlTree.h
	g++ -c avlTree.cpp

trim.o: trim.cpp trim.h
	g++ -c trim.cpp
