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
.SUFFIXES: 
CC = gcc
CFLAGS = -g -ggdb -Wall -Wextra
LDFLAGS = -lcunit

SOURCES := $(shell find src -name "*.c")
OBJECTS := $(patsubst %.c,%.o,$(SOURCES)) # pattern, replacement, text

EXE := shrimpCC

help:
	@echo "USAGE: make [all, test, clean, help]"
	@echo

######################
#    Main Program    #
######################
all: $(OBJECTS)
	$(CC) $^ -o $(EXE) $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(RUN_TESTS) $(LDFLAGS) -Isrc/

#####################
#    Unit Tests     #
#####################
unit-test: $(OBJECTS) all
	@echo
	@./$(EXE) --unit_test

#####################
# Integration Tests #
#####################
TESTS_OBJ := $(wildcard tests/*/*.s)
TESTS_OUT := $(wildcard tests/*/*.out)
TESTS_EXE := $(wildcard tests/*/*.exe)

integ-test: $(OBJECTS)
	@python3 tests/unittests.py

.PHONY: all clean help test
clean:
	rm -rf $(OBJECTS) $(EXE) $(TESTS_OBJ) $(TESTS_OUT) $(TESTS_EXE)
