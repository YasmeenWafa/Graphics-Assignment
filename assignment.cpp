#include <stdlib.h>
#include <glut.h>
#include <stdio.h>

#include <math.h>
#include <sstream>
#include <windows.h>
#include <string> 

int count = 0;
char *specialStatus = "Not ready";
double height;
double width;
int time;
double x;
double y;
double scx = 500;
double scy = 500;
boolean doublescore;
boolean chasersstun;
boolean specialpower;
double xo=0;
double yo=0;
double xcord = 225;
double ycord = 225;
int score = 0;
double x_ = xcord+ 50;
double y_ = ycord+50;
double x1_ = xcord + 50;
double y1_ = ycord + 50;
double vecX;
double vecY;
double vecX_;
double vecY_;
double vecXo;
double vecYo;
double vecX1_;
double vecY1_;
double VectorX;
double VectorY;
const double PI = 3.141592653589793238463;
double angle;
double tt;

void Display(void);
void Anim(void);
void move(int,int);
void keyboard(unsigned char key, int x, int y);
void displayText(float x, float y, int r, int g, int b, const char *string);


void main(int argc, char** argr)
{
	

	glutInit(&argc, argr);
	  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	 // glutInitWindowSize(scx, scy);
	 // height = glutGet(GLUT_SCREEN_HEIGHT);
	  //width = glutGet(GLUT_SCREEN_WIDTH);

	  height = 500;
	  width = 500;
	  glutInitWindowSize(width, height);

	  glutInitWindowPosition(50, 50);
	  glutCreateWindow("assignment");
	  glutDisplayFunc(Display);
	  
	  glutIdleFunc(Anim);
	  glPointSize(25);
	  glutPassiveMotionFunc(move);
	  glutKeyboardFunc(keyboard);
	 // glutFullScreen();
	 
	 
	  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	  gluOrtho2D(0.0, height, 0.0, width);
	  //gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	  glutMainLoop();
	
}


void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	/*glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	std::string tt;
	tt = std::to_string(glutGet(GLUT_ELAPSED_TIME));
	char *s = new char[50];
	strcpy(s, tt.c_str);
	

	displayText(100, 100, 1, 0, 1, s);
	glPopMatrix();*/

	glPushMatrix();
	displayText(100, width-100, 1, 0, 1, specialStatus);
	glPopMatrix();


	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);

	glTranslated(xo, yo, 0);
	glRotated(angle, 0, 0, 1);
	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 0.0f, 0.0f);
	glEnd();


	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_TRIANGLES); // GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN
	glVertex3f(0.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 50.0f, 0.0f);
	glVertex3f(25.0f, 75.0f, 0.0f);
	glEnd();
	glPopMatrix();
	//CHASER
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	
	glTranslated(x, y, 0);
	glRotated(angle, 0, 0, 1);
	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 0.0f, 0.0f);
	glEnd();


	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_TRIANGLES); // GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN
	glVertex3f(0.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 50.0f, 0.0f);
	glVertex3f(25.0f, 75.0f, 0.0f);
	glEnd();
	glPopMatrix();
	
	//Player
	//
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslated(xcord, ycord, 0);
	glRotated(angle, 0, 0, 1);
	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 0.0f, 0.0f);
	glEnd();


	glColor3f(1.0f, 0.0f, 1.0f);

	glBegin(GL_TRIANGLES); // GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN
	glVertex3f(0.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 50.0f, 0.0f);
	glVertex3f(25.0f, 75.0f, 0.0f);
	glEnd();
	glPopMatrix();

	//object chased

	glPushMatrix();
	glColor3f(0.0f, 1.0f, 0.0f);

	glTranslated(x1_, y1_, 0);
	glRotated(angle, 0, 0, 1);
	
	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 0.0f, 0.0f);
	glEnd();


	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_TRIANGLES); // GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN
	glVertex3f(0.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 50.0f, 0.0f);
	glVertex3f(25.0f, 75.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0f, 1.0f, 0.0f);

	glTranslated(x_, y_, 0);
	glRotated(angle, 0, 0, 1);

	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 0.0f, 0.0f);
	glEnd();


	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_TRIANGLES); // GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN
	glVertex3f(0.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 50.0f, 0.0f);
	glVertex3f(25.0f, 75.0f, 0.0f);
	glEnd();
	glPopMatrix();

	

	glFlush();
}

void Anim(void)
{
	

	if ((x >= xcord-50 && x<= xcord)) {
		x = 0;
		y = 0;
		//printf("hi");
		score--;
	}
	if ((xo >= xcord - 50 && xo <= xcord)) {
		xo = 0;
		yo = 0;
		//printf("hi");
		score--;
	}
	if (xcord >= x_ && xcord <= x_ + 50)
	{
		x_ = xcord+50;
		y_ = ycord +50;
		if (doublescore == false)
			score++;
		else
			score -= 2;
	}
	if (xcord >= x1_ && xcord <= x1_ + 50)
	{
		x1_ = xcord + 50;
		y1_ = ycord + 50;
		if (doublescore == false)
		score++;
		else score += 2;

	}
	if ((x_ <= width && x_ >= width-1 )|| x_ <= 0)
	{
		x_ = xcord +50;
		y_ = ycord +50;
	}
	if ((x1_ <= width && x1_ >= width-1) || x1_<=0)
	{
		x1_ = xcord + 50;
		y1_ = ycord + 50;
	}
	
	
	vecX = 2*(xcord - x);
	vecY = 2*(ycord - y);
	
	vecX_ = 2*(x_ - xcord);
	vecY_ = 2*(y_ - ycord);

	double length = sqrt((vecX*vecX) + (vecY*vecY));
	double length_ = sqrt((vecX_*vecX_) + (vecY_*vecY_));

	vecXo = 2*(xcord - xo);
	vecYo = 2*(ycord - yo);

	vecX1_ = 2*(x1_ - xcord);
	vecY1_ = 2*(y1_ - ycord);

	double lengtho = sqrt((vecXo*vecXo) + (vecYo*vecYo));
	double length1_ = sqrt((vecX1_*vecX1_) + (vecY1_*vecY1_));

	if (chasersstun == false) {
		x += (vecX / length) - 0.65;
		y += (vecY / length) - 0.65;
		xo += (vecXo / lengtho) - 0.5;
		yo += (vecYo / lengtho) - 0.5;
	}

	x_ += (vecX_ / length_)-0.65;
	y_ -= (vecY_ / length_)-0.75;

	x1_ += (vecX1_ / length1_)/4;
	y1_ -= (vecY1_ / length1_);



	if (glutGet(GLUT_ELAPSED_TIME) == 300000) //5 minutes
	{
		printf("hi");
		exit(0); // it stops execution
	}

	if ((count >= 1))
	{
		specialStatus = "No more powers!";
	}
	if ((count == 0) && (glutGet(GLUT_ELAPSED_TIME) >= 30000) && (glutGet(GLUT_ELAPSED_TIME) < 60000))
	{
		specialStatus = "ready";
	}
	if ((count == 0) && (glutGet(GLUT_ELAPSED_TIME) < 30000))
	{
		specialStatus = "Not ready";
	}

	if (tt >= 30000)
	{
		if (specialpower == true) {

			if (doublescore == true || chasersstun ==true) {
				
				specialStatus = "active";
				if (tt + 30000 < glutGet(GLUT_ELAPSED_TIME))
				{
					doublescore = false;
					chasersstun = false;
					specialpower = false;
					
					specialStatus = "No more powers!";
				}
				
			}
		
		}
		
	}
	
	

	glutPostRedisplay();
}


void move(int xx, int yy)
{
	xcord = xx -25;
	ycord = (width) - yy - 25;

	VectorX =  xcord-xx;
	VectorY = ycord - yy;

	angle = atan2(VectorX, VectorY) * (180 / PI);

	
}

void keyboard(unsigned char key, int x, int y) {

	switch (key)
	{
	case (27) : exit(0); break;

	case('f') : glutFullScreen(); break;
	case ('d') : if (count < 1) {
		specialpower = true;
		doublescore = true;
		 tt = glutGet(GLUT_ELAPSED_TIME);

		count++;
	}
				 break;
	case('c') : if (count < 1) {

		specialpower = true;
		chasersstun = true;
		count++;
		 tt = glutGet(GLUT_ELAPSED_TIME);

	}
				break;
	}
	
	
	
}

void displayText(float x, float y, int r, int g, int b, const char *string)
{
	int j = strlen(string);
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for (int i = 0; i < j; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}




