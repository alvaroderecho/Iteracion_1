/**
 * @brief It tests die module
 *
 * @file die_test_en.c
 * @author Profesores Pprog
 * @version 2.0
 * @date 15-03-2021
 * @updated 15-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "die.h"
#include "die_test.h"
#include "test.h"

#define MAX_TESTS 7

/**
 * @brief Main function for DIE unit tests.
 *
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed
 *   2.- A number means a particular test (the one identified by that number)
 *       is executed
 *
 */
int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Die:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_die_create();
  if (all || test == 2) test2_die_create();
  if (all || test == 3) test1_die_destroy();
  if (all || test == 4) test1_die_getId();
  if (all || test == 5) test1_die_getLastThrow();
  if (all || test == 6) test1_die_roll();
  if (all || test == 7) test2_die_roll();



  PRINT_PASSED_PERCENTAGE;

  return 1;
}


void test1_die_create() {
  int result = die_create(1, 1, 6)!=NULL ;
  PRINT_TEST_RESULT(result);
}

void test2_die_create() {
  Die *d;
  d = die_create(2, 3, 7);
  PRINT_TEST_RESULT(die_getId(d) == 2);
}

void test1_die_destroy(){
  Die *d;
  d = die_create(2, 3, 7);
  PRINT_TEST_RESULT(die_destroy(d) == OK);
}

void test1_die_getId(){
  Die *d = NULL;
  PRINT_TEST_RESULT(die_getId(d) == -1);
}

void test1_die_getLastThrow(){
  Die *d;
  d = die_create(2, 3, 7);
  PRINT_TEST_RESULT(die_getLastThrow(d) == -1);
}

void test1_die_roll(){
  Die *d = NULL;
  PRINT_TEST_RESULT(die_roll(d) == ERROR);
}

void test2_die_roll(){
  Die *d = NULL;
  d = die_create(1, 1, 6);
  die_roll(d);
  PRINT_TEST_RESULT(die_getLastThrow(d) > 0 && die_getLastThrow(d) < 7);
}
