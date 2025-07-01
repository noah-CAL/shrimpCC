/* 
 * shrimpCC: the tiny C compiler written in C!
 *
 * Copyright (C) 2025 Noah Sedlik
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef __COMPILE_H
#define __COMPILE_H
#include <stddef.h>
#include <stdio.h>

/** A stream for the output program
	* where LEN is the total number of
  * bytes with no null terminator included
	*/
typedef struct {
	FILE *stream;
	char *buf;
	size_t len;
} program_t;

program_t *compile_program(int x);

void write_program(program_t *program, char *output_file);

#endif
