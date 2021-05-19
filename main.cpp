#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctime>
#include <sys/types.h>
#include <stdio.h>
#include <Windows.h>

#include "SourceAndMaterial.h"
#include "Globals.h"
#include "Functions.h"

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);

    glutCreateWindow("Explosion demo");
    glutReshapeWindow(SCR_WIDTH, SCR_HEIGHT);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    srand(time(NULL));

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0Amb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0Dif);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0Spec);
    glLightfv(GL_LIGHT0, GL_POSITION, light0Pos);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1Amb);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1Dif);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1Spec);
    glLightfv(GL_LIGHT1, GL_POSITION, light1Pos);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialDif);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
    glEnable(GL_NORMALIZE);

    glutCreateMenu(menuSelect);
    glutAddMenuEntry("Pause", PAUSE);
    glutAddMenuEntry("Quit", QUIT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();

    return 0;
}