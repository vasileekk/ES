#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <stdio.h>
#include <mmsystem.h>
#include <Windows.h>

// newSpeed - Randomize a new speed vector.
void newSpeed(float dest[3]) {
    float x;
    float y;
    float z;
    float len;

    x = (2.0 * ((GLfloat)rand()) / ((GLfloat)RAND_MAX)) - 1.0;
    y = (2.0 * ((GLfloat)rand()) / ((GLfloat)RAND_MAX)) - 1.0;
    z = (2.0 * ((GLfloat)rand()) / ((GLfloat)RAND_MAX)) - 1.0;

    /*
     * Normalizing the speed vectors gives a "fireball" effect
     */
    if (wantNormalize) {
        len = sqrt(x * x + y * y + z * z);

        if (len) {
            x = x / len;
            y = y / len;
            z = z / len;
        }
    }

    dest[0] = x;
    dest[1] = y;
    dest[2] = z;
}

// newExplosion - Create a new explosion.
void newExplosion(void) {
    int i;
    for (i = 0; i < NUM_PARTICLES; i++) {
        particles[i].position[0] = 0.0;
        particles[i].position[1] = 0.0;
        particles[i].position[2] = 0.0;

        particles[i].color[0] = 1.0;
        particles[i].color[1] = 1.0;
        particles[i].color[2] = 0.5;

        newSpeed(particles[i].speed);
    }

    for (i = 0; i < NUM_DEBRIS; i++) {
        debris[i].position[0] = 0.0;
        debris[i].position[1] = 0.0;
        debris[i].position[2] = 0.0;

        debris[i].orientation[0] = 0.0;
        debris[i].orientation[1] = 0.0;
        debris[i].orientation[2] = 0.0;

        debris[i].color[0] = 0.4;
        debris[i].color[1] = 0.4;
        debris[i].color[2] = 0.4;

        debris[i].scale[0] = (2.0 *
            ((GLfloat)rand()) / ((GLfloat)RAND_MAX)) - 1.0;
        debris[i].scale[1] = (2.0 *
            ((GLfloat)rand()) / ((GLfloat)RAND_MAX)) - 1.0;
        debris[i].scale[2] = (2.0 *
            ((GLfloat)rand()) / ((GLfloat)RAND_MAX)) - 1.0;

        newSpeed(debris[i].speed);
        newSpeed(debris[i].orientationSpeed);
    }
    PlaySound(L"Boom1.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
    fuel = 155;
}

//display - Draw the scene.
void display(void) {
    int i;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    /* Place the camera */

    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(angle, 0.0, 1.0, 0.0);

    /* If no explosion, draw cube */

    if (fuel == 0) {
        glEnable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
        glutSolidCube(1.0);
    }

    if (fuel > 0) {
        glPushMatrix();

        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH_TEST);

        glBegin(GL_POINTS);

        for (i = 0; i < NUM_PARTICLES; i++) {
            glColor3fv(particles[i].color);
            glVertex3fv(particles[i].position);
        }

        glEnd();

        glPopMatrix();

        glEnable(GL_LIGHTING);
        glEnable

        (GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);

        glNormal3f(0.0, 0.0, 1.0);

        for (i = 0; i < NUM_DEBRIS; i++) {
            glColor3fv(debris[i].color);

            glPushMatrix();

            glTranslatef(debris[i].position[0],
                debris[i].position[1],
                debris[i].position[2]);

            glRotatef(debris[i].orientation[0], 1.0, 0.0, 0.0);
            glRotatef(debris[i].orientation[1], 0.0, 1.0, 0.0);
            glRotatef(debris[i].orientation[2], 0.0, 0.0, 1.0);

            glScalef(debris[i].scale[0],
                debris[i].scale[1],
                debris[i].scale[2]);

            glBegin(GL_TRIANGLES);
            glVertex3f(0.0, 0.5, 0.0);
            glVertex3f(-0.25, 0.0, 0.0);
            glVertex3f(0.25, 0.0, 0.0);
            glEnd();

            glPopMatrix();
        }
    }
    Sleep(1);
    glutSwapBuffers();
}

// Keyboard callback.
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case ' ':
        newExplosion();
        break;

    case 'r':
        if (rotation_speed == 0.0)rotation_speed = 2.0;
        else rotation_speed = 0.0;

        break;

    case 'p':
        wantPause = 1 - wantPause;
        break;
    
    case 27:
            exit(0);
            break;
    }

}

bool particleCollision(particleData* particle) {
    if (particle->position[1] < -2)return 0;

    return 1;
}

bool debrisCollision(debrisData* debree) {
    if (debree->position[1] < -2)return 0;

    return 1;
}

//idle Update - animation variables.
void idle(void) {
    int i;

    if (!wantPause) {
        if (fuel > 0) {
            for (i = 0; i < NUM_PARTICLES; i++) {
                if (particleCollision(&particles[i])) {
                    particles[i].position[0] += particles[i].speed[0] * 0.2;
                    particles[i].position[1] += particles[i].speed[1] * 0.2;
                    particles[i].position[2] += particles[i].speed[2] * 0.2;
                }
                particles[i].color[0] -= 1.0 / 500.0;
                if (particles[i].color[0] < 0.0) {
                    particles[i].color[0] = 0.0;
                }

                particles[i].color[1] -= 1.0 / 100.0;
                if (particles[i].color[1] < 0.0) {
                    particles[i].color[1] = 0.0;
                }

                particles[i].color[2] -= 1.0 / 50.0;
                if (particles[i].color[2] < 0.0) {
                    particles[i].color[2] = 0.0;
                }
            }

            for (i = 0; i < NUM_DEBRIS; i++) {
                if (debrisCollision(&debris[i])) {
                    debris[i].position[0] += debris[i].speed[0] * 0.1;
                    debris[i].position[1] += debris[i].speed[1] * 0.1;
                    debris[i].position[2] += debris[i].speed[2] * 0.1;
                    debris[i].speed[1] -= 0.001;

                    debris[i].orientation[0] += debris[i].orientationSpeed[0] * 10;
                    debris[i].orientation[1] += debris[i].orientationSpeed[1] * 10;
                    debris[i].orientation[2] += debris[i].orientationSpeed[2] * 10;
                }
            }

            --fuel;
        }
    }
    angle += rotation_speed; /*Always continue to rotate the camera*/
    glutPostRedisplay();
}
 
// reshape - Window reshape callback.
void reshape(int w, int h) {
    glViewport(0.0, 0.0, (GLfloat)w, (GLfloat)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

// Menu selection callback.
void menuSelect(int value) {
    switch (value) {
    case PAUSE:
        wantPause = 1 - wantPause;
        break;

    case NORMALIZE_SPEED:
        wantNormalize = 1 - wantNormalize;
        break;

    case TOGGLE_ROTATION:
        if (rotation_speed == 0.0)rotation_speed = 2.0;
        else rotation_speed = 0.0;

        break;

    case QUIT:
        exit(0);
        break;
    }
}

#endif // !FUNCTIONS_H
