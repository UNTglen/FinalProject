#include "base.h"
#include "dinput.h"








///THIS GOES IN CLEANUP


//THIS GOES IN DISPLAY
//// J O Y S T I C K
//
// lpDIJS->Poll(); // this is needed for joysticks only
// lpDIJS->GetDeviceState(sizeof(DIJOYSTATE), (LPVOID)&joy_state);
//
//
//
// x -= (joy_state.lY * 0.0001f);
// y -= (joy_state.lX * 0.0001f);
//
//
// if (joy_state.rgbButtons[0] & 0x80)
// {
// y = 0.0f;
// x = 3.14f / 4.0f;
// }
//
// if (joy_state.rgbButtons[1] & 0x80)
// {
// y = 0.0f;
// x = 3.14f / 4.0f;
// }
//
// if (joy_state.rgbButtons[3] & 0x80)
// {
// SendMessage(main_hwnd, WM_DESTROY, 0, 0);
// }
//
// // J O Y S T I C K