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
#include "unittest/test_data_structures.h"

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <include/ds.h>

void test_func1(void) { CU_ASSERT_TRUE(1); }
void test_func2(void) { CU_ASSERT_TRUE(0); }

void test_ll_create() {
  list *ll = ll_create();
  CU_ASSERT_NOT_EQUAL(ll, NULL);
}

void test_ll_null_peek() {
  list *ll = ll_create();
  CU_ASSERT_EQUAL(ll_peek(ll), NULL);
  CU_ASSERT_EQUAL(ll_peek(ll), NULL);
}

void test_ll_append_peek() {
  list *ll = ll_create();
  int val = 20;
  ll_append(ll, (void *)&val);
  CU_ASSERT_EQUAL(ll_peek(ll), val);
  CU_ASSERT_EQUAL(ll_peek(ll), val);
  CU_ASSERT_EQUAL(ll_peek(ll), val);
}

CU_TestInfo ll_tests[] = {
    {"test_ll_create", test_ll_create},
    {"test_ll_null_peek", test_ll_null_peek},
    {"test_ll_append_peek", test_ll_append_peek},
    CU_TEST_INFO_NULL,
};
