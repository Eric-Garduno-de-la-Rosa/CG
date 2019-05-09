//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//Solo para Visual Studio 2015
#if (_MSC_VER >= 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


//NEW// Keyframes
//Variables de dibujo y manipulacion
float posX =0, posY = 2.5, posZ =-3.5, rotRodIzq = 0, rotRodDer=0, rotBrazDer=0, rotBrazIzq=0, rotPuerta=0, rotPuerta2=0;
float giroMonito = 0;
float movRot = 0.0;
float movTrans = 0.0;
bool g_fanimacion = false;

#define MAX_FRAMES 5
int i_max_steps = 90;
int i_curr_steps = 0;

typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotInc;
	float rotRodDer;
	float rotInc2;
	float rotBrazDer;
	float rotInc3;
	float rotBrazIzq;
	float rotInc4;
	float rotPuerta;
	float rotInc5;
	float rotPuerta2;
	float rotInc6;
	float giroMonito;
	float giroMonitoInc;
	
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex=0;			//introducir datos
bool play=false;
int playIndex=0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////



int w = 500, h = 500;
int frame=0,time,timebase=0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;


//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = {22};

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01


//NEW///////////////////////////7

CTexture textMesa;
CTexture textPata;
CTexture textWall;
CTexture textSilla;
CTexture textTecho;
CTexture textMarble;
CTexture textPiso;
CTexture textGlassWasser;
CTexture textBarrote;
CTexture textCuadro1;
CTexture textMarco;
CTexture textLibroCG;
CTexture textPB;
CTexture textPuerta;
CTexture textPuerta_princ;
CTexture textMarco_1;
CTexture textMarco_2;
CTexture textMarco_3;
CTexture textGrass;
CTexture textSky;
CTexture textSky2;
CTexture textLibrero;

//***ROSE****
CTexture textAlmohada;
CTexture textColcha;
CTexture textMaderaBuro;
CTexture textMaderaCama;
CTexture textLampara;
CTexture textLaptop;
CTexture textPantalla;
CTexture textTeclado;
CTexture textTouchPad;
CTexture textGW;
CTexture textfachada;
CTexture textfachada2;
CTexture textpared;
CTexture textpared2;
CTexture textpared4;
CTexture textpared3;
CTexture textventana;
CTexture textventana2;
CTexture textacabado;
CTexture textpiso;
CTexture textbase;
CTexture textcolcha;
CTexture textfrazada;
CTexture textalfombra;
CTexture textalfombra2;
CTexture textbase2;
CTexture textcloset;
CTexture textalmohada1;
CTexture textalmohada2;
CTexture textmetal;
CTexture textduela;
CTexture textHP1;
CTexture textHP3;
CTexture textHP5;
CTexture textPOS;
CTexture textHP;
CTexture textlampara;
CTexture textlampara2;
CTexture textmetal2;
CTexture textmac;
CTexture textteclado;



//CFiguras fig1;
//CFiguras fig5;
CFiguras tablaMesa;
CFiguras pata1Mesa;
CFiguras pata2Mesa;
CFiguras pata3Mesa;
CFiguras pata4Mesa;
CFiguras asientoSilla;
CFiguras respaldoSilla1;
CFiguras respaldoSilla2;
CFiguras respaldoSilla3;
CFiguras respaldoSilla4;
CFiguras techoCasa;
CFiguras pisoCasa;
CFiguras cubo;
CFiguras sky;
//*****ROSE*****

CFiguras cama;
CFiguras buro;
CFiguras cono;
CFiguras lampara;
CFiguras laptop;

float abrirPuerta = 0;
//END NEW//////////////////////////////////////////

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito


void saveFrame ( void )
{
	
	printf("frameindex %d\n",FrameIndex);			

	KeyFrame[FrameIndex].posX=posX;
	KeyFrame[FrameIndex].posY=posY;
	KeyFrame[FrameIndex].posZ=posZ;

	KeyFrame[FrameIndex].rotRodIzq=rotRodIzq;
	KeyFrame[FrameIndex].rotRodDer = rotRodDer;
	KeyFrame[FrameIndex].rotBrazDer = rotBrazDer;
	KeyFrame[FrameIndex].rotBrazIzq = rotBrazIzq;
	KeyFrame[FrameIndex].rotPuerta = rotPuerta;
	KeyFrame[FrameIndex].rotPuerta2 = rotPuerta2;
    KeyFrame[FrameIndex].giroMonito=giroMonito;
			
	FrameIndex++;
}

void resetElements( void )
{
	posX=KeyFrame[0].posX;
	posY=KeyFrame[0].posY;
	posZ=KeyFrame[0].posZ;

	rotRodIzq=KeyFrame[0].rotRodIzq;
	rotRodDer = KeyFrame[0].rotRodDer;
	rotBrazDer = KeyFrame[0].rotBrazDer;
	rotBrazIzq = KeyFrame[0].rotBrazIzq;
	rotPuerta = KeyFrame[0].rotPuerta;
	rotPuerta2 = KeyFrame[0].rotPuerta2;
	giroMonito=KeyFrame[0].giroMonito;

}

void interpolation ( void )
{
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;	
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;	
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;	

	KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;	
	KeyFrame[playIndex].rotInc2 = (KeyFrame[playIndex + 1].rotRodDer - KeyFrame[playIndex].rotRodDer) / i_max_steps;
	KeyFrame[playIndex].rotInc3 = (KeyFrame[playIndex + 1].rotBrazDer - KeyFrame[playIndex].rotBrazDer) / i_max_steps;
	KeyFrame[playIndex].rotInc4 = (KeyFrame[playIndex + 1].rotBrazIzq - KeyFrame[playIndex].rotBrazIzq) / i_max_steps;
	KeyFrame[playIndex].rotInc5 = (KeyFrame[playIndex + 1].rotPuerta - KeyFrame[playIndex].rotPuerta) / i_max_steps;
	KeyFrame[playIndex].rotInc6 = (KeyFrame[playIndex + 1].rotPuerta2 - KeyFrame[playIndex].rotPuerta2) / i_max_steps;
	KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;

}


void ciudad ()
{

		glPushMatrix(); //Camino1
			glTranslatef(23.5,0.0,0.0);
			glScalef(40,0.1,7);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Camino2
			glTranslatef(-23.5,0.0,0.0);
			glScalef(40,0.1,7);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,-4.0);
			glScalef(87,0.1,1);
			glDisable(GL_LIGHTING);
			fig4.prisma2(text5.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,4.0);
			glScalef(87,0.1,1);
			glDisable(GL_LIGHTING);
			fig4.prisma2(text5.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		

	
}

void closet()
{
	glPushMatrix();
	glPushMatrix(); //closet 
	glTranslatef(-10.2, 3.2, -16.75);
	//glRotatef(240, 0, 1, 0);
	//glRotatef(45, 0, 1, 0);
	glScalef(0.1, 6.2, 3.0);
	glDisable(GL_LIGHTING);
	fig6.prisma2(textcloset.GLindex, textcloset.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //closet 
	glTranslatef(-10.9, 6.3, -16.75);
	//glRotatef(240, 0, 1, 0);
	//glRotatef(45, 0, 1, 0);
	glScalef(1.5, 0.1, 3.0);
	glDisable(GL_LIGHTING);
	fig6.prisma2(textcloset.GLindex, textcloset.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //closet 
	glTranslatef(-10.9, 0.25, -16.75);
	//glRotatef(240, 0, 1, 0);
	//glRotatef(45, 0, 1, 0);
	glScalef(1.5, 0.1, 3.0);
	glDisable(GL_LIGHTING);
	fig6.prisma2(textcloset.GLindex, textcloset.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //closet 
	glTranslatef(-10.9, 3.25, -15.3);
	//glRotatef(240, 0, 1, 0);
	//glRotatef(45, 0, 1, 0);
	glScalef(1.5, 6.2, 0.1);
	glDisable(GL_LIGHTING);
	fig6.prisma2(textcloset.GLindex, textcloset.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //closet 
	glTranslatef(-10.9, 3.25, -18.3);
	//glRotatef(240, 0, 1, 0);
	//glRotatef(45, 0, 1, 0);
	glScalef(1.5, 6.2, 0.1);
	glDisable(GL_LIGHTING);
	fig6.prisma2(textcloset.GLindex, textcloset.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //puesta1 closet 
	glTranslatef(-11.7, 3.25, -16.0);
	glRotatef(rotPuerta, 0, 1, 0);
	glScalef(0.1, 6.2, 1.5);
	glDisable(GL_LIGHTING);
	fig6.prisma2(textcloset.GLindex, textcloset.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glPopMatrix();

	 glPushMatrix(); //puesta2 closet 
		glTranslatef(-11.7, 3.25, -17.55);
		glScalef(0.1, 6.2, 1.55);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textcloset.GLindex, textcloset.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
}



//NEW CASA//////////////////////////////////////

void dibujaLaptop(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosBuro, GLfloat yPosBuro, GLfloat zPosBuro)
{
		glPushMatrix();		
			glScalef(xMadera, yMadera, zMadera); 
			glTranslatef(xPosBuro, yPosBuro, zPosBuro); //figura 
			//contorno
			glPushMatrix();
				glTranslatef(7.0,0.5,0.25);
				glScalef(14.0,1.0,0.5);
				 laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(7.0,11.5,0.25);
				glScalef(14.0,1.0,0.5);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();

 		glPushMatrix();
				glTranslatef(0.5,6.0,0.25);
				glScalef(1.0,10.0,0.5);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(13.5,6.0,0.25);
				glScalef(1.0,10.0,0.5);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();
 	glPushMatrix();
				glTranslatef(7.0,6.0,0.125);
				glScalef(12.0,10.0,0.25);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(7.0,6.0,0.375);
				glScalef(12.0,10.0,0.25);
				laptop.prisma(1.0,1.0,1.0, textPantalla.GLindex);
			glPopMatrix();

 		//teclado
			glPushMatrix();
				glTranslatef(7.0,-0.75,5.0);
				glScalef(14.0,0.5,10.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	

			glPushMatrix();
				glTranslatef(7.0,-0.25,0.5);
				glScalef(14.0,0.5,1.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	
 			glPushMatrix();
				glTranslatef(7.0,-0.25,6.5);
				glScalef(14.0,0.5,1.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	

			glPushMatrix();
				glTranslatef(2.5,-0.25,8.0);
				glScalef(5.0,0.5,2.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	
 		glPushMatrix();
				glTranslatef(11.5,-0.25,8.0);
				glScalef(5.0,0.5,2.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	

			glPushMatrix();
				glTranslatef(7.0,-0.25,9.5);
				glScalef(14.0,0.5,1.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	
 		glPushMatrix();
				glTranslatef(0.5,-0.25,5.0);
				glScalef(1.0,0.5,10.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	

			glPushMatrix();
				glTranslatef(13.5,-0.25,5.0);
				glScalef(1.0,0.5,10.0);
				laptop.prisma(1.0,1.0,1.0, textLaptop.GLindex);
			glPopMatrix();	
 		//teclas
			glPushMatrix();
				glTranslatef(7.0,-0.25,3.5);
				glScalef(12.0,0.5,5.0);
				laptop.prisma(1.0,1.0,1.0, textTeclado.GLindex);
			glPopMatrix();	

			//touchpad
			glPushMatrix();
				glTranslatef(7.0,-0.25,8.0);
				glScalef(4.0,0.5,2.0);
				laptop.tecla(1.0,1.0,1.0, textTouchPad.GLindex);
			glPopMatrix();	
 		glPopMatrix();
}


void mesa(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosMesa, GLfloat yPosMesa, GLfloat zPosMesa){
	//mesa	
		//tabla
		glPushMatrix();
			glScalef(xMadera, yMadera, zMadera);
			glTranslatef(xPosMesa, yPosMesa, zPosMesa);
			glPushMatrix();
				glScalef(10,.5,5);
				tablaMesa.prisma (1.0, 1.0, 1.0, textMarble.GLindex);
			//patas
			glPopMatrix();
			glPushMatrix();
				glTranslatef(4, -2.75, 2);
				glScalef( .5,5,.5);
				pata1Mesa.prisma (1.0, 1.0, 1.0, textMarble.GLindex);
				glTranslatef(0, 0, -8);
				pata2Mesa.prisma (1.0, 1.0, 1.0, textMarble.GLindex);
				glTranslatef(-16, 0, 0);
				pata3Mesa.prisma (1.0, 1.0, 1.0, textMarble.GLindex);
				glTranslatef(0, 0, 8);
				pata4Mesa.prisma (1.0, 1.0, 1.0, textMarble.GLindex);
			glPopMatrix();
		glPopMatrix();

		return;
}

void silla(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosSilla, GLfloat yPosSilla, GLfloat zPosSilla){
	float numBarrotes = -2.9;
	glPushMatrix();
		//posicion y tamaño
		glScalef(xMadera, yMadera, zMadera);
		glTranslatef(xPosSilla, yPosSilla, zPosSilla);
		//figura
		glPushMatrix();
			glScalef(3,.5,3);
			asientoSilla.prisma (1.0, 1.0, 1.0, textSilla.GLindex);//1
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.35, -3.25,-1.35);
			glScalef( .3,6,.3);
			pata1Mesa.prisma (1.0, 1.0, 1.0, textSilla.GLindex);
			glTranslatef(-9.0, 0, 0);
			pata2Mesa.prisma (1.0, 1.0, 1.0, textSilla.GLindex);
			glTranslatef(0, 0, 9);
			pata3Mesa.prisma (1.0, 1.0, 1.0, textSilla.GLindex);
			glTranslatef(9, 0, 0);
			pata4Mesa.prisma (1.0, 1.0, 1.0, textSilla.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.45, 4.25, -1.45);
			glScalef( 0.1,8.0,0.1);
			respaldoSilla1.prisma(1.0,1.0,1.0, textSilla.GLindex);
			for(int numBar = 1; numBar <= 10; numBar++){
				glTranslatef(numBarrotes,0,0);
				respaldoSilla1.prisma(1.0,1.0,1.0, textSilla.GLindex);
			}
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0,1,-1.45);
			glScalef( 2.3,0.1,0.1);
			respaldoSilla1.prisma(1.0,1.0,1.0, textSilla.GLindex);
			//
			for(int numBar = 1; numBar <= 30; numBar++){
				glTranslatef(0,2,0);
				respaldoSilla1.prisma(1.0,1.0,1.0, textSilla.GLindex);
			}
			glTranslatef(0,12,0);
			glScalef( 1.5,1,1);
			respaldoSilla1.prisma(1.0,1.0,1.0, textSilla.GLindex);
		glPopMatrix();
	glPopMatrix();

	return;
}

void comedor(void){
	glPushMatrix();
			mesa(2,2,2,0,1,0);
	glPopMatrix();
	//SILLAS
	glPushMatrix();
		glTranslatef(0,0,-0.5);
		glRotatef(25, 0,1,0);
		glTranslatef(2,0,-0.5);
		silla(1,1,1,5,-1,-4.5);
		glPopMatrix();
		glPushMatrix();
			silla(1,1,1,-5,-1,-4.5);
		glPopMatrix();
		glPushMatrix();
			silla(1,1,1,0,-1,-4.5);
		glPopMatrix();
		//giramos con respecto Z
		glScalef(1,1,-1);
		glPushMatrix();				
		glPushMatrix();
			silla(1,1,1,5,-1,-4.5);
		glPopMatrix();
		glPushMatrix();
			silla(1,1,1,-5,-1,-4.5);
		glPopMatrix();
		glPushMatrix();
			silla(1,1,1,0,-1,-4.5);
		glPopMatrix();
	glPopMatrix();
		return;
}
void ropero(void){
			glPushMatrix();
				glTranslatef(-8,-20,50);
				fig5.prisma(50.0,1.0,30.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-20,35);
				glRotatef(90,1,0,0);
				fig5.prisma(1.0,6.0,50.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-20,65);
				glRotatef(90,1,0,0);
				fig5.prisma(1.0,6.0,50.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-20,57.5);
				glRotatef(90,1,0,0);
				fig5.prisma(0.5,6.0,50.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-20,42.5);
				glRotatef(90,1,0,0);
				fig5.prisma(0.5,6.0,50.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-45,50);
				fig5.prisma(0.5,6.0,31.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,5,50);
				fig5.prisma(0.5,6.0,31.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-20,50);
				fig5.prisma(0.5,6.0,30.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-30,50);
				fig5.prisma(0.5,6.0,30.0, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-10,39);
				fig5.prisma(0.5,6.0,7.5, textGW.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-5.5,-10,61);
				fig5.prisma(0.5,6.0,7.5, textGW.GLindex);
			glPopMatrix();
}
void casa( void ){
//*****casa*****
	glPushMatrix(); //Creamos paredes
		glTranslatef(0,20,0);
		fig1.skybox2(60.0, 85.0, 85.0, textPata.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0,50,0);
		techoCasa.prisma(1,90,90, textTecho.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0,-10,0);
		pisoCasa.prisma(1,85,85, textPiso.GLindex);
		//patio
		glTranslatef(0,-3,0);
		//pisoCasa.prisma(1,250,250, textGrass.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-27.5,10,-42);
		pisoCasa.prisma(40,30,1, textPata.GLindex);
		glTranslatef(30,0,0);
		pisoCasa.prisma(40,30,1, textPata.GLindex);
		glTranslatef(15,0,0);
		pisoCasa.prisma(40,30,1, textPata.GLindex);
		glPushMatrix();
			glTranslatef(15.5,0,0);
			pisoCasa.prisma(40,1,1, textMarco_1.GLindex);
			glTranslatef(9,0,0);
			pisoCasa.prisma(40,1,1, textMarco_2.GLindex);
			glTranslatef(-4.5,18.5,0);
			pisoCasa.prisma(2.5,8,1, textMarco_3.GLindex);
		glPopMatrix();
		//puerta
		glTranslatef(15,-1,0);
		glRotatef(abrirPuerta, 0,1,0);
		glTranslatef(5,-0.4,0);//eran 20 en x
		pisoCasa.prisma(37,8,1, textPuerta_princ.GLindex);
	glPopMatrix();
			
	//ventana 1
	glPushMatrix();
		glTranslatef(-34.5,38.5,-42);
		cubo.prisma(16.5,15,1, textGlassWasser.GLindex);
	glPopMatrix();
	// barrotes ventana
	glPushMatrix();
		glTranslatef(-42,38.5,-42);
		cubo.prisma(17,0.8,1, textBarrote.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-27,38.5,-42);
		cubo.prisma(17,0.8,1, textBarrote.GLindex);
	glPopMatrix();
	//ventana 2
	glPushMatrix();
		glTranslatef(-19,38.5,-42);
		cubo.prisma(16.5,15,1, textGlassWasser.GLindex);
	glPopMatrix();
	//barrote
	glPushMatrix();
		glTranslatef(-11,38.5,-42);
		cubo.prisma(17,0.8,1, textBarrote.GLindex);
	glPopMatrix();
	//ventana 3
	glPushMatrix();
		glTranslatef(-3,38.5,-42);
		cubo.prisma(16.5,15,1, textGlassWasser.GLindex);
	glPopMatrix();
	//barrote
	glPushMatrix();
		glTranslatef(5,38.5,-42);
		cubo.prisma(17,0.8,1, textBarrote.GLindex);
	glPopMatrix();
	//ventana 4
	glPushMatrix();
		glTranslatef(13,38.5,-42);
		cubo.prisma(16.5,15,1, textGlassWasser.GLindex);
	glPopMatrix();
	//barrote
	glPushMatrix();
		glTranslatef(19.8,38.5,-42);
		cubo.prisma(17,0.8,1, textBarrote.GLindex);
	glPopMatrix();	
	//cierra ventana
	glPushMatrix();
		glTranslatef(31,38.5,-42);
		cubo.prisma(17,23,1, textPata.GLindex);
	glPopMatrix();
	return;
}

void cuadro(void){
	glPushMatrix();
		glScalef(1,1,-1);
		glTranslatef(-19,30,-42);
		cubo.prisma(16,15,.2, textCuadro1.GLindex);
		glTranslatef(0,0,-.05);
		//cubo.prisma(17,16,.05, textMarco.GLindex);
	glPopMatrix();
	return;
}
//****ROSE****
void dibujaCama (GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosCama, GLfloat yPosCama, GLfloat zPosCama)
{			
			glPushMatrix(); 
			glScalef(xMadera, yMadera, zMadera); //posicion y tamaño 
			glTranslatef(xPosCama, yPosCama, zPosCama); //figura 

			//dibujamos la cabecera
			glPushMatrix(); 
				glTranslatef(9.0,1.5,0.5);
				glScalef(18.0,3.0,1.0);  //Tamaño de cabecera
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(0.5,6.0,0.5);
				glScalef(1.0,6.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(4.0,6.0,0.5);
				glScalef(4.0,6.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(9.0,6.0,0.5);
				glScalef(4.0,6.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(14.0,6.0,0.5);
				glScalef(4.0,6.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,6.0,0.5);
				glScalef(1.0,6.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(9.0,9.5,0.5);
				glScalef(18.0,1.0,1.0);  
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(0.5,5.0,0.5);
				glScalef(1.0,10.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();


			//dibujamos la base de la cama
			glPushMatrix(); 
				glTranslatef(0.5,1.0,11.0);
				glScalef(1.0,2.0,22.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,1.0,11.0);
				glScalef(1.0,2.0,22.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(9.0,1.0,21.5);
				glScalef(18.0,2.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();


			//colchon
			glPushMatrix(); 
				glTranslatef(9.0,3.5,11.0);
				glScalef(18.0,3.0,20.0);
				cama.prisma(1.0,1.0,1.0, textColcha.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(0.5,3.5,11.0);
				glScalef(1.0,3.0,20.0);
				cama.prisma(1.0,1.0,1.0, textColcha.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,3.5,11.0);
				glScalef(1.0,3.0,20.0);
				cama.prisma(1.0,1.0,1.0, textColcha.GLindex);
			glPopMatrix();

			//almohada izquierda
			glPushMatrix(); 
				glTranslatef(4.0,5.5,3.0);
				glScalef(8.0,1.0,4.0);
				cama.prisma(1.0,1.0,1.0, textAlmohada.GLindex);
			glPopMatrix();

			//almohada derecha
			glPushMatrix(); 
				glTranslatef(14.0,5.5,3.0);
				glScalef(8.0,1.0,4.0);
				cama.prisma(1.0,1.0,1.0, textAlmohada.GLindex);
			glPopMatrix();


			//enfrente
			glPushMatrix(); 
				glTranslatef(9.0,6.5,21.5);
				glScalef(16.0,1.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(9.0,2.5,21.5);
				glScalef(16.0,5.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(0.5,4.0,21.5);
				glScalef(1.0,8.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,4.0,21.5);
				glScalef(1.0,8.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();


			//patas
			glPushMatrix(); 
				glTranslatef(0.5,-1.0,21.5);
				glScalef(1.0,2.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,-1.0,21.5);
				glScalef(1.0,2.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(17.5,-1.0,0.5);
				glScalef(1.0,2.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();

			glPushMatrix(); 
				glTranslatef(0.5,-1.0,0.5);
				glScalef(1.0,2.0,1.0);
				cama.prisma(1.0,1.0,1.0, textMaderaCama.GLindex);
			glPopMatrix();
			glPopMatrix();
}


void dibujaBuro(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosBuro, GLfloat yPosBuro, GLfloat zPosBuro)
{
		glPushMatrix();		
			glScalef(xMadera, yMadera, zMadera); 
			glTranslatef(xPosBuro, yPosBuro, zPosBuro); //figura 
			//contorno
			glPushMatrix();
				glTranslatef(1.5,5.5,1.5);
				glScalef(1.0,11.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1.5,5.5,8.5);
				glScalef(1.0,11.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14.5,5.5,1.5);
				glScalef(1.0,11.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14.5,5.5,8.5);
				glScalef(1.0,11.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,10.5,8.5);
				glScalef(12.0,1.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1.5,10.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14.5,10.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();


			glPushMatrix();
				glTranslatef(8.0,6.5,8.5);
				glScalef(12.0,1.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1.5,6.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14.5,6.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,2.5,1.5);
				glScalef(12.0,1.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,2.5,8.5);
				glScalef(12.0,1.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1.5,2.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14.5,2.5,5.0);
				glScalef(1.0,1.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			//rellenos
			glPushMatrix();
				glTranslatef(13.5,6.5,5.0);
				glScalef(1.0,7.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(2.5,6.5,5.0);
				glScalef(1.0,7.0,6.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			//pared atras
			glPushMatrix();
				glTranslatef(8.0,6.5,1.5);
				glScalef(12.0,9.0,1.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();


			//base arriba
			glPushMatrix();
				glTranslatef(8.0,11.5,5.0);
				glScalef(16.0,1.0,10.0);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();


			//cajones
			glPushMatrix();
				glTranslatef(8.0,8.5,9.25);
				glScalef(12.0,3.0,0.5);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,4.5,9.25);
				glScalef(12.0,3.0,0.5);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,8.5,9.75);
				glScalef(2.0,1.0,0.5);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8.0,4.5,9.75);
				glScalef(2.0,1.0,0.5);
				buro.prisma(1.0,1.0,1.0, textMaderaBuro.GLindex);
			glPopMatrix();
		glPopMatrix();
}

void libros( void){
	glPushMatrix();
			glTranslatef(-1,-8,25);
			cubo.prisma(1,2,2, textLibroCG.GLindex);
		glPopMatrix();

		glPushMatrix();
			glRotatef(30, 0,1,0);
			glTranslatef(-10,-8,25);
			//cubo.prisma(.7,2,2, textPB.GLindex);
	glPopMatrix();
	return;
}
//END CASA////////////////////////////////////





GLuint createDL() 
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL,GL_COMPILE);
	// call the function that contains 
	// the rendering commands
		ciudad();
		//monito();
	// endList
	glEndList();

	return(ciudadDL);
}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);

	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();

	//FACHADA CASA
	textfachada.LoadTGA("FACHADA.tga");
	textfachada.BuildGLTexture();
	textfachada.ReleaseImage();

	//FACHADA CASA 2
	textfachada2.LoadTGA("fachada2.tga");
	textfachada2.BuildGLTexture();
	textfachada2.ReleaseImage();

	//pared casa

	textpared.LoadTGA("pared.tga");
	textpared.BuildGLTexture();
	textpared.ReleaseImage();

	textpared2.LoadTGA("pared2.tga");
	textpared2.BuildGLTexture();
	textpared2.ReleaseImage();

	textpared3.LoadTGA("pared3.tga");
	textpared3.BuildGLTexture();
	textpared3.ReleaseImage();

	textpared4.LoadTGA("pared4.tga");
	textpared4.BuildGLTexture();
	textpared4.ReleaseImage();

	//ventana casa

	textventana.LoadTGA("ventana.tga");
	textventana.BuildGLTexture();
	textventana.ReleaseImage();

	textventana2.LoadTGA("ventana2.tga");
	textventana2.BuildGLTexture();
	textventana2.ReleaseImage();

	textacabado.LoadTGA("acabado.tga");
	textacabado.BuildGLTexture();
	textacabado.ReleaseImage();

	textpiso.LoadTGA("piso.tga");
	textpiso.BuildGLTexture();
	textpiso.ReleaseImage();


	textbase.LoadTGA("base.tga");
	textbase.BuildGLTexture();
	textbase.ReleaseImage();

	textbase2.LoadTGA("base2.tga");
	textbase2.BuildGLTexture();
	textbase2.ReleaseImage();

	textcolcha.LoadTGA("colcha.tga");
	textcolcha.BuildGLTexture();
	textcolcha.ReleaseImage();

	textfrazada.LoadTGA("frazada.tga");
	textfrazada.BuildGLTexture();
	textfrazada.ReleaseImage();

	textalfombra.LoadTGA("alfombra.tga");
	textalfombra.BuildGLTexture();
	textalfombra.ReleaseImage();

	textalfombra2.LoadTGA("alfombra2.tga");
	textalfombra2.BuildGLTexture();
	textalfombra2.ReleaseImage();


	textcloset.LoadTGA("closet.tga");
	textcloset.BuildGLTexture();
	textcloset.ReleaseImage();

	textalmohada1.LoadTGA("almohada1.tga");
	textalmohada1.BuildGLTexture();
	textalmohada1.ReleaseImage();

	textalmohada2.LoadTGA("almohada2.tga");
	textalmohada2.BuildGLTexture();
	textalmohada2.ReleaseImage();

	textmetal.LoadTGA("metal.tga");
	textmetal.BuildGLTexture();
	textmetal.ReleaseImage();

	textmetal2.LoadTGA("metal2.tga");
	textmetal2.BuildGLTexture();
	textmetal2.ReleaseImage();

	textduela.LoadTGA("duela.tga");
	textduela.BuildGLTexture();
	textduela.ReleaseImage();


	textHP1.LoadTGA("HP1.tga");
	textHP1.BuildGLTexture();
	textHP1.ReleaseImage();

	textHP3.LoadTGA("HP3.tga");
	textHP3.BuildGLTexture();
	textHP3.ReleaseImage();


	textHP5.LoadTGA("HP5.tga");
	textHP5.BuildGLTexture();
	textHP5.ReleaseImage();

	textPOS.LoadTGA("POS.tga");
	textPOS.BuildGLTexture();
	textPOS.ReleaseImage();


	textHP.LoadTGA("HP.tga");
	textHP.BuildGLTexture();
	textHP.ReleaseImage();


	textlampara.LoadTGA("lampara.tga");
	textlampara.BuildGLTexture();
	textlampara.ReleaseImage();


	textlampara2.LoadTGA("lampara2.tga");
	textlampara2.BuildGLTexture();
	textlampara2.ReleaseImage();


	textmac.LoadTGA("mac.tga");
	textmac.BuildGLTexture();
	textmac.ReleaseImage();

	textteclado.LoadTGA("teclado.tga");
	textteclado.BuildGLTexture();
	textteclado.ReleaseImage();

	textSky2.LoadTGA("siege_bk.tga");
	textSky2.BuildGLTexture();
	textSky2.ReleaseImage();



	//NEW////////////////////////////////////////////

	textMesa.LoadBMP("casa/wood_5.bmp");
	textMesa.BuildGLTexture();
	textMesa.ReleaseImage();

	textPata.LoadBMP("casa/brick_3.bmp");
	textPata.BuildGLTexture();
	textPata.ReleaseImage();

	textWall.LoadBMP("casa/brick_2.bmp");
	textWall.BuildGLTexture();
	textWall.ReleaseImage();

	textSilla.LoadBMP("casa/madera.bmp");
	textSilla.BuildGLTexture();
	textSilla.ReleaseImage();
	
	textTecho.LoadBMP("casa/brick_3.bmp");
	textTecho.BuildGLTexture();
	textTecho.ReleaseImage();

	textMarble.LoadBMP("casa/marble_2.bmp");
	textMarble.BuildGLTexture();
	textMarble.ReleaseImage();

	textPiso.LoadBMP("casa/floor-parquet.bmp");
	textPiso.BuildGLTexture();
	textPiso.ReleaseImage();

	textGlassWasser.LoadBMP("casa/glass_2.bmp");
	textGlassWasser.BuildGLTexture();
	textGlassWasser.ReleaseImage();

	textBarrote.LoadBMP("casa/brickwall.bmp");
	textBarrote.BuildGLTexture();
	textBarrote.ReleaseImage();

	textCuadro1.LoadBMP("casa/cuadro_1.bmp");
	textCuadro1.BuildGLTexture();
	textCuadro1.ReleaseImage();

	textMarco.LoadBMP("casa/burned wood.bmp");
	textMarco.BuildGLTexture();
	textMarco.ReleaseImage();

	textLibroCG.LoadBMP("casa/gc_donald.bmp");
	textLibroCG.BuildGLTexture();
	textLibroCG.ReleaseImage();

	textPuerta.LoadBMP("casa/door_3.bmp");
	textPuerta.BuildGLTexture();
	textPuerta.ReleaseImage();

	textPuerta_princ.LoadBMP("casa/door_3_4_puerta.bmp");
	textPuerta_princ.BuildGLTexture();
	textPuerta_princ.ReleaseImage();

	textMarco_1.LoadBMP("casa/door_3_1_izq.bmp");
	textMarco_1.BuildGLTexture();
	textMarco_1.ReleaseImage();

	textMarco_2.LoadBMP("casa/door_3_2_der.bmp");
	textMarco_2.BuildGLTexture();
	textMarco_2.ReleaseImage();

	textMarco_3.LoadBMP("casa/door_3_3_cen.bmp");
	textMarco_3.BuildGLTexture();
	textMarco_3.ReleaseImage();

	textGrass.LoadBMP("casa/grass_2.bmp");
	textGrass.BuildGLTexture();
	textGrass.ReleaseImage();

	textSky.LoadBMP("casa/blue-sky-texture.bmp");
	textSky.BuildGLTexture();
	textSky.ReleaseImage();

	textLibrero.LoadBMP("casa/strata.bmp");
	textLibrero.BuildGLTexture();
	textLibrero.ReleaseImage();

	textGW.LoadBMP("casa/glass window.bmp");
	textGW.BuildGLTexture();
	textGW.ReleaseImage();
	
	//*****ROSE******
	textAlmohada.LoadBMP("casa/almohada.bmp");
	textAlmohada.BuildGLTexture();
	textAlmohada.ReleaseImage();

	textColcha.LoadBMP("casa/colcha.bmp");
	textColcha.BuildGLTexture();
	textColcha.ReleaseImage();

	textMaderaBuro.LoadBMP("casa/buro.bmp");
	textMaderaBuro.BuildGLTexture();
	textMaderaBuro.ReleaseImage();

	textMaderaCama.LoadBMP("casa/maderaCama.bmp");
	textMaderaCama.BuildGLTexture();
	textMaderaCama.ReleaseImage();

	textLampara.LoadBMP("casa/lampara.bmp");
	textLampara.BuildGLTexture();
	textLampara.ReleaseImage();

	textLaptop.LoadBMP("casa/laptop.bmp");
	textLaptop.BuildGLTexture();
	textLaptop.ReleaseImage();

	textPantalla.LoadBMP("casa/windows.bmp");
	textPantalla.BuildGLTexture();
	textPantalla.ReleaseImage();

	textTeclado.LoadBMP("casa/tecla.bmp");
	textTeclado.BuildGLTexture();
	textTeclado.ReleaseImage();

	textTouchPad.LoadBMP("casa/touchpad.bmp");
	textTouchPad.BuildGLTexture();
	textTouchPad.ReleaseImage();

	//END NEW//////////////////////////////

	/*objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);*/

	objCamera.Position_Camera(-20, 2.5f, 7, -20, 2.5f,0, 0, 1, 0);
	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

	//NEW Iniciar variables de KeyFrames
	for(int i=0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].posX =0;
		KeyFrame[i].posY =0;
		KeyFrame[i].posZ =0;
		KeyFrame[i].incX =0;
		KeyFrame[i].incY =0;
		KeyFrame[i].incZ =0;
		KeyFrame[i].rotRodIzq =0;
		KeyFrame[i].rotRodDer = 0;
		KeyFrame[i].rotBrazDer = 0;
		KeyFrame[i].rotBrazIzq = 0;
		KeyFrame[i].rotPuerta = 0;
		KeyFrame[i].rotInc =0;
		KeyFrame[i].rotInc2 = 0;
		KeyFrame[i].rotInc3 = 0;
		KeyFrame[i].rotInc4 = 0;
		KeyFrame[i].rotInc5 = 0;
		KeyFrame[i].giroMonito =0;
		KeyFrame[i].giroMonitoInc =0;
	}
	//NEW//////////////////NEW//////////////////NEW///////////

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	glPushMatrix();
	

	glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);

		glPushMatrix(); //Casa3 FACHADA
		glTranslatef(-20.0, 5.0, -14.5);
		glRotatef(90, 1, 0, 0);
		//glRotatef(180,0,0,1);
		glScalef(20, 20.0, 10);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfachada2.GLindex, textpared.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //Casa3 PAREDES
		glTranslatef(-20.0, 5.0, -14.5);
		glRotatef(90, 1, 0, 0);
		glRotatef(180, 0, 0, 1);
		glScalef(19.8, 19.8, 9.9);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textventana.GLindex, textpared4.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //piso casa
		glTranslatef(-20.0, 0.2, -14.5);
		glRotatef(90, 1, 0, 0);
		glRotatef(180, 0, 0, 1);
		glScalef(19.8, 19.8, 0.01);
		glDisable(GL_LIGHTING);
		fig6.prisma2(0, textduela.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //base cama
		glTranslatef(-13.0, 1.0, -11.5);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(5, 0.8, 3);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //colchon
		glTranslatef(-13.0, 1.6, -11.5);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(4.7, 0.6, 2.7);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textcolcha.GLindex, textcolcha.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //frazada
		glTranslatef(-14.0, 1.6, -11.5);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(2.3, 0.7, 2.8);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textfrazada.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //cabecera
		glTranslatef(-10.6, 2.0, -11.5);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(0.2, 2.0, 2.8);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //alfombra
		glTranslatef(-17, 0.2, -15.5);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(7.0, 0.1, 15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textalfombra2.GLindex, textalfombra2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();



		glPushMatrix(); //almohadas1
		glTranslatef(-11.2, 2.0, -12.2);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.4, 1.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textalmohada1.GLindex, textalmohada1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();



		glPushMatrix(); //almohadas2
		glTranslatef(-11.2, 2.0, -10.9);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.4, 1.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textalmohada2.GLindex, textalmohada2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();



		glPushMatrix(); //repisas central
		glTranslatef(-10.2, 4.5, -11.5);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(0.1, 1.0, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //repisas
		glTranslatef(-10.65, 5.0, -11.5);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //repisas
		glTranslatef(-10.65, 4.0, -11.5);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //repisas
		glTranslatef(-10.65, 4.5, -10.3);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //repisas
		glTranslatef(-10.65, 4.5, -12.7);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();



		glPushMatrix(); //repisas deracha
		glTranslatef(-10.2, 4.5, -9.0);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(0.1, 1.0, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //repisas
		glTranslatef(-10.65, 5.0, -9.0);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //repisas
		glTranslatef(-10.65, 4.0, -9.0);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //repisas
		glTranslatef(-10.65, 4.5, -7.8);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //repisas
		glTranslatef(-10.65, 4.5, -10.2);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //repisas izquierda
		glTranslatef(-10.2, 4.5, -14);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(0.1, 1.0, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //repisas
		glTranslatef(-10.65, 5.0, -14);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //repisas
		glTranslatef(-10.65, 4.0, -14);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //repisas
		glTranslatef(-10.65, 4.5, -12.8);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //repisas
		glTranslatef(-10.65, 4.5, -15.2);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //librero
		glTranslatef(-10.2, 7.0, -19.6);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(0.1, 1.0, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //librero
		glTranslatef(-10.65, 7.5, -19.6);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //librero
		glTranslatef(-10.65, 6.5, -19.6);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //librero
		glTranslatef(-10.65, 7.0, -18.4);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //librero
		glTranslatef(-10.65, 7.0, -20.8);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //librero
		glTranslatef(-10.65, 7.0, -19.56);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		/////////LIBRERO 2 //////////

		glPushMatrix(); //librero
		glTranslatef(-10.2, 6.0, -19.6);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(0.1, 1.0, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //librero
		glTranslatef(-10.65, 6.5, -19.6);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //librero
		glTranslatef(-10.65, 5.5, -19.6);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //librero
		glTranslatef(-10.65, 6.0, -18.4);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //librero
		glTranslatef(-10.65, 6.0, -20.8);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //librero
		glTranslatef(-10.65, 6.0, -19.56);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		/////////LIBRERO3 ///////

		glPushMatrix(); //librero
		glTranslatef(-10.2, 5.0, -19.6);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(0.1, 1.0, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //librero
		glTranslatef(-10.65, 5.5, -19.6);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //librero
		glTranslatef(-10.65, 4.5, -19.6);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //librero
		glTranslatef(-10.65, 5.0, -18.4);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //librero
		glTranslatef(-10.65, 5.0, -20.8);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //librero
		glTranslatef(-10.65, 5.0, -19.56);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		////////LIBRERO4//////////////

		glPushMatrix(); //librero
		glTranslatef(-10.2, 4.0, -19.6);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(0.1, 1.0, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //librero
		glTranslatef(-10.65, 4.5, -19.6);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //librero
		glTranslatef(-10.65, 3.5, -19.6);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //librero
		glTranslatef(-10.65, 4.0, -18.4);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //librero
		glTranslatef(-10.65, 4.0, -20.8);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //librero
		glTranslatef(-10.65, 4.0, -19.56);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		///////////LIBRERO5//////////////

		glPushMatrix(); //librero
		glTranslatef(-10.2, 3.0, -19.6);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(0.1, 1.0, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //librero
		glTranslatef(-10.65, 3.5, -19.6);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //librero
		glTranslatef(-10.65, 2.5, -19.6);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 0.1, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //librero
		glTranslatef(-10.65, 3.0, -18.4);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //librero
		glTranslatef(-10.65, 3.0, -20.8);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //librero
		glTranslatef(-10.65, 3.0, -19.56);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.0, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		//ESCRITORIO//
		glPushMatrix();
		glTranslatef(-14.15, 2.35, -22.06);
		glScalef(5.5, 0.2, 2.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textcloset.GLindex, textcloset.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-16.95, 0.35, -22.06);
		glScalef(1.5, 2.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.5, 1.0, 20, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(-11.55, 0.35, -22.06);
		glScalef(1.5, 2.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.5, 1.0, 20, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//SILLA//
		glPushMatrix();  //soporte
		glTranslatef(-14.05, 0.75, -19.56);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.08, 1.0, 20, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();  //patas
		glTranslatef(-14.05, 0.75, -19.56);
		glRotatef(110, 0, 0, 1);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.05, 1.0, 20, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();  //patas
		glTranslatef(-14.05, 0.75, -19.56);
		glRotatef(110, 1, 0, 0);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.05, 1.0, 20, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();  //patas
		glTranslatef(-14.05, 0.75, -19.56);
		glRotatef(-110, 0, 0, 1);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.05, 1.0, 20, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();  //patas
		glTranslatef(-14.05, 0.75, -19.56);
		glRotatef(-110, 1, 0, 0);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.05, 1.0, 20, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();  //llantas
		glTranslatef(-14.05, 0.40, -18.75);
		glRotatef(90, 1, 0, 0);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.15, 0.15, 20, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();  //llantas
		glTranslatef(-14.05, 0.40, -20.49);
		glRotatef(90, 1, 0, 0);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.15, 0.15, 20, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();  //llantas
		glTranslatef(-13.0, 0.40, -19.56);
		glRotatef(90, 0, 0, 1);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.15, 0.15, 20, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();  //llantas
		glTranslatef(-14.85, 0.40, -19.56);
		glRotatef(90, 0, 0, 1);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.15, 0.15, 20, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();  //asiento
		glTranslatef(-14.0, 1.7, -19.86);
		glScalef(2.0, 0.3, 2.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textmetal2.GLindex, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();  //respaldo
		glTranslatef(-14.0, 2.7, -18.86);
		glRotatef(100, 1, 0, 0);
		glScalef(2.0, 0.3, 2.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textmetal2.GLindex, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		//BURO//


		glPushMatrix();
		glTranslatef(-10.95, 1.65, -9.0);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.5, 0.08, 40, textcloset.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10.95, 1.05, -9.0);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.5, 0.08, 30, textcloset.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		//PATAS BURO//

		glPushMatrix();//pata1
		glTranslatef(-10.95, 1.05, -8.49);
		glScalef(0.03, 1.3, 0.03);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textmetal.GLindex, textmetal.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();//pata2
		glTranslatef(-10.95, 1.05, -9.5);
		glScalef(0.03, 1.3, 0.03);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textmetal.GLindex, textmetal.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//pata2
		glTranslatef(-11.45, 1.05, -9.0);
		glScalef(0.03, 1.3, 0.03);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textmetal.GLindex, textmetal.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//pata apoyo1
		glTranslatef(-11.2, 0.4, -9.0);
		glScalef(0.5, 0.03, 0.03);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textmetal.GLindex, textmetal.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//pata apoyo2
		glTranslatef(-10.95, 0.4, -8.75);
		glRotatef(90, 0, 1, 0);
		glScalef(0.5, 0.03, 0.03);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textmetal.GLindex, textmetal.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//pata apoyo3
		glTranslatef(-10.95, 0.4, -9.25);
		glRotatef(90, 0, 1, 0);
		glScalef(0.5, 0.03, 0.03);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textmetal.GLindex, textmetal.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		//LAMPARA//
		glPushMatrix();
		glTranslatef(-10.95, 2.2, -9.0);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.3, 0.6, 20, textlampara2.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10.95, 2.0, -9.0);
		glScalef(0.03, 0.55, 0.03);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textmetal2.GLindex, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10.95, 1.7, -9.0);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.2, 0.08, 20, textmetal2.GLindex);
		glPopMatrix();



		//libros REPISA DERECHA//

		//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 4.4, -9.0);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 4.4, -9.65);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO2//
		glPushMatrix();
		glTranslatef(-10.5, 4.5, -9.15);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.7, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP5.GLindex, textHP5.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO2//
		glPushMatrix();
		glTranslatef(-10.5, 4.5, -8.65);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.7, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP5.GLindex, textHP5.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		//LIBRO3//
		glPushMatrix();
		glTranslatef(-10.5, 4.5, -9.3);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.62, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textPOS.GLindex, textPOS.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 4.5, -8.8);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 4.5, -9.45);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		////LIBROS REPISA CENTRAL///


		//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 4.4, -11.5);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 4.4, -12.15);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO2//
		glPushMatrix();
		glTranslatef(-10.5, 4.5, -11.65);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.7, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP5.GLindex, textHP5.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO2//
		glPushMatrix();
		glTranslatef(-10.5, 4.5, -11.15);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.7, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP5.GLindex, textHP5.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		//LIBRO3//
		glPushMatrix();
		glTranslatef(-10.5, 4.5, -11.8);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.62, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textPOS.GLindex, textPOS.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 4.5, -11.3);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 4.5, -11.95);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		///LIBROS REPISA IZQUERDA

			//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 4.4, -14.5);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 4.4, -15.15);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO2//
		glPushMatrix();
		glTranslatef(-10.5, 4.5, -14.65);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.7, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP5.GLindex, textHP5.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO2//
		glPushMatrix();
		glTranslatef(-10.5, 4.5, -14.15);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.7, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP5.GLindex, textHP5.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		//LIBRO3//
		glPushMatrix();
		glTranslatef(-10.5, 4.5, -14.8);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.62, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textPOS.GLindex, textPOS.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 4.5, -14.3);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 4.5, -14.95);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		///libros arriba escritorio///


			//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 3.9, -18.8);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 3.9, -19.45);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO2//
		glPushMatrix();
		glTranslatef(-10.5, 4.0, -18.95);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.7, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP5.GLindex, textHP5.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		//LIBRO3//
		glPushMatrix();
		glTranslatef(-10.5, 4.0, -19.1);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.62, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textPOS.GLindex, textPOS.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 4.0, -18.7);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 4.0, -19.25);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		///librero arriba 2///


			//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 3.9, -19.8);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 3.9, -20.45);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO2//
		glPushMatrix();
		glTranslatef(-10.5, 4.0, -19.95);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.7, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP5.GLindex, textHP5.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		//LIBRO3//
		glPushMatrix();
		glTranslatef(-10.5, 4.0, -20.1);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.62, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textPOS.GLindex, textPOS.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 4.0, -19.7);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 4.0, -20.25);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		///librero arriba 3///


			//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 4.9, -19.8);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 4.9, -20.45);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO2//
		glPushMatrix();
		glTranslatef(-10.5, 5.0, -19.95);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.7, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP5.GLindex, textHP5.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		//LIBRO3//
		glPushMatrix();
		glTranslatef(-10.5, 5.0, -20.1);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.62, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textPOS.GLindex, textPOS.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 5.0, -19.7);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 5.0, -20.25);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		///librero arriba 4///


			//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 5.9, -18.8);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 5.9, -19.45);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO2//
		glPushMatrix();
		glTranslatef(-10.5, 6.0, -18.95);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.7, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP5.GLindex, textHP5.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		//LIBRO3//
		glPushMatrix();
		glTranslatef(-10.5, 6.0, -19.1);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.62, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textPOS.GLindex, textPOS.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 6.0, -18.7);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 6.0, -19.25);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();



		///librero arriba 5///


			//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 6.9, -19.8);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.5, 6.9, -20.45);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textfrazada.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO2//
		glPushMatrix();
		glTranslatef(-10.5, 7.0, -19.95);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.7, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP5.GLindex, textHP5.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		//LIBRO3//
		glPushMatrix();
		glTranslatef(-10.5, 7.0, -20.1);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.62, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textPOS.GLindex, textPOS.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 7.0, -19.7);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO4//
		glPushMatrix();
		glTranslatef(-10.5, 7.0, -20.25);
		glRotatef(270, 0.0, 0.0, 1.0);
		glScalef(0.8, 0.8, 0.15);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP.GLindex, textHP.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		///laptop///
		glPushMatrix();
		glTranslatef(-14.15, 2.52, -22.06);
		glScalef(1.5, 0.1, 1.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textteclado.GLindex, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(-14.15, 3.07, -22.51);
		glRotatef(90, 1.0, 0.0, 0.0);
		glScalef(1.5, 0.1, 1.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textmac.GLindex, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		///Librosescritorio///
		//LIBRO1//
		glPushMatrix();
		glTranslatef(-12.15, 2.55, -22.06);
		glRotatef(90, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP1.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO2//
		glPushMatrix();
		glTranslatef(-12.15, 2.70, -22.06);
		glRotatef(90, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.7, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP5.GLindex, textHP5.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		///Libros buro///
		//LIBRO1//
		glPushMatrix();
		glTranslatef(-10.95, 1.2, -9.0);
		glRotatef(90, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.6, 0.2);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP1.GLindex, textHP1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//LIBRO2//
		glPushMatrix();
		glTranslatef(-10.95, 1.3, -9.0);
		glRotatef(90, 1.0, 0.0, 0.0);
		glScalef(0.8, 0.7, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textHP5.GLindex, textHP5.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		///closet grande///

		glPushMatrix(); //pared de atras
		glTranslatef(-29.8, 3.7, -18.75);
		glScalef(0.1, 7.2, 4.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //pared de arriba
		glTranslatef(-28.85, 7.35, -18.75);
		glScalef(2.0, 0.1, 4.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //pared de abajo
		glTranslatef(-28.85, 0.25, -18.75);
		glScalef(2.0, 0.1, 4.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //pared izquierda
		glTranslatef(-28.85, 3.7, -16.8);
		glScalef(2.0, 7.2, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //pared DERECHA
		glTranslatef(-28.85, 3.7, -20.7);
		glScalef(2.0, 7.2, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //pared adelante
		glTranslatef(-27.8, 3.8, -18.75);
		glScalef(0.1, 7.2, 4.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //agarradera
		glTranslatef(-27.7, 3.5, -17.25);
		glScalef(0.1, 3.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		///closet grande centro///

		glPushMatrix(); //pared de atras
		glTranslatef(-29.8, 3.7, -14.75);
		glScalef(0.1, 7.2, 4.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //pared de arriba
		glTranslatef(-28.85, 7.35, -14.75);
		glScalef(2.0, 0.1, 4.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //pared de abajo
		glTranslatef(-28.85, 0.25, -14.75);
		glScalef(2.0, 0.1, 4.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //pared izquierda
		glTranslatef(-28.85, 3.7, -12.8);
		glScalef(2.0, 7.2, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //pared DERECHA
		glTranslatef(-28.85, 3.7, -16.7);
		glScalef(2.0, 7.2, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //pared adelante
		glTranslatef(-27.8, 3.8, -14.75);
		glScalef(0.1, 7.2, 4.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //agarradera
		glTranslatef(-27.7, 3.5, -16.0);
		glScalef(0.1, 3.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		///closet grande izquierda///

		glPushMatrix(); //pared de atras
		glTranslatef(-29.8, 3.7, -10.75);
		glScalef(0.1, 7.2, 4.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //pared de arriba
		glTranslatef(-28.85, 7.35, -10.75);
		glScalef(2.0, 0.1, 4.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //pared de abajo
		glTranslatef(-28.85, 0.25, -10.75);
		glScalef(2.0, 0.1, 4.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //pared izquierda
		glTranslatef(-28.85, 3.7, -8.8);
		glScalef(2.0, 7.2, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //pared DERECHA
		glTranslatef(-28.85, 3.7, -12.7);
		glScalef(2.0, 7.2, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //pared adelante
		glTranslatef(0, 0, movTrans);
		glTranslatef(-27.8, 3.8, -10.75);
		glScalef(0.1, 7.2, 4.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //agarradera
		glTranslatef(-27.7, 3.5, -9.5);
		glScalef(0.1, 3.0, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textbase2.GLindex, textbase2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //tubo delcloset
		glTranslatef(-28.7, 6.5, -14.75);
		glScalef(0.1, 0.1, 11.8);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textmetal.GLindex, textmetal.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		//VENTILADOR//
		glPushMatrix();  //BASE
		glTranslatef(-17.0, 9.7, -14.86);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.3, 0.1, 20, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//VENTILADOR//
		glPushMatrix();  //eje
		glTranslatef(-17.0, 9.0, -14.86);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.1, 0.7, 20, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//VENTILADOR//
		glPushMatrix();  //cuerpo
		glTranslatef(-17.0, 8.8, -14.86);
		glRotatef(movRot, 0.0f, 1.0f, 0.0f);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		fig6.cilindro(0.7, 0.3, 20, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//VENTILADOR//
		glPushMatrix();  //aspa1
		glTranslatef(-17.03, 8.9, -14.81);
		glRotatef(movRot, 0.0f, 1.0f, 0.0f);
		glScalef(2.0, 0.1, 0.3);
		glTranslatef(0.7, 1.0, -0.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textmetal2.GLindex, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//VENTILADOR//
		glPushMatrix();  //aspa2
		glTranslatef(-17, 8.9, -14.9);
		glRotatef(movRot, 0.0f, 1.0f, 0.0f);
		glRotatef(180, 0, 1, 0);
		glScalef(2.0, 0.1, 0.3);
		glTranslatef(0.8, 1.0, -0.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textmetal2.GLindex, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//VENTILADOR//
		glPushMatrix();  //aspa3
		glTranslatef(-17, 8.9, -14.8);
		glRotatef(movRot, 0.0f, 1.0f, 0.0f);
		glRotatef(90, 0, 1, 0);
		glScalef(2.0, 0.1, 0.3);
		glTranslatef(0.8, 1.0, -0.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textmetal2.GLindex, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		//VENTILADOR//
		glPushMatrix();  //aspa4
		glTranslatef(-17, 9.1, -14.8);
		glRotatef(movRot, 0.0f, 1.0f, 0.0f);
		glRotatef(180, 1, 0, 0);
		glRotatef(90, 0, 1, 0);
		glScalef(2.0, 0.1, 0.3);
		glTranslatef(0.8, 1.0, -0.5);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textmetal2.GLindex, textmetal2.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix(); //closet 
		glTranslatef(-10.2, 3.2, -16.75);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(0.1, 6.2, 3.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textcloset.GLindex, textcloset.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //closet 
		glTranslatef(-10.9, 6.3, -16.75);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.5, 0.1, 3.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textcloset.GLindex, textcloset.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //closet 
		glTranslatef(-10.9, 0.25, -16.75);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.5, 0.1, 3.0);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textcloset.GLindex, textcloset.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

	
		glPushMatrix(); //closet 
		glTranslatef(-10.9, 3.25, -15.3);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.5, 6.2, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textcloset.GLindex, textcloset.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		

		glPushMatrix(); //puesta1 closet 
		glTranslatef(-11.7, 3.25, -15.24);
       glRotatef(rotPuerta, 0, 1, 0);
		 //glTranslatef(0,0,-0.3);
	   glScalef(0.1, 6.2, 1.5);
	   glTranslatef(-0, 0, -0.50);
	   glDisable(GL_LIGHTING);
	   fig6.prisma2(textcloset.GLindex, textcloset.GLindex);
	   glEnable(GL_LIGHTING);
	   glPopMatrix();
		

		glPushMatrix();
		//closet 
		glTranslatef(-10.9, 3.25, -18.3);
		//glRotatef(240, 0, 1, 0);
		//glRotatef(45, 0, 1, 0);
		glScalef(1.5, 6.2, 0.1);
		glDisable(GL_LIGHTING);
		fig6.prisma2(textcloset.GLindex, textcloset.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		

		glPushMatrix(); //puesta2 closet 
		glTranslatef(-11.7, 3.25, -18.32);
		glRotatef(rotPuerta2, 0, 1, 0);
		glScalef(0.1, 6.2, 1.55);
		glDisable(GL_LIGHTING);
		glTranslatef(-0, 0, 0.50);
		fig6.prisma2(textcloset.GLindex, textcloset.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0,textSky2.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
				glEnable ( GL_COLOR_MATERIAL );
					glColor3f(1, 1, 1);
					//glScalef(0.5, 0.5, 0.5);
					//monito();
					glCallList(ciudad_display_list);
					glTranslatef(posX, posY, posZ);
					glRotatef(giroMonito, 0, 1, 0);
					//monito();
				glDisable ( GL_COLOR_MATERIAL );
			glPopMatrix();			

			glPushMatrix(); //Flecha
				glScalef(7,0.1,7);
				glDisable(GL_LIGHTING);
				fig3.prisma_anun(text3.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();


			//CASA///////////////////
			//¨****casa*****
			glPushMatrix();
				glScalef(1.0, 0.5, 1.0);
				glTranslatef(30, 3, -17.2);
				glRotatef(180, 0, 1, 0);
				glDisable(GL_LIGHTING);
				glScalef(0.3, 0.3, 0.3);
					casa();
				
				glPushMatrix();
					//****cuadros***			
					cuadro();
					//****LIBROS****
					glPushMatrix();
						glTranslatef(26,11,4);
						libros();	
					glPopMatrix();
					//****COMEDOR***
					glPushMatrix();
						glTranslatef(-20,0,25);
						glScalef(1.3,1.3,1.3);
						comedor();
					glPopMatrix();
					//mesa y laptop
					glPushMatrix();
						glRotatef(90, 0,1,0);
						mesa(1,1.5,1,-25,1.4,24);
					glPopMatrix();
				
					/*glPushMatrix();
					glTranslatef(125.2, 3.2, -16.75);
					glPushMatrix();
					
					glRotatef(180, 0, 1, 0);
					glScalef(5, 10, 10);
					closet();
					glPopMatrix();
					glPopMatrix();*/
					glPushMatrix();
						glRotatef(90, 0,1,0);
						dibujaLaptop(.3,.3,.3,-90,9,77);
					glPopMatrix();

					glPushMatrix();
						glRotatef(280, 0,1,0);
						silla(1,1,1,29,0,-24.5);
					glPopMatrix();

					//*****ROSE*****
					glPushMatrix(); 
						glPushMatrix();
							glTranslatef(0,0,-0.5); 
							glRotatef(90, 0,1,0); 
							glTranslatef(2,0,-0.5);
							dibujaCama(1.1,1.1,1.1,14.0,-5.5,-37.0); 
						glPopMatrix();
						glPushMatrix();
							glRotatef(90, 0,1,0); 
							dibujaBuro(1,1,1,-2,-9.5,-42.0); 
						glPopMatrix();
						glPushMatrix();
							glTranslatef(0,47,0);
							glScalef(1.2,1.2,1.2);
							lampara.cono(2.0,0.4,100,textLampara.GLindex);
						glPopMatrix();
					glPopMatrix();
					//******JOAN*****
					//ropero
					glPushMatrix();
						glRotatef(180, 0,1,0);
						glTranslatef(-35,23,-35);
						glScalef(.7,.7,.7);
						ropero();
					glPopMatrix();
				glPopMatrix();

			glEnable(GL_LIGHTING);
			glPopMatrix();
					

			glColor3f(1.0,1.0,1.0);

		glPopMatrix();
	glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
			glColor3f(1.0,0.0,0.0);
			pintaTexto(-11,12.0,-14.0,(void *)font,"PROYECTO FINAL");
			pintaTexto(-11,8.5,-14,(void *)font,s);
			glColor3f(1.0,1.0,1.0);
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void animacion()
{
	fig3.text_izq-= 0.001;
	fig3.text_der-= 0.001;
	if(fig3.text_izq<-1)
		fig3.text_izq=0;
	if(fig3.text_der<0)
		fig3.text_der=1;




	//Movimiento del monito
	if(play)
	{		
		
		if(	i_curr_steps >= i_max_steps) //end of animation between frames?
		{			
			playIndex++;		
			if(playIndex>FrameIndex-2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex=0;
				play=false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
				//Interpolation
				interpolation();

			}
		}
		else
		{
			//Draw animation
			posX+=KeyFrame[playIndex].incX;
			posY+=KeyFrame[playIndex].incY;
			posZ+=KeyFrame[playIndex].incZ;

			rotRodIzq+=KeyFrame[playIndex].rotInc;
			rotRodDer += KeyFrame[playIndex].rotInc2;
			rotBrazDer += KeyFrame[playIndex].rotInc3;
			rotBrazIzq += KeyFrame[playIndex].rotInc4;
			rotPuerta += KeyFrame[playIndex].rotInc5;
			rotPuerta2 += KeyFrame[playIndex].rotInc6;
			giroMonito+=KeyFrame[playIndex].giroMonitoInc;

			i_curr_steps++;
		}
		
	}


	if (g_fanimacion)
	{

		movRot += 1.0;
	
	}
	


	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'k':		//
		case 'K':
			if(FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}

			break;

		case 'l':						
		case 'L':
			if(play==false && (FrameIndex>1))
			{

				resetElements();
				//First Interpolation				
				interpolation();

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;

		case 'y':						
		case 'Y':
			posZ++;
			printf("%f \n", posZ);
			break;

		case 'g':						
		case 'G':
			posX--;
			printf("%f \n", posX);
			break;

		case 'h':						
		case 'H':
			posZ--;
			printf("%f \n", posZ);
			break;

		case 'j':						
		case 'J':
			posX++;
			printf("%f \n", posX);
			break;

		case 'b':						
			rotRodIzq++;
			printf("%f \n", rotRodIzq);
			break;

		case 'B':						
			rotRodIzq--;
			printf("%f \n", rotRodIzq);
			break;

		case 'n':
			rotRodDer++;
			printf("%f \n", rotRodDer);
			break;

		case 'N':
			rotRodDer--;
			printf("%f \n", rotRodDer);
			break;

		case 'u':
			rotBrazDer++;
			printf("%f \n", rotBrazDer);
			break;

		case 'U':
			rotBrazDer--;
			printf("%f \n", rotBrazDer);
			break;

		case 'i':
			rotBrazIzq++;
			printf("%f \n", rotBrazIzq);
			break;

		case 'I':
			rotBrazIzq--;
			printf("%f \n", rotBrazIzq);
			break;

		case 'z':
			rotPuerta++;
			printf("%f \n", rotPuerta);
			break;

		case 'Z':
			rotPuerta--;
			printf("%f \n", rotPuerta);
			break;

		case 'x':
			rotPuerta2--;
			printf("%f \n", rotPuerta2);
			break;

		case 'X':
			rotPuerta2++;
			printf("%f \n", rotPuerta2);
			break;


		case 'p':						
			giroMonito++;
			break;

		case 'P':						
			giroMonito--;
			break;

		case ' ':		//Poner algo en movimiento
			g_fanimacion ^= true; //Activamos/desactivamos la animacíon
			break;


		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

void menuKeyFrame( int id)
{
	switch (id)
	{
		case 0:	//Save KeyFrame
			if(FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}
			break;

		case 1:	//Play animation
			if(play==false && FrameIndex >1)
			{

				resetElements();
				//First Interpolation
				interpolation();

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;


	}
}


void menu( int id)
{
	
}



int main ( int argc, char** argv )   // Main Function
{
  int submenu;
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("PROYECTO FINAL"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );

  submenu = glutCreateMenu	  ( menuKeyFrame );
  glutAddMenuEntry	  ("Guardar KeyFrame", 0);
  glutAddMenuEntry	  ("Reproducir Animacion", 1);
  glutCreateMenu	  ( menu );
  glutAddSubMenu	  ("Animacion Monito", submenu);
 
  glutAttachMenu	  (GLUT_RIGHT_BUTTON);


  glutMainLoop        ( );          // 

  return 0;
}