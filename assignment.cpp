#include <stdlib.h>

#include <glut.h>
#include <stdio.h> 
#include <math.h>


double x;
double y;

double xcord = 225;
double ycord = 225;
int score = 0;
double x_ = xcord + 50;
double y_ = ycord;


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


	//glColor3f(1.0f, 0.0f, 0.0f);
	
	//CHASER
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	
	glTranslated(x, y, 0);
	glRotated(-30, 0, 0, 1);
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
	
	
	//
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslated(xcord, ycord, 0);
	//glRotated(-30, 0, 0, 1);
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
	glRotated(-120, 0, 0, 1);
	
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
	if ((x >= xcord-50 && x<= xcord) &&( y >= ycord-50 && y<= ycord)) {
		x = 0;
		y = 0;
		//printf("hi");
		score--;
	}
	if (xcord <= x_ + 50 && xcord >= x_)
	{
		score++;
		
	}
	if (x_ <= 500 && x_ >= 499)
	{
		x_ = xcord + 50;
		y_ = ycord;
	}

	x += 0.04;
	y += 0.04;

	x_ += 0.04;
	y_ -= 0.04;
	glutPostRedisplay();
}
void move(int xx, int yy)
{
	xcord = x - 25;
	ycord = 500 - y - 25;
	x = xx;
	y = 500- yy;
	x_ = xx;
	y_ = 500 -yy;
}
