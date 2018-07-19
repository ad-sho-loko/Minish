0;95;0cCC=gcc
0;95;0c0;95;0cCFLAGS=-Wall
SRCS=./src/main.c ./src/echo.c
OBJS:=$(SRCS:.c=.o)

main:
	$(CC) ./src/main.c -I./src/ -o ./src/main

run: main
	./src/main

clean:
	rm -rf *.o ./src/main

# smt:
#	$(CC) -c $(SRCS)
