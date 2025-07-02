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
#ifndef __DS_H
#define __DS_H
#include <stdbool.h>
/********************/
/* FIFO Linked list */
/********************/
typedef struct ll_node list;

list *ll_create();

void ll_pop_front(list *, char buf[32]);
void ll_peek(list *, char buf[32]);
void ll_append(list *, char *val);
void ll_destroy(list *);
bool ll_is_empty(list *);
#endif
