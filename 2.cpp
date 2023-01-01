#include<stdlib.h>
#include<GL/glut.h>
#include<iostream>

int xc, yc, r;

void plot(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc - y, yc + x);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - y, yc - x);
	glEnd();



}

void circle() {
	int x = 0, y = r;
	int d = 1 - r;
	while (x< y) {
		plot(x, y);
		
		if (d < 0) {
			d = d + 2 * x + 3;


		}
		else {
			
			d = d + 2 * x - 2 * y + 5;
			y--;
		}
		x++;
		
		plot(x, y);

	}
	glFlush();

}


void mydisplay() {

	
	circle();
	glFlush();
}

void myinit() {
	glColor3f(1.0, 0.0, 0.0);
	glClearColor(1, 1, 1, 1);
	
	
	glPointSize(1);
	gluOrtho2D(-250,250,-250,250);


}

int main(int argc,char ** argv)
{
	std::cout << "Enter co\n";
	std::cin >> xc >> yc >> r;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Hi");
	glutDisplayFunc(mydisplay);
	myinit();
	glutMainLoop();
	
}


