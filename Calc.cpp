#include <cmath>

float degToRadf(int anglei)
{
	return (float)anglei * 3.141592f / 180.0f;
}

void calculatePosXZ(float& posXf, float& posZf, int anglei, float radiusf)
{
	if (anglei == 0)
	{
		posXf = 0;
		posZf = radiusf;
	}
	else
	{
		posXf = sin(degToRadf(anglei)) * radiusf;
		posZf = cos(degToRadf(anglei)) * radiusf;
	}

}