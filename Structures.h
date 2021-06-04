
/* A particle */
typedef struct particleData {
    float position[3];
    float speed[3];
    float color[3];
}particleData;

/* A piece of debris */
typedef struct debrisData {
    float position[3];
    float speed[3];
    float orientation[3]; /* Rotation angles around x, y, and z axes */
    float orientationSpeed[3];
    float color[3];
}debrisData;