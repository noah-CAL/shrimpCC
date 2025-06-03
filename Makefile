CC = gcc
CFLAGS = -g -ggdb -Wall -Wextra

SOURCES := $(wildcard src/*.c)
OBJECTS := $(patsubst %.c,%.o,$(SOURCES)) # pattern, replacement, text
DEPENDS := $(patsubst %.c,%.h,$(SOURCES))

EXE := main.out

help:
	@echo "USAGE: make [all, clean, help]"
	@echo

all: $(OBJECTS)
	$(CC) $^ -o $(EXE) $(CFLAGS)

run:
	@./$(EXE)

%.o: %.c %.h Makefile
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: all clean run
clean:
	rm -rf $(OBJECTS) $(EXE) *.wav
