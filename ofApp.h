#pragma once

#include "ofMain.h"
#include "cg_extras.h"
#include "cg_drawing_extras.h"
#include "cam_things.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void app_block_1();
		void app_block_2();
		void draw_car();
		void draw_full_cene();
		void center_light();
		void factory();
		void fumo(int tam, int tipo);
		void cams(int cam);
		void directional_light();
		void sky_box();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		

		//floor
		GLfloat floorWidth, floorHeight, floorHeightPos;

		//app
		GLfloat appWidth, appHeight, appHeightPos;

		//app Block_1
		GLfloat appWidth_pred_1, appHeight_pred_1, appHeightPos_pred_1;
		GLfloat appWidth_pred_2, appHeight_pred_2, appHeightPos_pred_2;

		//app Block_2
		GLfloat appWidth_pred_3, appHeight_pred_3, appHeightPos_pred_3;
		GLfloat appWidth_pred_4, appHeight_pred_4, appHeightPos_pred_4;

		//factory
		GLfloat appWidth_fac_1, appHeight_fac_1, appHeightPos_fac_1;
		GLfloat appWidth_fac_2, appHeight_fac_2, appHeightPos_fac_2;
		GLfloat appWidth_fac_3, appHeight_fac_3, appHeightPos_fac_3;
		GLfloat appWidth_fac_4, appHeight_fac_4, appHeightPos_fac_4;
		GLfloat appWidth_fac_5, appHeight_fac_5, appHeightPos_fac_5;
		GLfloat Width_chamine, Height_chamine, HeightPos_chamine;
		GLfloat Width_smoke, Height_smoke, HeightPos_smoke;
		GLfloat subida1, subida2, subida3;

		//stick
		GLfloat stickWidth, stickHeight, stickHeightPos;

		//light source
		GLfloat lightsourceWidth, lightsourceHeight, lightsourceHeightPos;

		//Car
		GLfloat carWidth, carHeight, carHeightPos;
		GLfloat car_x_pos, car_y_pos;
		int caso;

		//view
		bool topView;
		int view;

		//Experiment
		GLfloat rotate;
		GLfloat user_rotation_z;
		GLfloat user_rotation_y;

		//Cam
		GLfloat lensAngle;
		GLfloat alpha, beta;
		

		// Iluminação
		
		// aux
		GLfloat init_Matriz[16];
		GLfloat Matriz[16];

		// luzes
		bool pontual;
		bool direcional;
		bool foco;
		bool poste;
		bool auto_move_d;
		bool sun_up;
		bool ambient;
		bool difuse;
		bool specular;


		// direcional
		GLfloat dirVec[4];
		GLfloat dirAmb[4];
		GLfloat dirDif[4];
		GLfloat dirSpec[4];


		// ponto
		GLfloat pointPos[4];
		GLfloat pointAmb[4];
		GLfloat pointDif[4];
		GLfloat pointSpec[4];
		GLfloat pointZtheta;

		

		// foco
		GLfloat focPos[4];
		GLfloat focAmb[4];
		GLfloat focDif[4];
		GLfloat focSpec[4];
		GLfloat focDir[3];


		// poste
		GLfloat postePos[4];
		GLfloat posteAmb[4];
		GLfloat posteDif[4];
		GLfloat posteSpec[4];
		GLfloat posteDir[3];
		

		// Texturas
		ofImage nullImage;

		//skybox
		ofImage sky;
		float freqs[10];
		float amps[10];
		float phaseX;
		float phaseY;
		GLint px;
		GLint py;
		ofImage nightSkyImg;
		unsigned char* skyPixels = NULL;

		//
		//ofImage normalMap;
		//unsigned char* normalPixels = NULL;
		//

		Apartamento chao;

		Apartamento app_block1_esq;
		Apartamento app_block1_dir;

		Apartamento app_block2_centro;
		Apartamento app_block2_lado;
		
		Apartamento block_fabrica;
		Apartamento block_fabrica2;
		Apartamento muro_fabrica;
		Apartamento bloco_fabrica_tras;
		Apartamento bloco_fabrica_tras_2;
		Apartamento chamine;
		Apartamento smoke;
		
		Apartamento triangle;
		Apartamento cubo_piramide;

		Apartamento u_unit_10;
		Apartamento u_unit_4;

		Apartamento carro;
		Apartamento roda;

		Apartamento stick;
		Apartamento lantern;

		Apartamento app_null;

		ofVec3f pos;
		ofVec3f pos_center_light;
		ofVec3f pos_center_light2;
		ofVec3f dir_focus_light;

};

