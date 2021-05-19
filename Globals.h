#include "Structures.h"

const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 1000;

/* GLUT menu entries */

#define PAUSE 0
#define NORMALIZE_SPEED 1
#define TOGGLE_ROTATION 2
#define QUIT 3


/* Globals */
#define NUM_PARTICLES 20000 /* Number of particles */
#define NUM_DEBRIS 80 /* Number of debris */

particleData particles[NUM_PARTICLES];
debrisData debris[NUM_DEBRIS];

int fuel = 0; /* "fuel" of the explosion */

/*Camera variables*/

float camX = 0.0;
float camZ = 2.0;
float oX = 0.0;
float oZ = -1.0;

float angle = 0.0; /* camera rotation angle */
float rotation_speed = 2.0; /* camera rotation speed */