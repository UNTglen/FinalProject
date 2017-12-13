#define WINDOWS_LEAN_AND_MEAN

#include <windows.h>   // include all the windows headers
#include <windowsx.h>  // include useful macros
#include <mmsystem.h>  // very important and include WINMM.LIB too!
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "resource.h"


#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code)   ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

int counter, x, y, ScreenX, ScreenY = 0;

int classRooms, restRooms, hallways, elevator, closet, 
	office,auditorium, displayArea, serverRoom, stairs, unknown = 0;

char buffer[80];

HWND      main_window_handle = NULL; // globally track main window
HWND	  current_window_handle = NULL;
HINSTANCE hinstance_app      = NULL; // globally track hinstance

//Create Rectange Function (SUCH a time saver)
//Params (hdc, hwnd, x1, y1, x2, y2, fill?, Red, Green, Blue)
void createRectangle(HDC hdc, HWND hwnd,int left, int top, int right, int bottom, bool fill, int R, int G, int B)
{
	hdc = GetDC(hwnd);
	RECT rect;
	rect.left = left;
	rect.top = top;
	rect.right = right;
	rect.bottom = bottom;
	HBRUSH recthbrush = CreateSolidBrush(RGB(R,G,B));

	if(fill == true)
		FillRect(hdc, &rect, recthbrush);
	else
		FrameRect(hdc, &rect, recthbrush);

	DeleteObject(recthbrush);
	ReleaseDC(hwnd, hdc);
}

///////////////Draw Basic map/////////////////////
void drawOutline(HDC hdc, HWND hwnd)
{
	hdc = GetDC(hwnd);

//THICK LINES
	//Create and select thick black pen
	HPEN thickhpen = CreatePen(PS_SOLID, 5, RGB(255,255,255));
	HPEN old_thickhpen = (HPEN)SelectObject(hdc, thickhpen);

	//Main bold outline
	//Line1
	MoveToEx(hdc, 292, 180, NULL);
	LineTo(hdc, 292, 69);
	LineTo(hdc, 508, 69);
	//Line2
	MoveToEx(hdc, 534, 69, NULL);
	LineTo(hdc, 653, 69);
	LineTo(hdc, 653, 281);
	//Line3
	MoveToEx(hdc, 653, 303, NULL);
	LineTo(hdc, 653, 342);
	LineTo(hdc, 756, 342);
	LineTo(hdc, 756, 438);
	//Line4
	MoveToEx(hdc, 756, 461, NULL);
	LineTo(hdc, 756, 537);
	LineTo(hdc, 653, 537);
	LineTo(hdc, 653, 634);
	LineTo(hdc, 268, 634);
	LineTo(hdc, 268, 563);
	LineTo(hdc, 237, 563);
	LineTo(hdc, 237, 533);
	LineTo(hdc, 231, 533);
	//Line5
	MoveToEx(hdc, 208, 533, NULL);
	LineTo(hdc, 201, 533);
	LineTo(hdc, 187, 562);
	LineTo(hdc, 167, 563);
	LineTo(hdc, 143, 561);
	LineTo(hdc, 120, 555);
	LineTo(hdc, 99, 546);
	LineTo(hdc, 80, 531);
	LineTo(hdc, 66, 513);
	LineTo(hdc, 59, 496);
	LineTo(hdc, 55, 476);
	LineTo(hdc, 54, 456);
	LineTo(hdc, 34, 456);
	LineTo(hdc, 34, 378);
	LineTo(hdc, 109, 378);
	LineTo(hdc, 109, 181);
	LineTo(hdc, 119, 178);
	LineTo(hdc, 130, 174);
	LineTo(hdc, 141, 171);
	LineTo(hdc, 153, 168);
	LineTo(hdc, 164, 166);
	LineTo(hdc, 178, 165);
	LineTo(hdc, 192, 166);
	LineTo(hdc, 205, 168);
	LineTo(hdc, 218, 171);
	LineTo(hdc, 230, 174);
	LineTo(hdc, 242, 177);
	LineTo(hdc, 253, 179);
	LineTo(hdc, 266, 180);

	SelectObject(hdc, old_thickhpen);
	DeleteObject(thickhpen);

//THIN LINES
	//Create and select thin black pen
	HPEN thinhpen = CreatePen(PS_SOLID, 1, RGB(255,255,255));
	HPEN old_thinhpen = (HPEN)SelectObject(hdc, thinhpen);

	//Outline Auditorium
	MoveToEx(hdc, 266, 180, NULL);
	LineTo(hdc, 266, 378);
	LineTo(hdc, 250, 378);
	LineTo(hdc, 244, 381);
	LineTo(hdc, 238, 383);
	LineTo(hdc, 232, 384);
	LineTo(hdc, 226, 384);
	LineTo(hdc, 220, 383);
	LineTo(hdc, 214, 381);
	LineTo(hdc, 209, 379);
	LineTo(hdc, 205, 378);
	LineTo(hdc, 109, 378);

	//Outline Stairs
	MoveToEx(hdc, 145, 492,NULL);
	LineTo(hdc, 187, 517);
	LineTo(hdc, 187, 562);
	LineTo(hdc, 123, 527);
	LineTo(hdc, 145, 492);

	//Outline Display
	MoveToEx(hdc, 268, 490, NULL);
	LineTo(hdc, 227, 490);
	LineTo(hdc, 228, 480);
	LineTo(hdc, 232, 471);
	LineTo(hdc, 238, 465);
	LineTo(hdc, 247, 461);
	LineTo(hdc, 256, 460);
	LineTo(hdc, 268, 461);
	LineTo(hdc, 268, 563);

	//Outline Elevator
	MoveToEx(hdc, 145, 492, NULL);
	LineTo(hdc, 154, 478);
	LineTo(hdc, 174, 487);
	LineTo(hdc, 163, 502);

	//Other / Unknown
	//35
	MoveToEx(hdc, 174, 487, NULL);
	LineTo(hdc, 201, 501);
	LineTo(hdc, 201, 517);
	LineTo(hdc, 187, 517);
	//36
	MoveToEx(hdc, 201, 517, NULL);
	LineTo(hdc, 201, 533);
	//37
	MoveToEx(hdc, 237, 533, NULL);
	LineTo(hdc, 268, 533);
	//45
	MoveToEx(hdc, 534, 121, NULL);
	LineTo(hdc, 534, 281);
	LineTo(hdc, 577, 281);
	//51
	MoveToEx(hdc, 653, 438, NULL);
	LineTo(hdc, 756, 438);

	SelectObject(hdc, old_thinhpen);
	DeleteObject(thinhpen);


//RECTANGLES
	//Classroom Outlines
	createRectangle(hdc, hwnd, 292, 94, 364, 196, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 364, 94, 436, 196, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 436, 94, 508, 196, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 292, 218, 364, 327, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 364, 218, 436, 327, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 436, 218, 508, 327, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 292, 353, 418, 438, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 418, 353, 508, 438, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 292, 461, 396, 534, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 395, 461, 501, 534, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 501, 461, 609, 534, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 314, 534, 416, 608, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 416, 534, 521, 608, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 521, 534, 629, 608, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 534, 303, 629, 371, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 534, 371, 594, 438, false, 255, 255, 255);

	//Restroom Outlines
	createRectangle(hdc, hwnd, 34, 378, 109, 456, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 653, 461, 719, 537, false, 255, 255, 255);

	//Stairs Outline
	createRectangle(hdc, hwnd, 718, 461, 756, 537, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 132, 378, 200, 410, false, 255, 255, 255);
	
	//Closets Outline
	createRectangle(hdc, hwnd, 292, 69, 347, 94, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 347, 69, 404, 94, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 404, 69, 460, 94, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 460, 69, 508, 94, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 292, 327, 317, 353, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 317, 327, 364, 353, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 364, 327, 415, 353, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 415, 327, 461, 353, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 461, 327, 480, 353, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 480, 327, 508, 353, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 609, 481, 629, 508, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 609, 508, 629, 534, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 292, 534, 314, 594, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 629, 303, 653, 342, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 629, 342, 696, 371, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 572, 106, 599, 146, false, 255, 255, 255);

	//Server Room Outline
	createRectangle(hdc, hwnd, 594, 371, 653, 438, false, 255, 255, 255);

	//Offices Outline
	createRectangle(hdc, hwnd, 237, 533, 268, 563, false, 255, 255, 255);

	//Other / Unknown
	//39-40
	createRectangle(hdc, hwnd, 534, 69, 562, 121, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 562, 69, 599, 106, false, 255, 255, 255);
	//42-44
	createRectangle(hdc, hwnd, 599, 69, 653, 158, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 577, 158, 653, 217, false, 255, 255, 255);
	createRectangle(hdc, hwnd, 577, 217, 653, 281, false, 255, 255, 255);

	

	ReleaseDC(hwnd, hdc);
}

///////////////Fill for Auditorium/////////////////////
void drawAuditorium(HDC hdc, HWND hwnd)
{
	//Create Auditorium
//POLYGONS
	hdc = GetDC(hwnd);
	HBRUSH hbrush = CreateSolidBrush(RGB(0,255,0));
	HBRUSH old_hbrush = (HBRUSH)SelectObject(hdc, hbrush);
	POINT auditorium[25] = 
		{109, 181, 119, 178,
		 130, 174, 141, 171,
		 153, 168, 164, 166,
		 178, 165, 192, 166,
		 205, 168, 218, 171,
		 230, 174, 242, 177,
		 253, 180, 266, 180,
		 266, 378, 250, 378,
		 244, 381, 238, 383,
		 232, 384, 226, 384,
		 220, 383, 214, 381,
		 209, 379, 205, 378,
		 109, 378};
	Polygon(hdc, auditorium, 25);

	SelectObject(hdc, old_hbrush);
	DeleteObject(hbrush);
	ReleaseDC(hwnd, hdc);
}

///////////////Fill for Restrooms/////////////////////
void drawRestrooms (HDC hdc, HWND hwnd)
{
	//Create Restrooms
//RECTANGLES
	createRectangle(hdc, hwnd, 34, 378, 109, 456, true, 0, 0, 255);
	createRectangle(hdc, hwnd, 653, 461, 719, 537, true, 0, 0, 255);
}

///////////////Fill for Classrooms/////////////////////
void drawClassrooms (HDC hdc, HWND hwnd)
{
	//Create Classrooms
//RECTANGLES
	createRectangle(hdc, hwnd, 292, 94, 364, 196, true, 255, 0, 0);
	createRectangle(hdc, hwnd, 364, 94, 436, 196, true, 255, 0, 0);
	createRectangle(hdc, hwnd, 436, 94, 508, 196, true, 255, 0, 0);
	createRectangle(hdc, hwnd, 292, 218, 364, 327, true, 255, 0, 0);
	createRectangle(hdc, hwnd, 364, 218, 436, 327, true, 255, 0, 0);
	createRectangle(hdc, hwnd, 436, 218, 508, 327, true, 255, 0, 0);
	createRectangle(hdc, hwnd, 292, 353, 418, 438, true, 255, 0, 0);
	createRectangle(hdc, hwnd, 418, 353, 508, 438, true, 255, 0, 0);
	createRectangle(hdc, hwnd, 292, 461, 396, 534, true, 255, 0, 0);
	createRectangle(hdc, hwnd, 395, 461, 501, 534, true, 255, 0, 0);
	createRectangle(hdc, hwnd, 501, 461, 609, 534, true, 255, 0, 0);
	createRectangle(hdc, hwnd, 314, 534, 416, 608, true, 255, 0, 0);
	createRectangle(hdc, hwnd, 416, 534, 521, 608, true, 255, 0, 0);
	createRectangle(hdc, hwnd, 521, 534, 629, 608, true, 255, 0, 0);
	createRectangle(hdc, hwnd, 534, 303, 629, 371, true, 255, 0, 0);
	createRectangle(hdc, hwnd, 534, 371, 594, 438, true, 255, 0, 0);
}

///////////////Fill for Stairs/////////////////////
void drawStairs (HDC hdc, HWND hwnd)
{
	//Create Stairs
//RECTANGLES
	createRectangle(hdc, hwnd, 718, 461, 756, 537, true, 116, 74, 20);
	createRectangle(hdc, hwnd, 132, 378, 200, 410, true, 116, 74, 20);

//POLYGONS
	hdc = GetDC(hwnd);
	HBRUSH hbrush = CreateSolidBrush(RGB(116, 74, 20));
	HBRUSH old_hbrush = (HBRUSH)SelectObject(hdc, hbrush);

	POINT mainStairCase[4] = 
		{145, 492,
		 187, 517,
		 187, 562,
		 123, 527};
	Polygon(hdc, mainStairCase, 4);

	SelectObject(hdc, old_hbrush);
	DeleteObject(hbrush);
	ReleaseDC(hwnd, hdc);
}

///////////////Fill for Elevator/////////////////////
void drawElevator (HDC hdc, HWND hwnd)
{
	//Create Elevator
//POLYGONS
	hdc = GetDC(hwnd);
	HBRUSH hbrush = CreateSolidBrush(RGB(255, 126, 0));
	HBRUSH old_hbrush = (HBRUSH)SelectObject(hdc, hbrush);

	POINT elevator[4] = 
		{154, 478,
		 174, 487,
		 163, 502,
		 145, 492};
	Polygon(hdc, elevator, 4);

	SelectObject(hdc, old_hbrush);
	DeleteObject(hbrush);
	ReleaseDC(hwnd, hdc);
}

///////////////Fill For Hallways/////////////////////
void drawHallways (HDC hdc, HWND hwnd)
{
	//Create Hallways
//RECTANGLES
	createRectangle(hdc, hwnd, 266, 180, 292, 634, true, 255, 255, 0);
	createRectangle(hdc, hwnd, 268, 594, 314, 634, true, 255, 255, 0);
	createRectangle(hdc, hwnd, 268, 608, 653, 634, true, 255, 255, 0);
	createRectangle(hdc, hwnd, 292, 196, 508, 218, true, 255, 255, 0);
	createRectangle(hdc, hwnd, 292, 438, 756, 461, true, 255, 255, 0);
	createRectangle(hdc, hwnd, 508,  69, 534, 438, true, 255, 255, 0);
	createRectangle(hdc, hwnd, 629, 461, 653, 634, true, 255, 255, 0);
	createRectangle(hdc, hwnd, 609, 438, 653, 481, true, 255, 255, 0);
	createRectangle(hdc, hwnd, 534, 281, 653, 303, true, 255, 255, 0);
}

///////////////Fill For Closet/////////////////////
void drawClosets (HDC hdc, HWND hwnd)
{
	//Create Closets
//RECTANGLES
	createRectangle(hdc, hwnd, 292, 69, 347, 94, true, 0, 255, 255);
	createRectangle(hdc, hwnd, 347, 69, 404, 94, true, 0, 255, 255);
	createRectangle(hdc, hwnd, 404, 69, 460, 94, true, 0, 255, 255);
	createRectangle(hdc, hwnd, 460, 69, 508, 94, true, 0, 255, 255);
	createRectangle(hdc, hwnd, 292, 327, 317, 353, true, 0, 255, 255);
	createRectangle(hdc, hwnd, 317, 327, 364, 353, true, 0, 255, 255);
	createRectangle(hdc, hwnd, 364, 327, 415, 353, true, 0, 255, 255);
	createRectangle(hdc, hwnd, 415, 327, 461, 353, true, 0, 255, 255);
	createRectangle(hdc, hwnd, 461, 327, 480, 353, true, 0, 255, 255);
	createRectangle(hdc, hwnd, 480, 327, 508, 353, true, 0, 255, 255);
	createRectangle(hdc, hwnd, 609, 481, 629, 508, true, 0, 255, 255);
	createRectangle(hdc, hwnd, 609, 508, 629, 534, true, 0, 255, 255);
	createRectangle(hdc, hwnd, 292, 534, 314, 594, true, 0, 255, 255);
	createRectangle(hdc, hwnd, 629, 303, 653, 342, true, 0, 255, 255);
	createRectangle(hdc, hwnd, 629, 342, 696, 371, true, 0, 255, 255);
	createRectangle(hdc, hwnd, 572, 106, 599, 146, true, 0, 255, 255);

//POLYGONS
	hdc = GetDC(hwnd);
	HBRUSH hbrush = CreateSolidBrush(RGB(0, 255, 255));
	HBRUSH old_hbrush = (HBRUSH)SelectObject(hdc, hbrush);
	//35
	POINT closet35[5] = 
		{174, 487,
		 201, 501,
		 201, 517,
		 187, 517,
		 163, 502};
	Polygon(hdc, closet35, 5);
	//36
	POINT closet36[4] = 
		{187, 517,
		 201, 517,
		 201, 533,
		 187, 562};
	Polygon(hdc, closet36, 4);

	SelectObject(hdc, old_hbrush);
	DeleteObject(hbrush);
	ReleaseDC(hwnd, hdc);
}

///////////////Fill For Display Case/////////////////////
void drawDisplayCase (HDC hdc, HWND hwnd)
{
	//Create Display Case
//POLYGONS
	hdc = GetDC(hwnd);
	HBRUSH hbrush = CreateSolidBrush(RGB(0, 70, 0));
	HBRUSH old_hbrush = (HBRUSH)SelectObject(hdc, hbrush);

	POINT elevator[8] = 
		{268, 490,
		 227, 490,
		 228, 480,
		 232, 471,
		 238, 465,
		 247, 461,
		 256, 460,
		 268, 461};
	Polygon(hdc, elevator, 8);

	SelectObject(hdc, old_hbrush);
	DeleteObject(hbrush);
	ReleaseDC(hwnd, hdc);

}

///////////////Fill for Server Room/////////////////////
void drawServerRoom (HDC hdc, HWND hwnd)
{
	//Create Server Room
//RECTANGLES
	createRectangle(hdc, hwnd, 594, 371, 653, 438, true, 247, 128, 73);
}

///////////////Fill for Offices/////////////////////
void drawOffice (HDC hdc, HWND hwnd)
{
	//Create Offices
//RECTANGLES
	createRectangle(hdc, hwnd, 237, 533, 268, 563, true, 255, 0, 255);
}

///////////////Fill for Unknowns/////////////////////
void drawUnknown (HDC hdc, HWND hwnd)
{
	//Create Unknown
//RECTANGLES
	//39-40
	createRectangle(hdc, hwnd, 534, 69, 562, 121, true, 131, 0, 131);
	createRectangle(hdc, hwnd, 562, 69, 599, 106, true, 131, 0, 131);
	//42-44
	createRectangle(hdc, hwnd, 599, 69, 653, 158, true, 131, 0, 131);
	createRectangle(hdc, hwnd, 577, 158, 653, 217, true, 131, 0, 131);
	createRectangle(hdc, hwnd, 577, 217, 653, 281, true, 131, 0, 131);
//POLYGONS
	hdc = GetDC(hwnd);
	HBRUSH hbrush = CreateSolidBrush(RGB(131, 0, 131));
	HBRUSH old_hbrush = (HBRUSH)SelectObject(hdc, hbrush);

	POINT room45[10] = 
		{534, 121,
		 562, 121,
		 562, 106,
		 572, 106,
		 572, 146,
		 599, 146,
		 599, 158,
		 577, 158,
		 577, 281,
		 534, 281};
	Polygon(hdc, room45, 10);

	POINT room51[6] = 
		{653, 371,
		 696, 371,
		 696, 342,
		 756, 342,
		 756, 438,
		 653, 438};
	Polygon(hdc, room51, 6);

	SelectObject(hdc, old_hbrush);
	DeleteObject(hbrush);
	ReleaseDC(hwnd, hdc);
}

///////////////Check Screen Size of X/////////////////////
int checkX(int x)
{
	if(counter <= 1){x = 225;}
	else
		x = GetSystemMetrics(SM_CXSCREEN);

	return x;
}

///////////////Check Screen Size of Y/////////////////////
int checkY(int y)
{
	if(counter <= 1){y = 530;}
	else
		y = GetSystemMetrics(SM_CYSCREEN);

	return y;
}

///////////////Display Ledgend on Screen/////////////////////
void legend(HDC hdc, HWND hwnd)
{
	hdc = GetDC(hwnd);
	SetTextColor(hdc,RGB(255,255,255));
	SetBkColor(hdc,RGB(0,0,0));
	SetBkMode(hdc,OPAQUE);
	TextOut(hdc,ScreenX,50,"LEGEND",strlen("LEGEND"));
	SetTextColor(hdc,RGB(255,0,0));
	TextOut(hdc,ScreenX,75,"Class Rooms",strlen("Class Rooms"));
	SetTextColor(hdc,RGB(0,0,255));
	TextOut(hdc,ScreenX,100,"Restrooms",strlen("Restrooms"));
	SetTextColor(hdc,RGB(255,255,0));
	TextOut(hdc,ScreenX,125,"Hallways",strlen("Hallways"));
	SetTextColor(hdc,RGB(255,126,0));
	TextOut(hdc,ScreenX,150,"Elevator",strlen("Elevator"));
	SetTextColor(hdc,RGB(0,255,255));
	TextOut(hdc,ScreenX,175,"Closets",strlen("Closets"));
	SetTextColor(hdc,RGB(255,0,255));
	TextOut(hdc,ScreenX,200,"Office",strlen("Office"));
	SetTextColor(hdc,RGB(0,255,0));
	TextOut(hdc,ScreenX,225,"Auditorium",strlen("Auditorium"));
	SetTextColor(hdc,RGB(247,128,73));
	TextOut(hdc,ScreenX,250,"Server Room",strlen("Server Room"));
	SetTextColor(hdc,RGB(116,74,20));
	TextOut(hdc,ScreenX,275,"Stairs",strlen("Stairs"));
	SetTextColor(hdc,RGB(131,0,131));
	TextOut(hdc,ScreenX,300,"Unknown",strlen("Unknown"));
	ReleaseDC(hwnd,hdc);
}

///////////////create new window no buttons/////////////////////
void map(HWND& hwnd,HINSTANCE& hinstance, LPCSTR windowName, LPCSTR winClass)
{
	counter ++;
	ScreenX = checkX(ScreenX) - 10;
	ScreenY = checkY(ScreenY) - 50;
	hwnd = CreateWindowEx(NULL,							// extended style
						  winClass,						// class
						  windowName,					// title
						  WS_SYSMENU | WS_OVERLAPPED | WS_VISIBLE | WS_CAPTION,
						  4,4,							// initial x,y
						  ScreenX, ScreenY,				// initial width, height
						  NULL,							// handle to parent
						  NULL,							// handle to menu
						  hinstance,					// instance of this application
						  NULL);

	current_window_handle = hwnd;

	#define BUTTON_RETURN_ID 200
	#define NUM_BUTTON 1

	char *button_name[NUM_BUTTON] = {"Return to Main"};

	long button_type[NUM_BUTTON] = {BS_PUSHBUTTON};
	
	for(int button = 0; button < NUM_BUTTON; button++)
	{
		ScreenX = checkX(ScreenX) - 225;
		ScreenY = checkY(ScreenY) - 110;
		CreateWindowEx(NULL,											// extended style
					   "button",										// class
					   button_name[button],								// title
					   WS_CHILD | WS_VISIBLE | button_type[button],		// Child, Visible, of button types
					   ScreenX,ScreenY,									// initial x,y
					   200,24,											// initial width, height
					   current_window_handle,							// handle to parent
					   (HMENU)(BUTTON_RETURN_ID + button),				// handle to menu
					   hinstance,										// instance of this application
					   NULL);											// extra creation parms
	}

}

///////////////create new window with buttons/////////////////////
void mainMenu(HWND& hwnd,HINSTANCE& hinstance, LPCSTR windowName, LPCSTR winClass)
{
	counter ++;
	ScreenX = checkX(ScreenX);
	ScreenY = checkY(ScreenY);
	hwnd = CreateWindowEx(NULL,							// extended style
						  winClass,						// class
						  windowName,					// title
						  WS_SYSMENU | WS_VISIBLE,
						  10,10,						// initial x,y
						  ScreenX, ScreenY,				// initial width, height
						  NULL,							// handle to parent
						  NULL,							// handle to menu
						  hinstance_app,					// instance of this application
						  NULL);   
	

	main_window_handle = hwnd;

	#define BUTTON_BASE_ID 100
	#define NUM_BUTTONS 13

	char *button_names[NUM_BUTTONS] = 
	{	"Class Rooms",
		"Restrooms",
		"Hall Ways",
		"Elevator",
		"Closets",
		"Office",
		"Auditorum",
		"Display Area",
		"Server Room", 
		"Stairs",
		"Unknown",
		"Push to load map",
		"Clear All Checks"};

	long button_types[NUM_BUTTONS] = 
	{	BS_AUTOCHECKBOX, 
		BS_AUTOCHECKBOX,
		BS_AUTOCHECKBOX,
		BS_AUTOCHECKBOX, 
		BS_AUTOCHECKBOX,
		BS_AUTOCHECKBOX,
		BS_AUTOCHECKBOX, 
		BS_AUTOCHECKBOX,
		BS_AUTOCHECKBOX,
		BS_AUTOCHECKBOX, 
		BS_AUTOCHECKBOX,
		BS_PUSHBUTTON,
		BS_PUSHBUTTON};
	
	for(int button = 0; button < NUM_BUTTONS; button++)
	{
		CreateWindowEx(NULL,											// extended style
					   "button",										// class
					   button_names[button],							// title
					   WS_CHILD | WS_VISIBLE | button_types[button],	// Child, Visible, of button types
					   10,10+button*36,									// initial x,y
					   /*strlen(button_names[button])*16*/200,24,		// initial width, height
					   main_window_handle,								// handle to parent
					   (HMENU)(BUTTON_BASE_ID + button),				// handle to menu
					   hinstance,										// instance of this application
					   NULL);											// extra creation parms
	}// end for button
}

///////////////checks state of each check box/////////////////////
int checkState(int check)
{
	if(check == 1) check = 0;
	else
		check = 1;

	return check;
}

///////////////Callback WindowProc/////////////////////
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	PAINTSTRUCT ps;
	HDC		hdc;

	switch(msg)
	{
		case(WM_CREATE): //Create Class
		{
			return(0);
		}break;

		case(WM_PAINT): // Paint the Class
		{
			hdc = BeginPaint(hwnd,&ps);
			EndPaint(hwnd,&ps);
			return(0);
		}break;

		case(WM_COMMAND): //For Buttons
		{
			hdc = GetDC(hwnd);  // get the dc
			SetBkMode(hdc, OPAQUE); // set background mode
			SetTextColor(hdc, RGB(0.0,0.0,0.0));  // select a text color
			SetBkColor(hdc, RGB(255,255,255));  // select a random background color
			ReleaseDC(hwnd, hdc); //release DC


			switch(LOWORD(wparam))
			{
				case 100:
				{
					classRooms = checkState(classRooms);
				}break;

				case 101:
				{
					restRooms = checkState(restRooms);

				}break;

				case 102:
				{
					hallways = checkState(hallways);
				}break;

				case 103:
				{
					elevator = checkState(elevator);
				}break;

				case 104:
				{
					closet = checkState(closet);
				}break;

				case 105:
				{
					office = checkState(office);
				}break;

				case 106:
				{
					auditorium = checkState(auditorium);
				}break;

				case 107:
				{
					displayArea = checkState(displayArea);
				}break;

				case 108:
				{
					serverRoom = checkState(serverRoom);
				}break;

				case 109:
				{
					stairs = checkState(stairs);
				}break;

				case 110:
				{
					unknown = checkState(unknown);
				}break;

				case 111: //case for button to create map
				{
					map(hwnd,hinstance_app,"Map","MAPCLASS");
					if(classRooms == 1) drawClassrooms(hdc,hwnd);
					if(restRooms == 1) drawRestrooms(hdc,hwnd);
					if(closet == 1) drawClosets(hdc,hwnd);
					if(hallways== 1) drawHallways(hdc,hwnd);
					if(elevator == 1) drawElevator(hdc,hwnd);
					if(auditorium == 1) drawAuditorium(hdc,hwnd);
					if(displayArea == 1) drawDisplayCase(hdc,hwnd);
					if(serverRoom == 1) drawServerRoom(hdc,hwnd);
					if(restRooms == 1) drawRestrooms(hdc,hwnd);
					if(stairs == 1) drawStairs(hdc,hwnd);
					if(unknown == 1) drawUnknown(hdc,hwnd);
					drawOutline(hdc,hwnd);
					legend(hdc,hwnd);
				}break;

				case 112:
				{
					if(SendMessage(main_window_handle,BM_GETCHECK,101,0) == BST_UNCHECKED)
						SendMessage(hwnd,BM_CLICK,101,0);
				}break;

				case 200:
				{
					counter--; //keeps track of what window is closed
					DestroyWindow(hwnd); //destroy the window that you are closing
				}break;

				case MENU_FILE_EXIT: //if File -> Exit is selected
				{
					PostQuitMessage(0);
				}break;

				case MENU_HELP_ABOUT: //if Help -> About is selected
				{
					MessageBox(hwnd,									//get hwnd
						"Programed By:  Glen Newell, \n\t         "		//first line
						"Robert Busch, \n\t         Charles Felton"		//second & third line
						"\nCompleted: 10/12/2011 "						// date completed
						"\n\251 Cool Kids Inc.",						// copywrite
						"About",MB_OK);									//title of message box
				}break;

				default: break;		//default break for switch
			} //end switch statment

		}break;
		
		case WM_CLOSE: //If Closing window
		{
			counter--; //keeps track of what window is closed
			DestroyWindow(hwnd); //destroy the window that you are closing
			if(counter == 0)PostQuitMessage(0); //if this is the last window close
			return(0);
		}break;

		case WM_DESTROY: //If destroying window
		{
			if(counter !=0 && KEYDOWN(VK_ESCAPE))PostQuitMessage(0);
			return(0);
		}break;

		default:break;
	}
	return (DefWindowProc(hwnd, msg, wparam, lparam));
}

ATOM WINAPI RegisterClassEX(const WNDCLASSEX*lpwcx);

///////////////Fill new class/////////////////////
void fillClass(WNDCLASSEX& fill, HINSTANCE& hInstance, LPCSTR winClass, LPCSTR menuCall)
{
	fill.cbSize			= sizeof(WNDCLASSEX);
	fill.style			= CS_DBLCLKS | CS_OWNDC |
						  CS_HREDRAW | CS_VREDRAW;
	fill.lpfnWndProc	= WindowProc;
	fill.cbClsExtra		= 0;
	fill.cbWndExtra		= 0;
	fill.hInstance		= hInstance;
	fill.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	fill.hCursor		= LoadCursor(NULL, IDC_ARROW);
	fill.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	fill.lpszMenuName	= menuCall;
	fill.lpszClassName	= winClass;
	fill.hIconSm		= LoadIcon(NULL, IDI_APPLICATION);

	// save hinstance in global
	hinstance_app = hInstance;
}

///////////////WIN_MAIN/////////////////////
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance, LPSTR lpcmdline, int ncmdshow)
{
	WNDCLASSEX buttonClass,mapClass; //button window, map window
	MSG msg; //Message
	
	fillClass(buttonClass,hInstance,"BUTTONCLASS","MainMenu");			// fill class using main menu
	if(!RegisterClassEx(&buttonClass)){return(0);}						//register class
	mainMenu(main_window_handle,hinstance_app,"Main Menu","BUTTONCLASS");	//fill menu calls with buttons

	fillClass(mapClass,hInstance,"MAPCLASS",NULL);						//fill the map class in preperation for map
	if(!RegisterClassEx(&mapClass)){return(0);}							//register map class
	

	while(true)
	{
		if (PeekMessage(&msg, NULL, 0,0,PM_REMOVE))
		{
			if(msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (KEYDOWN(VK_ESCAPE)) //if escape key is hit exit program
		{
			SendMessage(main_window_handle, WM_CLOSE, 0,0);
		}
	}

	return(msg.wParam);
}