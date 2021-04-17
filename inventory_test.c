/**
 * @brief It tests inventory module
 *
 * @file inventory_test_en.c
 * @author Profesores Pprog
 * @version 2.0
 * @date 13-04-2021
 * @updated 13-04-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "inventory_test.h"
#include "test.h"

#define MAX_TESTS 20

/**
 * @brief Main function for INVENTORY unit tests.
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
    printf("Running all test for module Inventory:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_inventory_create();
  if (all || test == 2) test2_inventory_create();
  if (all || test == 3) test1_inventory_destroy();
  if (all || test == 4) test1_inventory_getIds();
  if (all || test == 5) test2_inventory_getIds();
  if (all || test == 6) test1_inventory_getMaxInv();
  if (all || test == 7) test1_inventory_addId();
  if (all || test == 8) test2_inventory_addId();
  if (all || test == 9) test1_inventory_delId();
  if (all || test == 10) test2_inventory_delId();
  if (all || test == 11) test3_inventory_delId();
  if (all || test == 12) test1_inventory_setMaxInv();
  if (all || test == 13) test2_inventory_setMaxInv();
  if (all || test == 14) test1_inventory_containsObject();
  if (all || test == 15) test2_inventory_containsObject();
  if (all || test == 16) test3_inventory_containsObject();
  if (all || test == 17) test4_inventory_containsObject();
  if (all || test == 18) test5_inventory_containsObject();
  if (all || test == 19) test1_inventory_isEmpty();
  if (all || test == 20) test2_inventory_isEmpty();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}


void test1_inventory_create() {
  int result = inventory_create(6)!= NULL ;
  PRINT_TEST_RESULT(result);
}

void test2_inventory_create() {
  Inventory *in;
  in = inventory_create(8);
  PRINT_TEST_RESULT(inventory_getMaxInv(in) == 8);
}

void test1_inventory_destroy(){
  Inventory *in;
  in = inventory_create(7);
  PRINT_TEST_RESULT(inventory_destroy(in) == OK);
}

void test1_inventory_getIds(){
  Inventory *in;
  Id *ids;
  in = inventory_create(6);
  ids = inventory_getIds(in);
  PRINT_TEST_RESULT(ids[0] == NO_ID);
}

void test2_inventory_getIds(){
  Inventory *in;
  Id *ids;
  in = inventory_create(6);
  inventory_addId(in, 5);
  ids = inventory_getIds(in);
  PRINT_TEST_RESULT(ids[0] == 5);
}

void test1_inventory_getMaxInv(){
  Inventory *in;
  in = inventory_create(2);
  PRINT_TEST_RESULT(inventory_getMaxInv(in) == 2);
}

void test1_inventory_addId(){
  Inventory *in;
  in = inventory_create(1);
  PRINT_TEST_RESULT(inventory_addId(in, 4) == OK);
}

void test2_inventory_addId(){
  Inventory *in;
  in = inventory_create(1);
  inventory_addId(in, 2);
  PRINT_TEST_RESULT(inventory_addId(in, 4) == ERROR);
}

void test1_inventory_delId(){
  Inventory *in;
  in = inventory_create(1);
  PRINT_TEST_RESULT(inventory_delId(in, 3) == ERROR);
}

void test2_inventory_delId(){
  Inventory *in;
  in = inventory_create(1);
  inventory_addId(in, 2);
  PRINT_TEST_RESULT(inventory_delId(in, 2) == OK);
}

void test3_inventory_delId(){
  Inventory *in;
  in = inventory_create(1);
  inventory_addId(in, 2);
  PRINT_TEST_RESULT(inventory_delId(in, 1) == ERROR);
}

void test1_inventory_setMaxInv(){
  Inventory *in;
  in = inventory_create(1);
  PRINT_TEST_RESULT(inventory_setMaxInv(in, 3) == OK);
}

void test2_inventory_setMaxInv(){
  Inventory *in;
  in = inventory_create(1);
  inventory_setMaxInv(in, 3);
  PRINT_TEST_RESULT(inventory_getMaxInv(in) == 3);
}

void test1_inventory_containsObject(){
  Inventory *in;
  in = inventory_create(1);
  inventory_addId(in, 1);
  PRINT_TEST_RESULT(inventory_containsObject(in, 1) == TRUE);
}

void test2_inventory_containsObject(){
  Inventory *in;
  in = inventory_create(1);
  inventory_addId(in, 2);
  PRINT_TEST_RESULT(inventory_containsObject(in, 3) == FALSE);
}

void test3_inventory_containsObject(){
  Inventory *in;
  in = inventory_create(1);
  PRINT_TEST_RESULT(inventory_containsObject(in, 3) == FALSE);
}

void test4_inventory_containsObject(){
  Inventory *in;
  in = inventory_create(3);
  inventory_addId(in, 2);
  inventory_addId(in, 1);
  PRINT_TEST_RESULT(inventory_containsObject(in, 1) == TRUE);
}

void test5_inventory_containsObject(){
  Inventory *in;
  in = inventory_create(3);
  inventory_addId(in, 2);
  inventory_addId(in, 1);
  inventory_delId(in, 2);
  PRINT_TEST_RESULT(inventory_containsObject(in, 2) == FALSE);
}

void test1_inventory_isEmpty(){
  Inventory *in;
  in = inventory_create(1);
  inventory_addId(in, 1);
  PRINT_TEST_RESULT(inventory_isEmpty(in) == FALSE);
}

void test2_inventory_isEmpty(){
  Inventory *in;
  in = inventory_create(1);
  PRINT_TEST_RESULT(inventory_isEmpty(in) == TRUE);
}
