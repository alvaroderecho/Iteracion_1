#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"
#include "test.h"
#include "link_test.h"

#define MAX_TESTS 25

int main(int argc, char **argv)
{

  int test = 0;
  int all = 1;

  if (argc < 2)
  {
    printf("Running all test for module Set:\n");
  }
  else
  {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 || test > MAX_TESTS)
    {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  //tests

if (all || test == 1) test1_link_create();
if (all || test == 2) test2_link_create();
if (all || test == 3) test1_link_destroy();
if (all || test == 4) test2_link_destroy();
if (all || test == 5) test1_link_set_name();
if (all || test == 6) test2_link_set_name();
if (all || test == 7) test3_link_set_name();
if (all || test == 8) test1_link_set_sp1();
if (all || test == 9) test2_link_set_sp1();
if (all || test == 10) test1_link_set_sp2();
if (all || test == 11) test2_link_set_sp2();
if (all || test == 12) test1_link_change_state();
if (all || test == 13) test2_link_change_state();
if (all || test == 14) test1_link_getId();
if (all || test == 15) test2_link_getId();
if (all || test == 16) test1_link_getname();
if (all || test == 17) test2_link_getname();
if (all || test == 18) test1_link_get_sp1();
if (all || test == 19) test2_link_get_sp2();
if (all || test == 20) test1_link_get_sp2();
if (all || test == 21) test2_link_get_sp2();
if (all || test == 22) test1_link_get_state();
if (all || test == 23) test2_link_get_state();
if (all || test == 24) test1_link_print();
if (all || test == 25) test2_link_print();


  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_link_create()
{
  int result = link_create(5) != NULL;
  PRINT_TEST_RESULT(result);
}

void test2_link_create()
{
  Link *l = link_create(NO_ID);
  PRINT_TEST_RESULT(l == NULL);
}

void test1_link_destroy()
{
  Link *l = link_create(5);
  PRINT_TEST_RESULT(link_destroy(l) == OK);
}

void test2_link_destroy()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_destroy(l) == ERROR);
}

void test1_link_set_name()
{
  Link *l = link_create(5);
  PRINT_TEST_RESULT(link_set_name(l, "nombre") == OK);
}

void test2_link_set_name()
{
  Link *l = link_create(5);
  PRINT_TEST_RESULT(link_set_name(l, NULL) == ERROR);
}

void test3_link_set_name()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_name(l, "nombre") == ERROR);
}

void test1_link_set_sp1()
{
  Link *l = link_create(5);
  PRINT_TEST_RESULT(link_set_sp1(l, 5) == OK);
}

void test2_link_set_sp1()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_sp1(l, 5) == ERROR);
}

void test1_link_set_sp2()
{
  Link *l = link_create(5);
  PRINT_TEST_RESULT(link_set_sp2(l, 5) == OK);
}

void test2_link_set_sp2()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_sp2(l, 5) == ERROR);
}

void test1_link_change_state()
{
  Link *l = link_create(5);
  PRINT_TEST_RESULT(link_change_state(l) == OK);
}

void test2_link_change_state()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_change_state(l) == ERROR);
}

void test1_link_getId()
{
  Link *l = link_create(5);
  PRINT_TEST_RESULT(link_getId(l) == 5);
}

void test2_link_getId()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_getId(l) == NO_ID);
}

void test1_link_getname()
{
  Link *l = link_create(5);
  PRINT_TEST_RESULT(strcmp((link_get_name(l)), "") == 0);
}

void test2_link_getname()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_name(l) == NULL);
}

void test1_link_get_sp1()
{
  Link *l = link_create(5);
  PRINT_TEST_RESULT(link_get_sp1(l) == NO_ID);
}

void test2_link_get_sp1()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_sp1(l) == NO_ID);
}

void test1_link_get_sp2()
{
  Link *l = link_create(5);
  PRINT_TEST_RESULT(link_get_sp2(l) == NO_ID);
}

void test2_link_get_sp2()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_sp2(l) == NO_ID);
}

void test1_link_get_state()
{
  Link *l = link_create(5);
  PRINT_TEST_RESULT(link_get_state(l) == TRUE);
}

void test2_link_get_state()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_state(l) == TRUE);
}

void test1_link_print()
{
  Link *l = link_create(5);
  PRINT_TEST_RESULT(link_print(l) == OK);
}

void test2_link_print()
{
  Link *l = NULL;
  PRINT_TEST_RESULT(link_print(l) == ERROR);
}