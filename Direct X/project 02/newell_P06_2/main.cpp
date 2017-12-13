#include "base.h"

////////////////////globals////////////////////
IDirect3DDevice9* Device = 0;	//device pointer to device
const int Width = 800;			//default width
const int Height = 600;			//default height
DWORD starttime = 0; //???

IDirect3DVertexBuffer9* VB=0;
IDirect3DIndexBuffer9* IB=0;

struct Vertex
{
	Vertex(){}
	Vertex(float x, float y, float z)
	{
		_x=x; _y=y; _z=z;
	}
	float _x,_y,_z;
	static const DWORD FVF;
};

const DWORD Vertex::FVF = D3DFVF_XYZ;

void fillIndices()
{
	//define triangles to make cube
	WORD* indices = 0;
	IB->Lock(0,0,(void**)&indices,0);

	//front side of cube
	indices[0] = 0; indices[1] = 1;indices[2] = 2;
	indices[3] = 0; indices[4] = 2;indices[5] = 3;
	
	//backside of cube
	indices[6] = 4; indices[7] = 6;indices[8] = 5;
	indices[9] = 4; indices[10] = 7;indices[11] = 6;

	//left side of cube
	indices[12] = 4; indices[13] = 5;indices[14] = 1;
	indices[15] = 4; indices[16] = 1;indices[17] = 0;
	
	//right side of cube
	indices[18] = 3; indices[19] = 2;indices[20] = 6;
	indices[21] = 3; indices[22] = 6;indices[23] = 7;

	//top of cube
	indices[24] = 1; indices[25] = 5;indices[26] = 6;
	indices[27] = 1; indices[28] = 6;indices[29] = 2;

	//bottom of cube
	indices[30] = 4; indices[31] = 0;indices[32] = 3;
	indices[33] = 4; indices[34] = 3;indices[35] = 7;
	IB->Unlock();
}

void drawBox(float x, float y, float z)
{
	//create vertex and index buffers (8 number of points)
	Device->CreateVertexBuffer(8 * sizeof(Vertex),
		D3DUSAGE_WRITEONLY, Vertex::FVF,
		D3DPOOL_MANAGED, &VB,0);

	//create index buffer(32 makes a cube)
	Device->CreateIndexBuffer(36 * sizeof(WORD),
		D3DUSAGE_WRITEONLY, D3DFMT_INDEX16,
		D3DPOOL_MANAGED, &IB,0);

	//Fill up buffer with cube data
	Vertex* vertices;
	VB->Lock(0,0,(void**)&vertices,0);

	//Fill verticies points (8)
	vertices[0] = Vertex(-x,-y,-z);
	vertices[1] = Vertex(-x, y,-z);
	vertices[2] = Vertex( x, y,-z);
	vertices[3] = Vertex( x,-y,-z);
	vertices[4] = Vertex(-x,-y, z);
	vertices[5] = Vertex(-x, y, z);
	vertices[6] = Vertex( x, y, z);
	vertices[7] = Vertex( x,-y, z);
	VB->Unlock();

	fillIndices();
}

void projectView(int x, int y)
{
	//set projection
	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
		&proj, 
		D3DX_PI * 0.5f,
		(float)x / (float)y,
		1.0f, 
		1000.0f);
	Device->SetTransform(D3DTS_PROJECTION, &proj);

	//set render state
	Device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

}

////////////////////Setup////////////////////
bool Setup()
{
	//set up lights camara view etc
	//////Camera//////
	D3DXVECTOR3 position(0.0f, 0.0f, -5.0f);
	D3DXVECTOR3 target(0.0f, -1.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXMATRIX V;
	D3DXMatrixLookAtLH(&V, &position, &target, &up);
	Device->SetTransform(D3DTS_VIEW, &V);

	projectView(Width,Height);

	return true;
}

////////////////////Clean Up////////////////////
void Cleanup()
{
	d3d::Release<IDirect3DVertexBuffer9*>(VB);
	d3d::Release<IDirect3DIndexBuffer9*>(IB);
}

void spinLeft(float timeDelta)
{
	//spin the cube
		D3DXMATRIX Rx,Ry;
		D3DXMatrixRotationX(&Rx, 0.0f);//3.14f / 4.0f);
		static float y = 0.0f;
		D3DXMatrixRotationY(&Ry,y);
		y += timeDelta;
		if(y >= 6.28f)
			y = 0.0f;
		D3DXMATRIX p = Rx * Ry;
		Device->SetTransform(D3DTS_WORLD, &p);
}

void spinRight(float timeDelta)
{
	//spin the cube
		D3DXMATRIX Rx,Ry;
		D3DXMatrixRotationX(&Rx, 0.0f);//3.14f / 4.0f);
		static float y = 0.0f;
		D3DXMatrixRotationY(&Ry,y);
		y -= timeDelta;
		if(y >= 6.28f)
			y = 0.0f;
		D3DXMATRIX p = Rx * Ry;
		Device->SetTransform(D3DTS_WORLD, &p);
}

void renderBox()
{
	
	Device->SetStreamSource(0,VB,0, sizeof(Vertex));
	Device->SetIndices(IB);
	Device->SetFVF(Vertex::FVF);
	Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12); 
	
}

////////////////////Display////////////////////
bool Display(float timeDelta)
{
	//spin a cube
	if(Device)
	{
		Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);
		Device->BeginScene();
		{
			drawBox(0.5f,0.5f,0.5f);
			spinRight(timeDelta);
			renderBox();
		}
		Device->EndScene();

		Device->BeginScene();
		{
			drawBox(1.0f,1.0f,1.0f);
			spinLeft(timeDelta);
			renderBox();
		}
		Device->EndScene();


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
