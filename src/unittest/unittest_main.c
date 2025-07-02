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
#include <stdio.h>

#include "unittest/test_list.h"

#define RED "\033[31m"
#define GREEN "\033[32m"

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
  /*****************/
  /*  Test Suites  */
  /*****************/
  // TODO(@self) current version of CUnit is legacy so additional
  // NULL setUp functions are required
  CU_SuiteInfo suites[] = {
      {"linked_list_tests", NULL, NULL, NULL, NULL, ll_tests},
      CU_SUITE_INFO_NULL,
  };

  /*****************/
  /*  Test Runner  */
  /*****************/
  CU_register_suites(suites);
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

  if (err != CUE_SUCCESS) goto cleanup;

  /*****************/
  /* Print Results */
  /*****************/
  unsigned int total = CU_get_number_of_tests_run();
  unsigned int failed = CU_get_number_of_tests_failed();
  if (failed >= 1) {
    printf(GREEN "%d passed unit test(s)\n", total - failed);
    printf(RED "%d failed unit test(s)\n", failed);
  } else {
    printf(GREEN "All %d Unit Tests Pass!\n", total);
  }

cleanup:
  if (err != CUE_SUCCESS) {
    printf("Error: %s\n", CU_get_error_msg());
  }
  CU_cleanup_registry();
  return err;
}
