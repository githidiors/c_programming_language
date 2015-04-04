CC = gcc
CFLAGS = -g -Wall
EXEC = demo_grep demo_atof demo_cal_v1 RevPoCal RevPoCal_v2 demo_recur \
	demo_macro

all: $(EXEC)
.PHONY: all

demo_grep : demo_grep.c
	$(CC) $(CFLAGS) demo_grep.c -o demo_grep

demo_atof : demo_atof.c
	$(CC) $(CFLAGS) -lm demo_atof.c -o demo_atof

demo_cal_v1 : demo_cal_v1.c
	$(CC) $(CFLAGS) -lm demo_cal_v1.c -o demo_cal_v1

RevPoCal: RevPoNoCal_main.c
	$(CC) $(CFLAGS) RevPoNoCal_main.c -o RevPoCal

RevPoCal_v2: RevPoCal_V2.c
	$(CC) $(CFLAGS) RevPoCal_V2.c -lm -o RevPoCal_v2

demo_recur: demo_recur.c
	$(CC) $(CFLAGS) demo_recur.c -o demo_recur

demo_macro: demo_macro.c
	$(CC) $(CFLAGS) demo_macro.c -o demo_macro
clean:
	rm $(EXEC)
