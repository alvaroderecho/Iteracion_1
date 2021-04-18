#include <stdio.h>
#include <stdlib.h>
#include "set.h"
#include "test.h"
#include "set_test.h"

#define MAX_TESTS 20
#define MAX_SET 1024

int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Set:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 || test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }
  if (all || test == 1) test1_set_create();
  if (all || test == 2) test1_set_destroy();
  if (all || test == 3) test2_set_destroy();
  if (all || test == 4) test1_set_add_values();
  if (all || test == 5) test2_set_add_values();
  if (all || test == 6) test3_set_add_values();
  if (all || test == 7) test4_set_add_values();
  if (all || test == 8) test1_set_del_values();
  if (all || test == 9) test2_set_del_values();
  if (all || test == 10) test3_set_del_values();
  if (all || test == 11) test4_set_del_values();
  if (all || test == 12) test1_set_print();
  if (all || test == 13) test2_set_print();
  if (all || test == 14) test1_set_get_ids();
  if (all || test == 15) test1_set_get_numids();
  if (all || test == 16) test1_set_containsId();
  if (all || test == 17) test2_set_containsId();
  if (all || test == 18) test3_set_containsId();
  
  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_set_create() {
    int result = set_create()!=NULL;
    PRINT_TEST_RESULT(result);
}

void test1_set_destroy() {
    Set * s = NULL;    
    PRINT_TEST_RESULT(set_destroy(s) == ERROR);
}

void test2_set_destroy() {
    Set * s = set_create();    
    PRINT_TEST_RESULT(set_destroy(s) == OK);
}

void test1_set_add_values() {
    Set * s = NULL;
    PRINT_TEST_RESULT(set_add_values(s,5) == ERROR);
}

void test2_set_add_values() {
    Set * s = set_create();
    PRINT_TEST_RESULT(set_add_values(s,-1) == ERROR);
}

void test3_set_add_values() {
    int i;
    Set *s = set_create();
    for (i=0;i<MAX_SET + 1;i++){
       set_add_values(s,i);
    }
    PRINT_TEST_RESULT(set_add_values(s,i) == ERROR);
    
}

void test4_set_add_values() {
    Set *s = set_create();
    PRINT_TEST_RESULT(set_add_values(s,5) == OK);
}

void test1_set_del_values() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_del_values(s,5) == ERROR);
}

void test2_set_del_values() {
    Set *s = set_create(); //número de valores es 0
    PRINT_TEST_RESULT(set_del_values(s,5) == ERROR);
}

void test3_set_del_values() {
    Set *s = set_create();
    set_add_values(s,5);
    PRINT_TEST_RESULT(set_del_values(s,4) == ERROR);
}

void test4_set_del_values() {
    Set *s = set_create();
    set_add_values(s,5);
    PRINT_TEST_RESULT(set_del_values(s,5) == OK);
}

void test1_set_print() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_print(s) == ERROR);
}

void test2_set_print() {
    Set *s = set_create();
    PRINT_TEST_RESULT(set_print(s) == OK);
}

void test1_set_get_ids(){
    Set *s = NULL;
    PRINT_TEST_RESULT(set_get_ids(s) == NULL);
}

void test1_set_get_numids(){
    Set *s = NULL;
    PRINT_TEST_RESULT(set_get_numids(s) == 0);
}

void test1_set_containsId(){
    Set *s = NULL;
    PRINT_TEST_RESULT(set_containsId(s,1) == FALSE);
}
void test2_set_containsId(){
    Set *s = NULL;
    PRINT_TEST_RESULT(set_containsId(s,-1) == FALSE);
}
void test3_set_containsId(){
    Set *s = set_create();
    PRINT_TEST_RESULT(set_containsId(s,-1) == FALSE);
}
