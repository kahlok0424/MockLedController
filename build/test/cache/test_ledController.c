#include "build/temp/_test_ledController.c"
#include "mock_Led.h"
#include "mock_Button.h"
#include "ledController.h"
#include "unity.h"


int turnLedCallNumbers = 0;

int getButtonStateMaxCalls = 0;

int expectedTurnLedMaxCalls = 0;

buttonState *expectedbuttonState = 

                                  ((void *)0)

                                      ;

ledState *expectedLedStates = 

                             ((void *)0)

                                 ;



void setUp(void)

{

}



void tearDown(void)

{

}



void fake_turnLed(ledState state ,int NumCalls ){

  turnLedCallNumbers++;

  if(NumCalls < expectedTurnLedMaxCalls){

    if(state != expectedLedStates[NumCalls]){

      UnityFail( (("turnLed() was called with ???,but expect ???")), (UNITY_UINT)(24));

    }

  }else

  UnityFail( (("turnLed() was called with ???,but expect ???")), (UNITY_UINT)(27));

}



buttonState fake_getButtonState(int NumCalls){

  if(NumCalls < getButtonStateMaxCalls){

    return expectedbuttonState[NumCalls];

  }

  else{

    UnityFail( (("Received extra getButtonState() calls")), (UNITY_UINT)(35));

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

    UnityFail( (("turnled() was not called at all. but 1 call is expected")), (UNITY_UINT)(50));

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



  UnityAssertEqualNumber((UNITY_INT)((LED_ON)), (UNITY_INT)((info.currrentState)), (

 ((void *)0)

 ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((UNITY_INT)((LED_OFF)), (UNITY_INT)((info.currrentState)), (

 ((void *)0)

 ), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_INT);

}
