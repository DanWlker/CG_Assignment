#include <GL/glut.h>
#include <windows.h>
#include "Environment.h"
#include "Light.h"
#include "Camera.h"
#include "Materials.h"

void drawFloor()
{
	float mat_ambient[] = { 0.435f, 0.5225f, 0.4575f, 0.95f };
	float mat_diffuse[] = { 0.54f, 0.89f, 0.63f, 0.95f };
	float mat_specular[] = { 0.0, 0.0, 0.0, 0.0 };
	float shine = 12.8f;


	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shine);

	float floorSize = 1.5f;

	glBegin(GL_POLYGON);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(floorSize, 0.0, floorSize);
		glVertex3f(floorSize, 0.0, -floorSize);
		glVertex3f(-floorSize, 0.0, -floorSize);
		glVertex3f(-floorSize, 0.0, floorSize);
	glEnd();


}

void drawStem()
{
	GLfloat top, bottom;
	GLfloat x, z;
	GLfloat angle;

	float PI = 3.1415;
	float radius = 0.03;

	int slices = 15;

	for (int i = 0; i < slices; ++i)
	{
		top = (float)(i + 1) / (float)slices;
		bottom = (float)i / (float)slices;

		glColor3f(1.0f - top, 0.0, bottom);

		glBegin(GL_QUAD_STRIP);
		for (int j = 0; j <= 360; ++j)
		{
			angle = (float)j * PI / 180.0f;
			x = radius * cos(angle);
			z = radius * sin(angle);
			glVertex3f(x, top, z);
			glVertex3f(x, bottom, z);
		}
		glEnd();
	}
}

void drawPot()
{
	GLfloat n[6][3] = 
	{  /* Normals for the 6 faces of a cube. */
		{-1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {1.0, 0.0, 0.0},
		{0.0, -1.0, 0.0}, {0.0, 0.0, -1.0}, {0.0, 0.0, 1.0} 
	};

	GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
	  {0, 1, 2, 3}, {3, 2, 6, 7}, {7, 6, 5, 4},
	  {4, 5, 1, 0}, {5, 6, 2, 1}, {7, 4, 0, 3} };

	GLfloat v[8][3];

	//body
	//x y z
	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -0.3; //x
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = 0.3; //x
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = 0; //y
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = 0.25; //y
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = 0.15; //z
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = -0.15; //z

	setMaterials("porcelain");
	
	for (int i = 0; i < 6; i++) 
	{
			glBegin(GL_QUADS);
				glNormal3fv(&n[i][0]);
				glVertex3fv(&v[faces[i][0]][0]);
				glVertex3fv(&v[faces[i][1]][0]);
				glVertex3fv(&v[faces[i][2]][0]);
				glVertex3fv(&v[faces[i][3]][0]);
			glEnd();
	}

	//back
	//x y z
	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -0.30; //x
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = 0.30; //x
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = 0.25; //y
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = 0.30; //y
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = -0.1; //z
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = -0.15; //z

	for (int i = 0; i < 6; i++)
	{
		glBegin(GL_QUADS);
		glNormal3fv(&n[i][0]);
		glVertex3fv(&v[faces[i][0]][0]);
		glVertex3fv(&v[faces[i][1]][0]);
		glVertex3fv(&v[faces[i][2]][0]);
		glVertex3fv(&v[faces[i][3]][0]);
		glEnd();
	}

	//front
	//x y z
	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -0.30; //x
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = 0.30; //x
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = 0.25; //y
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = 0.30; //y
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = 0.15; //z
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = 0.1; //z

	for (int i = 0; i < 6; i++)
	{
		glBegin(GL_QUADS);
		glNormal3fv(&n[i][0]);
		glVertex3fv(&v[faces[i][0]][0]);
		glVertex3fv(&v[faces[i][1]][0]);
		glVertex3fv(&v[faces[i][2]][0]);
		glVertex3fv(&v[faces[i][3]][0]);
		glEnd();
	}

	//left
	//x y z
	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -0.30; //x
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = -0.25; //x
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = 0.25; //y
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = 0.30; //y
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = 0.1; //z
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = -0.1; //z

	for (int i = 0; i < 6; i++)
	{
		glBegin(GL_QUADS);
		glNormal3fv(&n[i][0]);
		glVertex3fv(&v[faces[i][0]][0]);
		glVertex3fv(&v[faces[i][1]][0]);
		glVertex3fv(&v[faces[i][2]][0]);
		glVertex3fv(&v[faces[i][3]][0]);
		glEnd();
	}

	//right
	//x y z
	v[0][0] = v[1][0] = v[2][0] = v[3][0] = 0.25; //x
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = 0.3; //x
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = 0.25; //y
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = 0.30; //y
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = 0.1; //z
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = -0.1; //z

	for (int i = 0; i < 6; i++)
	{
		glBegin(GL_QUADS);
		glNormal3fv(&n[i][0]);
		glVertex3fv(&v[faces[i][0]][0]);
		glVertex3fv(&v[faces[i][1]][0]);
		glVertex3fv(&v[faces[i][2]][0]);
		glVertex3fv(&v[faces[i][3]][0]);
		glEnd();
	}

	//dirt
	//x y z
	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -0.25; //x
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = 0.25; //x
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = 0.25; //y
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = 0.27; //y
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = 0.1; //z
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = -0.1; //z

	setMaterials("dirt");

	for (int i = 0; i < 6; i++)
	{
		glBegin(GL_QUADS);
		glNormal3fv(&n[i][0]);
		glVertex3fv(&v[faces[i][0]][0]);
		glVertex3fv(&v[faces[i][1]][0]);
		glVertex3fv(&v[faces[i][2]][0]);
		glVertex3fv(&v[faces[i][3]][0]);
		glEnd();
	}
}

void drawFlower()
{

}



void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluLookAt
	(
		cameraPos[0], cameraPos[1], cameraPos[2], //camera position in the world
		cameraTarget[0], cameraTarget[1], cameraTarget[2],  //where the camera is looking at
		0, 1, 0 //camera up vector
	);

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	glRotatef(-30.0, 0.0, 1.0, 0.0);
	drawFloor();
	drawPot();
	//drawStem();
	//drawFlower();

	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(680, 800);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Computer Graphics Assignment");

	setup();
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(cameraMovement);
	glutSpecialFunc(lightMovement);

	glutMainLoop();
	return 0;
}