# shrimpCC: the tiny C compiler written in C!
#
# Copyright (C) 2025 Noah Sedlik
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
CC = gcc
CFLAGS = -g -ggdb -Wall -Wextra

SOURCES := $(wildcard src/*.c)
OBJECTS := $(patsubst %.c,%.o,$(SOURCES)) # pattern, replacement, text
DEPENDS := $(patsubst src/%.c,include/%.h,$(SOURCES))
TESTS_OBJ := $(wildcard tests/*/*.s)
TESTS_OUT := $(wildcard tests/*/*.out)
TESTS_EXE := $(wildcard tests/*/*.exe)

EXE := shrimpCC

help:
	@echo "USAGE: make [all, test, clean, help]"
	@echo

all: $(OBJECTS)
	$(CC) $^ -o $(EXE) $(CFLAGS)

%.o: %.c include/%.h
	$(CC) -c $< -o $@ $(CFLAGS)

test: $(OBJECTS)
	@python3 tests/unittests.py

.PHONY: all clean help test
clean:
	rm -rf $(OBJECTS) $(EXE) $(TESTS_OBJ) $(TESTS_OUT) $(TESTS_EXE)
