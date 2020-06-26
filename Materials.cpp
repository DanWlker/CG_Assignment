#include <string>
#include <GL/glut.h>

void setMaterial(std::string mats)
{
	if (mats == "floor")
	{
		float mat_ambf[] = { 0.435f, 0.5225f, 0.4575f, 0.95f };
		float mat_diff[] = { 0.54f, 0.89f, 0.63f, 0.95f };
		float mat_spef[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		float shinef = 12.8f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambf);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diff);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spef);
		glMaterialf(GL_FRONT, GL_SHININESS, shinef);
		return;
	}

	if (mats == "dirt")
	{
		float mat_ambf[4] = { 0.48f, 0.247f, 0.0f, 1.0f };
		float mat_diff[4] = { 0.48f, 0.247f, 0.0f, 1.0f };
		float mat_spef[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambf);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diff);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spef);
		return;
	}

	if (mats == "porcelain")
	{
		float mat_ambf[] = { 0.0f, 0.1f, 0.06f, 1.0f };
		float mat_diff[] = { 0.0f, 0.50980392f, 0.50980392f, 1.0f };
		float mat_spef[] = { 0.50196078f, 0.50196078f, 0.50196078f, 1.0f };
		float shinef = 32.0f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambf);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diff);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spef);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shinef);
		return;
	}

	if (mats == "petal")
	{
		float mat_ambient[] = { 207.0 / 255.0, 160.0 / 255.0, 182.0 / 255.0, 1.0f };
		float mat_diffuse[] = { 255.0 / 255.0, 198.0 / 255.0, 224.0 / 255.0, 1.0f };
		float mat_specular[] = { 235.0 / 255.0, 186.0 / 255.0, 207.0 / 255.0, 1.0f };
		float shine = 30.0f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
		return;
	}

	if (mats == "pistil")
	{
		float mat_ambient[] = { 237.0 / 255.0, 203.0 / 255.0, 25.0 / 255.0, 1.0f };
		float mat_diffuse[] = { 254.0 / 255.0, 225.0 / 255.0, 52.0 / 255.0, 1.0f };
		float mat_specular[] = { 254.0 / 255.0, 217.0 / 255.0, 0.0 / 255.0, 1.0f };
		float shine = 30.0f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
	}
}
