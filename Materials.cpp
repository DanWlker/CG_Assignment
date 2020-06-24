#include <string>
#include <GL/glut.h>

void setMaterials(std::string mat)
{
	if (mat == "floor")
	{
		float mat_ambient[] = { 0.435f, 0.5225f, 0.4575f, 0.95f };
		float mat_diffuse[] = { 0.54f, 0.89f, 0.63f, 0.95f };
		float mat_specular[] = { 0.0, 0.0, 0.0, 0.0 };
		float shine = 12.8f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);
		return;
	}

	if (mat == "dirt")
	{
		float mat_amb[4] = { 0.48f, 0.247f, 0.0f, 1.0f };
		float mat_dif[4] = { 0.48f, 0.247f, 0.0f, 1.0f };
		float mat_spe[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_amb);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_dif);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spe);
		return;
	}

	if (mat == "porcelain")
	{
		float mat_ambient[] = { 0.0f,0.1f,0.06f ,1.0f };
		float mat_diffuse[] = { 0.0f,0.50980392f,0.50980392f,1.0f };
		float mat_specular[] = { 0.50196078f,0.50196078f,0.50196078f,1.0f };
		float shine = 32.0f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
		return;
	}

	if (mat == "petal")
	{
		float mat_ambient[] = { 207.0 / 255.0, 159.0 / 255.0, 201.0 / 255.0, 0.9f };
		float mat_diffuse[] = { 238.0 / 255.0, 199.0 / 255.0, 223.0 / 255.0, 0.9f };
		float mat_specular[] = { 223.0 / 255.0, 192.0 / 255.0, 220.0 / 255.0, 0.8f };
		float shine = 5.0f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
		return;
	}

	if (mat == "pistil")
	{
		float mat_ambient[] = { 225.0 / 255.0, 216.0 / 255.0, 134.0 / 255.0, 1.0f };
		float mat_diffuse[] = { 254.0 / 255.0, 244.0 / 255.0, 150.0 / 255.0, 1.0f };
		float mat_specular[] = { 239.0 / 255.0, 232.0 / 255.0, 159.0 / 255.0, 1.0f };
		float shine = 5.0f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
	}
}
