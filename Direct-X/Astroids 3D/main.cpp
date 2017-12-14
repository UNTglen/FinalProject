#define INITGUID
#include "base.h"
#include "dinput.h"
#include "text.h"
#include "ship.h"
#include "XACT Sound.h"
#include <time.h>

#define DEGTORAD(degree) ((D3DX_PI / 180.0f) * (degree)) // converts from degrees to radians

//audio
XACTINDEX asthit = 0;
XACTINDEX shot	 = 0;
XACTINDEX thrust = 0;


// Globals
	IDirect3DDevice9* Device = 0; 
	HINSTANCE main_instance = NULL;
	HWND main_hwnd = NULL;
	bool game_state = true;

//Screen
	const int Width  = 1020;
	const int Height = 800;

//Texture
	IDirect3DTexture9* my_texture = 0;
	IDirect3DTexture9* my_texture2 = 0;

//score
	int score = 0;

//lives
	int lives = 3;

//Asteroid State
	int state = 0; //0 = whole asteroid, 1 = 1/2 asteroid, 2 = 1/4 asteroid, 3 dead asteroid

//controler state
	int direction = 0;

//asteroid Functions
extern bool createAsteroid(IDirect3DDevice9* device, IDirect3DTexture9* texture, int state);
extern bool render(IDirect3DDevice9* device, const int Height, const int Width,int state);

//controller functions
extern bool setupDirectInput(HINSTANCE main_instance, HWND main_hwnd);
extern bool checkBoost(bool hyperspace);
int checkState(int direction, stXACTAudio sound, XACTINDEX thrust);
//extern int checkState(int direction);
extern void cleanControls();

//text functions
extern void setupFont(IDirect3DDevice9* device);
extern void myText(int score, int lives, const int Height, const int Width);
extern void cleanText();

//ship funtions
extern bool createShip(IDirect3DDevice9* device, IDirect3DTexture9* texture, const int Height, const int Width);
extern void moveShip(IDirect3DDevice9* device, const int Height, const int Width, int dir);
extern void renderShip(IDirect3DDevice9* device);
extern bool render1(IDirect3DDevice9* device, const int Height, const int Width, int direction);

void setupTexture()
{
	if(FAILED(D3DXCreateTextureFromFile(Device,"ast.bmp",&my_texture)))
	{
		::MessageBox(0, "Tex - FAILED", 0, 0);
	}

	if(FAILED(D3DXCreateTextureFromFile(Device,"ship.jpg",&my_texture2)))
	{
		::MessageBox(0, "Tex - FAILED", 0, 0);
	}

	Device->SetTextureStageState(0, D3DTSS_ALPHAARG1,D3DTA_TEXTURE);
	Device->SetTextureStageState(0, D3DTSS_ALPHAARG1,D3DTOP_SELECTARG1);

}

void endGame()
{
	char end[512];
	sprintf_s(end,"You have Died!\nYour Score was: %d ",score);
	
	if(MessageBox(0, end, "Play Again?", MB_YESNO | MB_ICONQUESTION) == IDNO) ::PostQuitMessage(0);

	else 
		score = 0;
		lives = 3;
}

void setupXACT()
{
	if(!SetupXACT("Win\\Wave Bank.xwb", "Win\\Sound Bank.xsb"))
	{
		::MessageBox(0,"XACT - FAILED",0,0);
	}

	asthit = g_xactSound.m_soundBank->GetCueIndex("asthit");
	shot = g_xactSound.m_soundBank->GetCueIndex("Shot");
	thrust = g_xactSound.m_soundBank->GetCueIndex("Thrust");
}

//Setup everything
bool Setup()
{
	setupFont(Device);
	setupTexture();
	setupXACT();
	setupDirectInput(main_instance,main_hwnd);
	createAsteroid(Device,my_texture,state);
	createShip(Device,my_texture2,Height,Width);
	return true;
}

//Clean up everything
void Cleanup()
{
	cleanControls();
	cleanText();
	d3d::Release<IDirect3DTexture9*>(my_texture);
}



//Draw Everything
bool Display()
{
	if(game_state == false) endGame();
	while(game_state == true)
	{
		if( Device )
		{
			//set camera
			D3DXMATRIX V;
			D3DXMatrixIdentity(&V);
			Device->SetTransform(D3DTS_WORLD,&V);
			Device->SetTransform(D3DTS_VIEW, &V);
		
			//draw projection matrix
			D3DXMATRIX proj;
			//D3DXMatrixPerspectiveFovLH(&proj,D3DX_PI * 0.25f , (float)Width/(float)Height, 0.01f,1000.0f);
			D3DXMatrixOrthoOffCenterLH(&proj, -40.0f,40.0f, -40.0f,40.0f, 0.0f, 10.0f);
			//D3DXMatrixRotationY(&proj,DEGTORAD(1));
			Device->SetTransform(D3DTS_PROJECTION,&proj);
	
			direction = checkState(direction,g_xactSound,thrust);
			//if(direction !=0 ) g_xactSound.m_soundBank->Play(thrust, 0, 100, NULL);
			
			//draw everything
			Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000,1.0f,0 );
			Device->BeginScene();

				myText(score,lives,Height,Width); //score & life
				render(Device,Height,Width, state); //asteriods
				render1(Device,Height,Width,direction);

			Device->EndScene();
			Device->Present(0,0,0,0);
		

			if(lives < 0) endGame();
		}

		return true;
	}
	return true;
}

LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch( msg )
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
		
	case WM_KEYDOWN:
		if( wParam == VK_ESCAPE )
			::DestroyWindow(hwnd);
		
		if(wParam == VK_SPACE)
			g_xactSound.m_soundBank->Play(shot,0,0,NULL);

		if(wParam == 'A') 
		{	
			state++;
			if(state == 3) state = 0;
			g_xactSound.m_soundBank->Play(asthit, 0, 0, NULL);
		}

		break;
	}
	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE prevInstance, PSTR cmdLine, int showCmd)
{
	main_instance = hinstance;
	if(!d3d::InitD3D(hinstance, Width, Height, true, D3DDEVTYPE_HAL, &Device))
	{
		::MessageBox(0, "InitD3D() - FAILED", 0, 0);
		return 0;
	}
		
	if(!Setup())
	{
		::MessageBox(0, "Setup() - FAILED", 0, 0);
		return 0;
	}

	//createAsteroid(Device,Height,Width, my_texture,state);
	
	d3d::EnterMsgLoop(Display);

	Cleanup();

	Device->Release();

	return 0;
}

