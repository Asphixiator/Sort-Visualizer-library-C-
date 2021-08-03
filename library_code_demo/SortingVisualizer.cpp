#include<iostream>
#include<vector>
#include<limits>
#include<stdlib.h>
#include<algorithm>
#include<time.h>
#include<unistd.h>

#include<GL/glut.h>
#include "GL/gl.h"


using namespace std;


int length, delay;
vector<int> list;
void (*sortptr)(vector<int>*, int);


void display()
{
    glClearColor(0.184314, 0.184314, 0.309804, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);


    float l = (float) length;
    float width = 1/l;

    for(int i = 0; i < length; i++) {
        glBegin(GL_POLYGON);
            float indexToHeight = 2 * (list[i] + 1)/l;
            float widthAdder = 2*i/l;

            float left = -1 + widthAdder;
            float right = left + width;
            float bottom = -1;
            float top = bottom + indexToHeight;
            

            glColor4f(1, 0, 0, 0);
            glVertex2f(left, bottom);

            glColor4f(1, 0, 1, 0);
            glVertex2f(right, bottom);

            glColor4f(0, 1, 0, 0);
            glVertex2f(right, top);

            glColor4f(0, 0, 1, 0);
            glVertex2f(left, top);
        
        
        /*  TEST CODE
        
            glColor4f(1, 0, 0, 0);
            glVertex2f(-0.5, -0.5);

            glColor4f(1, 0, 1, 0);
            glVertex2f(-0.5, 0.5);

            glColor4f(1, 1, 0, 0);
            glVertex2f(0.5, 0.5);

            glColor4f(0, 0, 1, 0);
            glVertex2f(0.5, -0.5);
        */    

        glEnd();
    }
    glutSwapBuffers();
}   


void keyboardEvent(unsigned char key, int x, int y) {
     if(key == 27) {
        cout << "[Stop] Success" << "\n";
        exit(0);
    }
    else if (key == 115){
        cout << "[Start] Success" << "\n";
        sortptr(&list, length);
    }
}


void swap(int a, int b) {
    std::swap(list[a], list[b]);
    display();
    usleep(delay);
}


void setupVisualizer(int argc, char** argv, void (*sortAlgorithm) (vector<int>*, int)) {
    

    sortptr = sortAlgorithm;

    cout << "\nEnter the length for the array to be visualized: ";
    cin >> length;

    cout << "\nSet a delay for the animation: ";
    cin >> delay;

    for (int i = 0; i < length; i++)
        list.push_back(i);

    random_shuffle(list.begin(), list.end());
    // list.push_back(numeric_limits<int>::max());
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL- Sort Visualizer");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardEvent);
    glutMainLoop();
}


