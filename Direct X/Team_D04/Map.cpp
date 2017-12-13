#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <WindowsX.h>
#include <stdio.h>

#define WINDOW_MAIN "WINCLASS1"

//BEGIN FUNCTIONS

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

void drawRestrooms (HDC hdc, HWND hwnd)
{
	//Create Restrooms
//RECTANGLES
	createRectangle(hdc, hwnd, 34, 378, 109, 456, true, 0, 0, 255);
	createRectangle(hdc, hwnd, 653, 461, 719, 537, true, 0, 0, 255);
}

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

void drawServerRoom (HDC hdc, HWND hwnd)
{
	//Create Server Room
//RECTANGLES
	createRectangle(hdc, hwnd, 594, 371, 653, 438, true, 247, 128, 73);
}

void drawOffice (HDC hdc, HWND hwnd)
{
	//Create Offices
//RECTANGLES
	createRectangle(hdc, hwnd, 237, 533, 268, 563, true, 255, 0, 255);
}

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

//END FUNCTIONS
/*
LRESULT CALLBACK WindowProc(
							HWND hwnd,
							UINT uMsg,
							WPARAM wParam,
							LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	
	switch (uMsg)
	{
	case WM_CREATE:
		{
			return(0);
		} break;
	case WM_COMMAND:
		{
			return(0);
		}break;
	case WM_PAINT:
		{
			hdc = BeginPaint(hwnd,&ps);
			
			//BEGIN CALL FUNCTIONS

			//Create Overlays
			drawAuditorium(hdc, hwnd);
			//drawRestrooms(hdc, hwnd);
			//drawClassrooms(hdc, hwnd);
			//drawStairs(hdc, hwnd);
			//drawElevator(hdc, hwnd);
			//drawHallways(hdc, hwnd);
			//drawClosets(hdc, hwnd);
			//drawDisplayCase(hdc, hwnd);
			//drawServerRoom(hdc, hwnd);
			//drawUnknown(hdc, hwnd);
			//drawOffice(hdc, hwnd);
			//Create Outline
			drawOutline(hdc, hwnd);

			//END CALL FUNCTIONS

			EndPaint(hwnd,&ps);
			return(0);
		} break;
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			return(0);
		} break;
	default:break;
	}
	return (DefWindowProc(hwnd, uMsg, wParam, lParam));
}


int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrecInstance,
				   LPSTR lpCmdLine,
				   int nCmdShow)
{

	WNDCLASSEX winclass;
	HWND hwnd;
	MSG uMsg;

	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC |
				     CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = WINDOW_MAIN;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&winclass))
		return(0);

	if (!(hwnd = CreateWindowEx(NULL,
							WINDOW_MAIN,
							"Window Test",
							WS_POPUPWINDOW | WS_CAPTION | WS_VISIBLE,
							0,
							0,
							800,
							800,
							NULL,
							NULL,
							hInstance,
							NULL)))
		return(0);

	while(GetMessage(&uMsg,NULL,0,0))
	{
		TranslateMessage(&uMsg);

		DispatchMessage(&uMsg);
	}
	return(uMsg.wParam);

}*/

