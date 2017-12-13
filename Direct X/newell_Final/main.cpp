
#include "base.h"
#include "resource.h"


IDirect3DDevice9* Device = 0; 

const int Width  = 800;
const int Height = 600;

//dont think ill need
//DWORD starttime = 0;
//float DTime = 0.15f;

//variable controlls
int nextObject = 0; //Tab Menu
int  rotationX = 1, rotationY = 1; //direction menu X

//Array of meshes
ID3DXMesh* ActiveMesh[3] = {0,0,0}; //array of mesh's
D3DXMATRIX ActiveMatrix[3]; //array of matrices

//colors for object to be selected
const D3DXCOLOR RED(D3DCOLOR_XRGB(255,0,0));
const D3DXCOLOR GREEN(D3DCOLOR_XRGB(0,255,0)); 
const D3DXCOLOR BLUE(D3DCOLOR_XRGB(0,0,255));
const D3DXCOLOR BLACK(D3DCOLOR_XRGB(0,0,0));
D3DXCOLOR color[4] = {BLUE,GREEN,RED,BLACK};

//how to implment color?

bool Setup()
{
	//set up objects to be drawn and put in mesh array
	D3DXCreateTorus(Device,.5,1,10,20,&ActiveMesh[0],0); // torus
	D3DXCreateTeapot(Device,&ActiveMesh[1],0);			 // teapot
	D3DXCreateSphere(Device,1,15,10,&ActiveMesh[2],0);   // sphere
	
	//set the objects into matrix array
	D3DXMatrixTranslation(&ActiveMatrix[0], -5.0f, 0.0f, 5.0f);
	D3DXMatrixTranslation(&ActiveMatrix[1], 5.0f, 0.0f, -5.0f);
	D3DXMatrixTranslation(&ActiveMatrix[2], -5.0f, 0.0f, 5.0f);
	
	//set up camera
	D3DXVECTOR3 pos(0.0f, 0.0f, -5.0f);
	D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXMATRIX MINE;
	D3DXMatrixLookAtLH(&MINE, &pos, &target, &up);
	Device->SetTransform(D3DTS_VIEW, &MINE);

	//set up prjection matrix
	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
	&proj, 
	D3DX_PI * 0.5f,
	(float)Width / (float)Height,
	1.0f, 
	1000.0f);
	Device->SetTransform(D3DTS_PROJECTION, &proj);

	//set up object
	Device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	Device->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
	//color goes here some how

	Device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	Device->SetRenderState(D3DRS_SPECULARENABLE, true);

	return true;
}

//rotation of object
void rotateObject(float time)
{
	D3DXMATRIX Rx, Ry;
	static float x = 3.14f / 4.0;
	D3DXMatrixRotationX(&Rx,x);
	if(rotationX == 0) x += time;
	if(rotationX == 1) time;
	if(rotationX == 2) x += -time;
	if(x >= 6.28f) x = 0.0f;

	static float y = 0.0f;
	D3DXMatrixRotationY(&Ry,y);	
	if(rotationY == 0) y += time;
	if(rotationY == 1) time;
	if(rotationY == 2) y += -time;
	if(y >= 6.28f) x = 0.0f;

	D3DXMATRIX P = Ry * Rx;
	Device->SetTransform(D3DTS_WORLD,&P);

}

void Cleanup()
{
	for(int i=0; i<3; i++)
		d3d::Release<ID3DXMesh*>(ActiveMesh[i]);
}

void render()
{
	//checks to make sure objects do not go out of scope wile tabing
	if(nextObject > 2) nextObject = 0;

	Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);
	Device->BeginScene();

	D3DXMatrixTranslation(&ActiveMatrix[nextObject],0.0f,0.0f,5.0f);
	Device->SetTransform(D3DTS_VIEW, &ActiveMatrix[nextObject]);
	ActiveMesh[nextObject]->DrawSubset(0);

	Device->EndScene();
}

bool Display(float timeDelta)
{
	//starttime = GetTickCount();

	if(Device)
	{
		//
		// Render
		//
		rotateObject(timeDelta);
		render(); ///works
		Device->Present(0, 0, 0, 0);
	}

	//while ((GetTickCount() - starttime) < (1000/30))
	//{
	//}
	return true;
}

//
// WndProc
//
LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		

		case WM_DESTROY:
			::PostQuitMessage(0);
			break;
		
		case WM_KEYDOWN:
			if(wParam == VK_ESCAPE)
				::DestroyWindow(hwnd);
			if(wParam == VK_UP) //rotation up
				rotationX = 0;
			if(wParam == VK_DOWN) //rotation down
				rotationX = 2;
			if(wParam == VK_LEFT) //rotation left
				rotationY = 0;
			if(wParam == VK_RIGHT) //rotation right
				rotationY = 2;
			if(wParam == VK_F1) //select menu
				::MessageBox(0, "To rotate object press Up(^) or Down(v) Arrow keys\n"
				"To rotate object press Left(<-) or Right(->) Arrow keys\n"
				"To select next object press Tab (Tab)","Instructions",0);
			if(wParam == VK_TAB) //select next object
				nextObject++;  //works
			break;

		case WM_KEYUP:
			rotationX = 1;
			rotationY = 1;
			break;

		case(WM_COMMAND):
		{
			switch(LOWORD(wParam))
			{
				case MENU_FILE_EXIT:
					::PostQuitMessage(0);
				break;
				case MENU_HELP_INSTRUCTIONS:
					break;
			}
		 break;
		}

	}
	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}

//
// WinMain
//
int WINAPI WinMain(HINSTANCE hinstance,
				   HINSTANCE prevInstance, 
				   PSTR cmdLine,
				   int showCmd)
{
	if(!d3d::InitD3D(hinstance,
		Width, Height, true, D3DDEVTYPE_HAL, &Device))
	{
		::MessageBox(0, "InitD3D() - FAILED", 0, 0);
		return 0;
	}
		
	if(!Setup())
	{
		::MessageBox(0, "Setup() - FAILED", 0, 0);
		return 0;
	}

	ShowCursor(true);//false);
	d3d::EnterMsgLoop(Display);
	Cleanup();
	Device->Release();
	return 0;
}
