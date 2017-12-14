#include "text.h"

//Font
	LPD3DXFONT font;

void setupFont(IDirect3DDevice9* device)
{
	D3DXCreateFont(device, 20, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"), &font );
}

void myText(int score, int lives, const int Height, const int Width)
{

	char timeBuffer[512];
	sprintf_s(timeBuffer,"Score: %d",score);

	char lifeBuffer[512];
	sprintf_s(lifeBuffer,"Lifes Remaining: %d",lives);

	RECT font_box;
	font_box.top = 2;
	font_box.left = 0;
	font_box.bottom = Height+1;
	font_box.right = Width;

	font->DrawText(NULL,timeBuffer,-1,&font_box,0,d3d::GREEN);

	font_box.top = 20;
	font_box.left = 0;
	font->DrawText(NULL,lifeBuffer,-1,&font_box,0,d3d::GREEN);
}

void cleanText()
{
	font->Release();
}

