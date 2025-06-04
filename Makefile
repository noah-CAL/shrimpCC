CC = gcc
CFLAGS = -g -ggdb -Wall -Wextra

SOURCES := $(wildcard src/*.c)
OBJECTS := $(patsubst %.c,%.o,$(SOURCES)) # pattern, replacement, text
DEPENDS := $(patsubst %.c,%.h,$(SOURCES))
TESTS_OBJ := $(wildcard tests/*/*.s)
TESTS_OUT := $(wildcard tests/*/*.out)
TESTS_EXE := $(wildcard tests/*/*.exe)

EXE := main.out

help:
	@echo "USAGE: make [all, clean, help]"
	@echo

all: $(OBJECTS)
	$(CC) $^ -o $(EXE) $(CFLAGS)

run:
	@./$(EXE)

run-unit: $(OBJECTS)
	@python3 tests/unittests.py

%.o: %.c %.h Makefile
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: all clean run
clean:
	rm -rf $(OBJECTS) $(EXE) $(TESTS_OBJ) $(TESTS_OUT) $(TESTS_EXE)
