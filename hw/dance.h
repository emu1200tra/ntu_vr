//-----------------------------------------------------------------------------
// global define
//-----------------------------------------------------------------------------
#define _TIME_INTERVAL_ 113		// time interval between two frames (milli second)
#define _START_DELAY_   0		// time delay after animation(music) started (11500;)
#define _MAX_FRAME_NUM_ 1000	// just for the size of the script
#define _SURROUNDING_START_ 229
#define _MUSIC_FILENAME_ "C:/Users/user/Documents/VR/new/dance_cpp/dance.wav"


#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "GL/glut.h"
#include <vector>
#include <iostream>

#include "actor.h"
#include "music.h"
#include "script.h"

using namespace std;

/* Initial the OpenGL environment and all of the objects */
void init(void);

/* this is a callback function invoked when user resize the window */
void reshape(int w, int h);

/* this is a callback function invoked when glutPostRedisplay() is called */
void display(void);

/* this is a callback function invoked when any key is pressed */
void keyboard (unsigned char key, int x, int y);