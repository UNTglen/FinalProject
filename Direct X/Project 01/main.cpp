
#include "base.h"

//
// Globals
//

IDirect3DDevice9* Device = 0; 

const int Width  = 1200;
const int Height = 1200;

#define FVF_VERTEX (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1)

IDirect3DVertexBuffer9* BkGndQuad = 0;
IDirect3DVertexBuffer9* LeftQuad = 0;
IDirect3DVertexBuffer9* RightQuad = 0;
IDirect3DVertexBuffer9* BottomQuad = 0;

IDirect3DTexture9* BkGndTex = 0;
IDirect3DTexture9* LeftTex = 0;
IDirect3DTexture9* RightTex = 0;
IDirect3DTexture9* BottomTex = 0;

D3DMATERIAL9 BkGndMtrl;

//for teapot
IDirect3DTexture9* TeapotTex = 0;
ID3DXMesh* Teapot = 0;
D3DMATERIAL9 TeapotMtrl;
int x= -2, y = -2;
struct Vertex
{
	Vertex(){}
	Vertex(float x, float y, float z, float nx, float ny, float nz, float u, float v)
	{
		_x = x; _y = y; _z = z;
		_nx = nx; _ny = ny; _nz = nz;
		_u = u; _v = v;
	}
	float _x, _y, _z;
	float _nx, _ny, _nz;
	float _u, _v;
};

//
// Framework functions
//
bool Setup()
{
	//create quad to hold background
	Device->CreateVertexBuffer(6 * sizeof(Vertex), D3DUSAGE_WRITEONLY, FVF_VERTEX, D3DPOOL_MANAGED, &BkGndQuad, 0);
	
	Vertex* v;
	BkGndQuad->Lock(0, 0, (void**)&v, 0);
	//build an quad from two triangles for background
	v[0] = Vertex(-10.0f, -10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[1] = Vertex(-10.0f, 10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
	v[2] = Vertex(10.0f, 10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);

	v[3] = Vertex(-10.0f, -10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[4] = Vertex(10.0f, 10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
	v[5] = Vertex(10.0f, -10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);

	BkGndQuad->Unlock();
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//create 2nd quad to hold bkground
	Device->CreateVertexBuffer(6 * sizeof(Vertex), D3DUSAGE_WRITEONLY, FVF_VERTEX, D3DPOOL_MANAGED, &LeftQuad, 0);
	
	Vertex* v2;
	LeftQuad->Lock(0, 0, (void**)&v, 0);
	//build 2nd quad from two triangles for background
	v[0] = Vertex(-10.0f, 10.0f, -20.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[1] = Vertex(-10.0f, 10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
	v[2] = Vertex(-10.0f, -10.0f, -20.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);

	v[3] = Vertex(-10.0f, -10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[4] = Vertex(-10.0f, -10.0f, -20.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
	v[5] = Vertex(-10.0f, 10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);

	LeftQuad->Unlock();

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//create 3rd quad to hold bkground
	Device->CreateVertexBuffer(6 * sizeof(Vertex), D3DUSAGE_WRITEONLY, FVF_VERTEX, D3DPOOL_MANAGED, &RightQuad, 0);
	
	Vertex* v3;
	RightQuad->Lock(0, 0, (void**)&v, 0);
	//build 3rd quad from two triangles for background
	v[0] = Vertex(10.0f, -10.0f, -20.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[1] = Vertex(10.0f, -10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
	v[2] = Vertex(10.0f, 10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);

	v[3] = Vertex(10.0f, 10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[4] = Vertex(10.0f, 10.0f, -20.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
	v[5] = Vertex(10.0f, -10.0f, -20.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);

	RightQuad->Unlock();


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//create 4th quad to hold bkground
	Device->CreateVertexBuffer(6 * sizeof(Vertex), D3DUSAGE_WRITEONLY, FVF_VERTEX, D3DPOOL_MANAGED, &BottomQuad, 0);
	
	Vertex* v4;
	BottomQuad->Lock(0, 0, (void**)&v, 0);
	//build 4th quad from two triangles for background
	v[0] = Vertex(10.0f, -10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[1] = Vertex(10.0f, -10.0f, -20.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
	v[2] = Vertex(-10.0f, -10.0f, -20.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);

	v[3] = Vertex(-10.0f, -10.0f, -20.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[4] = Vertex(-10.0f, -10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
	v[5] = Vertex(10.0f, -10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);

	BottomQuad->Unlock();

	//TeapotMtrl = d3d::BLUE_MTRL;
	D3DXCreateTeapot(Device, &Teapot, 0);

	//load pictures
	D3DXCreateTextureFromFile(Device, "carnival.jpg", &BkGndTex);
	D3DXCreateTextureFromFile(Device, "carnival.jpg", &LeftTex);
	D3DXCreateTextureFromFile(Device, "carnival.jpg", &RightTex);
	D3DXCreateTextureFromFile(Device, "carnival.jpg", &BottomTex);


	Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_DIFFUSE);
	Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
	
	//disable lighting
	Device->SetRenderState(D3DRS_LIGHTING, false);



	//
	// Set camera.
	//

	D3DXVECTOR3 pos(0.0f, 0.0f, -10.0f);
	D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);

	D3DXMATRIX V;
	D3DXMatrixLookAtLH(&V, &pos, &target, &up);

	Device->SetTransform(D3DTS_VIEW, &V);
	//
	// Set projection matrix.
	//
	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
			&proj,
			D3DX_PI * 0.5f, // 90 - degree
			(float)Width / (float)Height,
			0.01f,
			1000.0f);
	Device->SetTransform(D3DTS_PROJECTION, &proj);

	return true;
}

void Cleanup()
{
	d3d::Release<IDirect3DVertexBuffer9*>(BkGndQuad);
	d3d::Release<IDirect3DTexture9*>(BkGndTex);
	d3d::Release<IDirect3DTexture9*>(TeapotTex);
	d3d::Release<ID3DXMesh*>(Teapot);
}

bool Display()
{


	if( Device )
	{
		
		D3DXMATRIX teapot;
		D3DXMatrixTranslation(&teapot, x, y, -1);

		Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);
		Device->BeginScene();

		//draw background
		D3DXMATRIX I;
		D3DXMatrixIdentity(&I);

		Device->SetStreamSource(0, BkGndQuad, 0, sizeof(Vertex));
		Device->SetFVF(FVF_VERTEX);
		Device->SetTransform(D3DTS_WORLD, &I);
		Device->SetMaterial(&BkGndMtrl);
		Device->SetTexture(0, BkGndTex);
		Device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

		//left 
		Device->SetStreamSource(0, LeftQuad, 0, sizeof(Vertex));
		Device->SetFVF(FVF_VERTEX);
		Device->SetTransform(D3DTS_WORLD, &I);
		Device->SetMaterial(&BkGndMtrl);
		Device->SetTexture(0, LeftTex);
		Device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

		//right
		Device->SetStreamSource(0, RightQuad, 0, sizeof(Vertex));
		Device->SetFVF(FVF_VERTEX);
		Device->SetTransform(D3DTS_WORLD, &I);
		Device->SetMaterial(&BkGndMtrl);
		Device->SetTexture(0, RightTex);
		Device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

		//bottom
		Device->SetStreamSource(0, BottomQuad, 0, sizeof(Vertex));
		Device->SetFVF(FVF_VERTEX);
		Device->SetTransform(D3DTS_WORLD, &I);
		Device->SetMaterial(&BkGndMtrl);
		Device->SetTexture(0, BottomTex);
		Device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

		//draw teapot
		Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
		Device->SetTransform(D3DTS_WORLD, &I);
		Device->SetMaterial(&TeapotMtrl);
		Device->SetTexture(0, TeapotTex);
		Device->SetTransform(D3DTS_WORLD, &teapot);
		Teapot->DrawSubset(0);

		Device->EndScene();
		Device->Present(0, 0, 0, 0);
	}

	return true;
}

//
// WndProc
//
LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch( msg )
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
		
	case WM_KEYDOWN:
		{
			if( wParam == VK_ESCAPE )
				::DestroyWindow(hwnd);
		
			if(wParam == VK_SPACE)
			{
				if(y != 3)
				{
					x+=1.0;
					y+=1.0;
				}

				
			}
		}
		break;
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

	d3d::EnterMsgLoop( Display );

	Cleanup();

	Device->Release();

	return 0;
}

