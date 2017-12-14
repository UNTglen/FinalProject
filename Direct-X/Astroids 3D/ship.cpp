#include "ship.h"

SHIP ship;

#define DEGTORAD(degree) ((D3DX_PI / 180.0f) * (degree)) // converts from degrees to radians

int degY = 0;

bool createShip(IDirect3DDevice9* device, IDirect3DTexture9* texture, const int Height, const int Width)
{
	ship.z = 10;
	ship.x = 0;
	ship.y = 0;
	ship.Texture = texture;
	return true;
}


void moveShip(IDirect3DDevice9* device, const int Height, const int Width, int dir)
{

		ship.direction = dir;
		//D3DXMATRIX b;
	
		//ship.z -= 0.5f;

		//if turning left '4' 
		if(ship.direction == 4)
		{
			//degY += 10;
			//D3DXMatrixRotationY(&b,DEGTORAD(degY));
			//D3DXMatrixMultiply(&ship.Location,&b,&ship.Location);
			ship.x += 0.05f;
			if(ship.x >= 50) ship.x = -50;
		}

		//if turning right '6' 
		if(ship.direction == 6)
		{
			ship.x -= 0.05f;
			if(ship.x <= -50) ship.x = 50;
		}

		//if going Up '8' 
		if(ship.direction == 8)
		{
			ship.y -= 0.05f;
			if(ship.y <= -50) ship.y = 50;
		}

		//if going up and right '8' and '6' 
		if(ship.direction == 9)
		{
			ship.y -= 0.05f;
			ship.x -= 0.05f;
			if(ship.x <= -50) ship.x = 50;
			if(ship.y <= -50) ship.y = 50;
		}

		//if going up and left '8' and '4' 
		if(ship.direction == 7)
		{
			ship.y -= 0.05f;
			ship.x += 0.05f;
			if(ship.x >= 50) ship.x = -50;
			if(ship.y <= -50) ship.y = 50;
		}

		//if going down and right '2' and '3' 
		if(ship.direction == 3)
		{
			ship.y += 0.05f;
			ship.x -= 0.05f;
			if(ship.x <= -50) ship.x = 50;
			if(ship.y >= 50) ship.y = -50;
		}

		//if going down '2' 
		if(ship.direction == 2)
		{
			ship.y += 0.05f;
			if(ship.y >= 50) ship.y = -50;
		}

		//if going down and left '1' and '2' 
		if(ship.direction == 1)
		{
			ship.y += 0.05f;
			ship.x += 0.05f;
			if(ship.x >= 50) ship.x = -50;
			if(ship.y >= 50) ship.y = -50;
		}

}

void renderShip(IDirect3DDevice9* device)
{
	D3DXMATRIX b, c;

	D3DXCreateCylinder(device,1,0,6,30,12,&ship.Mesh,0);
	D3DXMatrixTranslation(&ship.Location,ship.x,ship.y,ship.z);

	D3DXMatrixRotationY(&b,DEGTORAD(degY));
	D3DXMatrixMultiply(&ship.Location,&b,&ship.Location);

	D3DXMatrixRotationX(&c,DEGTORAD(270));
	D3DXMatrixMultiply(&ship.Location,&c,&ship.Location);

	

	device->SetTransform(D3DTS_WORLD, &ship.Location);
	device->SetTexture(0, ship.Texture);
	ship.Mesh->DrawSubset(0);

	d3d::Release<ID3DXMesh*>(ship.Mesh);
}

bool render1(IDirect3DDevice9* device, const int Height, const int Width, int direction)
{

	if(!device)return false;

		moveShip(device, Height, Width, direction);

		device->BeginScene();
		
		renderShip(device);
	
		device->EndScene();

	return true;
}