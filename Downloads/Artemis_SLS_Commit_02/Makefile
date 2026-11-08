CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic

all: artemis.exe

artemis.exe: main.c artemis.c artemis.h
	$(CC) $(CFLAGS) main.c artemis.c -o artemis.exe -lm

clean:
	rm -f artemis.exe artemis *.o
