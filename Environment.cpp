#pragma once
#include <GL/glut.h>
#include <windows.h>
#include "Light.h"

void setup()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);

	//lighting set up
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//Set lighting intensity and color (White)
	GLfloat ambientColor[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuseColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat specularColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseColor);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	glShadeModel(GL_SMOOTH);

	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glDepthFunc(GL_LEQUAL);
}

//to resize window
void resize(int w, int h)
{
	if (h == 0)
		h = 1;
	float aspectRatio = (float)w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45, aspectRatio, 2, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
