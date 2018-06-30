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

  tapTurnOnTapOffLed(&info);

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



  getButtonState_CMockExpectAndReturn(62, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(64, BUTTON_PRESSED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(66, BUTTON_RELEASED);

  turnLed_CMockExpect(67, LED_OFF);

  tapTurnOnTapOffLed(&info);



  UnityAssertEqualNumber((UNITY_INT)((LED_OFF)), (UNITY_INT)((info.currrentState)), (

 ((void *)0)

 ), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_INT);

}



void test_tapTurnOnTapOffLed_given_led_is_ON_and_button_is_pressed_and_release_expect_led_OFF_2_times(void)

{



  LedButtonInfo info= {LED_ON,BUTTON_RELEASED};



  getButtonState_CMockExpectAndReturn(78, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(80, BUTTON_PRESSED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(82, BUTTON_RELEASED);

  turnLed_CMockExpect(83, LED_OFF);

  tapTurnOnTapOffLed(&info);



  UnityAssertEqualNumber((UNITY_INT)((LED_OFF)), (UNITY_INT)((info.currrentState)), (

 ((void *)0)

 ), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_INT);



  getButtonState_CMockExpectAndReturn(88, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(90, BUTTON_PRESSED);

  turnLed_CMockExpect(91, LED_ON);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(93, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);



  UnityAssertEqualNumber((UNITY_INT)((LED_ON)), (UNITY_INT)((info.currrentState)), (

 ((void *)0)

 ), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_INT);



  getButtonState_CMockExpectAndReturn(98, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(100, BUTTON_PRESSED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(102, BUTTON_RELEASED);

  turnLed_CMockExpect(103, LED_OFF);

  tapTurnOnTapOffLed(&info);



  UnityAssertEqualNumber((UNITY_INT)((LED_OFF)), (UNITY_INT)((info.currrentState)), (

 ((void *)0)

 ), (UNITY_UINT)(106), UNITY_DISPLAY_STYLE_INT);

}



void test_tapTurnOnTapOffLed_given_led_is_ON_and_button_is_pressed_and_release_expect_led_OFF_keep_pressing(void)

{



  LedButtonInfo info= {LED_ON,BUTTON_RELEASED};



  getButtonState_CMockExpectAndReturn(114, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(116, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(118, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(120, BUTTON_PRESSED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(122, BUTTON_PRESSED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(124, BUTTON_PRESSED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(126, BUTTON_RELEASED);

  turnLed_CMockExpect(127, LED_OFF);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(129, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(131, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);



  UnityAssertEqualNumber((UNITY_INT)((LED_OFF)), (UNITY_INT)((info.currrentState)), (

 ((void *)0)

 ), (UNITY_UINT)(134), UNITY_DISPLAY_STYLE_INT);

}



void test_tapTurnOnTapOffLed_given_led_is_off_and_button_is_pressed_and_release_expect_led_ON_in_loop(void)

{



  LedButtonInfo info= {LED_OFF,BUTTON_RELEASED};



  getButtonState_CMockExpectAndReturn(142, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(144, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(146, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(148, BUTTON_PRESSED);

  turnLed_CMockExpect(149, LED_ON);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(151, BUTTON_PRESSED);

  turnLed_CMockExpect(152, LED_ON);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(154, BUTTON_PRESSED);

  turnLed_CMockExpect(155, LED_ON);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(157, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(159, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);

  getButtonState_CMockExpectAndReturn(161, BUTTON_RELEASED);

  tapTurnOnTapOffLed(&info);



  UnityAssertEqualNumber((UNITY_INT)((LED_ON)), (UNITY_INT)((info.currrentState)), (

 ((void *)0)

 ), (UNITY_UINT)(164), UNITY_DISPLAY_STYLE_INT);



}
