/**
 * @brief It tests object module
 *
 * @file object_test_en.c
 * @author Grupo C 2111
 * @version 2.0
 * @date 17-04-2021
 * @updated 17-04-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "object_test.h"
#include "test.h"

#define MAX_TESTS 29

/**
 * @brief Main function for OBJECT unit tests.
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
    printf("Running all test for module Object:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_object_create();
  if (all || test == 2) test2_object_create();
  if (all || test == 3) test1_object_setId();
  if (all || test == 4) test2_object_setId();
  if (all || test == 5) test1_object_setName();
  if (all || test == 6) test2_object_setName();
  if (all || test == 7) test1_object_set_description();
  if (all || test == 8) test2_object_set_description();
  if (all || test == 9) test1_object_get_id();
  if (all || test == 10) test2_object_get_id();
  if (all || test == 11) test1_object_get_name();
  if (all || test == 12) test2_object_get_name();
  if (all || test == 13) test1_object_get_description();
  if (all || test == 14) test1_object_get_description();
  if (all || test == 15) test1_object_set_dependency();
  if (all || test == 16) test2_object_set_dependency();
  if (all || test == 17) test1_object_set_open();
  if (all || test == 18) test2_object_set_open();
  if (all || test == 19) test1_object_set_ilumninate();
  if (all || test == 20) test2_object_set_ilumninate();
  if (all || test == 21) test3_object_set_ilumninate();
  if (all || test == 22) test1_object_set_turnedon();
  if (all || test == 23) test2_object_set_turnedon();
  if (all || test == 24) test3_object_set_turnedon();
  if (all || test == 25) test1_object_can_iluminate();
  if (all || test == 26) test1_object_is_on();
  if (all || test == 27) test1_object_get_dependency();
  if (all || test == 28) test1_object_get_open();
  if (all || test == 29) test1_object_is_movable();
  PRINT_PASSED_PERCENTAGE;

  return 1;
}


void test1_object_create(){
  int result = object_create(1)!=NULL ;
  PRINT_TEST_RESULT(result);
}

void test2_object_create(){
  Object *o;
  o = object_create(4);
  PRINT_TEST_RESULT(object_get_id(o) == 4);
}

void test1_object_setId(){
  Object *o;
  o = object_create(3);
  PRINT_TEST_RESULT(object_set_id(o, 2) == OK);
}

void test2_object_setId(){
  Object *o;
  o = object_create(3);
  object_set_id(o, 2);
  PRINT_TEST_RESULT(object_get_id(o) == 2);
}

void test1_object_setName(){
  Object *o = object_create(1);
  PRINT_TEST_RESULT(object_set_name(o, "pablo") == OK);
}

void test2_object_setName(){
  Object *o = object_create(1);
  PRINT_TEST_RESULT(object_set_name(o, NULL) == ERROR);
}

void test1_object_set_description() {
  Object *o = object_create(4);
  PRINT_TEST_RESULT(object_set_description(o, "hola") == OK);
}

void test2_object_set_description() {
  Object *o = NULL;
  PRINT_TEST_RESULT(object_set_description(o, "hola") == ERROR);
}

void test1_object_get_id() {
  Object *o = object_create(25);
  PRINT_TEST_RESULT(object_get_id(o) == 25);
}

void test2_object_get_id() {
  Object *o = NULL;
  PRINT_TEST_RESULT(object_get_id(o) == NO_ID);
}

void test1_object_get_name() {
  Object *o = object_create(3);
  object_set_name(o, "adios");
  PRINT_TEST_RESULT(strcmp(object_get_name(o), "adios") == 0);
}

void test2_object_get_name() {
  Object *o = NULL;
  PRINT_TEST_RESULT(object_get_name(o) == NULL);
}

void test1_object_get_description() {
  Object *o = object_create(5);
  object_set_description(o, "adios");
  PRINT_TEST_RESULT(strcmp(object_get_description(o), "adios") == 0);

}

void test2_object_get_description() {
  Object *o = NULL;
  PRINT_TEST_RESULT(object_get_description(o) == NULL);
}

void test1_object_set_dependency(){
  Object *object = NULL;
  PRINT_TEST_RESULT(object_set_dependency(object,1) == ERROR);
}

void test2_object_set_dependency(){
  Object *object;
  object = object_create(8);
  PRINT_TEST_RESULT(object_set_dependency(object,1) == OK);
}

void test1_object_set_open() {
  Object *o = object_create(8);
  PRINT_TEST_RESULT(object_set_open(o,1) == OK);
}

void test2_object_set_open() {
  Object *o = NULL;
  PRINT_TEST_RESULT(object_set_open(o,1) == ERROR);
}

void test1_object_set_ilumninate() {
  Object *o = NULL;
  PRINT_TEST_RESULT(object_set_ilumninate(o,FALSE) == ERROR);
}

void test2_object_set_ilumninate() {
  Object *o = object_create(8);
  PRINT_TEST_RESULT(object_set_ilumninate(o,TRUE) == OK);
}

void test3_object_set_ilumninate() {
  Object *o = object_create(8);
  PRINT_TEST_RESULT(object_set_ilumninate(o,FALSE) == OK);
}

void test1_object_set_turnedon() {
  Object *o = NULL;
  PRINT_TEST_RESULT(object_set_turnedon(o,FALSE) == ERROR);
}

void test2_object_set_turnedon() {
  Object *o = object_create(8);
  PRINT_TEST_RESULT(object_set_turnedon(o,TRUE) == OK);
}

void test3_object_set_turnedon() {
  Object *o = object_create(8);
  PRINT_TEST_RESULT(object_set_turnedon(o,FALSE) == OK);
}

void test1_object_can_iluminate(){
  Object *o = NULL;
  PRINT_TEST_RESULT(object_can_iluminate(o) == FALSE);
}
void test1_object_is_on(){
  Object *o = NULL;
  PRINT_TEST_RESULT(object_is_on(o) == FALSE);
}
void test1_object_get_dependency(){
  Object *o = NULL;
  PRINT_TEST_RESULT(object_get_dependency(o) == NO_ID);
}
void test1_object_get_open(){
  Object *o = NULL;
  PRINT_TEST_RESULT(object_get_open(o) == NO_ID);
}
void test1_object_is_movable(){
  Object *o = NULL;
  PRINT_TEST_RESULT(object_is_movable(o) == FALSE);
}