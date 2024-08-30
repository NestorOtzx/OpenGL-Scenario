#include "Mundo.h"

Mundo::Mundo()
{
	ModelUtilities::InitModel(&hobbit, "./Mallas/hobbit.obj");
	ModelUtilities::InitModel(&dynamite, "./Mallas/dinamita.obj");
	//ModelUtilities::InitModel(&mountain, "./Mallas/mountain.obj");
	ModelUtilities::InitModel(&mountain_plane, "./Mallas/mountain_plane.obj");
	ModelUtilities::InitModel(&mountain, "./Mallas/mountain.obj");

	ModelUtilities::InitializeTextures(&ball_texture, "./Textures/bola.jpg");
	ModelUtilities::InitializeTextures(&terrain_texture, "./Textures/rock_hd.jpg");
}

void Mundo::DrawNoTexture()
{
	Hobbits();
	Dinamita();
}

void Mundo::DrawWithTexture()
{

	//MontaniaPlanos();
	Montania();
	
}

void Mundo::Montania()
{
	
	ModelUtilities::DrawModel(mountain, -0.1, 0, 0, terrain_texture, 500, 500, 500);
}

void Mundo::MontaniaPlanos()
{

	for (float z = -2; z <= 2; z += 2)
	{
		for (float x = -10; x <= 0; x += 2)
		{
			ModelUtilities::DrawModel(mountain_plane, x, -1, z, terrain_texture);
		}
	}
	glRotatef(20, 0, 0, 1);
	glPushMatrix();
	for (float z = -2; z <= 2; z += 2)
	{
		for (float x = 0; x <= 10; x += 2)
		{
			ModelUtilities::DrawModel(mountain_plane, x, -1, z, terrain_texture);
		}
	}
	glPopMatrix();

}

void Mundo::Hobbits()
{
	ModelUtilities::DrawModel(hobbit, -1.5f, 0.0f, 0.0f);
	ModelUtilities::DrawModel(hobbit, -1.5f, 0, 1.0f);
	ModelUtilities::DrawModel(hobbit, -1.5f, 0, -1.0f);
}

void Mundo::Dinamita()
{
	ModelUtilities::DrawModel(dynamite, 1.5, 0.0f, 0.0f);
}


