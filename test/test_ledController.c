#include "unity.h"
#include "ledController.h"
#include "mock_Button.h"
#include "mock_Led.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_LedController_given_button_expect_led(void)
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
  tapTurnOnTapOffLed(&info);;
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  turnLed_Expect(LED_ON);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);

  TEST_ASSERT_EQUAL(LED_ON,info.currrentState);
  //getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  //turnLed_Expect(LED_OFF);
}

void test_tapTurnOnTapOffLed_given_led_is_ON_and_button_is_pressed_and_release_expect_led_OFF(void)
{

  LedButtonInfo info= {LED_ON,BUTTON_RELEASED};

  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  tapTurnOnTapOffLed(&info);;
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  tapTurnOnTapOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  turnLed_Expect(LED_OFF);
  tapTurnOnTapOffLed(&info);

  TEST_ASSERT_EQUAL(LED_OFF,info.currrentState);
  //getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  //turnLed_Expect(LED_OFF);
}
