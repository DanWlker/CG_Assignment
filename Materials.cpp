#include <string>
#include <GL/glut.h>

void setMaterials(std::string mat)
{
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
}
