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
#include "unittest/test_list.h"

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <include/list.h>
#include <stdbool.h>

void test_ll_create() {
  list *ll = ll_create();
  CU_ASSERT_NOT_EQUAL(ll, NULL);
  CU_ASSERT_TRUE(ll_is_empty(ll));
  ll_destroy(ll);
}

void test_ll_null_peek() {
  list *ll = ll_create();
  char buf[32];
  ll_peek(ll, buf);
  CU_ASSERT_STRING_EQUAL(buf, "");
  ll_peek(ll, buf);
  CU_ASSERT_STRING_EQUAL(buf, "");
  CU_ASSERT_TRUE(ll_is_empty(ll));
  ll_destroy(ll);
}

void test_ll_append_peek() {
  char buf1[32], buf2[32], buf3[32];
  list *ll = ll_create();
  CU_ASSERT_TRUE(ll_is_empty(ll));
  char *tok = "void";
  ll_append(ll, tok);
  CU_ASSERT_FALSE(ll_is_empty(ll));
  ll_peek(ll, buf1);
  ll_peek(ll, buf2);
  ll_peek(ll, buf3);
  CU_ASSERT_STRING_EQUAL(buf1, tok);
  CU_ASSERT_STRING_EQUAL(buf2, tok);
  CU_ASSERT_STRING_EQUAL(buf3, tok);
  ll_destroy(ll);
}

void test_ll_append_pop() {
  char buf1[32], buf2[32];
  list *ll = ll_create();
  char *toks[] = {"void", "#define", "array[0]"};
  ll_append(ll, toks[0]);
  ll_append(ll, toks[1]);
  ll_append(ll, toks[2]);
  CU_ASSERT_FALSE(ll_is_empty(ll));
  ll_peek(ll, buf1);
  ll_pop_front(ll, buf2);
  CU_ASSERT_STRING_EQUAL(buf1, toks[0]);
  CU_ASSERT_STRING_EQUAL(buf2, toks[0]);
  ll_peek(ll, buf1);
  ll_pop_front(ll, buf2);
  CU_ASSERT_STRING_EQUAL(buf1, toks[1]);
  CU_ASSERT_STRING_EQUAL(buf2, toks[1]);
  ll_peek(ll, buf1);
  ll_pop_front(ll, buf2);
  CU_ASSERT_STRING_EQUAL(buf1, toks[2]);
  CU_ASSERT_STRING_EQUAL(buf2, toks[2]);
  ll_peek(ll, buf1);
  ll_pop_front(ll, buf2);
  CU_ASSERT_STRING_EQUAL(buf1, "");
  CU_ASSERT_STRING_EQUAL(buf2, "");
  CU_ASSERT_TRUE(ll_is_empty(ll));
  ll_destroy(ll);
}

void test_ll_max_token_len() {
  list *ll = ll_create();
  char big_buf[60];
  char *tok_long = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  char *tok_32 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  ll_append(ll, tok_long);
  ll_peek(ll, big_buf);
  CU_ASSERT_STRING_NOT_EQUAL(big_buf, tok_long);
  CU_ASSERT_STRING_EQUAL(big_buf, tok_32);
  ll_destroy(ll);
}

void test_ll_null_token() {
  list *ll = ll_create();
  char *tok = NULL;
  ll_append(ll, tok);
  CU_ASSERT_TRUE(ll_is_empty(ll));
  ll_destroy(ll);
}

CU_TestInfo ll_tests[] = {
    {"test_ll_create", test_ll_create},
    {"test_ll_null_peek", test_ll_null_peek},
    {"test_ll_append_peek", test_ll_append_peek},
    {"test_ll_append_pop", test_ll_append_pop},
    {"test_ll_max_token_len", test_ll_max_token_len},
    {"test_ll_null_token", test_ll_null_token},
    CU_TEST_INFO_NULL,
};
