#include <iostream>
#include <GL/glut.h>
using namespace std;

void defaultDisplay();
void displayTriangles();
void rotatetriangle();  

GLfloat angle = 0.0f; // this is for rotation angle 


GLfloat colors[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};

GLfloat trianglevertices[] = {
    0.0f, 0.0f, 0.0f,  -0.5f, 0.10f, 0.0f,  -0.5f, -0.10f, 0.0f, // LEFT
    0.0f, 0.0f, 0.0f,   0.5f, 0.10f, 0.0f,   0.5f, -0.10f, 0.0f, // RIGHT
    0.0f, 0.0f, 0.0f,  -0.10f, 0.50f, 0.0f,   0.10f, 0.50f, 0.0f, // UP
    0.0f, 0.0f, 0.0f,  -0.10f, -0.50f, 0.0f,  0.10f, -0.50f, 0.0f  // DOWN
};

GLfloat quadvertices[] = {
    -0.5f, -0.7f, 0.0f,
     0.5f, -0.7f, 0.0f,
     0.5f, -0.9f, 0.0f,
    -0.5f, -0.9f, 0.0f
};

void displayTriangles() {
    glPushMatrix();
	glRotatef(angle, 0.0f, 0.0f, 1.0f); 
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glVertexPointer(3, GL_FLOAT, 0, trianglevertices);
    glDrawArrays(GL_TRIANGLES, 0, 12);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glPopMatrix();
}


void defaultDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    displayTriangles();
    glFlush();
}

void rotatetriangle() {
	angle += 0.05f; //responsible for making the rotation slower or faster
	//currently the speed is set to slow, the smaller the value the slower the rotation
    if (angle > 360.0f) {
        angle -= 360.f;
	}   
	glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("DePaz_DelaCruz_Lab5");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(defaultDisplay);
	glutIdleFunc(rotatetriangle);   
    glutMainLoop();
    return 0;
}
