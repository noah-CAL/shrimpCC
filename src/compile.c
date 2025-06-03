#include <stdlib.h>
#include <string.h>
#include "compile.h"

/** Takes as input a C program stored in memory as S.
 *  TODO: change to a FILE stream.
 */
program_t compile_program(program_t s) {
	program_t prog = {malloc(s.bytes), s.bytes};
	memcpy(prog.s, s.s, s.bytes);
	return prog;
}
