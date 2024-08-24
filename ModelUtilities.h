#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include "glsl.h"
#include <time.h>
#include "glm.h"
#include <FreeImage.h>

class ModelUtilities
{
public:
	ModelUtilities() = delete;
	static void InitModel(GLMmodel** model, char * model_path);
	static void InitializeTextures(GLuint* texid, char* texture_path);

	static void DrawModel(GLMmodel* model, float x, float y, float z);
	static void DrawModel(GLMmodel* model, float x, float y, float z, GLuint texture);
};

