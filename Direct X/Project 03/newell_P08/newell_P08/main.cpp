#include "base.h"

////////////////////globals////////////////////
IDirect3DDevice9* Device = 0;	//device pointer to device
const int Width =  (GetSystemMetrics(SM_CXSCREEN)) - 10;
const int Height = (GetSystemMetrics(SM_CYSCREEN)) - 50;

//const int Width = 800;			//default width
//const int Height = 600;			//default height
ID3DXMesh* Text = 0;
int change = 0, directionX = 1, directionY = 1, directionZ = 1;

//colors
//const D3DXCOLOR ME(D3DCOLOR_XRGB(150,0,100));
const D3DXCOLOR WHITE(D3DCOLOR_XRGB(255,255,255));
const D3DXCOLOR RED(D3DCOLOR_XRGB(255,0,0));
const D3DXCOLOR GREEN(D3DCOLOR_XRGB(0,255,0));
const D3DXCOLOR BLUE(D3DCOLOR_XRGB(0,0,255));
const D3DXCOLOR BLACK(D3DCOLOR_XRGB(0,0,0));
D3DXCOLOR color[4] = {BLUE,GREEN,RED,WHITE};
 
const D3DMATERIAL9 ME_MTRL = d3d::InitMtrl(WHITE,WHITE,WHITE, BLACK, 5.0);
////////////////////Setup////////////////////
bool Setup()
{
	//set up font
	HDC hdc = CreateCompatibleDC(0);
	HFONT hFont;
	HFONT hFontOld;

	//describe font
	LOGFONT lf;
	ZeroMemory(&lf, sizeof(LOGFONT));
	lf.lfHeight = 10;
	lf.lfWidth = 10;
	lf.lfWeight = 200;
	lf.lfCharSet = DEFAULT_CHARSET;
	strcpy_s(lf.lfFaceName, "Comic Sans MS");

	//load font
	hFont = CreateFontIndirect(&lf);
	hFontOld = (HFONT)SelectObject(hdc, hFont);

	//create the text mesh bas on the selected font
	D3DXCreateText(Device, hdc,"Glen Newell", 0.001f,
		0.4f, &Text, 0,0);

	//restor old font and free aquired hdc
	SelectObject(hdc, hFontOld);
	DeleteObject(hFont);
	DeleteDC(hdc);

	return true;
}

///////////////Rotation X,Y,Z/////////////////
void rotateObject(float timeDelta)
{
	D3DXMATRIX Rx,Ry,Rz;
	
	static float x = 3.14f / 4.0;
	D3DXMatrixRotationX(&Rx,x);
	if(directionX == 0)	x += timeDelta;
	if(directionX == 1)	timeDelta;
	if(directionX == 2)	x += -timeDelta;
	if(x >= 6.28f) x = 0.0f;
	
	static float y = 0.0f;
	D3DXMatrixRotationY(&Ry,y);	
	if(directionY == 0)	y += timeDelta; //move forward
	if(directionY == 1)	timeDelta; //stop
	if(directionY == 2)	y += -timeDelta; //move backwords
	if(y >= 6.28f) y = 0.0f;

	static float z = 0.0f;
	D3DXMatrixRotationZ(&Rz,z);	
	if(directionZ == 0)	z += timeDelta; //move forward
	if(directionZ == 1)	timeDelta; //stop
	if(directionZ == 2)	z += -timeDelta; //move backwords
	if(z >= 6.28f) z = 0.0f;
	
	D3DXMATRIX p = Rx * Ry * Rz; 
	Device->SetTransform(D3DTS_WORLD, &p);
}

////////////////////Clean Up////////////////////
void Cleanup()
{
	d3d::Release<ID3DXMesh*>(Text);
}

void render(float timeDelta)
{
	//lights
	D3DXVECTOR3 dir(0.0f, -0.5f, 1.0f);
	D3DXCOLOR col = color[change];
	D3DLIGHT9 light = d3d::InitDirectionalLight(&dir, &col);

	Device->SetLight(0, &light);
	Device->LightEnable(0,true);
	Device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	Device->SetRenderState(D3DRS_SPECULARENABLE,true);

	D3DXVECTOR3 pos(0.0f, 1.5f, -40.3f);
	D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);

	D3DXMATRIX V;
	D3DXMatrixLookAtLH(&V,&pos, &target, &up);

	Device->SetTransform(D3DTS_VIEW, &V);

	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
		&proj,
		D3DX_PI * 0.025,
		(float)Width / (float)Height, 
		0.01f,
		1000.0f);
	Device->SetTransform(D3DTS_PROJECTION, &proj);

	Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000,1.0f,0 );
	Device->BeginScene();

	Device->SetMaterial(&ME_MTRL);
	Text->DrawSubset(0);

	Device->EndScene();
}

////////////////////Display////////////////////
bool Display(float timeDelta)
{

	if(Device)
	{
		render(timeDelta);
		rotateObject(timeDelta);
		Device->Present(0,0,0,0);
	}
	return true;
}

////////////////////WinProc(callback)////////////////////
LRESULT CALLBACK d3d::WinProc(HWND hwnd, UINT msg,
	WPARAM wparam, LPARAM lparam)
{
	switch(msg)
	{
		//if time to quit
		case WM_DESTROY:
			::PostQuitMessage(0);
			break;

		//if exscape key is pressed
		case WM_KEYDOWN:
			if(wparam == VK_ESCAPE)
				::DestroyWindow(hwnd);

			if(wparam ==VK_PRIOR) //page up

				if(change == 4) change = 0;
				else change++;

			if(wparam ==VK_NEXT) //page down
				if(change == 0) change = 4;
				else change--;

			if(wparam == VK_LEFT) 
				if(directionY == 2) break;
				else directionY++;

			if(wparam == VK_RIGHT)
				if(directionY == 0) break;
				else directionY--;

			if(wparam == VK_UP)
				if(directionX == 0) break;
				else directionX--;

			if(wparam == VK_DOWN)
				if(directionX == 2) break;
				else directionX++;
			
			if(wparam == VK_HOME)
				if(directionZ == 0) break;
				else directionZ--;

			if(wparam == VK_DELETE)
				if(directionZ == 2) break;
				else directionZ++;

			if(wparam == VK_F1)
				::MessageBox(0, "(Left Arrow) -    Will rotate name to left\n"
				"(Right Arrow) - Will rotate name to right\n(Up arrow) -      Will rotate name up\n"
				"(Down arrow) - Will rotate name down\n(Home) - Will rotate the name on the forward\n"
				"(Delete) - Will rotat the name backwards\n(ESC) - Exit the program"
				"\n\nPressing any key once will initiate the spin, if you press the \n"
				"oppisite key once it will stop the spin, press the key again \n"
				"it will spin the opisite way.",
				"Instructions",0);
			break;
		break;

	}
	return ::DefWindowProc(hwnd,msg,wparam,lparam);
}

////////////////////WinMain////////////////////
int WINAPI WinMain(HINSTANCE hInstance,
					HINSTANCE prevInstance,
					PSTR cmdLine,
					int showCmd)
{
	if(!d3d::InitD3D(hInstance, Width, Height, true,
		D3DDEVTYPE_HAL, &Device))
	{
		::MessageBox(0, "InitD3D() - FAILED", 0,0);
		return 0;
	}

	if(!Setup())
	{
		::MessageBox(0, "Setup() - FAILED", 0,0);
		return 0;
	}

	d3d::EnterMsgLoop(Display);
	Cleanup();
	Device->Release();
	return 0;
}