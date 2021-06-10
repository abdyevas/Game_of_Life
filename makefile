CC = gcc
SRC = main.c game.c
all: 
	$(CC) $(SRC) -o game

clean: 
	rm -fr game