/*
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
 *
 * ds.c is for the data structures necessary for the compiler. Namely:
 * + Linked List
 */
#include "include/ds.h"

#include <stdlib.h>
/***************/
/* Linked list */
/***************/
typedef struct ll_node ll_node;

// TODO(@self) limit tokens to 32 bytes?
struct ll_node {
  struct ll_node *next;
  char data[32];
};

ll_node *ll_create() { return malloc(sizeof(ll_node)); }

void *ll_pop(list *) { return NULL; }
void *ll_peek(list *) { return NULL; }
void ll_append(list *, void *val) { return; }
void ll_destroy(list *) {
  // TODO
  return;
}
