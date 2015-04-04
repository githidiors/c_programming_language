CC = gcc
CFLAGS = -g -Wall
EXEC = demo shellsort

all: $(EXEC)
.PHONY: all

demo : demo.c
	$(CC) $(CFLAGS) demo.c -o demo
shellsort : shellsort.c
	$(CC) $(CFLAGS) shellsort.c -o shellsort
clean:
	rm $(EXEC)
