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
#include "unittest/unittest_main.h"

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <stdio.h>

#define RED "\033[31m"
#define GREEN "\033[32m"

void test_func1(void) { CU_ASSERT_TRUE(1); }
void test_func2(void) { CU_ASSERT_TRUE(0); }

int init(void) { return 0; }

/* CUnit -- Unit test suite + test runner in C
 * https://cunit.sourceforge.net/doc/introduction.html#usage
 *
 * A typical sequence of steps for using the CUnit framework is:
 * Write functions for tests (and suite init/cleanup if necessary).
 * Initialize the test registry - CU_initialize_registry()
 * Add suites to the test registry - CU_add_suite()
 * Add tests to the suites - CU_add_test()
 * Run tests using an appropriate interface, e.g. CU_console_run_tests
 * Cleanup the test registry - CU_cleanup_registry
 */
int unittest_main() {
  CU_ErrorCode err = CU_initialize_registry();
  if (err != CUE_SUCCESS) goto cleanup;

  CU_pSuite pSuite = CU_add_suite("Suite_1", NULL, NULL);
  if (pSuite == NULL) goto cleanup;

  CU_TestInfo test_array1[] = {
      {"test == true", test_func1},
      {"test == false", test_func2},
      CU_TEST_INFO_NULL,
  };

  // TODO(@self) current version of CUnit is legacy so additional
  // NULL setUp functions are required
  CU_SuiteInfo suites[] = {
      {"suitename1", NULL, NULL, NULL, NULL, test_array1},
      CU_SUITE_INFO_NULL,
  };

  CU_register_suites(suites);

  CU_basic_set_mode(CU_BRM_NORMAL);
  CU_basic_run_tests();

  if (err != CUE_SUCCESS) goto cleanup;

  unsigned int failed = CU_get_number_of_failures();
  if (failed >= 1) {
    printf(RED "%d failed unit test(s)\n", failed);
  } else {
    printf(GREEN "All Unit Tests Pass!\n");
  }
cleanup:
  if (err != CUE_SUCCESS) {
    printf("Error: %s\n", CU_get_error_msg());
  }
  CU_cleanup_registry();
  return err;
}
