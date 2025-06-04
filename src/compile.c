#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compile.h"


void print_function_headers(FILE *stream, char *func_name) {
	fprintf(stream, ".text\n");
	fprintf(stream, ".p2align 4\n");
	fprintf(stream, ".global %s\n", func_name);
	fprintf(stream, "%s:\n", func_name);
}

program_t *compile_program(int x) {
	program_t *program = malloc(sizeof(program_t));
	program->stream = open_memstream(&program->buf, &program->len);
	if (program->stream == NULL) {
		fprintf(stderr, "Error opening stream");
		return NULL;
	}
	print_function_headers(program->stream, "entry");
	fprintf(program->stream, "	movl $%d, %%eax\n", x);
	fprintf(program->stream, "	ret\n");
	// clean up
	return program;
}

void write_program(program_t *program, char *output_file) {
	FILE *f = fopen(output_file, "w");
	fflush(program->stream);
	fseeko(program->stream, 0, SEEK_SET);
	fwrite(program->buf, program->len, 1, f);
	fclose(program->stream);
	free(program->buf);
	free(program);
}
