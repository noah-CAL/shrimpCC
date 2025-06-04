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
