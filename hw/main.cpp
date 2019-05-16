#include "dance.h"

#define _WINDOW_NAME_ "VR2012 HW1"
#define _WIN_W_	700
#define _WIN_H_ 500
#define _WIN_POS_X_ 50
#define _WIN_POS_Y_ 50

//-----------------------------------------------------------------------------
// Name: main
// Desc: the main function
//-----------------------------------------------------------------------------
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (_WIN_W_, _WIN_H_); 
	glutInitWindowPosition (_WIN_POS_X_, _WIN_POS_Y_);
	glutCreateWindow (_WINDOW_NAME_);
	init();
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}