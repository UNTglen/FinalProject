#include "controls.h"
#include "dinput.h"
#include "XACT Sound.h"
#define INITGUID

//Device for direct input
LPDIRECTINPUT8 lpDI = NULL;

//Device for direct keyboard
LPDIRECTINPUTDEVICE8  lpDIKey = NULL;
UCHAR keyboard_state[256];

//Device for direct mouse
LPDIRECTINPUTDEVICE8 lpDIMouse = NULL;
DIMOUSESTATE mouse_state;

// Direct Input 8 – Joystick 
LPDIRECTINPUTDEVICE8 lpDIJS = NULL;
GUID                joystickGUID;        // guid for main joystick
char                joyname[80];         // name of joystick
DIJOYSTATE  joy_state;					// contains state of joystick

BOOL CALLBACK DI_Enum_Joysticks(LPCDIDEVICEINSTANCE lpddi, LPVOID guid_ptr)
{
	// this function enumerates the joysticks, but stops at the first one and returns the instance guid of it, so we can create it
	*(GUID*)guid_ptr = lpddi->guidInstance;
	// copy name into global
	strcpy(joyname, (char *)lpddi->tszProductName);
	// stop enumeration after one iteration
	return(DIENUM_STOP);
} // end DI_Enum_Joysticks


bool setupDirectInput(HINSTANCE main_instance, HWND main_hwnd)
{
	if(FAILED(DirectInput8Create(main_instance,DIRECTINPUT_VERSION, IID_IDirectInput8,(void**)&lpDI,NULL))) return(0);

	//check for keyboard
	if(FAILED(lpDI->CreateDevice(GUID_SysKeyboard,&lpDIKey,NULL))) return(0);
	if(FAILED(lpDIKey->SetCooperativeLevel(main_hwnd,DISCL_NONEXCLUSIVE | DISCL_BACKGROUND))) return(0);
	if(FAILED(lpDIKey->SetDataFormat(&c_dfDIKeyboard)))return(0);
	if(FAILED(lpDIKey->Acquire())) return(0);

	//check for mouse
	if(FAILED(lpDI->CreateDevice(GUID_SysMouse,&lpDIMouse,NULL))) return(0);
	if(FAILED(lpDIMouse->SetCooperativeLevel(main_hwnd,DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))	return(0);
	if(FAILED(lpDIMouse->SetDataFormat(&c_dfDIMouse))) return(0);
	if(FAILED(lpDIMouse->Acquire())) return(0);

	// Direct Input 8 - J O Y S T I C K  goes in Setup function
	// first find the GUID of your particular joystick
	lpDI->EnumDevices(DI8DEVCLASS_GAMECTRL, DI_Enum_Joysticks, &joystickGUID, DIEDFL_ATTACHEDONLY);
	if (FAILED(lpDI->CreateDevice(joystickGUID, &lpDIJS, NULL)))return(0);
	if (FAILED(lpDIJS->SetCooperativeLevel(main_hwnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))return(0);
	if (FAILED(lpDIJS->SetDataFormat(&c_dfDIJoystick)))return(0);

	// set the range of the joystick
	DIPROPRANGE joy_axis_range;

	// first x axis
	joy_axis_range.lMin = -100;
	joy_axis_range.lMax = 100;
	joy_axis_range.diph.dwSize      = sizeof(DIPROPRANGE);
	joy_axis_range.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	joy_axis_range.diph.dwObj        = DIJOFS_X;
	joy_axis_range.diph.dwHow        = DIPH_BYOFFSET;

	lpDIJS->SetProperty(DIPROP_RANGE,&joy_axis_range.diph);

	// now y-axis
	joy_axis_range.lMin = -100;
	joy_axis_range.lMax = 100;

	joy_axis_range.diph.dwSize      = sizeof(DIPROPRANGE);
	joy_axis_range.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	joy_axis_range.diph.dwObj        = DIJOFS_Y;
	joy_axis_range.diph.dwHow        = DIPH_BYOFFSET;

	lpDIJS->SetProperty(DIPROP_RANGE,&joy_axis_range.diph);

	// and now the dead band

	DIPROPDWORD dead_band; // here's our property word

	dead_band.diph.dwSize      = sizeof(dead_band);
	dead_band.diph.dwHeaderSize = sizeof(dead_band.diph);
	dead_band.diph.dwObj        = DIJOFS_X;
	dead_band.diph.dwHow        = DIPH_BYOFFSET;

	// 10% will be used on both sides of the range +/-
	dead_band.dwData            = 1000;

	// finally set the property
	lpDIJS->SetProperty(DIPROP_DEADZONE,&dead_band.diph);

	dead_band.diph.dwSize      = sizeof(dead_band);
	dead_band.diph.dwHeaderSize = sizeof(dead_band.diph);
	dead_band.diph.dwObj        = DIJOFS_Y;
	dead_band.diph.dwHow        = DIPH_BYOFFSET;

	// 10% will be used on both sides of the range +/-
	dead_band.dwData            = 1000;

	// finally set the property
	lpDIJS->SetProperty(DIPROP_DEADZONE,&dead_band.diph);


	//acquire the joystick
	if (FAILED(lpDIJS->Acquire()))
	{
	 return(0);
	}

	return true;
}

bool checkBoost(bool hyperspace)
{
	//input stuff
	HRESULT hresult; //result of device
	hresult = lpDIKey->GetDeviceState(256,(LPVOID)keyboard_state);
		
	//incase they unplug keyboard
	if(hresult == DIERR_INPUTLOST) if(FAILED(lpDIKey->Acquire())) return(0);

	//if(keyboard_state[DIK_SPACE]&0x80) return true;

	return false;
}

int checkState(int direction, stXACTAudio sound, XACTINDEX thrust)
{
	//input stuff
	HRESULT hresult; //result of device
	hresult = lpDIKey->GetDeviceState(256,(LPVOID)keyboard_state);
		
	//incase they unplug keyboard
	if(hresult == DIERR_INPUTLOST) if(FAILED(lpDIKey->Acquire())) return(0);

	//booster = keystate();
	direction = 0;
	
	if(keyboard_state[DIK_RIGHT]&0x80) direction = 4;
	if(keyboard_state[DIK_LEFT]&0x80) direction = 6;
	if(keyboard_state[DIK_UP]&0x80)	direction = 2;
	if(keyboard_state[DIK_DOWN]&0x80) direction = 8;
	if(keyboard_state[DIK_UP]&0x80 && keyboard_state[DIK_LEFT]&0x80) direction = 3;
	if(keyboard_state[DIK_UP]&0x80 && keyboard_state[DIK_RIGHT]&0x80) direction = 1;
	if(keyboard_state[DIK_DOWN]&0x80 && keyboard_state[DIK_RIGHT]&0x80)	direction = 7;
	if(keyboard_state[DIK_DOWN]&0x80 && keyboard_state[DIK_LEFT]&0x80) direction = 9;
	
	

	//mouse
	HRESULT hresult2;
	hresult2 = lpDIMouse->GetDeviceState(sizeof(DIMOUSESTATE),(LPVOID)&mouse_state);

	//incase they unplug mouse
	if(hresult2 == DIERR_INPUTLOST)	if(FAILED(lpDIMouse->Acquire())) return(0);

	//x-=(mouse_statelX* .01);

	//joystick
	 lpDIJS->Poll(); // this is needed for joysticks only
	 lpDIJS->GetDeviceState(sizeof(DIJOYSTATE), (LPVOID)&joy_state);

	 if(joy_state.lY < 0)direction = 2;
	 if(joy_state.lY > 0)direction = 8;
	 if(joy_state.lX < 0)direction = 6;
	 if(joy_state.lX > 0)direction = 4;

	 
	 if (joy_state.rgbButtons[0] & 0x80)
	 {
		 //shoot
	 }

	return direction;
}

void cleanControls()
{
	if(lpDIMouse)
		lpDIMouse->Unacquire();
	if(lpDIMouse)
		lpDIMouse->Release();
	if(lpDIKey)
		lpDIKey->Unacquire();
	if(lpDIKey)
		lpDIKey->Release();
	if(lpDI)
		lpDI->Release();
	if (lpDIJS)
		lpDIJS->Unacquire();
	if (lpDIJS)
		lpDIJS->Release();
}


