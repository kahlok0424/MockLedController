#include "build/temp/_test_ledController.c"
#include "mock_Led.h"
#include "mock_Button.h"
#include "ledController.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_LedController_given_button_expect_led(void)

{

  getButtonState_CMockExpectAndReturn(16, 23);

  getButtonState_CMockExpectAndReturn(17, 0);



  int ledstate = getButtonState();

  int ledstate2 = getButtonState();



}



void test_turnLedIfButtonIsPressed_given_button_ON_expect_led_ON(void)

{

  getButtonState_CMockExpectAndReturn(26, BUTTON_PRESSED);

  turnLed_CMockExpect(27, LED_ON);



  turnLedIfButtonIsPressed();

}



void test_turnLedIfButtonIsPressed_given_button_off_expect_led_OFF(void)

{

  getButtonState_CMockExpectAndReturn(34, BUTTON_RELEASED);

  turnLed_CMockExpect(35, LED_OFF);



  turnLedIfButtonIsPressed();

}



void test_tapTurnOnTapOffLed_given_led_is_off_and_button_is_pressed_and_release_expect_led_ON(void)

{



  LedButtonInfo info= {LED_OFF,BUTTON_RELEASED};



  getButtonState_CMockExpectAndReturn(45, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);;

  getButtonState_CMockExpectAndReturn(47, BUTTON_PRESSED);

  turnLed_CMockExpect(48, LED_ON);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(50, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);



  UnityAssertEqualNumber((UNITY_INT)((LED_ON)), (UNITY_INT)((info.currrentState)), (

 ((void *)0)

 ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);





}



void test_tapTurnOnTapOffLed_given_led_is_ON_and_button_is_pressed_and_release_expect_led_OFF(void)

{



  LedButtonInfo info= {LED_ON,BUTTON_RELEASED};



  getButtonState_CMockExpectAndReturn(63, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);;

  getButtonState_CMockExpectAndReturn(65, BUTTON_PRESSED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(67, BUTTON_RELEASED);

  turnLed_CMockExpect(68, LED_OFF);

  tapTurnOnTapOffLed(&info);



  UnityAssertEqualNumber((UNITY_INT)((LED_OFF)), (UNITY_INT)((info.currrentState)), (

 ((void *)0)

 ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);





}
