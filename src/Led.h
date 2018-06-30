#ifndef _LED_H
#define _LED_H

typedef enum{
  LED_OFF,
  LED_ON,
}ledState;

int getButtonState();
void turnLed(ledState state);

#endif // _LED_H
