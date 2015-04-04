CFLAGS = -g -Wall
CC = gcc
objects = hello_world.o histogram.o main_getline.o C_syntax_main.o\
		 demo_main.o c_comment.o
execs = hello_world histogram main_getline C_syntax_main demo_main\
		 c_comment

all : $(execs)
.PHONY : all

allobject: $(objects)
.PHONY: allobjects

#$(CC) -c $(CFLAGS) $< -o $@
$(objects): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY : clean
clean:
	rm *.o $(execs)
