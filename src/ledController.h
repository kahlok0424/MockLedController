#ifndef _LEDCONTROLLER_H
#define _LEDCONTROLLER_H
#include "Led.h"
#include "Button.h"

typedef struct LedButtonInfo LedButtonInfo;

struct LedButtonInfo{
  ledState currrentState;
  buttonState previousButtonState;
};

void turnLedIfButtonIsPressed(void);
void tapTurnOnTapOffLed(LedButtonInfo *info);
//void doTapTapLedController(LedButtonInfo info);

#endif // _LEDCONTROLLER_H
