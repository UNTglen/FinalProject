#ifndef __asteroid_H__
#define __asteroid_H__
#include "base.h"

void setupFont(IDirect3DDevice9* device, LPD3DXFONT font);
void myText(int score, int lives, const int Height, const int Width, LPD3DXFONT font);
void cleanText();

#endif