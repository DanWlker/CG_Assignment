#include <cmath>

float degToRad(int angle)
{
	return angle * 3.141592 / 180;
}

void calculatePosXZ(float& posX, float& posZ, float angle, float radius)
{
	if (angle == 0)
	{
		posX = 0;
		posZ = radius;
	}
	else
	{
		posX = sin(degToRad(angle)) * radius;
		posZ = cos(degToRad(angle)) * radius;
	}
		

}