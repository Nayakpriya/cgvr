#include<GL/glut.h>
#include<iostream>
#include<math.h>

double c, c80, phir20,phir, phi, t, tr,x,y,z;


void sphere() {
    c = 3.14 / 180;
    
    for (phi = -80.0; phi <= 60.0; phi += 20.0)
    {
        glBegin(GL_QUAD_STRIP);
        phir = phi * c;
        for (t = -180.0; t <= 180.0; t+=20.0)
        {
            tr = c * t;
            x = sin(tr) * cos(phir);
            y = cos(tr) * cos(phir);
            z = sin(phir);
            glVertex3d(x, y, z);

            phir20 = c * (phi + 20);
            x = sin(tr) * cos(phir20);
            y = cos(tr) * cos(phir20);
            z = sin(phir20);
            glVertex3d(x, y, z);
        }
        glEnd();
    }

    c80 = 80.0 * c;
    z = sin(c80);
    
    glBegin(GL_TRIANGLE_FAN);
    glVertex3d(0.0, 0.0, 1.0);
    for (t = -180.0; t <= 180.0; t += 20.0) {
        tr = t * c;
        x = sin(tr) * cos(c80);
        y = cos(tr) * cos(c80);
        glVertex3d(x, y, z);
        
    }
    glEnd();

    z = -sin(c80);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3d(0.0, 0.0, -1.0);
    for (t = -180.0; t <= 180.0; t += 20.0) {
        tr = t * c;
        x = sin(tr) * cos(c80);
        y = cos(tr) * cos(c80);
        glVertex3d(x, y, z);

    }
    glEnd();

}


void display() {
    glClear(GL_COLOR_BUFFER_BIT );
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLoadIdentity();
  

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -1);
    glRotatef(-90.0, 0.0, 1.0, 0.0);
    sphere();
    glFlush();
}

void myInit() {
    

    glClearColor(1, 1, 1, 1);
    glColor3f(1.0, 0,0);
    glOrtho(-500, 500, -500, 500, -500, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("sphere");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
}
