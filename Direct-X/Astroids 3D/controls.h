#ifndef __controls_H__
#define __controls_H__


#include "base.h"
#include "XACT Sound.h"
#include "dinput.h"

bool setupDirectInput(HINSTANCE main_instance, HWND main_hwnd);
bool checkBoost(bool hyperspace);
int checkState(int direction, stXACTAudio sound, XACTINDEX thrust);
//int checkState(int direction);
void cleanControls();


#endif