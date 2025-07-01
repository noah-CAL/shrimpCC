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
#include "include/compile.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_function_headers(FILE *stream, char *func_name) {
  fprintf(stream, ".text\n");
  fprintf(stream, ".p2align 4\n");
  fprintf(stream, ".global %s\n", func_name);
  fprintf(stream, "%s:\n", func_name);
}

void print_footers(FILE *stream) {
  fprintf(stream, ".section     .note.GNU-stack\n");
}

program_t *compile_program(int x) {
  program_t *program = malloc(sizeof(program_t));
  program->stream = open_memstream(&program->buf, &program->len);
  if (program->stream == NULL) {
    fprintf(stderr, "Error opening stream");
    return NULL;
  }
  print_function_headers(program->stream, "entry");
  fprintf(program->stream, "    movl $%d, %%eax\n", x);
  fprintf(program->stream, "    ret\n");
  // clean up
  print_footers(program->stream);
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
