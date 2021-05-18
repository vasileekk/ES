#include "Structures.h"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

/* GLUT menu entries */

#define PAUSE 0
#define NORMALIZE_SPEED 1
#define QUIT 2

#define NUM_PARTICLES 1000 /* Number of particles */
#define NUM_DEBRIS 70 /* Number of debris */

/* Globals */

particleData particles[NUM_PARTICLES];
debrisData debris[NUM_DEBRIS];
int fuel = 0; /* "fuel" of the explosion */

float angle = 0.0; /* camera rotation angle */