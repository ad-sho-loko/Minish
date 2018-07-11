CC = gcc

main:
	$(CC) ./src/main.c -I./src/ -o ./src/main

run: main
	./src/main

clean:
	rm -rf *.o ./src/main
