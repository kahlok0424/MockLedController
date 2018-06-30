#include "ledController.h"
#include "Led.h"

void turnLedIfButtonIsPressed(void){
  int state = getButtonState();

  if(state > 0){
    turnLed(LED_ON);
  }else{
    turnLed(LED_OFF);
  }
}

void tapTurnOnTapOffLed(LedButtonInfo *info){
  //info->previousButtonState = getButtonState();
  buttonState state = getButtonState();

  if(info->currrentState == LED_OFF){
    if(state == BUTTON_PRESSED && state != info->previousButtonState){
      info->currrentState = LED_ON ;
      turnLed(info->currrentState);
    }else{
      info->previousButtonState =  BUTTON_RELEASED;
    }
  }
  else
  {
  if(state == BUTTON_PRESSED && state != info->previousButtonState){
    info->previousButtonState = BUTTON_PRESSED;
  }
  else if(state == BUTTON_RELEASED && state != info->previousButtonState){
    info->currrentState = LED_OFF ;
    turnLed(info->currrentState);
    }
  }

}


/*void doTapTapLedController(LedButtonInfo info){
  while(1){
    tapTurnOnTapOffLed(&info);
  }
}*/
