#include <GL/glut.h>
#include <math.h>
#include <windows.h>
#include "Environment.h"
#include "Light.h"
#include "Camera.h"
#include "Materials.h"
#include "Calc.h"

void drawFloor()
{
	setMaterial("floor");

	float floor_sizef = 1.5f;

	glBegin(GL_POLYGON);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(floor_sizef, 0.0f, floor_sizef);
		glVertex3f(floor_sizef, 0.0f, -floor_sizef);
		glVertex3f(-floor_sizef, 0.0f, -floor_sizef);
		glVertex3f(-floor_sizef, 0.0f, floor_sizef);
	glEnd();
}

void tangentBezier(float t, float point_1[2], float point_2[2], float point_3[2], float& tanX, float& tanY)
{
	tanX = 2 * (1 - t) * (point_2[0] - point_1[0]) + 2 * t * (point_3[0] - point_2[0]);
	tanY = 2 * (1 - t) * (point_2[1] - point_1[1]) + 2 * t * (point_3[1] - point_2[1]);

	float unit = sqrt(tanX * tanX + tanY * tanY);

	tanX /= unit;
	tanY /= unit;
}

float angleOfRotation(float x2, float y2)
{
}

void drawStem()
{
	/*float top, bottom;
	float x, y, z;
	float angle;

	float PI = 3.1415;
	float radius = 0.03;

	int slices = 15;*/

	float t = 0;
	float point_1[2] = { 0, 0 };
	float point_2[2] = { 1.3, 0.26};
	float point_3[2] = { 0.56, 0.94 };
	float tanX, tanY;

	float y, z;

	glBegin(GL_LINE_STRIP);
	for (t = 0; t < 1; t += 0.1)
	{
		glPushMatrix();

		y = (1 - t) * (1 - t) * point_1[0] + 2 * (1 - t) * t * point_2[0] + t * t * point_3[0];
		z = (1 - t) * (1 - t) * point_1[1] + 2 * (1 - t) * t * point_2[1] + t * t * point_3[1];
		tangentBezier(t, point_1, point_2, point_3, tanX, tanY);


		glVertex3f(0, y, z);
		glPopMatrix();
	}
	glEnd();
	



	/*for (int i = 0; i < slices; ++i)
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
	}*/
}

void drawCuboid(
	float x_low_coorf, float x_high_coorf,
	float y_low_coorf, float y_high_coorf,
	float z_low_coorf, float z_high_coorf)
{
	//Normals for the 6 faces
	GLfloat arr_face_normalf[6][3] =
	{  
		{-1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {1.0, 0.0, 0.0},
		{0.0, -1.0, 0.0}, {0.0, 0.0, -1.0}, {0.0, 0.0, 1.0}
	};

	GLint arr_face_vertexi[6][4] = {  //Vertex labels for the indices of the 6 faces
	  {0, 1, 2, 3}, {3, 2, 6, 7}, {7, 6, 5, 4},
	  {4, 5, 1, 0}, {5, 6, 2, 1}, {7, 4, 0, 3} };

	GLfloat arr_vertex_coorf[8][3]; //To store actual coordinates of the vertices

	arr_vertex_coorf[0][0] = arr_vertex_coorf[1][0] = arr_vertex_coorf[2][0] = arr_vertex_coorf[3][0] = x_low_coorf; //x
	arr_vertex_coorf[4][0] = arr_vertex_coorf[5][0] = arr_vertex_coorf[6][0] = arr_vertex_coorf[7][0] = x_high_coorf; //x
	arr_vertex_coorf[0][1] = arr_vertex_coorf[1][1] = arr_vertex_coorf[4][1] = arr_vertex_coorf[5][1] = y_low_coorf; //y
	arr_vertex_coorf[2][1] = arr_vertex_coorf[3][1] = arr_vertex_coorf[6][1] = arr_vertex_coorf[7][1] = y_high_coorf; //y
	arr_vertex_coorf[1][2] = arr_vertex_coorf[2][2] = arr_vertex_coorf[5][2] = arr_vertex_coorf[6][2] = z_low_coorf; //z
	arr_vertex_coorf[0][2] = arr_vertex_coorf[3][2] = arr_vertex_coorf[4][2] = arr_vertex_coorf[7][2] = z_high_coorf; //z

	for (int i = 0; i < 6; i++)
	{
		glBegin(GL_QUADS);
			glNormal3fv(&arr_face_normalf[i][0]);
			glVertex3fv(&arr_vertex_coorf[arr_face_vertexi[i][0]][0]);
			glVertex3fv(&arr_vertex_coorf[arr_face_vertexi[i][1]][0]);
			glVertex3fv(&arr_vertex_coorf[arr_face_vertexi[i][2]][0]);
			glVertex3fv(&arr_vertex_coorf[arr_face_vertexi[i][3]][0]);
		glEnd();
	}
}

void drawPot()
{
	//body
	setMaterial("porcelain");
	drawCuboid(-0.3f, 0.3f, 0.0f, 0.25f, -0.15f, 0.15f);

	//back top part
	drawCuboid(-0.3f, 0.3f, 0.25f, 0.3f, -0.15f, -0.1f);

	//front top part
	drawCuboid(-0.3f, 0.3f, 0.25f, 0.3f, 0.1f, 0.15f);

	//left top part
	drawCuboid(-0.3f, -0.25f, 0.25f, 0.3f, -0.1f, 0.1f);

	//right top part
	drawCuboid(0.25f, 0.3f, 0.25f, 0.3f, -0.1f, 0.1f);

	//dirt
	setMaterial("dirt");
	drawCuboid(-0.25f, 0.25f, 0.25f, 0.27f, -0.1f, 0.1f);
}

void drawFlower()
{
	glPushMatrix();
		glTranslatef(0.0, 1.0, 0.0);
		glRotatef(-45.0f, 1.0, 0.0, 0.0);

		glPushMatrix();
			setMaterial("petal");
			
			for (int i = 0; i < 180; i += 30)
			{
				glRotatef(i, 0.0, 0.0, 1.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glBegin(GL_POLYGON);
				for (int i = 0; i < 360; i++)
				{
					glVertex3f(0.25 * cos(degToRadf(i)), 0.125 * sin(degToRadf(i)), 0);
				}
				glEnd();
			}
		glPopMatrix();

		glPushMatrix();
			setMaterial("pistil");
			glScalef(1.0, 1.0, 0.5);
			glutSolidSphere(0.1, 20, 20);
			glPopMatrix();
	glPopMatrix();
}

void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluLookAt
	(
		camera_posf[0], camera_posf[1], camera_posf[2], //camera position in the world
		camera_targetf[0], camera_targetf[1], camera_targetf[2],  //where the camera is looking at
		0, 1, 0 //camera up vector
	);

	glLightfv(GL_LIGHT0, GL_POSITION, light_posf);

	glRotatef(-30.0, 0.0, 1.0, 0.0);
	drawFloor();
	//drawPot();
	drawStem();
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