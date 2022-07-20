DEPFILE_FLAGS=-MMD -MP
WARNINGS=-pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable
CPPFLAGS=-Iinc/
CXXFLAGS=-std=c11 -c
LDFLAGS=-std=c11

split-string: obj/node.o obj/list.o obj/split-string.o | OBJ_DIR
	gcc $^ $(LDFLAGS) -o $@

obj/%.o: %.c
	gcc $(WARNINGS) $(DEPFILE_FLAGS) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

OBJ_DIR:
	mkdir -p obj

-include *.d

clean:
	rm -rf obj/*.o obj/*.d;

.PHONY: all clean