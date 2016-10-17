#include <stdlib.h>

#include <glut.h>
#include <stdio.h> 
#include <math.h>
#include <sstream>
#include <windows.h>


double x;
double y;
double scx = 500;
double scy = 500;
boolean doublescore= false;
boolean chasersstun = false;
boolean specialpower = false;
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

void Display(void);
void Anim(void);
void move(int,int);
void exit(unsigned char key, int x, int y);

void main(int argc, char** argr)
{
	

	glutInit(&argc, argr);
	  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	  glutInitWindowSize(scx, scy);
	 
	  

	  glutInitWindowPosition(50, 50);
	  glutCreateWindow("assignment");
	  glutDisplayFunc(Display);
	  
	  glutIdleFunc(Anim);
	  glPointSize(25);
	  glutPassiveMotionFunc(move);
	  glutKeyboardFunc(exit);
	 
	  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	  gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	  glutMainLoop();
	
}


void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	

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
	if (x_ <= scx && x_ >= scx-1)
	{
		x_ = xcord +50;
		y_ = ycord +50;
	}
	if (x1_ <= scx && x1_ >= scx-1)
	{
		x1_ = xcord + 50;
		y1_ = ycord + 50;
	}
	
	
	vecX = xcord - x;
	vecY = ycord - y;
	
	vecX_ = x_ - xcord;
	vecY_ = y_ - ycord;

	double length = sqrt((vecX*vecX) + (vecY*vecY));
	double length_ = sqrt((vecX_*vecX_) + (vecY_*vecY_));

	vecXo = xcord - xo;
	vecYo = ycord - yo;

	vecX1_ = x1_ - xcord;
	vecY1_ = y1_ - ycord;

	double lengtho = sqrt((vecXo*vecXo) + (vecYo*vecYo));
	double length1_ = sqrt((vecX1_*vecX1_) + (vecY1_*vecY1_));

	x += (vecX/length)-0.65;
	y += (vecY/length)-0.65;
	xo += (vecXo / lengtho) - 0.5;
	yo += (vecYo / lengtho) - 0.5;

	x_ += (vecX_ / length_)-0.65;
	y_ -= (vecY_ / length_)-0.75;

	x1_ += (vecX1_ / length1_)/4;
	y1_ -= (vecY1_ / length1_);



	if (glutGet(GLUT_ELAPSED_TIME) == 300000) //5 minutes
	{
		printf("hi");
		glutEnterGameMode(); // it stops execution
	
		

	}
	if (glutGet(GLUT_ELAPSED_TIME) == 30000)
	{
		if (specialpower == false) {
			while (glutGet(GLUT_ELAPSED_TIME) <= 60000)
			{
				doublescore = true;
			}
		}
		else {
			while (glutGet(GLUT_ELAPSED_TIME) <= 60000)
			{
				xo = 0;
				yo = 0;
				x  =  0;
				y = 0;
			}
		}
	}

	

	glutPostRedisplay();
}

void move(int xx, int yy)
{
	xcord = xx - 25;
	ycord = 500 - yy - 25;

	VectorX =  xcord-xx;
	VectorY = ycord - yy;

	angle = atan2(VectorX, VectorY) * (180 / PI);

	
}

void exit(unsigned char key, int x, int y) {
	if (key == 27) //escape key to terminate
	{
		exit(0);
	}
	if (key == 'f') { //to enter full screen
		glutFullScreen();
		scx = 1366;
			scy = 768;
		
	}
	
}



