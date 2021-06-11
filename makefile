CC = gcc
SRC = main.c game.c
all: 
	$(CC) $(SRC) -o game

clean: 
	rm -fr game

doc: 
	doxygen config.h

dist: 
	tar -czf Life.tar.gz main.c game.c game.h