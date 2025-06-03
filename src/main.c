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
		program_t prog = {malloc(0), 0};
		size_t bytes_read = 0;
		do {
			prog.s = realloc(prog.s, prog.bytes + 1);
			bytes_read = fread(prog.s + prog.bytes, 1, 1, f);
			prog.bytes += 1;
		} while (bytes_read != 0);
		prog.s[prog.bytes - 1] = 0x00;  // set null terminator
		fclose(f);
		/********************************/
		/*          Compile!            */
		/********************************/
		program_t result = compile_program(prog);
		free(prog.s);
		// NOTE: 
		// only write back result.bytes - 1 because we do not need 
		// to write the null terminator to a file. 
		f = fopen("program.out", "w");
		fwrite(result.s, result.bytes - 1, 1, f);
		fclose(f);
		free(result.s);
	}
	return 0;
}
