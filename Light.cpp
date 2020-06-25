#include <GL/glut.h>
#include "Calc.h"

float light_radiusf = -3.0f;
int light_anglei = 0;
GLfloat light_posf[4] = { 0.0f, 1.25f, light_radiusf, 1.0f};

//to move position of light source
void lightMovement(int keyi, int xi, int yi)
{
	switch (keyi)
	{
	case GLUT_KEY_LEFT:
		light_anglei -= 2;
		calculatePosXZ(light_posf[0], light_posf[2], light_anglei, light_radiusf);
		break;

	case GLUT_KEY_RIGHT:
		light_anglei += 2;
		calculatePosXZ(light_posf[0], light_posf[2], light_anglei, light_radiusf);
		break;

	case GLUT_KEY_UP:
		if (light_posf[1] > 3.0f)
			light_posf[1] = 3.0f;
		else
			light_posf[1] += 0.1f;
		break;

	case GLUT_KEY_DOWN:
		if (light_posf[1] < 0.0f)
			light_posf[1] = 0.0f;
		else
			light_posf[1] -= 0.1f;
		break;

	default:
		break;
	}

	glutPostRedisplay();
}
