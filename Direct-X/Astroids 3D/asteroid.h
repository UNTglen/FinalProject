#ifndef __asteroid_H__
#define __asteroid_H__

#include "base.h"
#include <time.h>

struct ASTEROID
{
	LPD3DXMESH Mesh;
	D3DMATERIAL9 Mtrl;
	D3DXMATRIX Location;
	IDirect3DTexture9* Texture;

    float x;			// Asteriod X Posistion
    float y;			// Asteriod Y Posistion
	float z;			// Far Plane 

	float raduis;		//Size of asteroid
	
	int State;			// Have Asteroids been hit
	int direction;		// Direction of asteroid movment
	int number;			// Number of asteroids
};


bool createAsteroid(IDirect3DDevice9* device, IDirect3DTexture9* texture, int state);
void moveAsteroids(IDirect3DDevice9* device, const int Height, const int Width, int state);
void renderAsteroids(IDirect3DDevice9* device, int state);
bool render(IDirect3DDevice9* device, const int Height, const int Width, int state);

#endif