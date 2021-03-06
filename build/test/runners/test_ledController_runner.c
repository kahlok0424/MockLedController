/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  CMock_Init(); \
  UNITY_CLR_DETAILS(); \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT()) \
  { \
    tearDown(); \
    CMock_Verify(); \
  } \
  CMock_Destroy(); \
  UnityConcludeTest(); \
}

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include "cmock.h"
#include <setjmp.h>
#include <stdio.h>
#include "mock_Button.h"
#include "mock_Led.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_tapTurnOnTapOffLed_given_led_is_off_and_button_is_pressed_and_release_expect_led_ON(void);
extern void test_tapTurnOnTapOffLed_given_led_is_off_and_button_is_pressed_and_release_expect_led_FAKE(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_Button_Init();
  mock_Led_Init();
}
static void CMock_Verify(void)
{
  mock_Button_Verify();
  mock_Led_Verify();
}
static void CMock_Destroy(void)
{
  mock_Button_Destroy();
  mock_Led_Destroy();
}

/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
  CMock_Verify();
  CMock_Destroy();
  tearDown();
  CMock_Init();
  setUp();
}


/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_ledController.c");
  RUN_TEST(test_tapTurnOnTapOffLed_given_led_is_off_and_button_is_pressed_and_release_expect_led_ON, 97);
  RUN_TEST(test_tapTurnOnTapOffLed_given_led_is_off_and_button_is_pressed_and_release_expect_led_FAKE, 115);

  CMock_Guts_MemFreeFinal();
  return (UnityEnd());
}
