/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_LED_H
#define _MOCK_LED_H

#include "Led.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#pragma GCC diagnostic push
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_Led_Init(void);
void mock_Led_Destroy(void);
void mock_Led_Verify(void);




#define getButtonState_IgnoreAndReturn(cmock_retval) getButtonState_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void getButtonState_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define getButtonState_ExpectAndReturn(cmock_retval) getButtonState_CMockExpectAndReturn(__LINE__, cmock_retval)
void getButtonState_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
typedef int (* CMOCK_getButtonState_CALLBACK)(int cmock_num_calls);
void getButtonState_StubWithCallback(CMOCK_getButtonState_CALLBACK Callback);
#define turnLed_Ignore() turnLed_CMockIgnore()
void turnLed_CMockIgnore(void);
#define turnLed_Expect(state) turnLed_CMockExpect(__LINE__, state)
void turnLed_CMockExpect(UNITY_LINE_TYPE cmock_line, ledState state);
typedef void (* CMOCK_turnLed_CALLBACK)(ledState state, int cmock_num_calls);
void turnLed_StubWithCallback(CMOCK_turnLed_CALLBACK Callback);

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#pragma GCC diagnostic pop
#endif

#endif
