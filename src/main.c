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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compile.h"
#include "errors.h"

int main(int argc, char *argv[]) {
	/********************************/
	/*       Error Handling         */
	/********************************/
	if (argc <= 1) {
		fprintf(stderr, "Error: zero arguments passed to compiler.\n");
		return ERR_INCORRECT_ARGUMENTS;
	}
	/********************************/
	/*   Compile each file in args  */
	/********************************/
	for (int i = 1; i < argc; i += 1) {
		FILE *f = fopen(argv[i], "r");
		if (!f) {
			fprintf(stderr, "Error: file %s not found.\n", argv[i]);
			return ERR_FILE_NOT_FOUND;
		}
		/********************************/
		/* Read File into memory buffer */
		/* (via dynamic resizing)       */
		/********************************/
		// TODO
		/********************************/
		/*          Compile!            */
		/********************************/
		program_t *result = compile_program(55);
		char *out_program = "program.out";
		if (argc >= 3) {
			out_program = argv[2];
		}
		write_program(result, out_program);
	}
	return 0;
}
