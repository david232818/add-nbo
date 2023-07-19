# Makefile
all: add-nbo

add-nbo: main.o add.o
	g++ -o add-nbo main.o add.o

main.o: add.h main.cpp
	g++ -c main.cpp -o main.o

add.o: add.h add.cpp
	g++ -c add.cpp -o add.o

clean:
	rm -f add-nbo
	rm -f *.o
