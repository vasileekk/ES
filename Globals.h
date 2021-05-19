#include "Structures.h"

const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 1000;

/* GLUT menu entries */

#define PAUSE 0
#define NORMALIZE_SPEED 1
#define TOGGLE_ROTATION 2
#define QUIT 3

#define NUM_PARTICLES 1000 /* Number of particles */
#define NUM_DEBRIS 70 /* Number of debris */

/* Globals */

particleData particles[NUM_PARTICLES];
debrisData debris[NUM_DEBRIS];
int fuel = 0; /* "fuel" of the explosion */

float angle = 0.0; /* camera rotation angle */
float rotation_speed = 3.0;