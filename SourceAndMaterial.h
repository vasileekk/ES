
/* Light sources and material */

GLfloat light0Amb[4] = {
  1.0,
  0.6,
  0.2,
  1.0
};
GLfloat light0Dif[4] = {
  1.0,
  0.6,
  0.2,
  1.0
};
GLfloat light0Spec[4] = {
  0.0,
  0.0,
  0.0,
  1.0
};
GLfloat light0Pos[4] = {
  0.0,
  0.0,
  0.0,
  1.0
};

GLfloat light1Amb[4] = {
  0.0,
  0.0,
  0.0,
  1.0
};
GLfloat light1Dif[4] = {
  1.0,
  1.0,
  1.0,
  1.0
};
GLfloat light1Spec[4] = {
  1.0,
  1.0,
  1.0,
  1.0
};
GLfloat light1Pos[4] = {
  0.0,
  5.0,
  5.0,
  0.0
};

GLfloat materialAmb[4] = {
  0.25,
  0.22,
  0.26,
  1.0
};
GLfloat materialDif[4] = {
  0.63,
  0.57,
  0.60,
  1.0
};
GLfloat materialSpec[4] = {
  0.99,
  0.91,
  0.81,
  1.0
};
GLfloat materialShininess = 27.8;

int wantPause = 0; /* Pause flag */