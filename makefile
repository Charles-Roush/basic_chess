CC = gcc
CFLAGS = -Wno-implicit-function-declaration
EXEC = chess

main.o: main.c board.h game.h pieces.h chess.h
	$(CC) $(CFLAGS) -c main.c

board.o: board.c board.h pieces.h
	$(CC) $(CFLAGS) -c board.c

game.o: game.c game.h board.h pieces.h util.c chess.h
	$(CC) $(CFLAGS) -c game.c

pieces.o: pieces.c pieces.h
	$(CC) $(CFLAGS) -c pieces.c

util.o: util.c
	$(CC) $(CFLAGS) -c util.c

$(EXEC): main.o board.o game.o pieces.o util.o
	$(CC) $(CFLAGS) main.o board.o game.o pieces.o util.o -o $(EXEC)

clean:
	rm -f *.o $(EXEC)

.PHONY: all clean