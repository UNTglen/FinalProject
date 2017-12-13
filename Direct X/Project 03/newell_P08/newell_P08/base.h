#ifndef base_H_
#define base_H_

#include <d3dx9.h>
#include <string>

namespace d3d
{
	// could initialize colors, lights etc
	bool InitD3D(HINSTANCE hInstance, int width, int height, bool windowed, D3DDEVTYPE deviceType,
		IDirect3DDevice9** device);

	int EnterMsgLoop(bool (*ptr_display)(float timeDelta));
	//int EnterMsgLoop(bool (*ptr_display)());

	LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);


	//deallocate memory
	template<class T> void Release(T t)
	{
		if( t )
		{
			t->Release();
			t = 0;
		}
	}



	//lighting
	D3DLIGHT9 InitDirectionalLight(D3DXVECTOR3* direction,
		D3DXCOLOR* color);

	D3DMATERIAL9 InitMtrl(D3DXCOLOR a, D3DXCOLOR d, D3DXCOLOR s,
		D3DXCOLOR e, float p);

}
#endif

