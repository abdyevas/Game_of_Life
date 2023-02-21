
output: main.o game.o draw_board.o
	gcc main.o game.o draw_board.o -o output

main.o: main.c
	gcc -c main.c

game.o: game.c
	gcc -c game.c

draw_board.o: draw_board.c
	gcc -c draw_board.c

clean:
	rm *.o executable