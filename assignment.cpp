#include <stdlib.h>

#include <glut.h>
#include <stdio.h> 
#include <math.h>

void Display(void);
void Anim(void);
double x;
double y;
double xcord=400;
double ycord = 400;

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

	  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	  gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	  glutMainLoop();
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);


	//glColor3f(1.0f, 0.0f, 0.0f);
	

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	
	glTranslated(x, y, 0);
	glRotated(-30, 0, 0, 1);
	glBegin(GL_POLYGON);
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
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslated(xcord, ycord, 0);
	//glRotated(-30, 0, 0, 1);
	glBegin(GL_POLYGON);
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

	//1st shape
	//glColor3f(1.0f, 1.0f, 0.0f);


	//glBegin(GL_POLYGON);
	//glVertex3f(200.0f, 200.0f, 0.0f);
	//glVertex3f(200.0f, 250.0f, 0.0f);
	//glVertex3f(250.0f, 250.0f, 0.0f);
	//glVertex3f(250.0f, 200.0f, 0.0f);
	//glEnd();


	//glColor3f(1.0f, 0.0f, 0.0f);

	//glBegin(GL_TRIANGLES); // GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN
	//glVertex3f(200.0f, 250.0f, 0.0f);
	//glVertex3f(250.0f, 250.0f, 0.0f);
	//glVertex3f(225.0f, 275.0f, 0.0f);
	//glEnd();
	////


	//////////
	 	


	///////////


	//glColor3f(1.0f, 1.0f, 0.0f);


	//glBegin(GL_POLYGON);
	//glVertex3f(300.0f, 300.0f, 0.0f);
	//glVertex3f(300.0f, 350.0f, 0.0f);
	//glVertex3f(350.0f, 350.0f, 0.0f);
	//glVertex3f(350.0f, 300.0f, 0.0f);
	//glEnd();


	//glColor3f(1.0f, 0.0f, 0.0f);

	//glBegin(GL_TRIANGLES); // GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN
	//glVertex3f(300.0f, 350.0f, 0.0f);
	//glVertex3f(350.0f, 350.0f, 0.0f);
	//glVertex3f(325.0f, 375.0f, 0.0f);
	//glEnd();

	glFlush();
}

void Anim(void)
{
	if (x == xcord || y == ycord) {
		x = 0;
		y = 0;
	}
	
	x += 0.01;
	y += 0.01;
	glutPostRedisplay();
}
