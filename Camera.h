#pragma once
extern float camera_posf[3];
extern float camera_targetf[3];
extern float camera_radiusf;
extern int camera_anglei;
extern bool grow;
extern bool reset;
void cameraMovement(unsigned char keyc, int xi, int yi);