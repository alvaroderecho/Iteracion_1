/**
 * @brief It tests player module
 *
 * @file player_test_en.c
 * @author Grupo C 2111
 * @version 2.0
 * @date 13-04-2021
 * @updated 13-04-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "player_test.h"
#include "test.h"

#define MAX_TESTS 22

/**
 * @brief Main function for PLAYER unit tests.
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
    printf("Running all test for module Player:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_player_create();
  if (all || test == 2) test2_player_create();
  if (all || test == 3) test1_player_setId();
  if (all || test == 4) test2_player_setId();
  if (all || test == 5) test1_player_setName();
  if (all || test == 6) test2_player_setName();
  if (all || test == 7) test1_player_set_location();
  if (all || test == 8) test2_player_set_location();
  if (all || test == 9) test1_player_add_object();
  if (all || test == 10) test2_player_add_object();
  if (all || test == 11) test1_player_del_object();
  if (all || test == 12) test2_player_del_object();
  if (all || test == 13) test1_player_getId();
  if (all || test == 14) test2_player_getId();
  if (all || test == 15) test1_player_getName();
  if (all || test == 16) test2_player_getName();
  if (all || test == 17) test1_player_getLocation();
  if (all || test == 18) test1_player_getObjects();
  if (all || test == 19) test2_player_getObjects();
  if (all || test == 20) test1_player_containsObject();
  if (all || test == 21) test2_player_containsObject();
  if (all || test == 22) test3_player_containsObject();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_player_create(){
  int result = player_create(1)!=NULL ;
  PRINT_TEST_RESULT(result);
}

void test2_player_create(){
  Player *p;
  p = player_create(4);
  PRINT_TEST_RESULT(player_get_id(p) == 4);
}

void test1_player_setId(){
  Player *p;
  p = player_create(3);
  PRINT_TEST_RESULT(player_set_id(p, 2) == OK);
}

void test2_player_setId(){
  Player *p;
  p = player_create(3);
  player_set_id(p, 2);
  PRINT_TEST_RESULT(player_get_id(p) == 2);
}

void test1_player_setName(){
  Player *p = player_create(1);
  PRINT_TEST_RESULT(player_set_name(p, "pablo") == OK);
}

void test2_player_setName(){
  Player *p = player_create(1);
  PRINT_TEST_RESULT(player_set_name(p, NULL) == ERROR);
}

void test1_player_set_location(){
  Player *p = player_create(3);
  PRINT_TEST_RESULT(player_set_location(p, 2) == OK);
}

void test2_player_set_location(){
  Player *p = player_create(4);
  player_set_location(p, 2);
  PRINT_TEST_RESULT(player_get_location(p) == 2);
}

void test1_player_add_object(){
  Player *p = player_create(4);
  PRINT_TEST_RESULT(player_add_object(p, 3) == OK);
}

void test2_player_add_object(){
  Player *p = player_create(4);
  player_add_object(p, 3);
  PRINT_TEST_RESULT(player_containsObject(p, 3) == TRUE);
}

void test1_player_del_object(){
  Player *p = player_create(4);
  PRINT_TEST_RESULT(player_del_object(p, 3) != OK);
}

void test2_player_del_object(){
  Player *p = player_create(4);
  player_add_object(p, 3);
  PRINT_TEST_RESULT(player_del_object(p, 3) == OK);
}

void test1_player_getId(){
  Player *p = player_create(2);
  PRINT_TEST_RESULT(player_get_id(p) == 2);
}

void test2_player_getId(){
  Player *p = NULL;
  PRINT_TEST_RESULT(player_get_id(p) == NO_ID);
}

void test1_player_getName(){
  Player *p = player_create(2);
  char *aux = "Pablo";
  player_set_name(p, aux);
  PRINT_TEST_RESULT(player_get_name(p) == aux);
}

void test2_player_getName(){
  Player *p = player_create(2);
  PRINT_TEST_RESULT(player_get_name(p) == NULL);
}

void test1_player_getLocation(){
  Player *p = NULL;
  PRINT_TEST_RESULT(player_get_location(p) == NO_ID);
}

void test1_player_getObjects(){
  Player *p = NULL;
  PRINT_TEST_RESULT(player_get_objects(p) == NULL);
}

void test2_player_getObjects(){
  Player *p = player_create(2);
  player_add_object(p, 5);
  PRINT_TEST_RESULT(player_get_objects(p) != NULL);
}

void test1_player_containsObject(){
  Player *p = NULL;
  PRINT_TEST_RESULT(player_containsObject(p, 2) == FALSE);
}

void test2_player_containsObject(){
  Player *p = player_create(2);
  player_add_object(p, 3);
  PRINT_TEST_RESULT(player_containsObject(p, 3) == TRUE);
}

void test3_player_containsObject(){
  Player *p = player_create(2);
  player_add_object(p, 3);
  PRINT_TEST_RESULT(player_containsObject(p, 2) == FALSE);
}
