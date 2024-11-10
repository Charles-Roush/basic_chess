CC = gcc
CFLAGS = -g -Wall -I./src/board -I./src/game -I./src/pieces -I./src/util -I./src/checks

SRC = $(wildcard src/**/*.c) src/main.c
OBJ = $(SRC:.c=.o)
TARGET = chess_game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)