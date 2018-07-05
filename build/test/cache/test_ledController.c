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





char *createMsg(char *format,...){

  va_list valist;

  int neededSize;

  char *buffer;



  

 __builtin_va_start(

 valist

 ,

 format

 )

                        ;

  neededSize = vsnprintf(

                        ((void *)0) 

                             , 0 , format , valist) +1;

  buffer = malloc(neededSize);

  vsnprintf(buffer , neededSize ,format,valist);

  

 __builtin_va_end(

 valist

 )

               ;



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

      msg = createMsg("turnLed() was called with %s ,but expect %s", getLedStateName(state),

      getLedStateName(expectedLedStates[NumCalls]));

      UnityFail( ((msg)), (UNITY_UINT)(64));

    }

  }else{

    msg = createMsg("turned(%s) was called more times than expected", getLedStateName(state),

    getLedStateName(expectedLedStates[NumCalls]));;

    UnityFail( ((msg)), (UNITY_UINT)(69));

}

}



buttonState fake_getButtonState(int NumCalls){

  if(NumCalls < getButtonStateMaxCalls){

    return expectedbuttonState[NumCalls];

  }

  else{

    UnityFail( (("Received extra getButtonState() calls")), (UNITY_UINT)(78));

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

    UnityFail( (("turnled() was not called at all. but 1 call is expected")), (UNITY_UINT)(93));

  }

}



void test_tapTurnOnTapOffLed_given_led_is_off_and_button_is_pressed_and_release_expect_led_ON(void)

{



  LedButtonInfo info= {LED_OFF,BUTTON_RELEASED};

  ledState expectedLedStates[] = {LED_OFF};

  buttonState buttonStates[] = {BUTTON_RELEASED , BUTTON_PRESSED , BUTTON_RELEASED};



  setupFake(expectedLedStates,1,buttonStates,3);



  tapTurnOnTapOffLed(&info);

  tapTurnOnTapOffLed(&info);

  tapTurnOnTapOffLed(&info);



  verifyturnLedCalls(1);



  UnityAssertEqualNumber((UNITY_INT)((LED_ON)), (UNITY_INT)((info.currrentState)), (

 ((void *)0)

 ), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_INT);

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

 ), (UNITY_UINT)(130), UNITY_DISPLAY_STYLE_INT);

}
