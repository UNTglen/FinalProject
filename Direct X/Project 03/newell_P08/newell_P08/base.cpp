#include "base.h"

bool d3d::InitD3D(HINSTANCE hInstance, 
	int width, int height, bool windowed,
	D3DDEVTYPE deviceType,
	IDirect3DDevice9** device)
{
	//creat the main application window
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)d3d::WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0,IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = "Direct3D";

	if(!RegisterClass(&wc))
	{
		::MessageBox(0, "RegisterClass() - FAILED",0,0);
		return false;
	}

	HWND hwnd = 0;

	::MessageBox(0, "Press Okay to continue\n while in game Press 'F1' for help", "Help",0);

	hwnd = ::CreateWindow("Direct3D","Rotating Font",WS_EX_TOPMOST | WS_SYSMENU,0,0,width,height,0,0,hInstance,0);
	
	if(!hwnd)
	{
		::MessageBox(0, "CreateWindow() - FAILED",0,0);
		return false;
	}

	::ShowWindow(hwnd,SW_SHOW);
	::UpdateWindow(hwnd);

	HRESULT hr = 0;

	//STEP 1: Create the direct3D object
	IDirect3D9* d3d9 = 0;
	d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

	if(!d3d9)
	{
		::MessageBox(0, "Direct3DCreate9() - FAILED",0,0);
		return false;
	}

	//STEP 2: check for hardware
	D3DCAPS9 caps;
	d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, deviceType, &caps);
	int vp = 0;
	if(caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	else
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	//Step 3: Fill out the perameters
	D3DPRESENT_PARAMETERS d3dpp;
	d3dpp.BackBufferWidth = width;
	d3dpp.BackBufferHeight = height;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hwnd;
	d3dpp.Windowed = windowed;
	d3dpp.EnableAutoDepthStencil = true;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	d3dpp.Flags = 0;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	//step 4: creat the device
	hr = d3d9->CreateDevice(D3DADAPTER_DEFAULT, 
		deviceType, hwnd, vp, &d3dpp, device);

	if(FAILED(hr))
	{
		d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
		
		hr = d3d9->CreateDevice(D3DADAPTER_DEFAULT, 
		deviceType, hwnd, vp, &d3dpp, device);
	

		if(FAILED(hr))
		{
			::MessageBox(0, "CreateDevice() - FAILED",0,0);
			return false;
		}
	}
	d3d9->Release();
	return true;
}

//float timeDelta allows us to set up for animation

int d3d::EnterMsgLoop(bool (*ptr_display)(float timeDelta))
{
	MSG msg;
	::ZeroMemory(&msg, sizeof(MSG));

	static float lastTime = (float)timeGetTime();

	while(msg.message != WM_QUIT)
	{
		if(::PeekMessage(&msg,0,0,0,PM_REMOVE))
		{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
		}

		else
		{
			float currTime = (float)timeGetTime();
			float timeDelta = (currTime - lastTime)* 0.001f;
			ptr_display(timeDelta);
			lastTime = currTime;
		}
	}

	return msg.wParam;
}
/*
int d3d::EnterMsgLoop(bool (*ptr_display)())
{
	MSG msg;
	::ZeroMemory(&msg, sizeof(MSG));

	while(msg.message != WM_QUIT)
	{
		if(::PeekMessage(&msg,0,0,0,PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}

		else
		{
			ptr_display();
		}
	}

	return msg.wParam;
}*/

D3DLIGHT9 d3d::InitDirectionalLight(D3DXVECTOR3* direction,
	D3DXCOLOR* color)
{
	D3DLIGHT9 light;
	::ZeroMemory(&light, sizeof(light));
	light.Type = D3DLIGHT_DIRECTIONAL;
	light.Ambient = *color * 0.04f;
	light.Diffuse = *color;
	light.Specular = *color * 0.0f;
	light.Direction = *direction;
	return light;
}

D3DMATERIAL9 d3d::InitMtrl(D3DXCOLOR a, D3DXCOLOR d, 
	D3DXCOLOR s, D3DXCOLOR e, float p)
{
	D3DMATERIAL9 mtrl;
	mtrl.Ambient = a;
	mtrl.Diffuse = d;
	mtrl.Emissive = e;
	mtrl.Power = p;
	return mtrl;
}