CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -ggdb
LDFLAGS = -lncurses
SRC = src/main.c src/buffer.c src/gui_ncs.c src/buffer.h src/gui_ncs.h


redit: $(SRC)
	$(CC) $(CCFLAGS) -o redit $(SRC) $(LDFLAGS)

clean:
	rm -rf redit
