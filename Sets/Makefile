all: map # set multiset multimap

set: obj/set.o
	gcc -std=c11 $^ -o $@

multiset: obj/multiset.o
	gcc -std=c11 $^ -o $@

multimap: obj/multimap.o
	gcc -std=c11 $^ -o $@

map: obj/map.o
	gcc -std=c11 $^ -o $@

obj/%.o: src/%.c inc/%.h
	mkdir -p obj;
	gcc -std=c11 -pedantic -Wall -Iinc -c $< -o $@

mkdir:
	mkdir -p obj/

clean:
	rm -rf obj/*.o obj/*.d
