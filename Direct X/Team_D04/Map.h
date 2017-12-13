#ifdef MAP_H
#define MAP_H

	void createRectangle(HDC, HWND,int, int, int, int, bool, int, int, int);
	void drawOutline(HDC, HWND);
	void drawAuditorium(HDC, HWND);
	void drawRestrooms (HDC, HWND);
	void drawClassrooms (HDC, HWND);
	void drawStairs (HDC, HWND);
	void drawElevator (HDC, HWND);
	void drawHallways (HDC, HWND);
	void drawClosets (HDC, HWND);
	void drawDisplayCase (HDC, HWND);
	void drawServerRoom (HDC, HWND);
	void drawOffice (HDC, HWND);
	void drawUnknown (HDC, HWND);


#endif

