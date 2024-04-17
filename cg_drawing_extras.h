#pragma once

#include "ofMain.h"
#include "cg_extras.h"



int shine;
ofVec3f dirVec3f;
GLfloat dirVecTheta;


float bumpScale = 0.0010;
ofImage normalMap;
ofPixels normalPixels;

inline void loadMaterial(int material, GLfloat *amb, GLfloat *dif, GLfloat *spec, int& shine) {
	GLfloat jadeAmb[] = { 0.135, 0.2225, 0.1575, 1. };
	GLfloat jadeDif[] = { 0.54, 0.89, 0.63, 1. };
	GLfloat jadeSpec[] = { 0.316228, 0.316228, 0.316228, 1. };
	GLint jadeCoef = 0.1 * 128;

	GLfloat pearlAmb[] = { 0.25, 0.20725, 0.20725, 1. };
	GLfloat pearlDif[] = { 1.0, 0.829, 0.829, 1. };
	GLfloat pearlSpec[] = { 0.296648, 0.296648, 0.296648, 1. };
	GLint pearlCoef = 0.088 * 128;

	GLfloat copperAmb[] = { 0.19125, 0.0735, 0.0225, 1. };
	GLfloat copperDif[] = { 0.7038, 0.27048, 0.0828, 1. };
	GLfloat copperSpec[] = { 0.256777, 0.137622, 0.086014, 1. };
	GLint copperCoef = 0.1 * 128;

	GLfloat  chromeAmb[] = { 0.25 ,0.25 ,0.25, 1. };
	GLfloat  chromeDif[] = { 0.4 ,0.4 ,0.4, 1. };
	GLfloat  chromeSpec[] = { 0.774597 ,0.774597 ,0.774597, 1. };
	GLint  chromeCoef = 0.6 * 128;

	GLfloat  carAmb[] = { 0.5, 0., 0., 1. };
	GLfloat  carDif[] = { 1 ,0. ,0., 1. };
	GLfloat  carSpec[] = { 0.8 ,0. ,0., 1. };
	GLint  carCoef = 0.6 * 128;

	GLfloat  tierAmb[] = { 0. ,0. ,0., 1. };
	GLfloat  tierDif[] = { 0.1 ,0.1 ,0.1, 1. };
	GLfloat  tierSpec[] = { 0.774597 ,0.774597 ,0.774597, 1. };
	GLint  tierCoef = 0.6 * 128;

	GLfloat  lanternAmb[] = { 0.2 ,0.2 ,0.1, 1. };
	GLfloat  lanternDif[] = { 1. ,1. ,0.5, 1. };
	GLfloat  lanternSpec[] = { 0.7 ,0.7 ,0.35, 1. };
	GLint  lanternCoef = 0.6 * 128;

	GLfloat defaultAmb[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat defaultDif[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat defaultSpec[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat defaultCoef = 0.7 * 128;

	GLfloat fumoAmb[] = { 0.5627, 0.5627, 0.5627, 1.0f };
	GLfloat fumoDif[] = { 0.6627, 0.6627, 0.6627, 1.0f };
	GLfloat fumoSpec[] = { 0.6627, 0.6627, 0.6627, 1.0f };
	GLfloat fumoCoef = 0.2 * 128;

	switch (material) {
		case 0:
			std::copy(jadeAmb, jadeAmb + 4, amb);
			std::copy(jadeDif, jadeDif + 4, dif);
			std::copy(jadeSpec, jadeSpec + 4, spec);
			shine = jadeCoef;
			break;
		case 1:
			std::copy(pearlAmb, pearlAmb + 4, amb);
			std::copy(pearlDif, pearlDif + 4, dif);
			std::copy(pearlSpec, pearlSpec + 4, spec);
			shine = pearlCoef;
			break;
		case 2:
			std::copy(copperAmb, copperAmb + 4, amb);
			std::copy(copperDif, copperDif + 4, dif);
			std::copy(copperSpec, copperSpec + 4, spec);
			shine = copperCoef;
			break;
		case 3:
			std::copy(chromeAmb, chromeAmb + 4, amb);
			std::copy(chromeDif, chromeDif + 4, dif);
			std::copy(chromeSpec, chromeSpec + 4, spec);
			shine = chromeCoef;
			break;
		case 4:
			std::copy(carAmb, carAmb + 4, amb);
			std::copy(carDif, carDif + 4, dif);
			std::copy(carSpec, carSpec + 4, spec);
			shine = carCoef;
			break;
		case 5:
			std::copy(tierAmb, tierAmb + 4, amb);
			std::copy(tierDif, tierDif + 4, dif);
			std::copy(tierSpec, tierSpec + 4, spec);
			shine = tierCoef;
			break;
		case 6:
			std::copy(lanternAmb, lanternAmb + 4, amb);
			std::copy(lanternDif, lanternDif + 4, dif);
			std::copy(lanternSpec, lanternSpec + 4, spec);
			shine = lanternCoef;
			break;
		case 7:
			std::copy(defaultAmb, defaultAmb + 4, amb);
			std::copy(defaultDif, defaultDif + 4, dif);
			std::copy(defaultSpec, defaultSpec + 4, spec);
			shine = defaultCoef;
			break;
		case 8:
			std::copy(fumoAmb, fumoAmb + 4, amb);
			std::copy(fumoDif, fumoDif + 4, dif);
			std::copy(fumoSpec, fumoSpec + 4, spec);
			shine = fumoCoef;
			break;
		default:
			break;
	}
}

class Apartamento {
public:
	ofImage frente, cima, esquerda, direita, tras;
	GLfloat amb[4], dif[4], spec[4];
	int shine;

	Apartamento() = default;

	Apartamento(const std::string& a, const std::string& b, const std::string& c, const std::string& d, const std::string& e, int material) {
		if (a != "none")
			frente.load(a);
		if (b != "none")
			cima.load(b);
		if (c != "none")
			esquerda.load(c);
		if (d != "none")
			direita.load(d);
		if (e != "none")
			tras.load(e);

		loadMaterial(material, amb, dif, spec, shine);
		
	}

	ofImage image(const std::string& spot) {
		if (spot == "frente")
			return frente;
		if (spot == "cima")
			return cima;
		if (spot == "esquerda")
			return esquerda;
		if (spot == "direita")
			return direita;
		if (spot == "tras")
			return tras;

		// Return a default image or handle the case where 'spot' is not recognized.
		return ofImage(); // Change this line based on your needs.
	}
};


//desenha axis 3D
inline void axis3d() {
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1);
	glEnd();
}

//função que desenha quadrado unitário 
//centrado na origem e preenchido
inline void rectFill_unit() {
	glBegin(GL_QUADS);
	glVertex3d(-0.5, -0.5, 0.);
	glVertex3d(-0.5, 0.5, 0.);
	glVertex3d(0.5, 0.5, 0.);
	glVertex3d(0.5, -0.5, 0.);
	glEnd();
}

inline void floor_unit(GLint m, GLint n, ofImage img) {
	GLfloat x_start = -0.5;
	GLfloat y_start = -0.5;
	GLfloat x_step = 1.0 / GLfloat(m);
	GLfloat y_step = 1.0 / GLfloat(n);

	glEnable(GL_TEXTURE);
	img.bind();
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glPushMatrix();
	glBegin(GL_QUADS);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int picIndex = 3 * (j * n + i);

			float nx = normalPixels[picIndex] / 127.0 - 1.0;
			float ny = normalPixels[picIndex + 1] / 127.0 - 1.0;
			float nz = normalPixels[picIndex + 2] / 255.0;

			ofVec3f normal = ofVec3f(nx, ny, nz * bumpScale).normalized();

			glNormal3f(normal.x, normal.y, normal.z);

			glTexCoord2f(i * 1.0 / m, j * 1.0 / n);
			glVertex2d(i * x_step + x_start, j * y_step + y_start);

			glTexCoord2f(i * 1.0 / m, (j + 1) * 1.0 / n);
			glVertex2d(i * x_step + x_start, (j + 1) * y_step + y_start);

			glTexCoord2f((i + 1) * 1.0 / m, (j + 1) * 1.0 / n);
			glVertex2d((i + 1) * x_step + x_start, (j + 1) * y_step + y_start);

			glTexCoord2f((i + 1) * 1.0 / m, j * 1.0 / n);
			glVertex2d((i + 1) * x_step + x_start, j * y_step + y_start);
		}
	}

	glEnd();
	glPopMatrix();
	img.unbind();
	glDisable(GL_TEXTURE);
}


//função que desenha malha unitária com resolução mxn
inline void malha_unit(GLint m, GLint n, ofImage img) {
	GLfloat x_start = -0.5;
	GLfloat y_start = -0.5;
	GLfloat x_step = 1.0 / GLfloat(m);
	GLfloat y_step = 1.0 / GLfloat(n);

	//
	//ofVec3f normal;
	//float nx, ny, nz;
	//int picIndex;
	//float bumpScale = 0.008;

	//ofImage normalMap;
	

	//unsigned char* normalPixels = new unsigned char[3 * 256 * 256];

	if (img.isAllocated()) {

		//normalMap.load("Parede_fabrica_normal.png");
		//normalPixels = normalMap.getPixels().getData();

		glEnable(GL_TEXTURE);
		img.bind();
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR); //!

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glPushMatrix();
		glBegin(GL_QUADS);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {


				glTexCoord2f(i * x_step, j * y_step);
				glVertex2d(i * x_step + x_start, j * y_step + y_start);
				
				glTexCoord2f(i * x_step, (j + 1) * y_step);
				glVertex2d(i * x_step + x_start, (j + 1) * y_step + y_start);
				
				glTexCoord2f((i + 1) * x_step, (j + 1) * y_step);
				glVertex2d((i + 1) * x_step + x_start, (j + 1) * y_step + y_start);
				
				glTexCoord2f((i + 1) * x_step, j * y_step);
				glVertex2d((i + 1) * x_step + x_start, j * y_step + y_start);
			}
		}
		glEnd();
		glPopMatrix();
		img.unbind();
		glDisable(GL_TEXTURE);
	} else {
		glBegin(GL_QUADS);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				glVertex2d(i * x_step + x_start, j * y_step + y_start);
				glVertex2d(i * x_step + x_start, (j + 1) * y_step + y_start);
				glVertex2d((i + 1) * x_step + x_start, (j + 1) * y_step + y_start);
				glVertex2d((i + 1) * x_step + x_start, j * y_step + y_start);
			}
		}
		glEnd();
	}
}

inline void cube_malha_unit(GLint m, GLint n, Apartamento app) {

	ofImage nullImage;

	glMaterialfv(GL_FRONT, GL_AMBIENT, app.amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, app.dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, app.spec);
	glMaterialf(GL_FRONT, GL_SHININESS, app.shine);


	glPushMatrix();
	//baixo
	glNormal3f(0, 0, -1);
	glPushMatrix();
	glTranslated(0., 0., -0.5);
	glRotated(180, 0, 1, 0);
	malha_unit(m, n, nullImage);
	glPopMatrix();

	//tras
	glNormal3f(0, -1, 0);
	glPushMatrix();
	glTranslated(0., -0.5, 0.);
	glRotated(90, 1, 0, 0);
	glRotated(180, 0, 0, 1);
	malha_unit(m, n, app.image("tras"));
	glPopMatrix();

	//frente
	glNormal3f(0, 1, 0);
	glPushMatrix();
	glTranslated(0., 0.5, 0.);
	glRotated(-90, 1, 0, 0);
	malha_unit(m, n, app.image("frente"));
	glPopMatrix();

	//esquerda
	glNormal3f(-1, 0, 0);
	glPushMatrix();
	glTranslated(-0.5, 0., 0.);
	glRotated(-90, 0, 1, 0);
	glRotated(90, 0, 0, 1);
	malha_unit(m, n, app.image("esquerda"));
	glPopMatrix();

	//direita
	glNormal3f(1, 0, 0);
	glPushMatrix();
	glTranslated(0.5, 0., 0.);
	glRotated(90, 0, 1, 0);
	glRotated(-90, 0, 0, 1);
	malha_unit(m, n, app.image("direita"));
	glPopMatrix();

	//cima
	glNormal3f(0, 0, 1);
	glPushMatrix();
	glTranslated(0., 0., 0.5);
	malha_unit(m, n, app.image("cima"));
	glPopMatrix();

	glPopMatrix();
}

inline void cube_unit() {
	GLfloat p = 0.5;
	glBegin(GL_QUADS);

	//frente
	glVertex3f(-p, -p, p);
	glVertex3f(-p, p, p);
	glVertex3f(p, p, p);
	glVertex3f(p, -p, p);

	//tras
	glVertex3f(-p, -p, -p);
	glVertex3f(p, -p, -p);
	glVertex3f(p, p, -p);
	glVertex3f(-p, p, -p);

	//cima
	glVertex3f(-p, -p, -p);
	glVertex3f(-p, -p, p);
	glVertex3f(p, -p, p);
	glVertex3f(p, -p, -p);

	//baixo
	glVertex3f(-p, p, p);
	glVertex3f(-p, p, -p);
	glVertex3f(p, p, -p);
	glVertex3f(p, p, p);

	//esq
	glVertex3f(-p, -p, p);
	glVertex3f(-p, -p, -p);
	glVertex3f(-p, p, -p);
	glVertex3f(-p, p, p);

	//dir
	glVertex3f(p, -p, p);
	glVertex3f(p, p, p);
	glVertex3f(p, p, -p);
	glVertex3f(p, -p, -p);

	glEnd();

}

inline void u_unit(int num, GLfloat value, Apartamento app) {
	GLfloat color1, color2, color3 = value;
	GLfloat p = 0.5;
	GLfloat x, x2;
	GLfloat y, y2;
	GLfloat dx, dy;
	GLfloat dx2, dy2;
	GLfloat teta = (180./num+1) * PI / 180;

	glRotatef(-22.5-180, 0, 0, 1);

	glMaterialfv(GL_FRONT, GL_AMBIENT, app.amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, app.dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, app.spec);
	glMaterialf(GL_FRONT, GL_SHININESS, app.shine);
	

	glEnable(GL_TEXTURE);
	ofImage img;
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR); //!

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);


	for (int i = 0; i < num; i++) {
		x = p * cos((1 + i) * teta);
		y = p * sin((1 + i) * teta);
		dx = p * cos((2 + i) * teta);
		dy = p * sin((2 + i) * teta);

		x2 = 2 * p * cos((1 + i) * teta);
		y2 = 2 * p * sin((1 + i) * teta);
		dx2 = 2 * p * cos((2 + i) * teta);
		dy2 = 2 * p * sin((2 + i) * teta);

		color1 = float(i) / num;
		color2 = 1 - float(1) / num;
		if (i % 2 == 0)
			color3 += 0.2;
		else
			color3 -= 0.2;

		glColor3f(color1, color2, color3);

		//frente
		img = app.image("frente");
		img.bind();
		glBegin(GL_QUADS);

		glPushMatrix();

		float texCoordFactor = float(i) / num;  // Calculate the texture coordinate factor

		glTexCoord2f(texCoordFactor, 1);
		glVertex3f(x, y, -p);
		glTexCoord2f(texCoordFactor + 1.0 / num, 1);
		glVertex3f(dx, dy, -p);
		glTexCoord2f(texCoordFactor + 1.0 / num, 0);
		glVertex3f(dx, dy, p);
		glTexCoord2f(texCoordFactor, 0);
		glVertex3f(x, y, p);

		glPopMatrix();
		glEnd();
		img.unbind();

		//cima
		img = app.image("cima");
		img.bind();
		glBegin(GL_QUADS);
		glPushMatrix();

		glTexCoord2f(0, 0);
		glVertex3f(x, y, p);
		glTexCoord2f(0, 1);
		glVertex3f(dx, dy, p);
		glTexCoord2f(1, 1);
		glVertex3f(dx2, dy2, p);
		glTexCoord2f(1, 0);
		glVertex3f(x2, y2, p);

		glPopMatrix();
		glEnd();
		img.unbind();

		//baixo
		glBegin(GL_QUADS);
		glPushMatrix();
		glVertex3f(x, y, -p);
		glVertex3f(x2, y2, -p);
		glVertex3f(dx2, dy2, -p);
		glVertex3f(dx, dy, -p);
		glPopMatrix();
		glEnd();


		//tras
		img = app.image("tras");
		img.bind();
		glBegin(GL_QUADS);
		glPushMatrix();
		
		glTexCoord2f(1, 1);
		glVertex3f(x2, y2, -p);
		glTexCoord2f(1, 0);
		glVertex3f(x2, y2, p);
		glTexCoord2f(0, 0);
		glVertex3f(dx2, dy2, p);
		glTexCoord2f(0, 1);
		glVertex3f(dx2, dy2, -p);

		glPopMatrix();
		glEnd();
		img.unbind();


		if (i == 0) {
			//lado
			img = app.image("esquerda");
			img.bind();
			glBegin(GL_QUADS);
			glPushMatrix();
			
			glTexCoord2f(1, 0);
			glVertex3f(x, y, p);
			glTexCoord2f(0, 0);
			glVertex3f(x2, y2, p);
			glTexCoord2f(0, 1);
			glVertex3f(x2, y2, -p);
			glTexCoord2f(1, 1);
			glVertex3f(x, y, -p);

			glPopMatrix();
			glEnd();
			img.unbind();
		}


		if (i == num - 1) {
			//lado
			img = app.image("direita");
			img.bind();
			glBegin(GL_QUADS);
			glPushMatrix();
			
			glTexCoord2f(0, 1);
			glVertex3f(dx, dy, -p);
			glTexCoord2f(1, 1);
			glVertex3f(dx2, dy2, -p);
			glTexCoord2f(1, 0);
			glVertex3f(dx2, dy2, p);
			glTexCoord2f(0, 0);
			glVertex3f(dx, dy, p);

			glPopMatrix();
			glEnd();
			img.unbind();
		}
	}

	glDisable(GL_TEXTURE);
}

inline void triangle_unit(Apartamento app) {
	GLfloat p = 0.5;

	glMaterialfv(GL_FRONT, GL_AMBIENT, app.amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, app.dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, app.spec);
	glMaterialf(GL_FRONT, GL_SHININESS, app.shine);

	glBegin(GL_TRIANGLES);

	//lado 1
	glVertex3f(0, -p, 0);
	glVertex3f(p, p, p);
	glVertex3f(p, p, -p);

	//lado 2
	glVertex3f(0, -p, 0);
	glVertex3f(-p, p, p);
	glVertex3f(p, p, p);

	//lado 3
	glVertex3f(0, -p, 0);
	glVertex3f(-p, p, -p);
	glVertex3f(-p, p, p);

	//lado 4
	glVertex3f(0, -p, 0);
	glVertex3f(p, p, -p);
	glVertex3f(-p, p, -p);

	glEnd();

	//frente
	glBegin(GL_QUADS);
	glVertex3f(p, p, p);
	glVertex3f(-p, p, p);
	glVertex3f(-p, p, -p);
	glVertex3f(p, p, -p);
	glEnd();

}

inline void egypt(Apartamento app, Apartamento cubo) {
	GLfloat p = 0.5;
	ofImage img = app.image("frente");
	glMaterialfv(GL_FRONT, GL_AMBIENT, app.amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, app.dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, app.spec);
	glMaterialf(GL_FRONT, GL_SHININESS, app.shine);

	glEnable(GL_TEXTURE);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR); //!

	glTexParameteri(GL_TEXTURE, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glPushMatrix();
	glScalef(1, 0.5, 1);
	glTranslatef(0, 0.5, 0);

	img.bind();
	glNormal3f(0, -1, 0);
	glBegin(GL_QUADS);

	//lado 1

	glTexCoord2f(0.63, 0.05);
	glVertex3f(p/2, -p, -p/2);
	glTexCoord2f(0.41, 0.05);
	glVertex3f(p/2, -p, p/2);
	glTexCoord2f(0.05, 0.9);
	glVertex3f(p, p, p);
	glTexCoord2f(0.9, 0.9);
	glVertex3f(p, p, -p);

	glEnd();

	glBegin(GL_QUADS);

	//lado 2
	glTexCoord2f(0.63, 0.05);
	glVertex3f(p/2, -p, p/2);
	glTexCoord2f(0.41, 0.05);
	glVertex3f(-p/2, -p, p/2);
	glTexCoord2f(0.05, 0.9);
	glVertex3f(-p, p, p);
	glTexCoord2f(0.9, 0.9);
	glVertex3f(p, p, p);

	glEnd();

	
	glBegin(GL_QUADS);

	//lado 3
	glTexCoord2f(0.63, 0.05);
	glVertex3f(-p/2, -p, p/2);
	glTexCoord2f(0.41, 0.05);
	glVertex3f(-p/2, -p, -p/2);
	glTexCoord2f(0.05, 0.9);
	glVertex3f(-p, p, -p);
	glTexCoord2f(0.9, 0.9);
	glVertex3f(-p, p, p);

	glEnd();

	glBegin(GL_QUADS);

	//lado 4
	glTexCoord2f(0.63, 0.05);
	glVertex3f(-p/2, -p, -p/2);
	glTexCoord2f(0.41, 0.05);
	glVertex3f(p/2, -p, -p/2);
	glTexCoord2f(0.05, 0.9);
	glVertex3f(p, p, -p);
	glTexCoord2f(0.9, 0.9);
	glVertex3f(-p, p, -p);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(p/2, -p, -p/2);
	glVertex3f(-p/2, -p, -p/2);
	glVertex3f(-p/2, -p, p/2);
	glVertex3f(p/2, -p, p/2);

	glEnd();

	glPopMatrix();

	app.image("frente").unbind();
	glDisable(GL_TEXTURE);


	glScalef(0.3, 0.18, 0.3);
	glTranslatef(0, -0.5, 0);
	glRotatef(90, 1, 0, 0);
	cube_malha_unit(1, 1, cubo);

	/*
	//frente
	glBegin(GL_QUADS);
	glVertex3f(p, p, p);
	glVertex3f(-p, p, p);
	glVertex3f(-p, p, -p);
	glVertex3f(p, p, -p);
	glEnd();
	*/
}

inline void sphereSkyBox(int res) {
	float dtheta = PI / float(res);
	float dphi = 2 * PI / float(res);



	for (int i = 0; i < res; i++) {
		for (int j = 0; j < res; j++) {
			glBegin(GL_QUADS);

			float x1 = sin(i * dtheta) * cos(j * dphi);
			float y1 = sin(i * dtheta) * sin(j * dphi);
			float z1 = cos(i * dtheta);
			float tx1 = i / float(res);
			float ty1 = j / float(res);
			ofVec3f n1 = ofVec3f(-x1, -y1, -z1);
			glTexCoord2f(ty1, tx1);
			glNormal3f(n1.x, n1.y, n1.z);
			glVertex3f(x1, y1, z1);

			float x2 = sin(i * dtheta) * cos((j + 1) * dphi);
			float y2 = sin(i * dtheta) * sin((j + 1) * dphi);
			float z2 = cos(i * dtheta);
			float tx2 = i / float(res);
			float ty2 = (j + 1) / float(res);
			ofVec3f n2 = ofVec3f(-x2, -y2, -z2);
			glTexCoord2f(ty2, tx2);
			glNormal3f(n2.x, n2.y, n2.z);
			glVertex3f(x2, y2, z2);

			float x3 = sin((i + 1) * dtheta) * cos((j + 1) * dphi);
			float y3 = sin((i + 1) * dtheta) * sin((j + 1) * dphi);
			float z3 = cos((i + 1) * dtheta);
			float tx3 = (i + 1) / float(res);
			float ty3 = (j + 1) / float(res);
			ofVec3f n3 = ofVec3f(-x3, -y3, -z3);
			glTexCoord2f(ty3, tx3);
			glNormal3f(n3.x, n3.y, n3.z);
			glVertex3f(x3, y3, z3);

			float x4 = sin((i + 1) * dtheta) * cos(j * dphi);
			float y4 = sin((i + 1) * dtheta) * sin(j * dphi);
			float z4 = cos((i + 1) * dtheta);
			float tx4 = (i + 1) / float(res);
			float ty4 = j / float(res);
			ofVec3f n4 = ofVec3f(-x4, -y4, -z4);
			glTexCoord2f(ty4, tx4);
			glNormal3f(n4.x, n4.y, n4.z);
			glVertex3f(x4, y4, z4);

			glEnd();
		}
	}
}

inline void cubeSkyBox() {
	glBegin(GL_QUADS);

	glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
	glTexCoord2f(1, 0); glVertex3f(1, -1, -1);
	glTexCoord2f(1, 1); glVertex3f(1, 1, -1);
	glTexCoord2f(0, 1); glVertex3f(-1, 1, -1);

	glTexCoord2f(1, 0); glVertex3f(-1, -1, 1);
	glTexCoord2f(1, 1); glVertex3f(-1, 1, 1);
	glTexCoord2f(0, 1); glVertex3f(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(1, -1, 1);

	glTexCoord2f(0, 1); glVertex3f(-1, -1, -1);
	glTexCoord2f(0, 0); glVertex3f(-1, 1, -1);
	glTexCoord2f(1, 0); glVertex3f(-1, 1, 1);
	glTexCoord2f(1, 1); glVertex3f(-1, -1, 1);

	glTexCoord2f(1, 1); glVertex3f(1, -1, -1);
	glTexCoord2f(0, 1); glVertex3f(1, -1, 1);
	glTexCoord2f(0, 0); glVertex3f(1, 1, 1);
	glTexCoord2f(1, 0); glVertex3f(1, 1, -1);

	glTexCoord2f(0, 1); glVertex3f(-1, 1, -1);
	glTexCoord2f(1, 1); glVertex3f(1, 1, -1);
	glTexCoord2f(1, 0); glVertex3f(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(-1, 1, 1);

	glTexCoord2f(1, 1); glVertex3f(-1, -1, -1);
	glTexCoord2f(1, 0); glVertex3f(-1, -1, 1);
	glTexCoord2f(0, 0); glVertex3f(1, -1, 1);
	glTexCoord2f(0, 1); glVertex3f(1, -1, -1);

	glEnd();
}


