#include "base.h"
#include <Windows.h>
#include <math.h>

////////////////////Globals////////////////////
IDirect3DDevice9* Device = 0;	//device pointer to device

const int Width = 800;					//default width
const int Height = 600;					//default height

int check = 0;							//Tab Menu	

ID3DXMesh* ActiveMesh[4] = {0,0,0,0};	//array of mesh's
D3DXMATRIX ActiveMatrix[4];				//array of matrices

int directionX = 1, directionY = 1;		 //direction menu X and Y

float x=0.0f,y=0.0f,z=-5.0f;			// camera cord.

///////////////Rotation X,Y,Z/////////////////
void rotateObject(float timeDelta)
{
	D3DXMATRIX Rx,Ry;
	
	static float x = 3.14f / 4.0;
	D3DXMatrixRotationX(&Rx,x);
	if(directionX == 0)	x += timeDelta;
	if(directionX == 1)	timeDelta;
	if(directionX == 2)	x += -timeDelta;
	if(x >= 6.28f) x = 0.0f;

	static float y = 0.0f;
	D3DXMatrixRotationY(&Ry,y);	
	if(directionY == 0)	y += timeDelta;
	if(directionY == 1)	timeDelta;
	if(directionY == 2)	y += -timeDelta;
	if(y >= 6.28f) y = 0.0f;
	
	D3DXMATRIX p = Rx * Ry; 
	Device->SetTransform(D3DTS_WORLD, &p);
}

////////////////////Setup////////////////////
bool Setup()
{
	//set up objects to be drawn and put in mesh array
	D3DXCreateSphere(Device,1,15,10,&ActiveMesh[0],0);
	D3DXCreateBox(Device,1.5,1.5,1.5,&ActiveMesh[1],0);
	D3DXCreateCylinder(Device,.5,.5,2.5,20,5,&ActiveMesh[2],0);
	D3DXCreateTorus(Device,.5,1,10,20,&ActiveMesh[3],0);

	//set the objects into matrix array
	D3DXMatrixTranslation(&ActiveMatrix[0], -5.0f, 0.0f, 5.0f);
	D3DXMatrixTranslation(&ActiveMatrix[1], 5.0f, 0.0f, -5.0f);
	D3DXMatrixTranslation(&ActiveMatrix[2], -5.0f, 0.0f, 5.0f);
	D3DXMatrixTranslation(&ActiveMatrix[3], 5.0f, 0.0f, -5.0f);
	
	//set up the camera
	D3DXVECTOR3 position(0.0f, 0.0f, -5.0f);
	D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXMATRIX V;
	D3DXMatrixLookAtLH(&V, &position, &target, &up);
	Device->SetTransform(D3DTS_VIEW, &V);


	//set projection Matrix
	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
		&proj, 
		D3DX_PI * 0.5f,
		(float)Width / (float)Height,
		1.0f, 
		1000.0f);
	Device->SetTransform(D3DTS_PROJECTION, &proj);

	//set render state
	Device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	return true;
}

////////////////////Clean Up////////////////////
void Cleanup()
{
	//cycle through mesh and deallocate all memory
	for(int x = 0; x < 4; x++)
		d3d::Release<ID3DXMesh*>(ActiveMesh[x]);
}


/////////////////Random float/////////////////
float randomFloat(float min, float max)
{
	return ((max-min)*((float)rand()/RAND_MAX))+min;
}


/////////////////Render Everything/////////////////
void render(float timeDelta)
{
		//draw the scene
		Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);
		Device->BeginScene();
		
		//checks to make sure objects do not go out of scope
		if(check > 3) check = 0;
			
		D3DXMatrixTranslation(&ActiveMatrix[check],x,y,z);
		Device->SetTransform(D3DTS_VIEW, &ActiveMatrix[check]);
		ActiveMesh[check]->DrawSubset(0);
		
		Device->EndScene();	
}



////////////////////Display////////////////////
bool Display(float timeDelta)
{
	
	if(Device)
	{
		rotateObject(timeDelta);
		render(timeDelta);
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

			//controlls
			if(wparam == VK_LEFT)
				directionY = 0;
			if(wparam == VK_RIGHT)
				directionY = 2;
			if(wparam == VK_UP)
				directionX = 0;
			if(wparam == VK_DOWN)
				directionX = 2;

			//Select next object
			if(wparam == VK_TAB)
			{
				check++;
				/////////need to find limits/////////
				x = randomFloat(1.0f,-5.0f);
				y = randomFloat(9.0f,-5.0f);
				z = randomFloat(10.0f,-0.0f);
			}

			//Select specific object
			if(wparam == 0x31)
				check = 0;
			if(wparam == 0x32)
				check = 1;
			if(wparam == 0x33)
				check = 2;
			if(wparam == 0x34)
				check = 3;


			if(wparam == VK_F1)
				::MessageBox(0, "Directional Arrows - Rotates X and Y axis of the Object\n"
				"Tab - selects object to controll\n1 - Selects sphere\n2 - Selects cube\n"
				"3 - Selects cylinder\n4 - Selects Toras", 
				"Instructions",0);
			break;

		case WM_KEYUP:
			directionY = 1;
			directionX = 1;
			//directionZ = 1;
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
