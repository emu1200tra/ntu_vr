
/*
 * file name: dance.c
 * decs: Two dancer model to show dance in OpenGL
 */

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------
#include "dance.h"

vector<Actor> actor;
vector<Script*> script;
Music music(_MUSIC_FILENAME_);
AnimationVariables animation;
int counter = 0;





//-----------------------------------------------------------------------------
// Name: init
// Desc: initial all data
//-----------------------------------------------------------------------------
void init(void) 
{
	actor.push_back(Actor(1));						// Create a male actor
	script.push_back(new Script("C:/Users/user/Documents/VR/new/dance_cpp/mmovie.txt"));		// Create his script
	script[0]->Load();								// Load his Script
	
	actor.push_back(Actor(2));						// Create a female actor
	script.push_back(new Script("C:/Users/user/Documents/VR/new/dance_cpp/fmovie.txt"));		// Create her script
	script[1]->Load();								// Load her Script

	actor.push_back(Actor(3));
	script.push_back(new Script("C:/Users/user/Documents/VR/new/dance_cpp/fuckmovie.txt"));
	script[2]->Load();

	actor.push_back(Actor(1));
	script.push_back(new Script("C:/Users/user/Documents/VR/new/dance_cpp/fuckmovie2.txt"));
	script[3]->Load();

	actor.push_back(Actor(2));
	script.push_back(new Script("C:/Users/user/Documents/VR/new/dance_cpp/fuckmovie3.txt"));
	script[4]->Load();

	actor.push_back(Actor(1));
	script.push_back(new Script("C:/Users/user/Documents/VR/new/dance_cpp/running1.txt"));
	script[5]->Load();

	actor.push_back(Actor(2));
	script.push_back(new Script("C:/Users/user/Documents/VR/new/dance_cpp/running2.txt"));
	script[6]->Load();



	music.Open();									// Initial the music (not yet play)

	
	glClearColor (0.0, 0.0, 0.0, 0.0);    
	glShadeModel (GL_SMOOTH);

	// OpenGL Set light and material
	GLfloat mat_diffuse[]={0.7,0.7,0.7,1.0};
	GLfloat mat_ambient[]={0.7,0.7,0.7,1.0};
	GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
	GLfloat mat_shininess[]={50.0};
	GLfloat light_ambient[]={0.2,0.2,0.2,1.0};
	GLfloat light_diffuse[]={1.0,1.0,1.0,1.0};
	GLfloat light_position[]={1.0,1.0,1.0,0.0};

	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);   
	glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	
}

//-----------------------------------------------------------------------------
// Name: reshape
// Desc: for reshaping all view
//-----------------------------------------------------------------------------
void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
	glMatrixMode (GL_PROJECTION);

	glLoadIdentity ();
	if(!animation.zoom)
		glFrustum(-1.0,1.0,-1.0,1.0,1.2,100.0);
	else
		glFrustum(-1.0,1.0,-1.0,1.0,1.2,50.0);
	glMatrixMode(GL_MODELVIEW);
}



//-----------------------------------------------------------------------------
// Name: base room
// Desc: for setting baseroom data
//-----------------------------------------------------------------------------
void baseroom(void)
{
	glPushMatrix();    
	glColor3f(1.0,1.0,1.0);              //外層地板
	glTranslatef (0.0, -4.0, 0.0);
	glScalef (50.0, 2.0, 50.0);    
	glutSolidCube (1.0);	
	glPopMatrix();
	glPushMatrix();    
	for (int i = 1; i <= 44; i++) {
		glColor3f(0.862+(i/100.0), 0.541/*+(i/50.0)*/, 0.07+counter/100.0);          //地板
		glTranslatef(i/10.0, -1.5, i/10.0);
		glScalef(44.0, 3.0, 44.0);
		glutSolidCube(1.0);

		glPopMatrix();
		glPushMatrix();
	}
	for (int i = 1; i <= 44; i++) {
		glColor3f(0.862+counter/1000.0, 0.541+(i/100.0), 0.07/*+(i/150.0)*/);          //地板
		glTranslatef(i / 10.0, -4.0, i / 10.0);
		glScalef(50.0, 2.0, 50.0);
		glutSolidCube(1.0);

		glPopMatrix();
		glPushMatrix();
	}
	counter++;


	/*
	glColor3f(0.862,0.541,0.07);          //地板
	glTranslatef (0.0, -1.5, 0.0);
	glScalef (44.0, 3.0, 44.0);    
	glutSolidCube (1.0);	
	glPopMatrix();
	glPushMatrix();  
	*/

	glColor3f(1.0+counter/1000.0,1.0,0.0);              //柱子
	glTranslatef (23.5, 7.0, 23.5);
	glScalef (3.0, 20.0, 3.0);    
	glutSolidCube (1.0);	
	glPopMatrix();
	glPushMatrix();  
	glColor3f(1.0,0.5+counter/1000.0,0.0);              //柱子
	glTranslatef (-23.5, 7.0, 23.5);
	glScalef (3.0, 20.0, 3.0);    
	glutSolidCube (1.0);	
	glPopMatrix();
	glPushMatrix();  
	glColor3f(1.0,0+counter/100.0,0.5);              //柱子
	glTranslatef (23.5, 7.0, -23.5);
	glScalef (3.0, 20.0, 3.0);    
	glutSolidCube (1.0);	
	glPopMatrix();
	glPushMatrix();  
	glColor3f(1.0,1.0,0.0+counter/100.0);              //柱子
	glTranslatef (-23.5, 7.0, -23.5);
	glScalef (3.0, 20.0, 3.0);    
	glutSolidCube (1.0);	
	glPopMatrix();
}

//-----------------------------------------------------------------------------
// Name: display
// Desc: for display all value
//-----------------------------------------------------------------------------
void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();

	// Set look point and direct 
	if(!animation.zoom)
		gluLookAt(50*cos(animation.viewAngle),20,50*sin(animation.viewAngle),0.0,0.0,0.0,0.0,1.0,0.0);
	else
		gluLookAt(25*cos(animation.viewAngle),10,25*sin(animation.viewAngle),0.0,10.0,0.0,0.0,1.0,0.0);

	// Set the ballroom 
	baseroom();

	// Set the Actors' Pose
	for(unsigned int i = 0 ; i < actor.size() ; i++){
		actor[i].performPose();
	}

	glutSwapBuffers();
}




//-----------------------------------------------------------------------------
// Name: OnTimer
// Desc: timer function
//-----------------------------------------------------------------------------
void OnTimer(int value)
{
	/* animation playing */
	if(animation.frameIndex < script[0]->frameNumber()){
		// invoke the next frame
		glutTimerFunc(_TIME_INTERVAL_, OnTimer, 1);

		// load the Current Frame Pose from the scripts to the actors  
		for(unsigned int i = 0 ; i < actor.size(); i++){
			actor[i].setPose(script[i]->getFrame(animation.frameIndex));
		}

		// set the effects
		animation.BackgroundColorEffect();
		animation.CameraSurroundEffect();
		//animation.LightEffect();
		animation.ZoomEffect();

		animation.frameIndex++;

	}
	/* animation end */
	else												
	{
		animation.ResetVars();
		music.Stop();
		
		for(unsigned int i = 0 ; i < actor.size(); i++){
			actor[i].resetPose();
		}
	}

	
	glLightfv(GL_LIGHT0, GL_DIFFUSE, animation.ltColor);
	glClearColor (animation.bgColor.r, animation.bgColor.g, animation.bgColor.b, animation.bgColor.a); 
	glutPostRedisplay();	
	return;
}

//-----------------------------------------------------------------------------
// Name: keyboard
// Desc: for keyboard setting
//-----------------------------------------------------------------------------
void keyboard (unsigned char key, int x, int y)
{
	int actorIdx = animation.actorIndex;
	switch (key) {
		case '1': animation.actorIndex = 0;    break;
		case '2': animation.actorIndex = 1;    break;
		case '0': animation.actorIndex = 2;    break;
		case '`': animation.actorIndex = 3;    break;
		case '9': animation.actorIndex = 4;    break;

		//身體移動 Body Translate
		case 'q':	actor[actorIdx].Torso.Offset[0] += 1;		break;	 // x+
		case 'Q':	actor[actorIdx].Torso.Offset[0] -= 1;		break;	 // x-
		case 'a': actor[actorIdx].Torso.Offset[1] += 1;		break;	 // y+
		case 'A': actor[actorIdx].Torso.Offset[1] -= 1;		break;	 // y-
		case 'z': actor[actorIdx].Torso.Offset[2] += 1;		break;	 // z+
		case 'Z': actor[actorIdx].Torso.Offset[2] -= 1;		break;	 // z-

		//身體轉動 Body Rotate
		case 'w': (actor[actorIdx].Torso.Rotate[0] += 5) %= 360;	break; // x+
		case 'W': (actor[actorIdx].Torso.Rotate[0] -= 5) %= 360;	break; // x-
		case 's': (actor[actorIdx].Torso.Rotate[1] += 5) %= 360;	break; // y+
		case 'S': (actor[actorIdx].Torso.Rotate[1] -= 5) %= 360;	break; // y-
		case 'x': (actor[actorIdx].Torso.Rotate[2] += 5) %= 360;	break; // z+
		case 'X': (actor[actorIdx].Torso.Rotate[2] -= 5) %= 360;	break; // z-

		//右上手轉動 Right Upper Arm Rotate
		case '3': (actor[actorIdx].RUpperArm.Rotate[0] += 5) %= 360;	break; // x+
		case '#': (actor[actorIdx].RUpperArm.Rotate[0] -= 5) %= 360;	break; // x-
		case '4': (actor[actorIdx].RUpperArm.Rotate[1] += 5) %= 360;	break; // y+
		case '$': (actor[actorIdx].RUpperArm.Rotate[1] -= 5) %= 360;	break; // y-
		case '5': (actor[actorIdx].RUpperArm.Rotate[2] += 5) %= 360;	break; // z+
		case '%': (actor[actorIdx].RUpperArm.Rotate[2] -= 5) %= 360;	break; // z-

		//右下手轉動 Right Fore Arm Rotate
		case 'e': (actor[actorIdx].RForeArm.Rotate[0] += 5) %= 360;	break; // x+
		case 'E': (actor[actorIdx].RForeArm.Rotate[0] -= 5) %= 360;	break; // x-
		case 'r': (actor[actorIdx].RForeArm.Rotate[1] += 5) %= 360;	break; // y+
		case 'R': (actor[actorIdx].RForeArm.Rotate[1] -= 5) %= 360;	break; // y-
		case 't': (actor[actorIdx].RForeArm.Rotate[2] += 5) %= 360;	break; // z+
		case 'T': (actor[actorIdx].RForeArm.Rotate[2] -= 5) %= 360;	break; // z-

		//左上手轉動 Left Upper Arm Rotate
		case 'd': (actor[actorIdx].LUpperArm.Rotate[0] += 5) %= 360;	break; // x+
		case 'D': (actor[actorIdx].LUpperArm.Rotate[0] -= 5) %= 360;	break; // x-
		case 'f': (actor[actorIdx].LUpperArm.Rotate[1] += 5) %= 360;	break; // y+
		case 'F': (actor[actorIdx].LUpperArm.Rotate[1] -= 5) %= 360;	break; // y-
		case 'g': (actor[actorIdx].LUpperArm.Rotate[2] += 5) %= 360;	break; // z+
		case 'G': (actor[actorIdx].LUpperArm.Rotate[2] -= 5) %= 360;	break; // z-

		//左下手轉動 Left Fore Arm Rotate
		case 'c': (actor[actorIdx].LForeArm.Rotate[0] += 5) %= 360;	break; // x+
		case 'C': (actor[actorIdx].LForeArm.Rotate[0] -= 5) %= 360;	break; // x-
		case 'v': (actor[actorIdx].LForeArm.Rotate[1] += 5) %= 360;	break; // y+
		case 'V': (actor[actorIdx].LForeArm.Rotate[1] -= 5) %= 360;	break; // y-
		case 'b': (actor[actorIdx].LForeArm.Rotate[2] += 5) %= 360;	break; // z+
		case 'B': (actor[actorIdx].LForeArm.Rotate[2] -= 5) %= 360;	break; // z-

		//右大腿轉動 Right Thigh Rotate
		case '6': (actor[actorIdx].RThigh.Rotate[0] += 5) %= 360;	break; // x+
		case '^': (actor[actorIdx].RThigh.Rotate[0] -= 5) %= 360;	break; // x-
		case '7': (actor[actorIdx].RThigh.Rotate[1] += 5) %= 360;	break; // y+
		case '&': (actor[actorIdx].RThigh.Rotate[1] -= 5) %= 360;	break; // y-
		case '8': (actor[actorIdx].RThigh.Rotate[2] += 5) %= 360;	break; // z+
		case '*': (actor[actorIdx].RThigh.Rotate[2] -= 5) %= 360;	break; // z-

		//右小腿轉動 Right Thigh Rotate
		case 'y': (actor[actorIdx].RLowerLeg.Rotate[0] += 5) %= 360;	break; // x+
		case 'Y': (actor[actorIdx].RLowerLeg.Rotate[0] -= 5) %= 360;	break; // x-
		case 'u': (actor[actorIdx].RLowerLeg.Rotate[1] += 5) %= 360;	break; // y+
		case 'U': (actor[actorIdx].RLowerLeg.Rotate[1] -= 5) %= 360;	break; // y-
		case 'i': (actor[actorIdx].RLowerLeg.Rotate[2] += 5) %= 360;	break; // z+
		case 'I': (actor[actorIdx].RLowerLeg.Rotate[2] -= 5) %= 360;	break; // z-

		//左大腿轉動 Left Thigh Rotate
		case 'h': (actor[actorIdx].LThigh.Rotate[0] += 5) %= 360;	break; // x+
		case 'H': (actor[actorIdx].LThigh.Rotate[0] -= 5) %= 360;	break; // x-
		case 'j': (actor[actorIdx].LThigh.Rotate[1] += 5) %= 360;	break; // y+
		case 'J': (actor[actorIdx].LThigh.Rotate[1] -= 5) %= 360;	break; // y-
		case 'k': (actor[actorIdx].LThigh.Rotate[2] += 5) %= 360;	break; // z+
		case 'K': (actor[actorIdx].LThigh.Rotate[2] -= 5) %= 360;	break; // z-

		//左小腿轉動 Left Thigh Rotate
		case 'n': (actor[actorIdx].LLowerLeg.Rotate[0] += 5) %= 360;	break; // x+
		case 'N': (actor[actorIdx].LLowerLeg.Rotate[0] -= 5) %= 360;	break; // x-
		case 'm': (actor[actorIdx].LLowerLeg.Rotate[1] += 5) %= 360;	break; // y+
		case 'M': (actor[actorIdx].LLowerLeg.Rotate[1] -= 5) %= 360;	break; // y-
		case ',': (actor[actorIdx].LLowerLeg.Rotate[2] += 5) %= 360;	break; // z+
		case '<': (actor[actorIdx].LLowerLeg.Rotate[2] -= 5) %= 360;	break; // z-

		//右腳背轉 Right Thenar Rotate
		case 'o': (actor[actorIdx].RThenar.Rotate[0] += 5) %= 360;	break; // +
		case 'O': (actor[actorIdx].RThenar.Rotate[0] -= 5) %= 360;	break; // -

		//左腳背轉 Left Thenar Rotate
		case 'p': (actor[actorIdx].LThenar.Rotate[0] += 5) %= 360;	break; // +
		case 'P': (actor[actorIdx].LThenar.Rotate[0] -= 5) %= 360;	break; // -

		//視角 Viewing Angle
		case '.': animation.viewAngle += 0.314;	break;
		case '>': animation.viewAngle -= 0.314;	break;

		//預覽下一個動作 Display the next pose
		case ';':	
			if(animation.frameIndex+1 < script[0]->frameNumber())	animation.frameIndex++;
			for(unsigned int i = 0 ; i < actor.size(); i++){
				actor[i].setPose(script[i]->getFrame(animation.frameIndex));
			}
			break;

		//預覽前一個動作 Display the previous pose
		case ':':
			if(animation.frameIndex-1 < script[0]->frameNumber())	animation.frameIndex--;
			for(unsigned int i = 0 ; i < actor.size(); i++){
				actor[i].setPose(script[i]->getFrame(animation.frameIndex));
			}
			break;
		 

		// Append the current pose to the script
		case '/':	
			for(unsigned int i = 0 ; i < script.size() ; i++){
			  script[i]->Append2File(actor[i].getPose());
			}
			break;

		// Start the animation
		case '=':
			music.Play();
			glutTimerFunc(_START_DELAY_, OnTimer, 1);
			break;

		case 27:
			music.Close();
			exit(0);
			break;

		default:
			break;
	}
	glutPostRedisplay();
}

