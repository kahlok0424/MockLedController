 #include "unity.h"
#include "ledController.h"
#include "mock_Button.h"
#include "mock_Led.h"
#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>

int turnLedCallNumbers = 0;
int getButtonStateMaxCalls = 0;
int expectedTurnLedMaxCalls = 0;
buttonState *expectedbuttonState = NULL;
ledState *expectedLedStates = NULL;

void setUp(void)
{
}

void tearDown(void)
{
}


char *createMsg(char *format,...){
  va_list valist;
  int neededSize;
  char *buffer;

  va_start(valist,format);
  neededSize = vsnprintf(NULL , 0 , format , valist) +1;
  buffer = malloc(neededSize);
  vsnprintf(buffer , neededSize ,format,valist);
  va_end(valist);

  return buffer;
}

void freeMsg(char *msg){
  if(msg){
    if(msg)
    free(msg);
  }
}

char *getLedStateName( ledState state){
  switch(state){
    case LED_ON:
    return "LED_ON";
    case LED_OFF:
    return "LED_OFF";
    default:
    return "Unknown LED state";
  }
}

void fake_turnLed(ledState state ,int NumCalls ){
  char *msg;
  turnLedCallNumbers++;
  if(NumCalls < expectedTurnLedMaxCalls){
    ledState expectedState = expectedLedStates[NumCalls];
    if(state != expectedState){
      msg = createMsg("turnLed() was called with %s ,but expect %s",  getLedStateName(state),    \
      getLedStateName(expectedLedStates[NumCalls]));
      TEST_FAIL_MESSAGE(msg);
    }
  }else{
    msg = createMsg("turned(%s) was called more times than expected",  getLedStateName(state),    \
    getLedStateName(expectedLedStates[NumCalls]));;
    TEST_FAIL_MESSAGE(msg);
}
}

buttonState fake_getButtonState(int NumCalls){
  if(NumCalls < getButtonStateMaxCalls){
    return expectedbuttonState[NumCalls];
  }
  else{
    TEST_FAIL_MESSAGE("Received extra getButtonState() calls");
  }
}
void setupFake(ledState expLedStates[] , int ledMaxCalls , buttonState buttStates[], int buttonMaxCalls){
  turnLedCallNumbers = 0;
  turnLed_StubWithCallback(fake_turnLed);
  expectedLedStates = expLedStates;
  expectedTurnLedMaxCalls = ledMaxCalls;
  getButtonState_StubWithCallback(fake_getButtonState);
  expectedbuttonState = buttStates;
  getButtonStateMaxCalls = buttonMaxCalls;
}

void verifyturnLedCalls(int numCalls){
  if(turnLedCallNumbers != numCalls){
    TEST_FAIL_MESSAGE("turnled() was not called at all. but 1 call is expected");
  }
}

void test_tapTurnOnTapOffLed_given_led_is_off_and_button_is_pressed_and_release_expect_led_ON(void)
{

  LedButtonInfo info= {LED_OFF,BUTTON_RELEASED};
  ledState expectedLedStates[] = {LED_ON};
  buttonState buttonStates[] = {BUTTON_RELEASED , BUTTON_PRESSED , BUTTON_RELEASED};

  setupFake(expectedLedStates,1,buttonStates,3);

  tapTurnOnTapOffLed(&info);
  tapTurnOnTapOffLed(&info);
  tapTurnOnTapOffLed(&info);

  verifyturnLedCalls(1);

  TEST_ASSERT_EQUAL(LED_ON,info.currrentState);
}

void test_tapTurnOnTapOffLed_given_led_is_off_and_button_is_pressed_and_release_expect_led_FAKE(void)
{

  LedButtonInfo info= {LED_ON,BUTTON_RELEASED};
  ledState expectedLedStates[] = {LED_OFF};
  buttonState buttonStates[] = {BUTTON_RELEASED , BUTTON_PRESSED , BUTTON_RELEASED};

  setupFake(expectedLedStates,1,buttonStates,3);

  tapTurnOnTapOffLed(&info);
  tapTurnOnTapOffLed(&info);
  tapTurnOnTapOffLed(&info);

  verifyturnLedCalls(1);

  TEST_ASSERT_EQUAL(LED_OFF,info.currrentState);
}
/*void test_LedController_given_button_expect_led(void)
{
  getButtonState_ExpectAndReturn(23);
  getButtonState_ExpectAndReturn(0);

  int ledstate = getButtonState();
  int ledstate2 = getButtonState();

}


void test_turnLedIfButtonIsPressed_given_button_ON_expect_led_ON(void)
{
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  turnLed_Expect(LED_ON);

  turnLedIfButtonIsPressed();
}

void test_turnLedIfButtonIsPressed_given_button_off_expect_led_OFF(void)
{
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  turnLed_Expect(LED_OFF);

  turnLedIfButtonIsPressed();
}

void test_tapTurnOnTapOffLed_given_led_is_off_and_button_is_pressed_and_release_expect_led_ON(void)
{

  LedButtonInfo info= {LED_OFF,BUTTON_RELEASED};

  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  turnLed_Expect(LED_ON);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);

  TEST_ASSERT_EQUAL(LED_ON,info.currrentState);

}

void test_tapTurnOnTapOffLed_given_led_is_ON_and_button_is_pressed_and_release_expect_led_OFF(void)
{

  LedButtonInfo info= {LED_ON,BUTTON_RELEASED};

  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  turnLed_Expect(LED_OFF);
  tapTurnOnTapOffLed(&info);

  TEST_ASSERT_EQUAL(LED_OFF,info.currrentState);
}

void test_tapTurnOnTapOffLed_given_led_is_ON_and_button_is_pressed_and_release_expect_led_OFF_2_times(void)
{

  LedButtonInfo info= {LED_ON,BUTTON_RELEASED};

  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  turnLed_Expect(LED_OFF);
  tapTurnOnTapOffLed(&info);

  TEST_ASSERT_EQUAL(LED_OFF,info.currrentState);

  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  turnLed_Expect(LED_ON);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);

  TEST_ASSERT_EQUAL(LED_ON,info.currrentState);

  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  turnLed_Expect(LED_OFF);
  tapTurnOnTapOffLed(&info);

  TEST_ASSERT_EQUAL(LED_OFF,info.currrentState);
}

void test_tapTurnOnTapOffLed_given_led_is_ON_and_button_is_pressed_and_release_expect_led_OFF_keep_pressing(void)
{

  LedButtonInfo info= {LED_ON,BUTTON_RELEASED};

  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  turnLed_Expect(LED_OFF);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);

  TEST_ASSERT_EQUAL(LED_OFF,info.currrentState);
}*/

/*void test_tapTurnOnTapOffLed_given_led_is_off_and_button_is_pressed_and_release_expect_led_ON_in_loop(void)
{

  LedButtonInfo info= {LED_OFF,BUTTON_RELEASED};

  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  turnLed_Expect(LED_ON);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  turnLed_Expect(LED_ON);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  turnLed_Expect(LED_ON);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);

  TEST_ASSERT_EQUAL(LED_ON,info.currrentState);

}*/
