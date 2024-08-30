#include "ModelUtilities.h"

void ModelUtilities::InitModel(GLMmodel** model, char* model_path)
{
	*model = NULL;
	if (!*model)
	{
		*model = glmReadOBJ(model_path);
		if (!*model)
			exit(0);

		glmUnitize(*model);
		glmFacetNormals(*model);
		glmVertexNormals(*model, 90.0);
	}
}

void ModelUtilities::InitializeTextures(GLuint* texid, char* texture_path)
{
	int w, h;
	GLubyte* data = 0;
	//data = glmReadPPM("soccer_ball_diffuse.ppm", &w, &h);
	//std::cout << "Read soccer_ball_diffuse.ppm, width = " << w << ", height = " << h << std::endl;

	//dib1 = loadImage("soccer_ball_diffuse.jpg"); //FreeImage

	glGenTextures(1, texid);
	glBindTexture(GL_TEXTURE_2D, *texid);
	glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Loading JPG file
	FIBITMAP* bitmap = FreeImage_Load(FreeImage_GetFileType(texture_path, 0),texture_path);  //*** Para Textura: esta es la ruta en donde se encuentra la textura

	FIBITMAP* pImage = FreeImage_ConvertTo32Bits(bitmap);
	int nWidth = FreeImage_GetWidth(pImage);
	int nHeight = FreeImage_GetHeight(pImage);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
		0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

	FreeImage_Unload(pImage);
	//
	glEnable(GL_TEXTURE_2D);
}

void ModelUtilities::DrawModel(GLMmodel* model, float x, float y, float z)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glmDraw(model, GLM_SMOOTH | GLM_MATERIAL);
	glPopMatrix();
}

void ModelUtilities::DrawModel(GLMmodel* model, float x, float y, float z, GLuint texture)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glBindTexture(GL_TEXTURE_2D, texture);
	glmDraw(model, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
	glPopMatrix();
}


void ModelUtilities::DrawModel(GLMmodel* model, float x, float y, float z, GLuint texture, float scale_x, float scale_y, float scale_z)
{
	glPushMatrix();
	glScalef(scale_x, scale_y, scale_z);
	glTranslatef(x, y, z);
	glBindTexture(GL_TEXTURE_2D, texture);
	glmDraw(model, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
	glPopMatrix();
}
