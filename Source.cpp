#include <GL/glut.h>
#include <math.h>
#include <windows.h>
#include "Environment.h"
#include "Light.h"
#include "Camera.h"
#include "Materials.h"
#include "Calc.h"

float point_1[2] = { 0, 0.27 };
float point_2[2] = { 0.1, 1.0 };
float point_3[2] = { 0.2, 0.4 };
float p3_limit = 1;

float flower_rotation;
float flower_trans_y, flower_trans_z;

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
}

float angleOfRotation(float x, float y)
{
	return atan(x/y) * 180 / 3.141592;
}

void drawStem()
{
	//to draw cylinder
	float top, bottom;
	float x, z;
	float PI = 3.1415;
	float radius = 0.01;
	int slices = 20;

	//to move to bezier
	float t = 0;
	
	float tanY, tanZ;
	float bezY, bezZ;
	float angle;

	for (t = 0; t < 1; t += (float)1.0 / slices)
	{
		

		bezZ = (1 - t) * (1 - t) * point_1[0] + 2 * (1 - t) * t * point_2[0] + t * t * point_3[0];
		bezY = (1 - t) * (1 - t) * point_1[1] + 2 * (1 - t) * t * point_2[1] + t * t * point_3[1];
		

		tangentBezier(t, point_1, point_2, point_3, tanZ, tanY);

		angle = angleOfRotation(tanZ, tanY);
		top = 0.1 - sin(abs(angle) * 3.141592/180) * 0.1;
		bottom = 0;

		glPushMatrix();

		glTranslatef(0.0, bezY, bezZ);
		glRotatef(angle, 1.0, 0.0, 0.0);

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

		glPopMatrix();
	}

	flower_rotation = angle;
	flower_trans_y = bezY;
	flower_trans_z = bezZ;
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
		glTranslatef(0.0, flower_trans_y, flower_trans_z);
		glRotatef(flower_rotation, 0.0, 0.0, 1.0);

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
	drawPot();
	drawStem();
	drawFlower();

	glutSwapBuffers();
}

void timer(int value)
{
	if (point_3[1] < p3_limit && grow)
	{
		point_3[1] += 0.05;
		grow = false;
	}

	glutPostRedisplay();
	glutTimerFunc(80, timer, 0);
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
	glutTimerFunc(100, timer, 0);

	glutMainLoop();
	return 0;
}