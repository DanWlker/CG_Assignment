#pragma once
#include <windows.h>
#include <GL/glut.h>
#include "Calc.h"

float cameraRadius = 3.0f;
int cameraAngle = 0;
float cameraPos[3] = { 0.0f, 2.0f, cameraRadius };
float cameraTarget[3] = { 0.0f, 0.0f, 0.0f };


//to rotate object
void cameraMovement(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		if (cameraPos[1] > 3.0f)
			cameraPos[1] = 3.0;
		else
			cameraPos[1] += 0.1f;
		break;

	case 'a':
		cameraAngle -= 2;
		calculatePosXZ(cameraPos[0], cameraPos[2], cameraAngle, cameraRadius);
		break;

	case 's':
		if (cameraPos[1] < 0.0f)
			cameraPos[1] = 0.0f;
		else
			cameraPos[1] -= 0.1f;
		break;

	case 'd':
		cameraAngle += 2;
		calculatePosXZ(cameraPos[0], cameraPos[2], cameraAngle, cameraRadius);
		break;

	case 27:
		exit(0);
		break;

	default:
		break;
	}

	glutPostRedisplay();
}