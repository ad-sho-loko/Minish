main:
	gcc ./src/main.c -I./include/ -o ./src/main

run: main
	./src/main

clean:
	rm -rf *.o src/main
