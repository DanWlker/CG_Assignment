#pragma once
#include <windows.h>
#include <GL/glut.h>
#include "Calc.h"

float camera_radiusf = 3.0f;
int camera_anglei = 0;
float arr_camera_posf[3] = { 0.0f, 2.0f, camera_radiusf };
float arr_camera_targetf[3] = { 0.0f, 0.0f, 0.0f };


//to rotate object
void func_cameraMovement(unsigned char keyc, int xi, int yi)
{
	switch (keyc)
	{
	case 'w':
		if (arr_camera_posf[1] > 3.0f)
			arr_camera_posf[1] = 3.0f;
		else
			arr_camera_posf[1] += 0.1f;
		break;

	case 'a':
		camera_anglei -= 2;
		calculatePosXZ(arr_camera_posf[0], arr_camera_posf[2], camera_anglei, camera_radiusf);
		break;

	case 's':
		if (arr_camera_posf[1] < 0.0f)
			arr_camera_posf[1] = 0.0f;
		else
			arr_camera_posf[1] -= 0.1f;
		break;

	case 'd':
		camera_anglei += 2;
		calculatePosXZ(arr_camera_posf[0], arr_camera_posf[2], camera_anglei, camera_radiusf);
		break;

	case 27:
		exit(0);
		break;

	default:
		break;
	}

	glutPostRedisplay();
}