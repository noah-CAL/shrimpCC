#ifndef __COMPILE_H
#define __COMPILE_H
#include <stddef.h>

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
