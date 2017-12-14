#include "asteroid.h"
#include <time.h>

//Asteroids

const int TOTAL_ASTEROIDS = 3;
ASTEROID asteroids[TOTAL_ASTEROIDS];
D3DXMATRIX asteroid_matrix[TOTAL_ASTEROIDS];



bool createAsteroid(IDirect3DDevice9* device, IDirect3DTexture9* texture, int state )
{

	time_t now = time(0);
	srand((unsigned int )&now);

	for(int i = 0; i < TOTAL_ASTEROIDS; i++)
	{
		asteroids[i].State = state;
		asteroids[i].Location = asteroid_matrix[i];
		//asteroids[i].Mtrl = d3d::WHITE_MTRL;
		asteroids[i].Texture = texture;

		asteroids[i].z = 10;
		
		asteroids[i].x = 20.0f - (rand()%60);
		if(asteroids[i-1].x <= asteroids[i].x + 20) asteroids[i].x = 20.0f - (rand()%60);

		asteroids[i].y = 20.0f - (rand()%60);
		if(asteroids[i-1].y <= asteroids[i].y + 20) asteroids[i].y = 20.0f - (rand()%60);
	}
	return true;
}


void moveAsteroids(IDirect3DDevice9* device, const int Height, const int Width, int state)
{
	for(int i = 0; i < TOTAL_ASTEROIDS; i++)
	{
		asteroids[i].x += 0.02f;
		asteroids[i].y -= 0.05f;

		if(asteroids[i].x >= 43) asteroids[i].x = -42;
		if(asteroids[i].x <= -43) asteroids[i].x = 43;
		if(asteroids[i].y >= 38) asteroids[i].y = -37;
		if(asteroids[i].y <= -38) asteroids[i].y = 37;
	}
}


void calculateAsteroid(IDirect3DDevice9* device, int state)
{
	
	for(int i = 0; i < TOTAL_ASTEROIDS; i++)
	{	
		float radius = 7; 
		if(state == 1) radius = radius/2;
		if(state == 2) radius = radius/4;

		D3DXCreateSphere(device, radius, 8, 25, &asteroids[i].Mesh, 0);
		D3DXMatrixTranslation(&asteroids[i].Location,asteroids[i].x,asteroids[i].y,asteroids[i].z);
		device->SetTransform(D3DTS_WORLD, &asteroids[i].Location);
		//device->SetMaterial(&asteroids[i].Mtrl);
		device->SetTexture(0, asteroids[i].Texture);
		asteroids[i].Mesh->DrawSubset(0);

		//d3d::Release<IDirect3DTexture9*>(asteroids[i].Texture);
		d3d::Release<ID3DXMesh*>(asteroids[i].Mesh);
	}
}


void astroidNotHit(IDirect3DDevice9* device)
{
	for(int i = 0; i < TOTAL_ASTEROIDS; i++)
	{
		D3DXCreateSphere(device, 7.0f, 8, 25, &asteroids[i].Mesh, 0);
		D3DXMatrixTranslation(&asteroids[i].Location,asteroids[i].x,asteroids[i].y,asteroids[i].z);
		device->SetTransform(D3DTS_WORLD, &asteroids[i].Location);
		//device->SetMaterial(&asteroids[i].Mtrl);
		device->SetTexture(0, asteroids[i].Texture);
		asteroids[i].Mesh->DrawSubset(0);

		d3d::Release<IDirect3DTexture9*>(asteroids[i].Texture);
		d3d::Release<ID3DXMesh*>(asteroids[i].Mesh);
	}
}


void setupLight(IDirect3DDevice9* device)
{
	D3DLIGHT9 light;    // create the light struct
    D3DMATERIAL9 material;    // create the material struct

    ZeroMemory(&light, sizeof(light));    // clear out the light struct for use
    light.Type = D3DLIGHT_DIRECTIONAL;    // make the light type 'directional light'
	light.Diffuse =d3d::WHITE;   // set the light's color
    light.Direction = D3DXVECTOR3(-1.0f, -0.3f, -1.0f);
	
    device->SetLight(0, &light);    // send the light struct properties to light #0
    device->LightEnable(0, TRUE);    // turn on light #0

	light.Direction = D3DXVECTOR3(1.0f,0.3f,2.0f);
	device->SetLight(1,&light);
	device->LightEnable(1,true);

    ZeroMemory(&material, sizeof(D3DMATERIAL9));    // clear out the struct for use
	material.Diffuse = d3d::WHITE;
	material.Ambient = d3d::WHITE;

    device->SetMaterial(&material);    // set the globably-used material to &material
}



void renderAsteroids(IDirect3DDevice9* device, int state)
{
	setupLight(device);
	calculateAsteroid(device,state);
}



bool render(IDirect3DDevice9* device, const int Height, const int Width, int state)
{
	if(!device)return false;

		moveAsteroids(device, Height, Width,state);

		device->BeginScene();
		
		renderAsteroids(device,state);
	
		device->EndScene();

	return true;
}