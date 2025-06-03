#ifndef __COMPILE_H
#define __COMPILE_H
#include <stddef.h>

typedef struct {
	char *s;
	size_t bytes;
} program_t;

program_t compile_program(program_t s);

#endif
