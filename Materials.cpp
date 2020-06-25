#include <string>
#include <GL/glut.h>

void setMaterial(std::string mats)
{
	if (mats == "floor")
	{
		float arr_mat_ambf[] = { 0.435f, 0.5225f, 0.4575f, 0.95f };
		float arr_mat_diff[] = { 0.54f, 0.89f, 0.63f, 0.95f };
		float arr_mat_spef[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		float shinef = 12.8f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, arr_mat_ambf);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, arr_mat_diff);
		glMaterialfv(GL_FRONT, GL_SPECULAR, arr_mat_spef);
		glMaterialf(GL_FRONT, GL_SHININESS, shinef);
		return;
	}

	if (mats == "dirt")
	{
		float arr_mat_ambf[4] = { 0.48f, 0.247f, 0.0f, 1.0f };
		float arr_mat_diff[4] = { 0.48f, 0.247f, 0.0f, 1.0f };
		float arr_mat_spef[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, arr_mat_ambf);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, arr_mat_diff);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, arr_mat_spef);
		return;
	}

	if (mats == "porcelain")
	{
		float arr_mat_ambf[] = { 0.0f, 0.1f, 0.06f, 1.0f };
		float arr_mat_diff[] = { 0.0f, 0.50980392f, 0.50980392f, 1.0f };
		float arr_mat_spef[] = { 0.50196078f, 0.50196078f, 0.50196078f, 1.0f };
		float shinef = 32.0f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, arr_mat_ambf);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, arr_mat_diff);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, arr_mat_spef);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shinef);
		return;
	}

	if (mats == "petal")
	{
		float arr_mat_ambf[] = { 207.0f / 255.0f, 159.0f / 255.0f, 201.0f / 255.0f, 0.9f };
		float arr_mat_diff[] = { 238.0f / 255.0f, 199.0f / 255.0f, 223.0f / 255.0f, 0.9f };
		float arr_mat_spef[] = { 223.0f / 255.0f, 192.0f / 255.0f, 220.0f / 255.0f, 0.8f };
		float shinef = 5.0f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, arr_mat_ambf);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, arr_mat_diff);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, arr_mat_spef);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shinef);
		return;
	}

	if (mats == "pistil")
	{
		float arr_mat_ambf[] = { 225.0f / 255.0f, 216.0f / 255.0f, 134.0f / 255.0f, 1.0f };
		float arr_mat_diff[] = { 254.0f / 255.0f, 244.0f / 255.0f, 150.0f / 255.0f, 1.0f };
		float arr_mat_spef[] = { 239.0f / 255.0f, 232.0f / 255.0f, 159.0f / 255.0f, 1.0f };
		float shinef = 5.0f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, arr_mat_ambf);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, arr_mat_diff);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, arr_mat_spef);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shinef);
	}
}
