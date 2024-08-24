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
	GLMmodel* dynamite, *hobbit, *mountain;

	GLuint ball_texture, terrain_texture;

public:
	Mundo();
	void DrawNoTexture();
	void DrawWithTexture();
};

