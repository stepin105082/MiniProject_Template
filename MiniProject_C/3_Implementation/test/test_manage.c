

#include "unity.h"
#include "manage.h"
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/*Required for the first test cases*/


struct Customer c={.phone="1234567890"};

struct Customer d={.phone="123456"};

void test_phone(void)
{
  TEST_ASSERT_EQUAL(1, phone_check(c));
  TEST_ASSERT_EQUAL(0, phone_check(d));
}

void temperature_1(void)
{
  TEST_ASSERT_EQUAL(1, temp_check());
  TEST_ASSERT_EQUAL(1, temp_check());
}

void sanitize_check(void)
{
  TEST_ASSERT_EQUAL(1, sanitize());
  TEST_ASSERT_EQUAL(1, sanitize());
}

void temperature_2(void)
{
    TEST_ASSERT_NOT_EQUAL(0,temp_check());
    TEST_ASSERT_NOT_EQUAL(0,temp_check());
}

int test_main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_phone);
  RUN_TEST(sanitize_check);
  RUN_TEST(temperature_1);
  RUN_TEST(temperature_2);


  /* Close the Unity Test Framework */
  return UNITY_END();
}

