#include "CUnit/Basic.h"
#include <CUnit/CUnit.h>

/* Modify these two lines according to the project */
#include <manage.h>
#define PROJECT_NAME    "Customer_Management"


/* Prototypes for all the test functions */
void test_phone(void);
/*void test_temperature_1(void);
void test_temperature_2(void);
void test_sanitize_check(void);*/

/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */


  /* Add your test functions in this format for testing*/
  CU_add_test(suite, "phone", test_phone);
 /* CU_add_test(suite, "temperature", test_temperature_1());
  CU_add_test(suite, "temperature", test_temperature_2());
  CU_add_test(suite, "sanitize", test_sanitize_check());*/


/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);

  /* run the unit test framework*/
  CU_basic_run_tests();

  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}

struct Customer c={.phone="1234567890"};

struct Customer d={.phone="123456"};

/* Write all the test functions */
void test_phone(void) {
  CU_ASSERT(1 == phone_check(c));
  CU_ASSERT(0 == phone_check(d));
}
/*
void test_subtract(void) {
  CU_ASSERT(-3 == subtract(0, 3));

  CU_ASSERT(1 == subtract(1000, 900));
}

void test_multiply(void) {
  CU_ASSERT(0 == multiply(1, 0));

  CU_ASSERT(2 == multiply(2, 5));
}

void test_divide(void) {
  CU_ASSERT(0 == divide(1, 0));

  CU_ASSERT(3 == divide(2, 2));
}
*/
