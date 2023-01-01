
#include<stdlib.h>
#include<gl/glut.h>
#include<iostream>


int x1, x2, yc1, y2;

// function to draw a pixel
void drawPixel(int x, int y)
{
	glColor3f(0, 0, 1); //blue
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void drawLine()
{
	int dx, dy, i, e;
	int incx = 1, incy = 1, inc1, inc2;
	int x, y;
	dx = x2 - x1;
	dy = y2 - yc1;
	if (dx == 0)
	{
		for (i = 0; i <= dy; i++)
			drawPixel(x1, yc1 + i);
		return;
	}
	if (dy == 0)
	{
		for (i = 0; i <= dx; i++)
			drawPixel(x1 + i, yc1);
		return;
	}
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	if (x2 < x1)
		incx = -1;
	if (y2 < yc1)
		incy = -1;
	x = x1;
	y = yc1;
	if (dx > dy)
	{
		drawPixel(x, y);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++)
		{
			if (e > 0)
			{
				y = y + incy;
				e = e + inc1;
			}
			else
			{
				e = e + inc2;
			}
			x = x + incx;
			drawPixel(x, y);
		}
	}
	else
	{
		drawPixel(x, y);
		e = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++)
		{
			if (e > 0)
			{
				x = x + incx;
				e = e + inc1;
			}
			else
				e = e + inc2;
			y = y + incy;
			drawPixel(x, y);
		}
	}
	glFlush();
}

void myInit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1, 1);
	gluOrtho2D(-250, 250, -250, 250);
}

int main(int argc, char** argv)
{
		std::cout << "Enter x1 : ";
		std::cin >> x1;
		std::cout << "Enter yc1 : ";
		std::cin >> yc1;
		std::cout << "Enter x2 : ";
		std::cin >> x2;
		std::cout << "Enter y2 : ";
		std::cin >> y2;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("Line Drawing");
		glutDisplayFunc(drawLine);
		myInit();
	glutMainLoop();
}
