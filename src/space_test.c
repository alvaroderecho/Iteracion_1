/**
 * @brief It tests space module
 *
 * @file space_test_en.c
 * @author Profesores Pprog
 * @version 2.0
 * @date 16-01-2015
 * @updated 19-01-2016
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"
#include "space_test.h"
#include "test.h"
#include "link.h"

#define MAX_TESTS 46

/**
 * @brief Main function for SPACE unit tests.
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
    printf("Running all test for module Space:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_space_create();
  if (all || test == 2) test2_space_create();
  if (all || test == 3) test1_space_set_name();
  if (all || test == 4) test2_space_set_name();
  if (all || test == 5) test3_space_set_name();
  if (all || test == 6) test1_space_set_north();
  if (all || test == 7) test2_space_set_north();
  if (all || test == 8) test1_space_set_south();
  if (all || test == 9) test2_space_set_south();
  if (all || test == 10) test1_space_set_east();
  if (all || test == 11) test2_space_set_east();
  if (all || test == 12) test1_space_set_west();
  if (all || test == 13) test2_space_set_west();
  if (all || test == 14) test1_space_get_name();
  if (all || test == 15) test2_space_get_name();
  if (all || test == 16) test1_space_get_object();
  if (all || test == 17) test2_space_get_object();
  if (all || test == 18) test3_space_get_object();
  if (all || test == 19) test1_space_get_north();
  if (all || test == 20) test2_space_get_north();
  if (all || test == 21) test1_space_get_south();
  if (all || test == 22) test2_space_get_south();
  if (all || test == 23) test1_space_get_east();
  if (all || test == 24) test2_space_get_east();
  if (all || test == 25) test1_space_get_west();
  if (all || test == 26) test2_space_get_west();
  if (all || test == 27) test1_space_get_id();
  if (all || test == 28) test2_space_get_id();
  if (all || test == 29) test1_space_set_description();
  if (all || test == 30) test2_space_set_description();
  if (all || test == 31) test1_space_get_description();
  if (all || test == 32) test2_space_get_description();
  if (all || test == 33) test1_space_add_object();
  if (all || test == 34) test2_space_add_object();
  if (all || test == 35) test1_space_get_up();
  if (all || test == 36) test2_space_get_up();
  if (all || test == 37) test1_space_get_down();
  if (all || test == 38) test2_space_get_down();
  if (all || test == 39) test1_space_set_up();
  if (all || test == 40) test2_space_set_up();
  if (all || test == 41) test1_space_set_down();
  if (all || test == 42) test2_space_set_down();
  if (all || test == 43) test1_space_get_illuminate();
  if (all || test == 44) test2_space_get_illuminate();
  if (all || test == 45) test1_space_set_illuminate();
  if (all || test == 46) test2_space_set_illuminate();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_space_create() {
  int result = space_create(5)!=NULL ;
  PRINT_TEST_RESULT(result);
}

void test2_space_create() {
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_get_id(s) == 4);
}

void test1_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, "hola") == OK);
}

void test2_space_set_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

void test3_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
}

void test1_space_set_north() {
  Space *s;
  Link * l = link_create(1);
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_north(s, l) == OK);
}

void test2_space_set_north() {
  Space *s = NULL;
  Link * l = link_create(1);
  PRINT_TEST_RESULT(space_set_north(s, l) == ERROR);
}

void test1_space_set_south() {
  Space *s;
  Link * l = link_create(1);

  s = space_create(5);
  PRINT_TEST_RESULT(space_set_south(s, l) == OK);
}

void test2_space_set_south() {
  Space *s = NULL;
  Link * l = link_create(1);

  PRINT_TEST_RESULT(space_set_south(s, l) == ERROR);
}

void test1_space_set_east() {
  Space *s;
  s = space_create(5);
  Link * l = link_create(1);

  PRINT_TEST_RESULT(space_set_east(s, l) == OK);
}

void test2_space_set_east() {
  Space *s = NULL;
  Link * l = link_create(1);

  PRINT_TEST_RESULT(space_set_east(s, l) == ERROR);
}

void test1_space_set_west() {
  Space *s;
  Link * l = link_create(1);

  s = space_create(5);

  PRINT_TEST_RESULT(space_set_west(s, l) == OK);
}

void test2_space_set_west() {
  Space *s = NULL;
  Link * l = link_create(1);

  PRINT_TEST_RESULT(space_set_west(s, l) == ERROR);
}

void test1_space_set_up() {
  Space *s;
  Link * l = link_create(1);

  s = space_create(5);

  PRINT_TEST_RESULT(space_set_up(s, l) == OK);
}

void test2_space_set_up() {
  Space *s = NULL;
  Link * l = link_create(1);

  PRINT_TEST_RESULT(space_set_up(s, l) == ERROR);
}

void test1_space_set_down() {
  Space *s;
  Link * l = link_create(1);

  s = space_create(5);

  PRINT_TEST_RESULT(space_set_down(s, l) == OK);
}

void test2_space_set_down() {
  Space *s = NULL;
  Link * l = link_create(1);

  PRINT_TEST_RESULT(space_set_down(s, l) == ERROR);
}

void test1_space_add_object() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_add_object(s,TRUE) == OK);
}

void test2_space_add_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_add_object(s,TRUE) == ERROR);
}

void test1_space_get_name() {
  Space *s;
  s = space_create(1);
  space_set_name(s, "adios");
  PRINT_TEST_RESULT(strcmp(space_get_name(s), "adios") == 0);

}

void test2_space_get_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_name(s) == NULL);

}

void test1_space_get_object() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_get_object(s,0) == NO_ID);

}

void test2_space_get_object() {
  Space *s;
  s = space_create(1);
  space_add_object(s,1);
  PRINT_TEST_RESULT(space_get_object(s,0) == 1);

}

void test3_space_get_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_object(s,0) == NO_ID);
}

void test1_space_get_north() {
  Space *s;
  Link *l = link_create(1);
  s = space_create(5);

  space_set_north(s, l);
  PRINT_TEST_RESULT(space_get_north(s) == l);
}

void test2_space_get_north() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_north(s) == NULL);
}

void test1_space_get_south() {
  Space *s;
  Link *l = link_create(1);

  s = space_create(5);
  space_set_south(s, l);
  PRINT_TEST_RESULT(space_get_south(s) == l);
}

void test2_space_get_south() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_south(s) == NULL);
}

void test1_space_get_east() {
  Space *s;
  Link *l = link_create(1);

  s = space_create(5);
  space_set_east(s, l);
  PRINT_TEST_RESULT(space_get_east(s) == l);
}

void test2_space_get_east() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_east(s) == NULL);
}

void test1_space_get_west() {
  Space *s;
    Link *l = link_create(1);

  s = space_create(5);
  space_set_west(s, l);
  PRINT_TEST_RESULT(space_get_west(s) == l);
}

void test2_space_get_west() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_west(s) == NULL);
}

void test1_space_get_up() {
  Space *s;
    Link *l = link_create(1);

  s = space_create(5);
  space_set_up(s, l);
  PRINT_TEST_RESULT(space_get_up(s) == l);
}

void test2_space_get_up() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_up(s) == NULL);
}

void test1_space_get_down() {
  Space *s;
    Link *l = link_create(1);

  s = space_create(5);
  space_set_down(s, l);
  PRINT_TEST_RESULT(space_get_down(s) == l);
}

void test2_space_get_down() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_up(s) == NULL);
}

void test1_space_get_id() {
  Space *s;
  s = space_create(25);
  PRINT_TEST_RESULT(space_get_id(s) == 25);
}

void test2_space_get_id() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}

void test1_space_set_description() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_description(s, "hola") == OK);
}

void test2_space_set_description() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_description(s, "hola") == ERROR);
}

void test1_space_get_description() {
  Space *s;
  s = space_create(1);
  space_set_description(s, "adios");
  PRINT_TEST_RESULT(strcmp(space_get_description(s), "adios") == 0);

}

void test2_space_get_description() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_description(s) == NULL);
}

void test1_space_get_illuminate() {
  Space *s = space_create(1);
  PRINT_TEST_RESULT(space_get_illuminate(s) == TRUE);
}

void test2_space_get_illuminate() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_illuminate(s) == FALSE);
}

void test1_space_set_illuminate() {
  Space *s = space_create(1);
  PRINT_TEST_RESULT(space_set_illuminate(s,TRUE) == OK);
}

void test2_space_set_illuminate() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_illuminate(s,TRUE) == ERROR);
}