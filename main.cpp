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
   GLMmodel* ciclope;
   GLMmodel* poso;
   GLMmodel* carri;
   GLMmodel* torre;
   GLMmodel* terreno;
   GLMmodel* objmodel_ptr1; //*** Para Textura: variable para objeto texturizado
   GLMmodel* spidey; //
   GLMmodel* mushrooms; //
   GLMmodel* alien;
   GLMmodel* dog;
   GLMmodel* choza;
   GLMmodel* mountain;//
   GLMmodel* ocean;//
   GLuint texid; //*** Para Textura: variable que almacena el identificador de textura
   GLuint texid2;
   GLuint texid3;
   GLuint texidAlien;
   GLuint texidgoat;
   GLuint texidDog;
   GLuint texidTerreno;
   GLuint texidTorre;
   GLuint texidCarri;
   GLuint texidPoso;
   GLuint texidChoza;

public:
	myWindow(){}

	//*** Para Textura: aqui adiciono un método que abre la textura en JPG
	void initialize_textures(void)
	{
		int w, h;
		GLubyte* data = 0;

		glGenTextures(1, &texid);
		glBindTexture(GL_TEXTURE_2D, texid);
		glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


		FIBITMAP* bitmap = FreeImage_Load(
			FreeImage_GetFileType("./Mallas/Mushrooms1.jpg", 0),
			"./Mallas/Mushrooms1.jpg");  //*** Para Textura: esta es la ruta en donde se encuentra la textura


		FIBITMAP* pImage = FreeImage_ConvertTo32Bits(bitmap);
		int nWidth = FreeImage_GetWidth(pImage);
		int nHeight = FreeImage_GetHeight(pImage);


		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
			0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

		FreeImage_Unload(pImage);


		glEnable(GL_TEXTURE_2D);
	}

	void loadCarri(void)
	{
		int w, h;
		GLubyte* data = 0;

		glGenTextures(1, &texidCarri);
		glBindTexture(GL_TEXTURE_2D, texidCarri);
		glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


		FIBITMAP* bitmap = FreeImage_Load(
			FreeImage_GetFileType("./Mallas/Medieval_House_Diff.png", 0),
			"./Mallas/Medieval_House_Diff.png");  //*** Para Textura: esta es la ruta en donde se encuentra la textura


		FIBITMAP* pImage = FreeImage_ConvertTo32Bits(bitmap);
		int nWidth = FreeImage_GetWidth(pImage);
		int nHeight = FreeImage_GetHeight(pImage);


		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
			0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

		FreeImage_Unload(pImage);


		glEnable(GL_TEXTURE_2D);
	}

	void loadPoso(void)
	{
		int w, h;
		GLubyte* data = 0;

		glGenTextures(1, &texidPoso);
		glBindTexture(GL_TEXTURE_2D, texidPoso);
		glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


		FIBITMAP* bitmap = FreeImage_Load(
			FreeImage_GetFileType("./Mallas/poso.png", 0),
			"./Mallas/poso.png");  //*** Para Textura: esta es la ruta en donde se encuentra la textura


		FIBITMAP* pImage = FreeImage_ConvertTo32Bits(bitmap);
		int nWidth = FreeImage_GetWidth(pImage);
		int nHeight = FreeImage_GetHeight(pImage);


		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
			0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

		FreeImage_Unload(pImage);


		glEnable(GL_TEXTURE_2D);
	}


	void loadChoza(void)
	{
		int w, h;
		GLubyte* data = 0;

		glGenTextures(1, &texidChoza);
		glBindTexture(GL_TEXTURE_2D, texidChoza);
		glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


		FIBITMAP* bitmap = FreeImage_Load(
			FreeImage_GetFileType("./Mallas/wind_wind turbine_BaseColor.png", 0),
			"./Mallas/wind_wind turbine_BaseColor.png");  //*** Para Textura: esta es la ruta en donde se encuentra la textura


		FIBITMAP* pImage = FreeImage_ConvertTo32Bits(bitmap);
		int nWidth = FreeImage_GetWidth(pImage);
		int nHeight = FreeImage_GetHeight(pImage);


		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
			0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

		FreeImage_Unload(pImage);


		glEnable(GL_TEXTURE_2D);
	}






	void loadGoat(void)
	{
		int w, h;
		GLubyte* data = 0;

		glGenTextures(1, &texidgoat);
		glBindTexture(GL_TEXTURE_2D, texidgoat);
		glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


		// Loading JPG file
		FIBITMAP* goatTexture = FreeImage_Load(
			FreeImage_GetFileType("./Mallas/Cyclops_Texture.png", 0),
			"./Mallas/Cyclops_Texture.png"); // Cambia la ruta a la ubicación de tu textura "goat.jpg"

		FIBITMAP* pImage = FreeImage_ConvertTo32Bits(goatTexture);
		int nWidth = FreeImage_GetWidth(pImage);
		int nHeight = FreeImage_GetHeight(pImage);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
			0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

		FreeImage_Unload(pImage);

		glEnable(GL_TEXTURE_2D);
	}

	void loadAlien(void)
	{
		int w, h;
		GLubyte* data = 0;

		glGenTextures(1, &texidAlien);
		glBindTexture(GL_TEXTURE_2D, texidAlien);
		glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


		// Loading JPG file
		FIBITMAP* alientext = FreeImage_Load(
			FreeImage_GetFileType("./Mallas/DeadTreeBark_Diffuse.jpg", 0),
			"./Mallas/DeadTreeBark_Diffuse.jpg"); // Cambia la ruta a la ubicación de tu textura "goat.jpg"

		FIBITMAP* pImage = FreeImage_ConvertTo32Bits(alientext);
		int nWidth = FreeImage_GetWidth(pImage);
		int nHeight = FreeImage_GetHeight(pImage);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
			0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

		FreeImage_Unload(pImage);

		glEnable(GL_TEXTURE_2D);
	}

	void loadTorre(void)
	{

		int w, h;
		GLubyte* data = 0;

		glGenTextures(1, &texidTorre);
		glBindTexture(GL_TEXTURE_2D, texidTorre);
		glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


		// Loading JPG file
		FIBITMAP* Torre = FreeImage_Load(
			FreeImage_GetFileType("./Mallas/brick07.jpg", 0),
			"./Mallas/brick07.jpg"); // Cambia la ruta a la ubicación de tu textura "goat.jpg"

		FIBITMAP* pImage = FreeImage_ConvertTo32Bits(Torre);
		int nWidth = FreeImage_GetWidth(pImage);
		int nHeight = FreeImage_GetHeight(pImage);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
			0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

		FreeImage_Unload(pImage);

		glEnable(GL_TEXTURE_2D);
	}

	void loadDog(void)
	{
		int w, h;
		GLubyte* data = 0;

		glGenTextures(1, &texidDog);
		glBindTexture(GL_TEXTURE_2D, texidDog);
		glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


		// Loading JPG file
		FIBITMAP* dogTexture = FreeImage_Load(
			FreeImage_GetFileType("./Mallas/dogtext.jpg", 0),
			"./Mallas/dogtext.jpg"); // Cambia la ruta a la ubicación de tu textura "goat.jpg"

		FIBITMAP* pImage = FreeImage_ConvertTo32Bits(dogTexture);
		int nWidth = FreeImage_GetWidth(pImage);
		int nHeight = FreeImage_GetHeight(pImage);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
			0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

		FreeImage_Unload(pImage);

		glEnable(GL_TEXTURE_2D);
	}

	void loadMountainTexture(void)
	{
		int w, h;
		GLubyte* data = 0;

		glGenTextures(1, &texid2); // Usa un nuevo identificador de textura
		glBindTexture(GL_TEXTURE_2D, texid2);
		glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		// Carga la nueva textura
		FIBITMAP* mountainTexture = FreeImage_Load(
			FreeImage_GetFileType("./Mallas/montana.jpg", 0),
			"./Mallas/montana.jpg");

		FIBITMAP* pImage = FreeImage_ConvertTo32Bits(mountainTexture);
		int nWidth = FreeImage_GetWidth(pImage);
		int nHeight = FreeImage_GetHeight(pImage);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
			0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

		FreeImage_Unload(pImage);

		glEnable(GL_TEXTURE_2D);
	}

	void loadOceanTexture(void)
	{
		int w, h;
		GLubyte* data = 0;

		glGenTextures(1, &texid3); // Usa un nuevo identificador de textura
		glBindTexture(GL_TEXTURE_2D, texid3);
		glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		// Carga la nueva textura
		FIBITMAP* mountainTexture = FreeImage_Load(
			FreeImage_GetFileType("./Mallas/pasto2.jpg", 0),
			"./Mallas/pasto2.jpg");

		FIBITMAP* pImage = FreeImage_ConvertTo32Bits(mountainTexture);
		int nWidth = FreeImage_GetWidth(pImage);
		int nHeight = FreeImage_GetHeight(pImage);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
			0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

		FreeImage_Unload(pImage);
	}

	void loadTerreno(void)
	{
		int w, h;
		GLubyte* data = 0;

		glGenTextures(1, &texidTerreno); // Usa un nuevo identificador de textura
		glBindTexture(GL_TEXTURE_2D, texidTerreno);
		glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		// Carga la nueva textura
		FIBITMAP* piedras = FreeImage_Load(
			FreeImage_GetFileType("./Mallas/ArchCave_Base_Diffuse.png", 0),
			"./Mallas/ArchCave_Base_Diffuse.png");

		FIBITMAP* pImage = FreeImage_ConvertTo32Bits(piedras);
		int nWidth = FreeImage_GetWidth(pImage);
		int nHeight = FreeImage_GetHeight(pImage);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
			0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

		FreeImage_Unload(pImage);

	}

	




	virtual void OnRender(void)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
      //timer010 = 0.09; //for screenshot!

      glPushMatrix();
	  glRotatef(timer010 * 100, 0.0f, 1.0f, 0.0f);

      if (shader) shader->begin();

		  //glPushMatrix();
		  //glTranslatef(3, -1.5, 0.0);
		  //glmDraw(ant, GLM_SMOOTH | GLM_MATERIAL);
		  //glPopMatrix();

		 // glPushMatrix();
		  //glTranslatef(0.0, -0.5, 3);
		 // glmDraw(spidey, GLM_SMOOTH | GLM_MATERIAL);
		 // glPopMatrix();


		  


		  glPushMatrix();

		  glColor3f(0.0f, 1.0f, 0.0f);
		  GLfloat material_Ka[] = { 0.0f, 0.5f, 0.0f, 1.0f };
		  GLfloat material_Kd[] = { 0.0f, 1.0f, 0.0f, 1.0f };
		  GLfloat material_Ks[] = { 0.0f, 1.0f, 0.0f, 1.0f };
		  GLfloat material_Ke[] = { 0.1f, 0.0f, 0.0f, 0.0f };
		  GLfloat material_Se = 128.0f;

		  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
		  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
		  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
		  glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_Ke);
		  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);


		  //glTranslatef(0.0f, -1.5f, 0.0f);
		  //glScalef(3, 0.001, 3);
		 // glutSolidCube(10);
		 // glPopMatrix();



	      //glutSolidTeapot(1.0);
      if (shader) shader->end();

	  //*** Para Textura: llamado al shader para objetos texturizados
	  if (shader1) shader1->begin();


		  glPushMatrix();
		  glTranslatef(-0.5, -0.5, -12.0);
		  glBindTexture(GL_TEXTURE_2D, texid);
		  glmDraw(mushrooms, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();

		  glPushMatrix();
		  glTranslatef(-2.5, -1, -12.0);
		  glBindTexture(GL_TEXTURE_2D, texidgoat);
		  glmDraw(ciclope, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(-3.5, -0.80, -12.0);
		  glBindTexture(GL_TEXTURE_2D, texidAlien);
		  glmDraw(alien, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(-5.5, -1, -12.0);
		  glBindTexture(GL_TEXTURE_2D, texidTorre);
		  glmDraw(torre, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(-10.5, -0.8, -12.0);
		  glBindTexture(GL_TEXTURE_2D, texidCarri);
		  glmDraw(carri, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(-7, -1, -12.0);
		  glBindTexture(GL_TEXTURE_2D, texidPoso);
		  glmDraw(poso, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(-8.5, -0.40,-12.0);
		  glBindTexture(GL_TEXTURE_2D, texidChoza);
		  glmDraw(choza, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(-1.5, -1, -12.0);
		  glBindTexture(GL_TEXTURE_2D, texidDog);
		  glmDraw(dog, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();


	
		  glPushMatrix();
		  glTranslatef(-2.5, -0.80, -3.0);
		  glBindTexture(GL_TEXTURE_2D, texidgoat);
		  glmDraw(ciclope, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(-3.5, -1, -3.0);
		  glBindTexture(GL_TEXTURE_2D, texidAlien);
		  glmDraw(alien, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(-5.5, -1, -3.0);
		  glBindTexture(GL_TEXTURE_2D, texidTorre);
		  glmDraw(torre, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(-10.5, -0.8, -3.0);
		  glBindTexture(GL_TEXTURE_2D, texidCarri);
		  glmDraw(carri, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(-7, -1.5, -3.0);
		  glBindTexture(GL_TEXTURE_2D, texidPoso);
		  glmDraw(poso, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(-8.5, -0.40, -3.0);
		  glBindTexture(GL_TEXTURE_2D, texidChoza);
		  glmDraw(choza, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(-1.5, -1, -3.0);
		  glBindTexture(GL_TEXTURE_2D, texidDog);
		  glmDraw(dog, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();



		  glPushMatrix();
		  glTranslatef(-0.5, -0.5, 2.0);
		  glBindTexture(GL_TEXTURE_2D, texid);
		  glmDraw(mushrooms, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glTranslatef(2.5, -0.80, 2.0);
		  glBindTexture(GL_TEXTURE_2D, texidgoat);
		  glmDraw(ciclope, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(3.5, -0.70, 2.0);
		  glBindTexture(GL_TEXTURE_2D, texidAlien);
		  glmDraw(alien, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(5.5, -1, 2.0);
		  glBindTexture(GL_TEXTURE_2D, texidTorre);
		  glmDraw(torre, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(10.5, -0.8, 2.0);
		  glBindTexture(GL_TEXTURE_2D, texidCarri);
		  glmDraw(carri, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(7, -1.5, 2.0);
		  glBindTexture(GL_TEXTURE_2D, texidPoso);
		  glmDraw(poso, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(8.5, -0.40, 2.0);
		  glBindTexture(GL_TEXTURE_2D, texidChoza);
		  glmDraw(choza, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(1.5, -1, 2.0);
		  glBindTexture(GL_TEXTURE_2D, texidDog);
		  glmDraw(dog, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();



		  glPushMatrix();
		  glTranslatef(-0.5, -0.5, -5.0);
		  glBindTexture(GL_TEXTURE_2D, texid);
		  glmDraw(mushrooms, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glTranslatef(2.5, -1, -5);
		  glBindTexture(GL_TEXTURE_2D, texidgoat);
		  glmDraw(ciclope, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(3.5, -1.80, -5);
		  glBindTexture(GL_TEXTURE_2D, texidAlien);
		  glmDraw(alien, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(5.5, -1, -5);
		  glBindTexture(GL_TEXTURE_2D, texidTorre);
		  glmDraw(torre, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(10.5, -0.8, -5);
		  glBindTexture(GL_TEXTURE_2D, texidCarri);
		  glmDraw(carri, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(7, -0.70, -5);
		  glBindTexture(GL_TEXTURE_2D, texidPoso);
		  glmDraw(poso, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(8.5, -0.40, -5);
		  glBindTexture(GL_TEXTURE_2D, texidChoza);
		  glmDraw(choza, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();
		  glPushMatrix();
		  glTranslatef(1.5, -1, -5);
		  glBindTexture(GL_TEXTURE_2D, texidDog);
		  glmDraw(dog, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		  glPushMatrix();












		  glPushMatrix();
		  glTranslatef(-10.0, 4.4, 7);
		  glScalef(27, 29, 8);
		  glBindTexture(GL_TEXTURE_2D, texid2);
		  glmDraw(mountain, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();

		  glPushMatrix();
		  glTranslatef(-20.0, 4.4, 7);
		  glScalef(27, 29, 8);
		  glBindTexture(GL_TEXTURE_2D, texid2);
		  glmDraw(mountain, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();

		  glPushMatrix();
		  glTranslatef(10.0, 4.4, -23);
		  glScalef(27, 29, 8);
		  glBindTexture(GL_TEXTURE_2D, texid2);
		  glmDraw(mountain, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();


		  glPushMatrix();
		  glTranslatef(-5.0, -2.0, 0.0);
		  glScalef(8, 29, 20);
		  glBindTexture(GL_TEXTURE_2D, texid3);
		  glmDraw(ocean, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();

		  glPushMatrix();
		  glTranslatef(5.0, -2.0, 0.0);
		  glScalef(8, 29, 20);
		  glBindTexture(GL_TEXTURE_2D, texid3);
		  glmDraw(ocean, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();


		  glPushMatrix();
		  glTranslatef(5.0, -2.0, -10);
		  glScalef(8, 10, 10);
		  glBindTexture(GL_TEXTURE_2D, texidTerreno);
		  glmDraw(terreno, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
		 




	  if (shader1) shader1->end();
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







	  //Abrir mallas
	  ciclope = NULL;
	  if (!ciclope)
	  {
		  ciclope = glmReadOBJ("./Mallas/Cyclops.obj");
		  if (!ciclope)
			  exit(0);

		  glmUnitize(ciclope);
		  glmFacetNormals(ciclope);
		  glmVertexNormals(ciclope, 90.0);
	  }

	  carri = NULL;
	  if (!carri)
	  {
		  carri = glmReadOBJ("./Mallas/Medieval_House.obj");
		  if (!carri)
			  exit(0);

		  glmUnitize(carri);
		  glmFacetNormals(carri);
		  glmVertexNormals(carri, 90.0);
	  }


	  poso = NULL;
	  if (!poso)
	  {
		  poso = glmReadOBJ("./Mallas/Well.obj");
		  if (!poso)
			  exit(0);

		  glmUnitize(poso);
		  glmFacetNormals(poso);
		  glmVertexNormals(poso, 90.0);
	  }

	  choza = NULL;
	  if (!choza)
	  {
		  choza = glmReadOBJ("./Mallas/wooden_windmill.obj");
		  if (!choza)
			  exit(0);

		  glmUnitize(choza);
		  glmFacetNormals(choza);
		  glmVertexNormals(choza, 90.0);
	  }


	  //*** Para Textura: abrir malla de objeto a texturizarr

	  alien = NULL;

	  if (!alien)
	  {
		  alien = glmReadOBJ("./Mallas/DeadTree2_01.obj");
		  if (!alien)
			  exit(0);

		  glmUnitize(alien);
		  glmFacetNormals(alien);
		  glmVertexNormals(alien, 90.0);
	  }
	 

	  torre = NULL;

	  if (!torre)
	  {
		  torre = glmReadOBJ("./Mallas/objChimney.obj");
		  if (!torre)
			  exit(0);

		  glmUnitize(torre);
		  glmFacetNormals(torre);
		  glmVertexNormals(torre, 90.0);
	  }



	  mushrooms = NULL;

	  if (!mushrooms)
	  {
		  mushrooms = glmReadOBJ("./Mallas/Mushrooms1.obj");
		  if (!mushrooms)
			  exit(0);

		  glmUnitize(mushrooms);
		  glmFacetNormals(mushrooms);
		  glmVertexNormals(mushrooms, 90.0);
	  }


	  dog = NULL;

	  if (!dog)
	  {
		  dog = glmReadOBJ("./Mallas/dog.obj");
		  if (!dog)
			  exit(0);

		  glmUnitize(dog);
		  glmFacetNormals(dog);
		  glmVertexNormals(dog, 90.0);
	  }


	  //Abrir mallas
	  terreno = NULL;
	  if (!terreno)
	  {
		  terreno = glmReadOBJ("./Mallas/ArchCave.obj");
		  if (!terreno)
			  exit(0);

		  glmUnitize(terreno);
		  glmFacetNormals(terreno);
		  glmVertexNormals(terreno, 90.0);
	  }

	  mountain = NULL;

	  if (!mountain)
	  {
		  mountain = glmReadOBJ("./Mallas/montana.obj");
		  if (!mountain)
			  exit(0);

		  glmUnitize(mountain);
		  glmFacetNormals(mountain);
		  glmVertexNormals(mountain, 90.0);
	  }

	  ocean = NULL;

	  if (!ocean)
	  {
		  ocean = glmReadOBJ("./Mallas/Ocean.obj");
		  if (!ocean)
			  exit(0);

		  glmUnitize(ocean);
		  glmFacetNormals(ocean);
		  glmVertexNormals(ocean, 90.0);
	  }


 
	  //*** Para Textura: abrir archivo de textura
	  initialize_textures();
	  loadTerreno();
	  loadGoat();
	  loadDog();
	  loadMountainTexture();
	  loadOceanTexture();
      DemoLight();
	  loadAlien();
	  loadTorre();
	  loadCarri();
	  loadPoso();
	  loadChoza();
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
	   gluLookAt(0.0f,5.0f,10.0f, 
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

	   // Light model parameters:
	   // -------------------------------------------

	   GLfloat lmKa[] = { 4.0f, 4.0f, 4.0f, 1.0f }; // Luz ambiental más brillante
	   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmKa);

	   glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1.0);
	   glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 0.0);

	   // -------------------------------------------
	   // Spotlight Attenuation

	   GLfloat spot_direction[] = { 1.0, -1.0, -1.0 };
	   GLint spot_exponent = 60; // Mayor exponente
	   GLint spot_cutoff = 90;  // Mayor ángulo de corte

	   glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	   glLighti(GL_LIGHT0, GL_SPOT_EXPONENT, spot_exponent);
	   glLighti(GL_LIGHT0, GL_SPOT_CUTOFF, spot_cutoff);

	   GLfloat Kc = 0.5;  // Atenuación constante moderada
	   GLfloat Kl = 0.01; // Atenuación lineal reducida
	   GLfloat Kq = 0.001; // Atenuación cuadrática reducida

	   glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, Kc);
	   glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, Kl);
	   glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, Kq);

	   // -------------------------------------------
	   // Lighting parameters:

	   GLfloat light_pos[] = { 0.0f, 5.0f, 5.0f, 1.0f };
	   GLfloat light_Ka[] = { 0.8f, 0.8f, 0.8f, 1.0f }; // Intensidad ambiental moderada
	   GLfloat light_Kd[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Intensidad difusa máxima
	   GLfloat light_Ks[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Intensidad especular máxima

	   glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	   glLightfv(GL_LIGHT0, GL_AMBIENT, light_Ka);
	   glLightfv(GL_LIGHT0, GL_DIFFUSE, light_Kd);
	   glLightfv(GL_LIGHT0, GL_SPECULAR, light_Ks);

	   // -------------------------------------------
	   // Material parameters:

	   GLfloat material_Ka[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	   GLfloat material_Kd[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	   GLfloat material_Ks[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Intensidad especular máxima
	   GLfloat material_Ke[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	   GLfloat material_Se = 50.0f; // Aumenta el exponente de brillo (shininess) para una especular más intensa

	   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
	   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
	   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
	   glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_Ke);
	   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);
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