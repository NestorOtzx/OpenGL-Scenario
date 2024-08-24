#include "Mundo.h"

Mundo::Mundo()
{
	ModelUtilities::InitModel(&hobbit, "./Mallas/hobbit.obj");
	ModelUtilities::InitModel(&dynamite, "./Mallas/dinamita.obj");
	ModelUtilities::InitModel(&mountain, "./Mallas/mountain.obj");

	ModelUtilities::InitializeTextures(&ball_texture, "./Mallas/bola.jpg");
	ModelUtilities::InitializeTextures(&terrain_texture, "./Mallas/terrain.jpg");
}

void Mundo::DrawNoTexture()
{
	ModelUtilities::DrawModel(hobbit, -1.5f, 0.0f, 0.0f);
	ModelUtilities::DrawModel(hobbit, -1.5f, 0, 1.0f);
	ModelUtilities::DrawModel(hobbit, -1.5f, 0, -1.0f);
	ModelUtilities::DrawModel(dynamite, 1.5, 0.0f, 0.0f);
}

void Mundo::DrawWithTexture()
{
	for (float z = -2; z <= 2; z+=2)
	{
		for (float x = -10; x <= 0; x += 2)
		{
			ModelUtilities::DrawModel(mountain, x, -1, z, terrain_texture);
		}
	}
	glRotatef(20, 0, 0, 1);
	glPushMatrix();
	for (float z = -2; z <= 2; z += 2)
	{
		for (float x = 0; x <= 10; x += 2)
		{
			ModelUtilities::DrawModel(mountain, x, -1, z, terrain_texture);
		}
	}
	glPopMatrix();
	
	
}


