/* A particle */

struct particleData {
    float position[3];
    float speed[3];
    float color[3];
};
typedef struct particleData particleData;

/* A piece of debris */

struct debrisData {
    float position[3];
    float speed[3];
    float orientation[3]; /* Rotation angles around x, y, and z axes */
    float orientationSpeed[3];
    float color[3];
    float scale[3];
};
typedef struct debrisData debrisData;

