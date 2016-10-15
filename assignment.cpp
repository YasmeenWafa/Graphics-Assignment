#include <stdlib.h>

#include <glut.h>
#include <stdio.h> 
#include <math.h>


double x;
double y;

double xcord = 225;
double ycord = 225;
int score = 0;
double x_ = 0;
double y_ = 500;
double vecX;
double vecY;
double vecX_;
double vecY_;
double VectorX;
double VectorY;
const double PI = 3.141592653589793238463;
double angle;

void Display(void);
void Anim(void);
void move(int,int);


void main(int argc, char** argr)
{
	

	glutInit(&argc, argr);
	  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	  glutInitWindowSize(500, 500);
	  
	  glutInitWindowPosition(50, 50);
	  glutCreateWindow("trial");
	  glutDisplayFunc(Display);
	  //glutFullScreen();
	  glutIdleFunc(Anim);
	  glPointSize(25);
	  glutPassiveMotionFunc(move);
	 
	  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	  gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	  glutMainLoop();
	
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);


	
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
	if (xcord <= x_ + 50 && xcord >= x_)
	{
		x_ = 0;
		y_ = 500;
		score++;
		
	}
	if (x_ <= 500 && x_ >= 499)
	{
		x_ = 0;
		y_ = 500;
	}
	
	
	vecX = xcord - x;
	vecY = ycord - y;
	
	/*vecX_ = x - x_;
	vecY_ = y - y_;*/

	double length = sqrt((vecX*vecX) + (vecY*vecY));
	double length_ = sqrt((vecX_*vecX_) + (vecY_*vecY_));

	x += (vecX/length)-0.65;
	y += (vecY/length)-0.65;

	x_ += 0.04;
	y_ -= 0.04;
	/*x_ += (vecX_ / length_);
	y_ += (vecY_ / length_);*/


	if (glutGet(GLUT_ELAPSED_TIME) == 300000) //5 minutes
	{
		printf("hi");
		glutEnterGameMode(); // it stops execution
	
		

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



