game: game.c game.h
    gcc -o game game.c game.h -I.

clean:
	rm *.o game