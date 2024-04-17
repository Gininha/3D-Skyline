#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	glEnable(GL_DEPTH_TEST);
	ofBackground(0.05, 0.05, 0.05);
	glLineWidth(5);

	//view
	topView = false;
	view = 1;

	//floor parameters
	floorWidth = gw() * 0.15;
	floorHeight = gw() * 0.15;
	floorHeightPos = 0.;//gh() * 0.75;
	chao = Apartamento("none", "chao.jpg", "none", "none", "none", 3);

	//apps parameters
	appWidth = floorWidth * 0.45;
	appHeight = floorHeight * 0.35;
	appHeightPos = 2 * appWidth;

	//block_1
	appWidth_pred_1 = appWidth * 1.5;
	appHeight_pred_1 = appHeight * 1.5;
	appHeightPos_pred_1 = appWidth * 2.5;
	app_block1_esq = Apartamento("madeira.png", "madeira.png", "madeira.png", "madeira.png", "madeira.png", 0);
	//---- 
	appWidth_pred_2 = appWidth * 2.6;
	appHeight_pred_2 = appHeight;
	appHeightPos_pred_2 = appWidth * 1.5;
	app_block1_dir = Apartamento("lateral_appblock_1.jpg", "teto_appblock_1.png", "lateral_appblock_1.jpg", "lateral_appblock_1.jpg", "frente_appblock_1.png", 1);

	//block_2
	appWidth_pred_3 = appWidth * 1.3;
	appHeight_pred_3 = appHeight * 2;
	appHeightPos_pred_3 = appWidth * 2;
	app_block2_centro = Apartamento("block_2_frente.png", "block_2_teto.png", "none", "none", "block_2_lado.png", 7);
	//---- 
	appWidth_pred_4 = floorWidth;
	appHeight_pred_4 = appHeight_pred_3 * 0.6;
	appHeightPos_pred_4 = appHeightPos_pred_3 * 0.75;
	app_block2_lado = Apartamento("block_2_apps_lado.png", "block_2_teto_lateral.png", "block2_laterais.png", "block2_laterais.png", "block2_laterais.png", 7);

	//factory
	appWidth_fac_1 = floorWidth;
	appHeight_fac_1 = floorHeight;
	appHeightPos_fac_1 = floorWidth * 1.2;
	appWidth_fac_2 = floorWidth * 0.4;
	appHeight_fac_2 = floorHeight * 1.5;
	appHeightPos_fac_2 = 0.6 * appHeightPos_fac_1;
	appWidth_fac_3 = floorWidth * 0.8;
	appHeight_fac_3 = floorHeight * 0.8;
	appHeightPos_fac_3 = floorWidth * 1.;
	appWidth_fac_4 = floorWidth * 1.2;
	appHeight_fac_4 = floorHeight * 1.2;
	appHeightPos_fac_4 = floorWidth * 1.4;
	appWidth_fac_5 = floorWidth * 0.7;
	appHeight_fac_5 = floorHeight;
	appHeightPos_fac_5 = floorWidth * 1.3;
	Width_chamine = floorWidth * 0.35;
	Height_chamine = floorHeight * 0.35;
	HeightPos_chamine = floorWidth * 0.45;
	Width_smoke = floorWidth * 0.1;
	Height_smoke = floorWidth * 0.1;
	HeightPos_smoke = floorWidth * 0.1;
	subida1 = 0;
	subida2 = 0;
	subida3 = 0;

	block_fabrica = Apartamento("torres_fabrica.png", "teto_torres_fabrica.png", "torres_fabrica.png", "torres_fabrica.png", "torres_fabrica.png", 3);
	block_fabrica2 = Apartamento("torres_fabrica.png", "teto_torres_fabrica.png", "torres_fabrica.png", "torres_fabrica.png", "torres_fabrica.png", 3);
	muro_fabrica = Apartamento("none", "teto_muro_fabrica.png", "none", "muro_fabrica.png", "none", 0);
	bloco_fabrica_tras = Apartamento("principal_fabrica.png", "teto_principal_fabrica.png", "principal_fabrica.png", "principal_fabrica.png", "portao_fabrica.png", 1);
	bloco_fabrica_tras_2 = Apartamento("principal_fabrica.png", "teto_principal_fabrica.png", "principal_fabrica.png", "principal_fabrica.png", "principal_fabrica.png", 1);
	chamine = Apartamento("chamine.png", "teto_chamine_fabrica.png", "chamine.png", "chamine.png", "chamine.png", 2);
	smoke = Apartamento("none", "none", "none", "none", "none", 8);

	//Center light
	
	//stick
	stickWidth = gh() * 0.015;
	stickHeight = gh() * 0.015;
	stickHeightPos = gh() * 0.03;

	stick = Apartamento("none", "none", "none", "none", "none", 2);

	//light source
	lightsourceWidth = stickWidth * 2;
	lightsourceHeight = stickHeight * 2;
	lightsourceHeightPos = stickHeightPos * 1.3;

	lantern = Apartamento("none", "none", "none", "none", "none", 6);

	//car
	carWidth = lightsourceWidth * 2;
	carHeight = lightsourceHeight;
	carHeightPos = lightsourceHeightPos;
	car_x_pos = 0;
	car_y_pos = floorHeight * 0.5;
	caso = 0;

	carro = Apartamento("none", "none", "none", "none", "none", 4);
	roda = Apartamento("none", "none", "none", "none", "none", 5);

	// Different forms

	// frente, cima, esquerda, direita, tras;
	
	triangle = Apartamento("lateral_piramide.png", "none", "lateral_piramide.png", "lateral_piramide.png", "lateral_piramide.png", 3);
	cubo_piramide = Apartamento("cubo_piramide.png", "none", "cubo_piramide.png", "cubo_piramide.png", "cubo_piramide.png", 3);
	u_unit_10 = Apartamento("u_unit_porta.png", "u_unit_teto.png", "u_unit_lateral.png", "u_unit_lateral.png", "u_unit_lateral.png", 3);
	u_unit_4 = Apartamento("u_unit2_porta.png", "u_unit_teto.png", "u_unit2_lateral.png", "u_unit2_lateral.png", "u_unit2_lateral.png", 3);

	//camera
	lensAngle = 60;
	alpha = 10;
	beta = 1000;

	//Experiment
	rotate = 0;
	user_rotation_z = 0;
	user_rotation_y = 0;


	// Luzes

	pontual = true;
	direcional = true;
	foco = true;
	poste = true;
	auto_move_d = true;
	sun_up = true;
	ambient = true;
	difuse = true;
	specular = true;
	pointZtheta = 0;
	dirVecTheta = 0.;
	pointPos[0] = 0;

	/////////////////////////////////////////

	dirAmb[0] = 0.2;//R
	dirAmb[1] = 0.2;//G
	dirAmb[2] = 0.2;//B
	dirAmb[3] = 1.;//constante

	dirDif[0] = 0.8;//R
	dirDif[1] = 0.8;//G
	dirDif[2] = 0.8;//B
	dirDif[3] = 1.;//constante

	dirSpec[0] = 0.8;//R
	dirSpec[1] = 0.8;//G
	dirSpec[2] = 0.8;//B
	dirSpec[3] = 1.;//constante

	/////////////////////////////////////////

	pointAmb[0] = 0.5;//R
	pointAmb[1] = 0.;//G
	pointAmb[2] = 0.;//B
	pointAmb[3] = 1.;//constante

	pointDif[0] = 1.;//R
	pointDif[1] = 0.;//G
	pointDif[2] = 0.;//B
	pointDif[3] = 1.;//constante

	pointSpec[0] = 1.;//R
	pointSpec[1] = 0.;//G
	pointSpec[2] = 0.;//B
	pointSpec[3] = 1.;//constante

	/////////////////////////////////////////

	focAmb[0] = 0.5;//R
	focAmb[1] = 0.5;//G
	focAmb[2] = 0.;//B
	focAmb[3] = 1.;//constante

	focDif[0] = 1.;//R
	focDif[1] = 1.;//G
	focDif[2] = 0.;//B
	focDif[3] = 1.;//constante

	focSpec[0] = 1.;//R
	focSpec[1] = 1.;//G
	focSpec[2] = 0.;//B
	focSpec[3] = 1.;//constante

	/////////////////////////////////////////

	posteAmb[0] = 0.9;//R
	posteAmb[1] = 0.4;//G
	posteAmb[2] = 0.;//B
	posteAmb[3] = 1.;//constante

	posteDif[0] = 1.;//R
	posteDif[1] = 0.5;//G
	posteDif[2] = 0.;//B
	posteDif[3] = 1.;//constante

	posteSpec[0] = 1.;//R
	posteSpec[1] = 0.5;//G
	posteSpec[2] = 0.;//B
	posteSpec[3] = 1.;//constante

	/////////////////////////////////////////
	

	pos.x = -3 * floorWidth + appWidth_fac_4 * 0.5;
	pos.y = -20;
	pos.z = appHeightPos_fac_4 - 10;

	// Texturas
	ofDisableArbTex();
	normalMap.load("normal.jpg");
	normalPixels = normalMap.getPixels();

	px = 128;
	py = 128;

	sky.allocate(px, py, OF_IMAGE_COLOR);
	skyPixels = new unsigned char[px * py * 3];

	for (int i = 0; i < 10; i++) {
		freqs[i] = 0.25 + 0.25 * i * 5;
		amps[i] = 1. / (i * 0.25 + 1);
	}
	phaseX = 0.;
	phaseY = 0.;

	nightSkyImg.load("night.png");
}

//--------------------------------------------------------------
void ofApp::update(){
	
	rotate += 1;

	car_x_pos = cos(rotate * PI / 180.) * floorWidth;
	car_y_pos = sin(rotate * PI / 180.) * floorWidth;

	if (car_x_pos > floorWidth)
		car_x_pos = floorWidth;

	if (car_x_pos < -floorWidth)
		car_x_pos = -floorWidth;

	if (car_y_pos > floorWidth * 0.5)
		car_y_pos = floorWidth * 0.5;

	if (car_y_pos < -floorWidth * 0.5)
		car_y_pos = -floorWidth * 0.5;

	subida1 += 0.05;
	subida2 += 0.05;
	subida3 += 0.02;

	if (subida1 > HeightPos_chamine * 0.3)
		subida1 = 0;
	if (subida2 > HeightPos_chamine * 0.2)
		subida2 = 0;
	if (subida3 > HeightPos_chamine * 0.1)
		subida3 = 0;

	if (auto_move_d) {
		float z = gh() * (cos(dirVecTheta * PI / 180.));
		float y = gh() * 0.7 * (sin(dirVecTheta * PI / 180.));
		float x = gh() * 0.7 * (sin(dirVecTheta * PI / 180.));
		dirVec3f = ofVec3f(x, y, z) - ofVec3f(0, 0, 0);
		dirVecTheta += 0.5;
		if (z < 0)
			sun_up = false;
		else
			sun_up = true;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){


	glPushMatrix();//master push

	if (!topView) {

		switch (view) {
		case 1:
			cams(1);

			glPushMatrix();
			lookat(gw() * 0.75, -gw() * 0.75, gw() * 0.15, 0, 0, 0, 0, 0, 1);
			glRotatef(user_rotation_y, 1, 1, 0);
			glRotatef(user_rotation_z, 0, 0, 1);
			draw_full_cene();
			glPopMatrix();
			break;

		case 2:

			cams(2);

			glPushMatrix();
			lookat(0, 0, gw() * 1.2, 0, 0, 0, 0, 1, 0);
			draw_full_cene();
			glPopMatrix();
			break;

		case 3:

			cams(3);

			glPushMatrix();
			lookat(0, -gw() * 0.25, 0, 0, 0, 0, 0, 0, 1);
			glRotatef(rotate, 0, 0, 1);
			draw_full_cene();
			glPopMatrix();
			break;

		default:
			break;
		}
	}
	else {
		cams(4);
		lookat(gw() * 0.8, 0, gw() * 0.3, 0, 0, 0, 0, 0, 1);
		draw_full_cene();
	}

	glPopMatrix();	//Master pop



}
//--------------------------------------------------------------
void ofApp::cams(int cam) {

	if (cam == 1) {
		glViewport(0, 0, gw(), gh());
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		perspective(lensAngle, alpha, beta, true, false);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	else {
		if (cam == 2) {
			glViewport(0, 0, gw(), gh());
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(-gw(), gw(), -gh(), gh(), -10000, 10000);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}
		else {
			if (cam == 3) {
				glViewport(0, 0, gw(), gh());
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				glOrtho(-gw(), gw(), -gh(), gh(), -10000, 10000);
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
			}
			else {
				glViewport(0, 0, gw(), gh());
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				glOrtho(-gw(), gw(), -gh(), gh(), -10000, 10000);
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
			}
		}
	}
}
//--------------------------------------------------------------
void ofApp::draw_full_cene() {

	sky_box();

	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, true);
	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
	//glEnable(GL_COLOR_MATERIAL);

	directional_light();

	glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	glGetFloatv(GL_MODELVIEW_MATRIX, init_Matriz);

	//floor
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();//floor push
	glScalef(8 * floorWidth, 4 * floorHeight, 1.);
	glMaterialfv(GL_FRONT, GL_AMBIENT, chao.amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, chao.dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, chao.spec);
	glMaterialf(GL_FRONT, GL_SHININESS, chao.shine);
	floor_unit(100, 100, chao.image("cima"));
	glPopMatrix();//floor pop

	//Apps

	glPushMatrix(); //appBlock1
	glTranslatef(floorWidth * 0.5, floorHeight * 1.5, appHeightPos_pred_1 * 0.5);
	app_block_1();
	glPopMatrix(); //appBlock1

	glPushMatrix(); //appBlock2
	glTranslatef(0, -floorHeight * 1.5, appWidth);
	app_block_2();
	glPopMatrix(); //appBlock2

	glPushMatrix(); //U block
	glTranslatef(floorWidth * 2, -floorHeight * 1.35, appHeightPos * 1.3 * 0.5);
	glScalef(appWidth * 1.3, appHeight * 1.3, appHeightPos * 1.3);
	u_unit(10, 0.5, u_unit_10);
	glPopMatrix(); //U block

	glColor3f(150. / 255, 75. / 255, 0);
	glPushMatrix(); //Piramide block
	glTranslatef(floorWidth * 2, floorHeight * 1.35, appHeightPos * 1.3 * 0.5);
	glScalef(appWidth * 2.3, appHeight * 2.3, appHeightPos * 1.3);
	glRotatef(-90, 1, 0, 0);
	egypt(triangle, cubo_piramide);
	glPopMatrix(); //Piramide block

	glPushMatrix(); //U block
	glTranslatef(floorWidth * 3.2, 0, appHeightPos * 1.3 * 0.5);

	glPushMatrix();
	glTranslatef(0, floorHeight, -(appHeightPos * 1.3 * 0.5) + stickHeightPos * 2.5);
	glScalef(stickWidth, stickHeight, stickHeightPos * 5);
	cube_malha_unit(1, 1, app_block1_esq);
	glPopMatrix();

	glScalef(appWidth * 1.3, appHeight * 1.3, appHeightPos * 1.3);
	glRotatef(75, 0, 0, 1);
	u_unit(6, 0.9, u_unit_4);
	glPopMatrix(); //U block

	glPushMatrix(); //factory
	glTranslatef(-floorWidth * 2., 0, 0);
	factory();
	glPopMatrix(); //factory

	// Fim Apps

	center_light();

	draw_car();

	glDisable(GL_LIGHTING);

	if (direcional) {
		glColor3f(1, 1, 1);
		glPushMatrix();
		glTranslatef(dirVec3f.x, dirVec3f.y, dirVec3f.z);
		glScalef(30, 30, 30);
		cube_unit();
		glPopMatrix();
	}

	if (pontual) {
		glColor3f(1, 0, 0);
		glPushMatrix();
		glTranslatef(-3 * floorWidth - 10 + appWidth_fac_4 * 0.5, -20, appHeightPos_fac_4-10);
		glScalef(20, 20, 20);
		cube_unit();
		glPopMatrix();
	}

	if (poste) {
		glColor3f(1, 0.5, 0);
		glPushMatrix();
		glTranslatef(3 * floorWidth + 20, floorHeight-8, stickHeightPos * 5);
		glRotatef(125, 0, 0, 1);
		glRotatef(-15, 1, 0, 0);
		glScalef(lightsourceWidth, lightsourceHeight, lightsourceHeightPos);
		triangle_unit(lantern);
		glPopMatrix();
	}
	
}
//--------------------------------------------------------------
void ofApp::sky_box() {
	if (!sun_up) {
		
		glEnable(GL_TEXTURE);
		nightSkyImg.bind();
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		glColor4f(1, 1, 1, 1);
		glPushMatrix();
		glScalef(gw() * 50, gw() * 50, gw() * 50);
		sphereSkyBox(64);
		glPopMatrix();


		nightSkyImg.unbind();
		glDisable(GL_TEXTURE);
	}
	else {

		phaseX += 0.0005 * cos(dirVecTheta * 0.001);
		phaseY -= 0.0006 * cos(dirVecTheta * 0.0001);

		skyPixels = sky.getPixels().getData();

		ofColor A(0, 30, 180);
		ofColor B(255, 255, 255);

		for (int j = 0; j < py; j++) {
			for (int i = 0; i < px; i++) {
				int index = 3 * (j * px + i);
				float noise = getMultiNoise(0.008 * (i)+phaseX, 0.008 * (j)+phaseY, freqs, amps, 10);
				ofColor auxColor = A.getLerped(B, noise);
				skyPixels[index] = auxColor.r;
				skyPixels[index + 1] = auxColor.g;
				skyPixels[index + 2] = auxColor.b;
			}
		}
		sky.setFromPixels(skyPixels, px, py, OF_IMAGE_COLOR);
		sky.update();

		glEnable(GL_TEXTURE);
		sky.bind();
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		glColor3f(1, 1, 1);
		glPushMatrix();
		glScalef(gw() * 50, gw() * 50., gw() * 50.);
		ofDrawSphere(1);
		glPopMatrix();


		sky.unbind();
		glDisable(GL_TEXTURE);
	}

}
//--------------------------------------------------------------
void ofApp::directional_light() {
	
	//luz direcional
	dirVec[0] = dirVec3f.x;
	dirVec[1] = dirVec3f.y;
	dirVec[2] = dirVec3f.z;
	dirVec[3] = 0;

	glLightfv(GL_LIGHT0, GL_POSITION, dirVec);
	glLightfv(GL_LIGHT0, GL_AMBIENT, dirAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, dirDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, dirSpec);

	if (direcional) {
		glEnable(GL_LIGHT0);
	}
	else {
		glDisable(GL_LIGHT0);
	}
	
	if(!sun_up)
		glDisable(GL_LIGHT0);
	
	////////////////////////////////////

	pointPos[0] = pos.x;
	pointPos[1] = pos.y;
	pointPos[2] = pos.z;
	pointPos[3] = 1;//ponto - posição!
	

	glLightfv(GL_LIGHT1, GL_POSITION, pointPos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, pointAmb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, pointDif);
	glLightfv(GL_LIGHT1, GL_SPECULAR, pointSpec);
	
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.0001);
	
	if (pontual) {
		glEnable(GL_LIGHT1);
	}
	else {
		glDisable(GL_LIGHT1);
	}

	////////////////////////////////////

	// luz de foco
	focPos[0] = 0;
	focPos[1] = 0;
	focPos[2] = stickHeightPos;
	focPos[3] = 1;

	glm::vec3 direction(cos(((rotate)*PI) / 180), sin(((rotate)*PI) / 180), 0);
	direction = glm::normalize(direction);

	focDir[0] = direction.x;
	focDir[1] = direction.y;
	focDir[2] = direction.z;

	GLfloat spotCutoff = 40.0f;
	GLfloat spotExponent = 8.0f;

	glLightfv(GL_LIGHT2, GL_POSITION, focPos);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, focDir);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, spotCutoff);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, spotExponent);
	glLightfv(GL_LIGHT2, GL_AMBIENT, focAmb);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, focDif);
	glLightfv(GL_LIGHT2, GL_SPECULAR, focSpec);

	if (foco) {
		glEnable(GL_LIGHT2);
	}
	else {
		glDisable(GL_LIGHT2);
	}

	////////////////////////////////////

	postePos[0] = 3 * floorWidth + 20;
	postePos[1] = floorHeight - 8;
	postePos[2] = stickHeightPos * 5;
	postePos[3] = 1;

	glm::vec3 direction2(cos(((210)*PI) / 180), sin(((210)*PI) / 180), 0);
	direction = glm::normalize(direction2);

	posteDir[0] = direction.x;
	posteDir[1] = direction.y;
	posteDir[2] = direction.z;

	glLightfv(GL_LIGHT3, GL_POSITION, postePos);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, posteDir);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, spotCutoff);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, spotExponent);
	glLightfv(GL_LIGHT3, GL_AMBIENT, posteAmb);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, posteDif);
	glLightfv(GL_LIGHT3, GL_SPECULAR, posteSpec);

	if (poste) {
		glEnable(GL_LIGHT3);
	}
	else {
		glDisable(GL_LIGHT3);
	}

}
//--------------------------------------------------------------
void ofApp::factory() {

	glColor3f(0, 0, 0.55);
	glPushMatrix();	//block 1
	glTranslatef(0, -appHeight_fac_1 * 0.5 - appHeight_fac_2 * 0.5, appHeightPos_fac_1 * 0.5);
	glScalef(appWidth_fac_1, appHeight_fac_1, appHeightPos_fac_1);
	cube_malha_unit(4, 4, block_fabrica);
	glPopMatrix();

	glColor3f(1, 1, 0);
	glPushMatrix();	//corridor
	glTranslatef(0, 0, appHeightPos_fac_2 * 0.5);
	glScalef(appWidth_fac_2, appHeight_fac_2, appHeightPos_fac_2);
	cube_malha_unit(3, 3, muro_fabrica);
	glPopMatrix();

	glColor3f(0, 0, 0.55);
	glPushMatrix();	//block2
	glTranslatef(0, appHeight_fac_2 * 0.5 + appHeight_fac_3 * 0.5, appHeightPos_fac_3 * 0.5);
	glScalef(appWidth_fac_3, appHeight_fac_3, appHeightPos_fac_3);
	cube_malha_unit(4, 4, block_fabrica2);
	glPopMatrix();

	glPushMatrix();	//block3 behind
	glTranslatef(-appWidth_fac_1 * 0.5 - appWidth_fac_4 * 0.5, -appHeight_fac_4 * 0.5, appHeightPos_fac_4 * 0.5);
	glPushMatrix();//CHAMINE
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, 0, HeightPos_chamine * 0.5 + appHeightPos_fac_4 * 0.5);
	glPushMatrix();//FUmo

	glPushMatrix();
	glTranslatef(-Width_chamine * 0.3, -Height_chamine * 0.3, -HeightPos_chamine * 0.5);
	fumo(1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(Width_chamine * 0.3, Height_chamine * 0.3, -HeightPos_chamine * 0.2);
	fumo(1, 2);
	glPopMatrix();

	glPushMatrix();
	fumo(2, 3);
	glPopMatrix();

	glPopMatrix();
	glColor3f(1, 1, 0);
	glScalef(Width_chamine, Height_chamine, HeightPos_chamine);
	cube_malha_unit(1, 1, chamine);
	glPopMatrix();
	glScalef(appWidth_fac_4, appHeight_fac_4, appHeightPos_fac_4);
	glColor3f(165./255, 42. / 255, 42. / 255);
	cube_malha_unit(4, 4, bloco_fabrica_tras);
	glPopMatrix();

	glPushMatrix();	//block4 behind
	glTranslatef(-appWidth_fac_5 * 0.5 - appWidth_fac_3 * 0.5, appHeight_fac_5 * 0.5, appHeightPos_fac_5 * 0.5);
	glScalef(appWidth_fac_5, appHeight_fac_5, appHeightPos_fac_5);
	glColor3f(165. / 255, 42. / 255, 42. / 255);
	cube_malha_unit(4, 4, bloco_fabrica_tras_2);
	glPopMatrix();


}
//--------------------------------------------------------------
void ofApp::fumo(int tam, int tipo) {
	glScalef(tam * Width_smoke, tam * Height_smoke, tam * HeightPos_smoke);
	if(tipo == 1)
		glTranslatef(0, 0, subida1);
	if (tipo == 2)
		glTranslatef(0, 0, subida2);
	if (tipo == 3)
		glTranslatef(0, 0, subida3);

	cube_malha_unit(1, 1, smoke);
}
//--------------------------------------------------------------
void ofApp::center_light() {

	glPushMatrix(); //Center light

	glTranslatef(0, 0, stickHeightPos * 0.5);

	glColor3f(1, 0.5, 0);
	glPushMatrix(); //stick
	glScalef(stickWidth, stickHeight, stickHeightPos);
	cube_malha_unit(1, 1, stick);
	glPopMatrix();	//stick

	if (foco) {
		glDisable(GL_LIGHTING);
	}

	glColor3f(1, 1, 0);
	glPushMatrix();	//lantern
	glRotatef(rotate - 90, 0, 0, 1);
	glTranslatef(0, lightsourceHeight * 0.5, stickHeightPos * 0.5);
	glScalef(lightsourceWidth, lightsourceHeight, lightsourceHeightPos);
	triangle_unit(lantern);
	if (foco) {
		glEnable(GL_LIGHTING);
	}
	glPopMatrix();	//lantern

	glPopMatrix();	//Center light

}

//--------------------------------------------------------------
void ofApp::draw_car() {

	glColor3f(1, 0, 0);
	glPushMatrix();	//Car

	glTranslatef(car_x_pos, car_y_pos, 0);

	glPushMatrix();
	glTranslatef(0, 0, carHeightPos * 0.5);
	glScalef(carWidth, carHeight, carHeightPos);
	cube_malha_unit(1, 1, carro);
	glPopMatrix();

	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(carWidth * 0.3, carHeight * 0.4, carHeightPos * 0.25);
	glScalef(carWidth / 4, carHeight / 2, carHeightPos / 2);
	cube_malha_unit(1, 1, roda);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-carWidth * 0.3, -carHeight * 0.4, carHeightPos * 0.25);
	glScalef(carWidth / 4, carHeight / 2, carHeightPos / 2);
	cube_malha_unit(1, 1, roda);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-carWidth * 0.3, carHeight * 0.4, carHeightPos * 0.25);
	glScalef(carWidth / 4, carHeight / 2, carHeightPos / 2);
	cube_malha_unit(1, 1, roda);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(carWidth * 0.3, -carHeight * 0.4, carHeightPos * 0.25);
	glScalef(carWidth / 4, carHeight / 2, carHeightPos / 2);
	cube_malha_unit(1, 1, roda);
	glPopMatrix();


	glPopMatrix();	//Car

}

//--------------------------------------------------------------
void ofApp::app_block_2() {

	glPushMatrix();
	glTranslatef(0, -appHeight_pred_4 * 0.2, -appWidth + appHeightPos_pred_4 * 0.5);
	glScalef(appWidth_pred_4, appHeight_pred_4, appHeightPos_pred_4);
	cube_malha_unit(3, 3, app_block2_centro);
	glPopMatrix();

	glColor3f(0, 0, 1);
	glPushMatrix();
	glTranslatef(floorWidth * 0.5 + appWidth_pred_3 * 0.5, 0, 0);
	glScalef(appWidth_pred_3, appHeight_pred_3, appHeightPos_pred_3);
	cube_malha_unit(5, 5, app_block2_lado);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-floorWidth * 0.5 - appWidth_pred_3 * 0.5, 0, 0);
	glScalef(appWidth_pred_3, appHeight_pred_3, appHeightPos_pred_3);
	cube_malha_unit(5, 5, app_block2_lado);
	glPopMatrix();

}
//--------------------------------------------------------------
void ofApp::app_block_1() {

	glColor3f(0, 1, 0);
	glPushMatrix();
	glScalef(appWidth_pred_1, appHeight_pred_1, appHeightPos_pred_1);
	cube_malha_unit(5, 5, app_block1_dir);
	glPopMatrix();

	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(-appWidth_pred_2 * 0.5 - appWidth_pred_1 * 0.5, 0, appHeightPos_pred_2 * 0.5 - appHeightPos_pred_1 * 0.5);
	glScalef(appWidth_pred_2, appHeight_pred_2, appHeightPos_pred_2);
	cube_malha_unit(5, 3, app_block1_esq);
	glPopMatrix();

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case '1':
		glDisable(GL_CULL_FACE);
		break;
	case '2':
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		break;
	case '3':
		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);
		break;
	case '4':
		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT_AND_BACK);
		break;
	case '5':
		if (ambient) {
			dirAmb[0] = 0.0f;
			dirAmb[1] = 0.0f;
			dirAmb[2] = 0.0f;
			dirAmb[3] = 1.0f;

			pointAmb[0] = 0.0f;
			pointAmb[1] = 0.0f;
			pointAmb[2] = 0.0f;
			pointAmb[3] = 1.0f;

			focAmb[0] = 0.0f;
			focAmb[1] = 0.0f;
			focAmb[2] = 0.0f;
			focAmb[3] = 1.0f;

			posteAmb[0] = 0.0f;
			posteAmb[1] = 0.0f;
			posteAmb[2] = 0.0f;
			posteAmb[3] = 1.0f;

			ambient = !ambient;
		}else{
			dirAmb[0] = 0.2;
			dirAmb[1] = 0.2;
			dirAmb[2] = 0.2;
			dirAmb[3] = 1.;

			pointAmb[0] = 0.5;
			pointAmb[1] = 0.;
			pointAmb[2] = 0.;
			pointAmb[3] = 1.;

			focAmb[0] = 0.5;
			focAmb[1] = 0.5;
			focAmb[2] = 0.;
			focAmb[3] = 1.;

			posteAmb[0] = 0.9;
			posteAmb[1] = 0.4;
			posteAmb[2] = 0.;
			posteAmb[3] = 1.;

			ambient = !ambient;
		}
		break;
	case '6':
		if (difuse) {
			dirDif[0] = 0.0f;
			dirDif[1] = 0.0f;
			dirDif[2] = 0.0f;
			dirDif[3] = 1.0f;

			pointDif[0] = 0.0f;
			pointDif[1] = 0.0f;
			pointDif[2] = 0.0f;
			pointDif[3] = 1.0f;

			focDif[0] = 0.0f;
			focDif[1] = 0.0f;
			focDif[2] = 0.0f;
			focDif[3] = 1.0f;

			posteDif[0] = 0.0f;
			posteDif[1] = 0.0f;
			posteDif[2] = 0.0f;
			posteDif[3] = 1.0f;

			difuse = !difuse;
		}
		else {
			dirDif[0] = 0.8;
			dirDif[1] = 0.8;
			dirDif[2] = 0.8;
			dirDif[3] = 1.;

			pointDif[0] = 1;
			pointDif[1] = 0.;
			pointDif[2] = 0.;
			pointDif[3] = 1.;

			focDif[0] = 1;
			focDif[1] = 1;
			focDif[2] = 0.;
			focDif[3] = 1.;

			posteDif[0] = 1;
			posteDif[1] = 0.5;
			posteDif[2] = 0.;
			posteDif[3] = 1.;

			difuse = !difuse;
		}
		break;
	case '7':
		if (specular) {
			dirSpec[0] = 0.0f;
			dirSpec[1] = 0.0f;
			dirSpec[2] = 0.0f;
			dirSpec[3] = 1.0f;

			pointSpec[0] = 0.0f;
			pointSpec[1] = 0.0f;
			pointSpec[2] = 0.0f;
			pointSpec[3] = 1.0f;

			focSpec[0] = 0.0f;
			focSpec[1] = 0.0f;
			focSpec[2] = 0.0f;
			focSpec[3] = 1.0f;

			posteSpec[0] = 0.0f;
			posteSpec[1] = 0.0f;
			posteSpec[2] = 0.0f;
			posteSpec[3] = 1.0f;

			specular = !specular;
		}
		else {
			dirSpec[0] = 1;
			dirSpec[1] = 1;
			dirSpec[2] = 1;
			dirSpec[3] = 1.;

			pointSpec[0] = 1;
			pointSpec[1] = 0.2;
			pointSpec[2] = 0.2;
			pointSpec[3] = 1.;

			focSpec[0] = 1;
			focSpec[1] = 1;
			focSpec[2] = 0.2;
			focSpec[3] = 1.;

			posteSpec[0] = 1;
			posteSpec[1] = 0.7;
			posteSpec[2] = 0.;
			posteSpec[3] = 1.;

			specular = !specular;
		}
		break;
	case 'g':
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	case 'f':
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;
	case 't':
		topView = !topView;
		break;
	case 'a' :
		user_rotation_z += 1.5;
		break;
	case 'd' :
		user_rotation_z -= 1.5;
		break;
	case 'w':
		user_rotation_y += 1.5;
		if (user_rotation_y >= 90) {
			user_rotation_y = 90;
		}
		break;
	case 's':
		user_rotation_y -= 1.5;
		if (user_rotation_y <= 0) {
			user_rotation_y = 0;
		}
		break;
	case 'm':
		auto_move_d = !auto_move_d;
		//direcional = !direcional;
		break;
	case 'p':
		pontual = !pontual;
		break;
	case 'c':
		foco = !foco;
		break;
	case 'o':
		direcional = !direcional;
		break;
	case 'i':
		poste = !poste;
		break;
	case 'v':
		view += 1;
		if (view >= 4)
			view = 1;
	
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	setup();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::exit() {

}
