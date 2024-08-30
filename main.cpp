//=============================================================================
// Sample Application: Lighting (Per Fragment Phong)
//=============================================================================

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include <iostream>
#include "glsl.h"
#include <time.h>
#include "glm.h"
#include <FreeImage.h> //*** Para Textura: Incluir librería
#include "Mundo.h"
//-----------------------------------------------------------------------------


class myWindow : public cwc::glutWindow
{
protected:
   cwc::glShaderManager SM;
   cwc::glShader *shader;
   cwc::glShader* shader1; //Para Textura: variable para abrir los shader de textura
   GLuint ProgramObject;
   clock_t time0,time1;
   float timer010;  // timer counting 0->1->0
   bool bUp;        // flag if counting up or down.
   Mundo* mundo;

   //GLMmodel* objmodel_ptr1; //*** Para Textura: variable para objeto texturizado
   //GLuint texid; //*** Para Textura: variable que almacena el identificador de textura

public:
	myWindow(){}

	virtual void OnRender(void)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
		//timer010 = 0.09; //for screenshot!
		
		glPushMatrix();
		//posicion y rotacion de la camara
		//glTranslatef(0, 0, -10);
		glRotatef(135, 0, 1, 0);
		//glRotatef(180, 0, 1, 0);

		//*** Para Textura: llamado al shader para objetos texturizados 
		if (shader1) shader1->begin();
		glPushMatrix();
		mundo->DrawWithTexture();
		glPopMatrix();
		if (shader1) shader1->end();

		if (shader) shader->begin();		  
			glPushMatrix();
			mundo->DrawNoTexture();
			glPopMatrix();
		if (shader) shader->end();

		
		glutSwapBuffers();
		glPopMatrix();

		UpdateTimer();

		Repaint();
	}

	virtual void OnIdle() {}

	// When OnInit is called, a render context (in this case GLUT-Window) 
	// is already available!


	virtual void OnInit()
	{
		glClearColor(0.5f, 0.5f, 1.0f, 0.0f);
		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);

		shader = SM.loadfromFile("vertexshader.txt","fragmentshader.txt"); // load (and compile, link) from file
		if (shader==0) 
			std::cout << "Error Loading, compiling or linking shader\n";
		else
		{
			ProgramObject = shader->GetProgramObject();
		}

	 //*** Para Textura: abre los shaders para texturas
		shader1 = SM.loadfromFile("vertexshaderT.txt", "fragmentshaderT.txt"); // load (and compile, link) from file
		if (shader1 == 0)
			std::cout << "Error Loading, compiling or linking shader\n";
		else
		{
			ProgramObject = shader1->GetProgramObject();
		}

		time0 = clock();
		timer010 = 0.0f;
		bUp = true;

		mundo = new Mundo();
 
		
		DemoLight();

	}

	virtual void OnResize(int w, int h)
    {
		if(h == 0) h = 1;
		float ratio = 1.0f * (float)w / (float)h;

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
	
		glViewport(0, 0, w, h);

		gluPerspective(45,ratio,1,100);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0f,0.0f,4.0f, 
					0.0,0.0,-1.0,
					0.0f,1.0f,0.0f);
    }

	virtual void OnClose(void){}
	virtual void OnMouseDown(int button, int x, int y) {}    
	virtual void OnMouseUp(int button, int x, int y) {}
	virtual void OnMouseWheel(int nWheelNumber, int nDirection, int x, int y){}

	virtual void OnKeyDown(int nKey, char cAscii)
	{       
		if (cAscii == 27) // 0x1b = ESC
		{
			this->Close(); // Close Window!
		} 
	};

	virtual void OnKeyUp(int nKey, char cAscii)
	{
      if (cAscii == 's')      // s: Shader
         shader->enable();
      else if (cAscii == 'f') // f: Fixed Function
         shader->disable();
	}

   void UpdateTimer()
   {
      time1 = clock();
      float delta = static_cast<float>(static_cast<double>(time1-time0)/static_cast<double>(CLOCKS_PER_SEC));
      delta = delta / 4;
      if (delta > 0.00005f)
      {
         time0 = clock();
         if (bUp)
         {
            timer010 += delta;
            if (timer010>=1.0f) { timer010 = 1.0f; bUp = false;}
         }
         else
         {
            timer010 -= delta;
            if (timer010<=0.0f) { timer010 = 0.0f; bUp = true;}
         }
      }
   }

   void DemoLight(void)
   {
	   glEnable(GL_LIGHTING);
	   glEnable(GL_LIGHT0);
	   glEnable(GL_NORMALIZE);

   }
};

//-----------------------------------------------------------------------------

class myApplication : public cwc::glApplication
{
public:
	virtual void OnInit() {std::cout << "Hello World!\n"; }
};

//-----------------------------------------------------------------------------

int main(void)
{
	myApplication*  pApp = new myApplication;
	myWindow* myWin = new myWindow();

	pApp->run();
	delete pApp;
	return 0;
}

//-----------------------------------------------------------------------------

