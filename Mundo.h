#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include "glsl.h"
#include <time.h>
#include "glm.h"
#include <FreeImage.h>
#include "ModelUtilities.h"


class Mundo
{
private:
	GLMmodel* dynamite, *hobbit, *mountain, *mountain_plane;

	GLuint ball_texture, terrain_texture;

	void Montania();
	void MontaniaPlanos();
	void Hobbits();
	void Dinamita();

public:
	Mundo();
	void DrawNoTexture();
	void DrawWithTexture();
	
};

