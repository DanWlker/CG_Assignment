#include <GL/glut.h>
#include "Calc.h"

float lightRadius = -3.0f;
int lightAngle = 0.0f;
GLfloat lightPos[] = { 0.0, 1.25, lightRadius, 1.0};

//to move position of light source
void lightMovement(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		lightAngle += 2;
		calculatePosXZ(lightPos[0], lightPos[2], lightAngle, lightRadius);
		break;

	case GLUT_KEY_RIGHT:
		lightAngle -= 2;
		calculatePosXZ(lightPos[0], lightPos[2], lightAngle, lightRadius);
		break;

	case GLUT_KEY_UP:
		if (lightPos[1] > 3.0f)
			lightPos[1] = 3.0;
		else
			lightPos[1] += 0.1;
		break;

	case GLUT_KEY_DOWN:
		if (lightPos[1] < 0.0f)
			lightPos[1] = 0;
		else
			lightPos[1] -= 0.1;
		break;

	default:
		break;
	}

	glutPostRedisplay();
}
