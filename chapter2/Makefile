CC = gcc
CFLAGS = -g -Wall
EXEC = demo exer2_3 bitwise

all: $(EXEC)
.PHONY: all

demo : demo.c
	$(CC) $(CFLAGS) demo.c -o demo

exer2_3 : exer2_3.c
	$(CC) $(CFLAGS) exer2_3.c -o exer2_3

bitwise : bitwise.c
	$(CC) $(CFLAGS) bitwise.c -o bitwise

clean:
	rm $(EXEC) 
