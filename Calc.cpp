#include <cmath>

float degToRad(int angle)
{
	return angle * 3.141592 / 180;
}

void calculatePosXZ(float& posX, float& posZ, float angle, float radius)
{
	posX = sin(degToRad(angle)) * radius;

	if (angle == 0)
		posZ = radius;
	else
		posZ = cos(degToRad(angle)) * radius;

}