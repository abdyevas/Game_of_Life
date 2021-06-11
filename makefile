CC = gcc
SRC = main.c 
LIBS = libdraw.a libgame.a
all: 
	$(CC) $(SRC) -o game.exe -L. $(LIBS)

clean: 
	rm -fr game

doc: 
	doxygen config.h

dist: 
	tar -czf Life.tar.gz main.c libgame.a libdraw.a game.h