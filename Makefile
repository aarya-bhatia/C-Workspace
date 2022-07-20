CXX=gcc
LD=gcc
OBJ_DIR=obj
SRC_DIR=src
BIN_DIR=bin
DEPFILE_FLAGS=-MMD -MP
WARNINGS=-pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable
CPPFLAGS=-I. $(patsubst %, -I%, $(shell find $(SRC_DIR) type -d))
CXXFLAGS=-std=c11 -O0 -g -c
LDFLAGS=-std=c11

SRCS=$(wildcard $(SRC_DIR)/*.c) # List all source files
OBJS=$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) # List all object files (one for each source file)

$(BIN_DIR)/main: $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $(BIN_DIR)/$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@);
	$(CXX) $(WARNINGS) $(DEPFILE_FLAGS) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

-include $(OBJ_DIR)/*.d

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR);

.PHONY: all tidy clean
