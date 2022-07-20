all: int_vec main

int_vec: int_vec.o vector.o
	gcc -std=c11 $^ -o $@

main: main.o vector.o
	gcc -std=c11 $^ -o $@

%.o: %.c
	gcc -Wall -std=c11 -pedantic -I. -c $< -o $@

.PHONY: clean
clean:
	rm *.o main int_vec
