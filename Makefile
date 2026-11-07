CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic

all: artemis

artemis: main.c artemis.c artemis.h
	$(CC) $(CFLAGS) main.c artemis.c -o artemis.exe

clean:
	rm -f artemis.exe artemis *.o
