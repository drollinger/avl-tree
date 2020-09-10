main: main.o input.o trim.o
	g++ -o main main.o input.o trim.o

main.o: main.cpp main.h input.o
	g++ -c main.cpp

input.o: input.cpp input.h trim.h
	g++ -c input.cpp

trim.o: trim.cpp trim.h
	g++ -c trim.cpp
