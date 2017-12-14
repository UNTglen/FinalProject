#ifndef __ship_H__
#define __ship_H__

#include "base.h"
#include <time.h>

struct SHIP
{
	LPD3DXMESH Mesh;
	D3DMATERIAL9 Mtrl;
	D3DXMATRIX Location;
	IDirect3DTexture9* Texture;

	float x;
	float y;
	float z;

	int direction;
	int boundx;
	int boundy;
};

bool createShip(IDirect3DDevice9* device, IDirect3DTexture9* texture, const int Height, const int Width);
void moveShip(IDirect3DDevice9* device, const int Height, const int Width, int dir);
void renderShip(IDirect3DDevice9* device);
bool render1(IDirect3DDevice9* device, const int Height, const int Width, int direction);

#endif