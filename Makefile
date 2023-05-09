CC	= gcc
CFLAGS = -Wall
LDFLAGS = -lncurses
OBJFILES = main.o game.o draw_board.o
TARGET = exe 

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~