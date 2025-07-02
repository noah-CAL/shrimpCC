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
#include "include/list.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
/**************************************/
/* Queue Implemented as a Linked list */
/**************************************/
typedef struct ll_node list;

// TODO(@self) limit tokens to 32 bytes?
struct ll_node {
  struct ll_node *next;
  char token[32];
};

list *ll_create() {
  list *SENTINEL = calloc(1, sizeof(list));
  return SENTINEL;
}

void ll_pop_front(list *head, char buf[32]) {
  ll_peek(head, buf);
  if (head->next != NULL) {
    list *next_node = head->next;
    if (next_node != NULL) {
      head->next = next_node->next;
      free(next_node);
    }
  }
}

/** Returns Heap-allocated memory of the token.
 *  When the return value is no longer needed,
 *  free the memory.
 */
void ll_peek(list *head, char buf[32]) {
  char *tok;
  if (head->next == NULL) {
    tok = "";
  } else {
    tok = head->next->token;
  }
  strncpy(buf, tok, sizeof(head->token));
}

// TODO(@self) add pointer to the back of the list
// to the SENTINEL for O(1) insertions
void ll_append(list *head, char *val) {
  if (val == NULL) return;
  while (head->next != NULL) {
    head = head->next;
  }
  list *node = malloc(sizeof(list));
  strncpy(node->token, val, sizeof(node->token));
  node->next = NULL;
  head->next = node;
}

void ll_destroy(list *head) {
  list *tmp;
  do {
    tmp = head->next;
    free(head);
    head = tmp;
  } while (head != NULL);
}

bool ll_is_empty(list *head) { return (head->next == NULL); }
