#include "actor.h"
#include "GL/glut.h"


/* 
 * Name: Actor (Constructor)
 * Desc: Set the actor's appearance							
 *	     1: Male											
 *	     2: Female											
 */
Actor::Actor(int app){
	resetPose();
	appearance = app;
	switch(app){
		case 1:	// Male
			setPositionOffset(10.f, 12.5f, 0.f);
			
			// 頭部 Head
			Head.setColor(0.1f, 0.1f, 0.1f);
			Head.setOffset(0.0, 3.5, 0.0);
			Head.setSize(1.2f);
			
			// 臀部 Bottom
			Bottom.setColor(0.0,1.0,1.0); 
			Bottom.setOffset(0.0, -3.0, 0.0);
			Bottom.setScale(3.0, 3.0, 2.0);
			Bottom.setSize(1.f);
			
			// 胸部 Chest
			Chest.setColor(1.0,1.0,1.0);
			Chest.setScale(3.0, 3.0, 2.0);  
			Chest.setSize(1.f);
			
			// 右上臂 Right Upper Arm
			RUpperArm.setPivot(-2.5, 1.0, 0.0); 
			RUpperArm.setColor(1.0,1.0,1.0);   
			RUpperArm.setOffset(-2.5, 0.0, 0.0);
			RUpperArm.setScale(1.2, 3.0, 1.2);    
			RUpperArm.setSize(1.0);	
			
			// 右下臂 Right Fore Arm
			RForeArm.setPivot(-2.5, -2.0, 0.0); 
			RForeArm.setColor(1.0,0.772,0.478);
			RForeArm.setOffset(-2.5, -3.0, 0.0);
			RForeArm.setScale(1.0, 3.0, 1.0);     
			RForeArm.setSize(1.0);	
			
			// 右拳頭 Right Fist
			RFist.setColor(1.0,0.772,0.478);
			RFist.setOffset(-2.5, -5.0, 0.0);         
			RFist.setSize(0.8);
			
			// 左上臂 Left Upper Arm
			LUpperArm.setPivot(2.5, 1.0, 0.0); 
			LUpperArm.setColor(1.0,1.0,1.0);   
			LUpperArm.setOffset(2.5, 0.0, 0.0);
			LUpperArm.setScale(1.2, 3.0, 1.2);    
			LUpperArm.setSize(1.0);	
			
			// 左下臂 Left Fore Arm
			LForeArm.setPivot(2.5, -2.0, 0.0); 
			LForeArm.setColor(1.0,0.772,0.478);
			LForeArm.setOffset(2.5, -3.0, 0.0);
			LForeArm.setScale(1.0, 3.0, 1.0);     
			LForeArm.setSize(1.0);	
			
			// 左拳頭 Left Fist
			LFist.setColor(1.0,0.772,0.478);
			LFist.setOffset(2.5, -5.0, 0.0);         
			LFist.setSize(0.8);

			// 右大腿 Right Thigh
			RThigh.setPivot(-1.0, -4.0, 0.0); 
			RThigh.setColor(0.0,1.0,0.0);
			RThigh.setOffset(-1.0, -6.25, 0.0);
			RThigh.setScale(1.5, 3.5, 2.0);    
			RThigh.setSize(1.0);	
			
			// 右小腿 Right Lower Leg
			RLowerLeg.setPivot(-1.0, -7.0, 0.0); 
			RLowerLeg.setColor(0.0, 1.0, 0.0);   
			RLowerLeg.setOffset(-1.0, -9.75, 0.0);
			RLowerLeg.setScale(1.5, 3.5, 2.0);   
			RLowerLeg.setSize(1.0);	

			// 右腳板 Right Thenar
			RThenar.setPivot(-1.0, -12.0, 0.5);
			RThenar.setColor(0.0, 1.0, 0.0);   
			RThenar.setOffset(-1.0, -12.0, -0.5);
			RThenar.setScale(1.5, 1.0, 3.0);  
			RThenar.setSize(1.0);

			// 左大腿 Left Thigh
			LThigh.setPivot(1.0, -4.0, 0.0); 
			LThigh.setColor(0.0,0.0,1.0);
			LThigh.setOffset(1.0, -6.25, 0.0);
			LThigh.setScale(1.5, 3.5, 2.0);    
			LThigh.setSize(1.0);	
			
			// 左小腿 Left Lower Leg
			LLowerLeg.setPivot(1.0, -7.0, 0.0); 
			LLowerLeg.setColor(0.0, 0.0, 1.0);   
			LLowerLeg.setOffset(1.0, -9.75, 0.0);
			LLowerLeg.setScale(1.5, 3.5, 2.0);   
			LLowerLeg.setSize(1.0);	

			// 左腳板 Left Thenar
			LThenar.setPivot(1.0, -12.0, 0.5);
			LThenar.setColor(0.0, 0.0, 1.0);   
			LThenar.setOffset(1.0, -12.0, -0.5);
			LThenar.setScale(1.5, 1.0, 3.0);  
			LThenar.setSize(1.0);

			break;
		case 2:	// Female
			setPositionOffset(-10.f, 11.5f, 0.f);
			
			// 頭部 Head
			Head.setColor(0.f, 0.f, 1.0f);
			Head.setOffset(0.0, 2.7, 0.0);
			Head.setSize(2.0f);
			
			// 臀部 Bottom
			Bottom.setColor(1.0,0.5,0.3); 
			Bottom.setOffset(0.0, -2.625, 0.0);
			Bottom.setScale(2.2, 2.625, 1.6); 
			Bottom.setSize(1.f);
			FBottom.setColor(1.0,0.0,0.0);
			FBottom.setOffset(0.0, -4.2, 0.0);  
			FBottom.setSize(0.7f);
			
			// 胸部 Chest
			Chest.setColor(0.0,0.5,0.1);
			Chest.setScale(2.625, 2.625, 1.8);    
			Chest.setSize(0.8f);
			
			// 右上臂 Right Upper Arm
			RUpperArm.setPivot(-2.0, 1.0, 0.0); 
			RUpperArm.setColor(1.0,0.772,0.478);   
			RUpperArm.setOffset(-2.0, 0.0, 0.0);
			RUpperArm.setScale(0.8, 2.625, 1.0);  
			RUpperArm.setSize(1.0);	
			
			// 右下臂 Right Fore Arm
			RForeArm.setPivot(-2.0, -2.0, 0.0); 
			RForeArm.setColor(1.0,0.772,0.478);
			RForeArm.setOffset(-2.0, -2.625, 0.0);
			RForeArm.setScale(0.7, 2.625, 0.9);     
			RForeArm.setSize(1.0);	
			
			// 右拳頭 Right Fist
			RFist.setColor(1.0,0.772,0.478);
			RFist.setOffset(-2.0, -5.0, 0.0);         
			RFist.setSize(0.7);
			
			// 左上臂 Left Upper Arm
			LUpperArm.setPivot(2.0, 1.0, 0.0); 
			LUpperArm.setColor(1.0,0.772,0.478);
			LUpperArm.setOffset(2.0, 0.0, 0.0);
			LUpperArm.setScale(0.8, 2.625, 1.0);    
			LUpperArm.setSize(1.0);	
			
			// 左下臂 Left Fore Arm
			LForeArm.setPivot(2.0, -2.0, 0.0); 
			LForeArm.setColor(1.0,0.772,0.478);
			LForeArm.setOffset(2.0, -2.625, 0.0);
			LForeArm.setScale(0.7, 2.625, 0.9);     
			LForeArm.setSize(1.0);	
			
			// 左拳頭 Left Fist
			LFist.setColor(1.0,0.772,0.478);
			LFist.setOffset(2.0, -5.0, 0.0);         
			LFist.setSize(0.7);

			// 右大腿 Right Thigh
			RThigh.setPivot(-1.0, -4.0, 0.0); 
			RThigh.setColor(1.0,0.772,0.478);
			RThigh.setOffset(-0.9, -5.5, 0.0);
			RThigh.setScale (1.2, 3.0, 1.6);  
			RThigh.setSize(1.0);	
			
			// 右小腿 Right Lower Leg
			RLowerLeg.setPivot(-1.0, -7.0, 0.0); 
			RLowerLeg.setColor(1.0,0.772,0.478); 
			RLowerLeg.setOffset(-0.9, -8.5, 0.0);
			RLowerLeg.setScale(1.0, 3.0, 1.4);   
			RLowerLeg.setSize(1.0);	

			// 右腳板 Right Thenar
			RThenar.setPivot(-1.0, -10.5, 0.0);
			RThenar.setColor(1.0,1.0,0.0);
			RThenar.setOffset(-0.9, -11.0, -0.55);
			RThenar.setScale(1.0, 1.0, 2.5);
			RThenar.setSize(1.0);

			// 左大腿 Left Thigh
			LThigh.setPivot(1.0, -4.0, 0.0); 
			LThigh.setColor(1.0,0.772,0.478);
			LThigh.setOffset(0.9, -5.5, 0.0);
			LThigh.setScale (1.2, 3.0, 1.6);  
			LThigh.setSize(1.0);	
			
			// 左小腿 Left Lower Leg
			LLowerLeg.setPivot(1.0, -7.0, 0.0); 
			LLowerLeg.setColor(1.0,0.772,0.478); 
			LLowerLeg.setOffset(0.9, -8.5, 0.0);
			LLowerLeg.setScale(1.0, 3.0, 1.4);   
			LLowerLeg.setSize(1.0);	

			// 左腳板 Left Thenar
			LThenar.setPivot(1.0, -10.5, 0.0);
			LThenar.setColor(1.0,1.0,0.0);
			LThenar.setOffset(0.9, -11.0, -0.55);
			LThenar.setScale(1.0, 1.0, 2.5);
			LThenar.setSize(1.0);

			break;
			case 3:	// air fucking
				setPositionOffset(10.f, 12.5f, 0.f);

				// 頭部 Head
				Head.setColor(0.f, 1.f, 0.f);
				Head.setOffset(0.0, 3.5, 0.0);
				Head.setSize(2.f);

				// 臀部 Bottom
				Bottom.setColor(0.0, 0.5f, 0.5f);
				Bottom.setOffset(0.0, -3.0, 0.0);
				Bottom.setScale(3.0, 3.0, 2.0);
				Bottom.setSize(1.5f);

				// 胸部 Chest
				Chest.setColor(0.f, 0.1f, 0.f);
				Chest.setScale(3.0, 3.0, 2.0);
				Chest.setSize(2.f);

				// 右上臂 Right Upper Arm
				RUpperArm.setPivot(-2.5, 1.0, 0.0);
				RUpperArm.setColor(1.0, 1.0, 1.0);
				RUpperArm.setOffset(-2.5, 0.0, 0.0);
				RUpperArm.setScale(1.2, 3.0, 1.2);
				RUpperArm.setSize(1.0);

				// 右下臂 Right Fore Arm
				RForeArm.setPivot(-2.5, -2.0, 0.0);
				RForeArm.setColor(1.0, 0.772, 0.478);
				RForeArm.setOffset(-2.5, -3.0, 0.0);
				RForeArm.setScale(1.0, 3.0, 1.0);
				RForeArm.setSize(1.0);

				// 右拳頭 Right Fist
				RFist.setColor(1.0, 0.772, 0.478);
				RFist.setOffset(-2.5, -5.0, 0.0);
				RFist.setSize(0.8);

				// 左上臂 Left Upper Arm
				LUpperArm.setPivot(2.5, 1.0, 0.0);
				LUpperArm.setColor(1.0, 1.0, 1.0);
				LUpperArm.setOffset(2.5, 0.0, 0.0);
				LUpperArm.setScale(1.2, 3.0, 1.2);
				LUpperArm.setSize(1.0);

				// 左下臂 Left Fore Arm
				LForeArm.setPivot(2.5, -2.0, 0.0);
				LForeArm.setColor(1.0, 0.772, 0.478);
				LForeArm.setOffset(2.5, -3.0, 0.0);
				LForeArm.setScale(1.0, 3.0, 1.0);
				LForeArm.setSize(1.0);

				// 左拳頭 Left Fist
				LFist.setColor(1.0, 0.772, 0.478);
				LFist.setOffset(2.5, -5.0, 0.0);
				LFist.setSize(0.8);

				// 右大腿 Right Thigh
				RThigh.setPivot(-1.0, -4.0, 0.0);
				RThigh.setColor(0.0, 0.0, 0.0);
				RThigh.setOffset(-1.0, -6.25, 0.0);
				RThigh.setScale(1.5, 3.5, 2.0);
				RThigh.setSize(1.0);

				// 右小腿 Right Lower Leg
				RLowerLeg.setPivot(-1.0, -7.0, 0.0);
				RLowerLeg.setColor(0.0, 0.0, 0.0);
				RLowerLeg.setOffset(-1.0, -9.75, 0.0);
				RLowerLeg.setScale(1.5, 3.5, 2.0);
				RLowerLeg.setSize(1.0);

				// 右腳板 Right Thenar
				RThenar.setPivot(-1.0, -12.0, 0.5);
				RThenar.setColor(0.0, 0.0, 0.0);
				RThenar.setOffset(-1.0, -12.0, -0.5);
				RThenar.setScale(1.5, 1.0, 3.0);
				RThenar.setSize(1.0);

				// 左大腿 Left Thigh
				LThigh.setPivot(1.0, -4.0, 0.0);
				LThigh.setColor(0.0, 0.0, 0.0);
				LThigh.setOffset(1.0, -6.25, 0.0);
				LThigh.setScale(1.5, 3.5, 2.0);
				LThigh.setSize(1.0);

				// 左小腿 Left Lower Leg
				LLowerLeg.setPivot(1.0, -7.0, 0.0);
				LLowerLeg.setColor(0.0, 0.0, 0.0);
				LLowerLeg.setOffset(1.0, -9.75, 0.0);
				LLowerLeg.setScale(1.5, 3.5, 2.0);
				LLowerLeg.setSize(1.0);

				// 左腳板 Left Thenar
				LThenar.setPivot(1.0, -12.0, 0.5);
				LThenar.setColor(0.0, 0.0, 0.0);
				LThenar.setOffset(1.0, -12.0, -0.5);
				LThenar.setScale(1.5, 1.0, 3.0);
				LThenar.setSize(1.0);

				break;
	}
}


/* 
 * Name: setPositionOffset
 * Desc: Set the starting positoin for this actor
 */
void Actor::setPositionOffset(float x, float y, float z){
	PositionOffset[0] = x;
	PositionOffset[1] = y; 
	PositionOffset[2] = z;
}
//-----------------------------------------------------------------------------
// Name: resetPose
// Desc: Reset the current pose to the initial pose
//-----------------------------------------------------------------------------
void Actor::resetPose(){
	
	this->Torso.resetPose();
	this->LForeArm.resetPose();
	this->LUpperArm.resetPose();
	this->RUpperArm.resetPose();
	this->RForeArm.resetPose();
	this->LThigh.resetPose();
	this->LLowerLeg.resetPose();
	this->RThigh.resetPose();
	this->RLowerLeg.resetPose();
	this->LThenar.resetPose();
	this->RThenar.resetPose();
}

//-----------------------------------------------------------------------------
// Name: performPose
// Desc: Setting the OpenGL Transformation Matrix for the current pose
//       the transformation hierarchy is described here.
//-----------------------------------------------------------------------------
void Actor::performPose(){
	glPushMatrix();   
		glTranslatef (PositionOffset[0], PositionOffset[1], PositionOffset[2]);     // 身體移動 Actor Offset
		glTranslatef (Torso.Offset[0], Torso.Offset[1], Torso.Offset[2]);			// 身體移動 Torso Translate
		Torso.RotateByPivot();		// 身體轉動 Torso Rotate

		// 頭部 Head
		glPushMatrix();					
			Head.ScaleTransColor();
			glutSolidSphere (Head.Size,10,10);	
		glPopMatrix();

		// 臀部 Bottom
		glPushMatrix();					
			Bottom.ScaleTransColor();
			glutSolidCube (Bottom.Size);	
		glPopMatrix();
		if(appearance == 2){
			glPushMatrix();					
				FBottom.ScaleTransColor();
				glutSolidSphere (FBottom.Size,10,10);	
			glPopMatrix();
		}

		// 胸部 Chest
		glPushMatrix();					
			Chest.ScaleTransColor();
			glutSolidCube (Chest.Size);	
		glPopMatrix();

		// 右臂 Right Arm
		glPushMatrix();					
			RUpperArm.RotateByPivot();		// 右上臂轉 Right Upper Arm Rotate
			glPushMatrix();						// 右上臂 Right Upper Arm
				RUpperArm.ScaleTransColor();	
				glutSolidCube (RUpperArm.Size);	
			glPopMatrix();
			RForeArm.RotateByPivot();	// 右下臂轉 Right Fore Arm Rotate
			glPushMatrix();					// 右下臂 Right Fore Arm
				RForeArm.ScaleTransColor();
				glutSolidCube (RForeArm.Size);	
			glPopMatrix();
			glPushMatrix();                //右拳頭 Right Fist
				RFist.ScaleTransColor();
				glutSolidSphere (RFist.Size,10,10);	
			glPopMatrix();
		glPopMatrix();

		// 左臂 Left Arm
		glPushMatrix();					
			LUpperArm.RotateByPivot();		// 左上臂轉 Left Upper Arm Rotate
			glPushMatrix();						// 左上臂	Left Upper Arm
				LUpperArm.ScaleTransColor();	
				glutSolidCube (LUpperArm.Size);	
			glPopMatrix();
			LForeArm.RotateByPivot();	// 左下臂轉 Left Fore Arm Rotate
			glPushMatrix();					// 左下臂 Left Fore Arm
				LForeArm.ScaleTransColor();
				glutSolidCube (LForeArm.Size);	
			glPopMatrix();
			glPushMatrix();                //左拳頭 Left Fist
				LFist.ScaleTransColor();
				glutSolidSphere (LFist.Size,10,10);	
			glPopMatrix();
		glPopMatrix();

		// 右腿 Right Leg
		glPushMatrix();					
			RThigh.RotateByPivot();		// 右大腿轉	Right Thigh Rotate
			glPushMatrix();						// 右大腿	Right Thigh
				RThigh.ScaleTransColor();	
				glutSolidCube (RThigh.Size);	
			glPopMatrix();
			RLowerLeg.RotateByPivot();	// 右小腿轉 Right Lower Leg Rotate
			glPushMatrix();					// 右小腿 Right Lower Leg
				RLowerLeg.ScaleTransColor();
				glutSolidCube (RLowerLeg.Size);	
			glPopMatrix();
			RThenar.RotateByPivot();	// 右腳板轉 Right Fist Rotate
			glPushMatrix();                // 右腳板 Right Fist
				RThenar.ScaleTransColor();
				glutSolidCube (RThenar.Size);
			glPopMatrix();
		glPopMatrix();

		// 左腿 Left Leg
		glPushMatrix();					
			LThigh.RotateByPivot();		// 左大腿轉	Left Thigh Rotate
			glPushMatrix();						// 左大腿	Left Thigh
				LThigh.ScaleTransColor();	
				glutSolidCube (LThigh.Size);	
			glPopMatrix();
			LLowerLeg.RotateByPivot();	// 左小腿轉 Left Lower Leg Rotate
			glPushMatrix();					// 左小腿 Left Lower Leg
				LLowerLeg.ScaleTransColor();
				glutSolidCube (LLowerLeg.Size);	
			glPopMatrix();
			LThenar.RotateByPivot();	// 左腳板轉 Left Fist Rotate
			glPushMatrix();                // 左腳板 Left Fist
				LThenar.ScaleTransColor();
				glutSolidCube (LThenar.Size);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}







/* 
 * Name: setPose
 * Desc: Set the current pose to the input parameter pose
 */
void Actor::setPose(vector<int> &pose){
	int i, j = 0;

	for(i=0 ; i<3; ++i) { Torso.Offset[i]		= pose[j++]; }
	for(i=0 ; i<3; ++i) { Torso.Rotate[i]		= pose[j++]; }
	for(i=0 ; i<3; ++i) { RUpperArm.Rotate[i]	= pose[j++]; }
	for(i=0 ; i<3; ++i) { RForeArm.Rotate[i]	= pose[j++]; }
	for(i=0 ; i<3; ++i) { LUpperArm.Rotate[i]	= pose[j++]; }
	for(i=0 ; i<3; ++i) { LForeArm.Rotate[i]	= pose[j++]; }
	for(i=0 ; i<3; ++i) { RThigh.Rotate[i]		= pose[j++]; }
	for(i=0 ; i<3; ++i) { RLowerLeg.Rotate[i]	= pose[j++]; }
	for(i=0 ; i<3; ++i) { LThigh.Rotate[i]		= pose[j++]; }
	for(i=0 ; i<3; ++i) { LLowerLeg.Rotate[i]	= pose[j++]; }

	RThenar.Rotate[0] = pose[j++];
	LThenar.Rotate[0] = pose[j++];
}
/* 
 * Name: getPose
 * Desc: get the current pose , return as an array
 */
vector<int> Actor::getPose(){
	vector<int> pose;
	int i;
	for(i=0 ; i<3; ++i) { pose.push_back(Torso.Offset[i]);		}
	for(i=0 ; i<3; ++i) { pose.push_back(Torso.Rotate[i]);		}
	for(i=0 ; i<3; ++i) { pose.push_back(RUpperArm.Rotate[i]);	}
	for(i=0 ; i<3; ++i) { pose.push_back(RForeArm.Rotate[i]);	}
	for(i=0 ; i<3; ++i) { pose.push_back(LUpperArm.Rotate[i]);	}
	for(i=0 ; i<3; ++i) { pose.push_back(LForeArm.Rotate[i]);	}
	for(i=0 ; i<3; ++i) { pose.push_back(RThigh.Rotate[i]);		}
	for(i=0 ; i<3; ++i) { pose.push_back(RLowerLeg.Rotate[i]);	}
	for(i=0 ; i<3; ++i) { pose.push_back(LThigh.Rotate[i]);		}
	for(i=0 ; i<3; ++i) { pose.push_back(LLowerLeg.Rotate[i]);	}

	pose.push_back(RThenar.Rotate[0]);
	pose.push_back(LThenar.Rotate[0]);
	return pose;
}
Component::Component(){
	setRotate(0.f, 0.f, 0.f);
	setOffset(0.f, 0.f, 0.f);
	setPivot(0.f, 0.f, 0.f);
	setSize(1);
	setColor(1.f, 1.f, 1.f);
	setScale(1.f, 1.f, 1.f);
}
void Component::setRotate(int x, int y, int z){
	Rotate[0] = x;
	Rotate[1] = y;
	Rotate[2] = z;
}
void Component::setOffset(float x, float y, float z){
	Offset[0] = x;
	Offset[1] = y;
	Offset[2] = z;
}
void Component::setPivot(float x, float y, float z){
	Pivot[0] = x;
	Pivot[1] = y;
	Pivot[2] = z;
}
void Component::setSize(float s) { Size = s; }
void Component::setColor(float r, float g, float b){
	Color[0] = r;
	Color[1] = g;
	Color[2] = b;
}
void Component::setScale(float x, float y, float z){
	Scale[0] = x;
	Scale[1] = y;
	Scale[2] = z;
}
void Component::resetPose(){
	this->setRotate(0.f, 0.f, 0.f);
}
void Component::RotateByPivot(){
	glTranslatef (Pivot[0], Pivot[1], Pivot[2]);
	glRotatef ((GLfloat) Rotate[0], 1.0, 0.0, 0.0); 
	glRotatef ((GLfloat) Rotate[1], 0.0, 1.0, 0.0);
	glRotatef ((GLfloat) Rotate[2], 0.0, 0.0, 1.0);
	glTranslatef (-Pivot[0], -Pivot[1], -Pivot[2]);
}
void Component::ScaleTransColor(){
	glColor3f(Color[0], Color[1], Color[2]);   
	glTranslatef (Offset[0], Offset[1], Offset[2]);
	glScalef (Scale[0], Scale[1], Scale[2]);   
}