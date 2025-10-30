#include <iostream>
//#include <GLUT/glut.h> <- for MacOS
#include <GL/glut.h> //for windows

using namespace std;

void defaultDisplay();
void displayTriangles();
void rotatetriangle();
void keyboard(unsigned char key, int x, int y);


GLfloat angle = 0.0f; // this is for rotation angle
GLfloat scaleFactor = 1.0f; // scale factor for zoom
GLfloat speed = 0.05f; // rotation speed


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




void displayTriangles() {
    glPushMatrix(); 
    glScalef(scaleFactor, scaleFactor, 1.0f); 
    glRotatef(angle, 0.0f, 0.0f, 1.0f); 

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    
    glColorPointer(3, GL_FLOAT, 0, colors);
    glVertexPointer(3, GL_FLOAT, 0, trianglevertices);
    glDrawArrays(GL_TRIANGLES, 0, 12); 
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glPopMatrix(); // Restore the original matrix
}



void defaultDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    displayTriangles();
    glFlush();
}


void rotatetriangle() {
    angle += speed; //responsible for making the rotation slower or faster
    //currently the speed is set to slow, the smaller the value the slower the rotation
    if (angle > 360.0f) {
        angle -= 360.0f;
    }
    glutPostRedisplay(); 
}

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'l':
        case 'L':
            scaleFactor += 0.1f; // zoom in
            cout << "Zoom In Activated - Scale: " << scaleFactor << endl;
            break;
        case 'm':
        case 'M':
            scaleFactor -= 0.1f; // zoom out
            if (scaleFactor < 0.1f) { // prevent negative/zero scale
                scaleFactor = 0.1f;
            }
            cout << "Zoom Out Activated - Scale: " << scaleFactor << endl;
            break;
        case '+':
            speed += 0.01f;
			cout << "Increase Speed - Speed: " << speed << endl;
            break;
        case '-':
			speed -= 0.01f;
            if (speed < 0.01f) {
                speed = 0.01f;
            }
            cout << "Decrease Speed - Speed: " << speed << endl;
            break;
    }
    glutPostRedisplay(); 
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("DePaz & Dela Cruz LAB5");
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    
    glutDisplayFunc(defaultDisplay);
    glutIdleFunc(rotatetriangle); 
    glutKeyboardFunc(keyboard); 
    
    glutMainLoop();
    return 0;
}