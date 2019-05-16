#include "script.h"
#include "GL/glut.h"

bool Script::Load(){
	file.open(fname.c_str());
	cout << "Reading file \"" << fname << "\"...";
	if(!file.is_open()){
		cout << " Failed!" << endl;
		return false;
	}

	vector<int>	frame(_CONTROLLER_NUM_);

	while(!file.eof()){
		
		// Peek if the current line is a comment or End-of-File or a mark
		char c = file.peek();
		if(c == '*')	file.ignore(1,'*');
		if(c == '/' || c == EOF){
			file.ignore(_TRASH_CAN_SIZE_,'\n');	// ignore this line
			continue;
		}
		
		for(int i = 0 ; i < _CONTROLLER_NUM_ ; i++)		file >> frame[i];
		file.ignore(16,'\n');

		script.push_back(frame);
	}


	file.close();

	cout << "Done!!" << endl;
	cout << "    script size = " << script.size() << endl;
	return true;
}

bool Script::Append2File(vector<int> pose){
	ofile.open(fname.c_str(), ios_base::app);
	if(!ofile.is_open()){
		cout << "Open file \"" << fname << "\" failed!" << endl;
		return false;
	}
	for(unsigned int i = 0 ; i < pose.size() ; i++){
		if(i > 0)	ofile << " ";
		ofile << pose[i];
	}
	script.push_back(pose);
	ofile << endl;
	ofile.close();
	return true;
}
vector<int> &Script::getFrame(int frameIdx){
	return script[frameIdx];
}

int Script::getController(int frameIdx, int ctrlIdx){
	return script[frameIdx][ctrlIdx];
}

int Script::frameNumber(){
	return (int)script.size();
}

AnimationVariables::AnimationVariables(){
	ResetVars();

	// register periods of frames where camera surrounding effect should be showing
	camSurroundReg.push_back(pair<int,int>(229,513));

	// register periods of frames where camera surrounding effect should be showing
	lightColorReg.push_back(pair<int,int>(0,228));

	// register periods of frames where background coloring effect should be showing
	bgColorReg.push_back(pair<int,int>(229,513));

	// register periods of frames where zoom in effect should be showing
	int head, tail;
	for(int i = 229 ; i < 513 ; i++){
		// this means it will register 16 frames on -> 16 frames off -> 16 on -> 16 off.....
		if((((i - 229) % 32) == 0 ) && (((i - 229) % 16) == 0))	head = i;
		if((((i - 229) % 32) != 0 ) && (((i - 229) % 16) == 0))	{
			tail = i;
			zoomReg.push_back(pair<int, int>(head,tail));
		}
	}
	
}
void AnimationVariables::ResetVars(){
	zoom = false;
	isColorLight = false;
	actorIndex  = 0;
	frameIndex = 0;
	viewAngle = 4.71;
	cameraSurroundStep = 0.03925;
	bgColor.r = 0.0;
	bgColor.g = 0.0;
	bgColor.b = 0.0;
	bgColor.a = 1.f;
	ltColor[0] = 1.0;
	ltColor[1] = 1.0;
	ltColor[2] = 1.0;
	ltColor[3] = 1.0;
}
bool AnimationVariables::isRegisteredFrame(vector<pair<int,int>> reg){
	bool res = false;
	for(unsigned int i = 0 ; i < reg.size() ; i++)
		if(frameIndex >= reg[i].first && frameIndex <= reg[i].second)
			res = true;
	return res;
}
void AnimationVariables::CameraSurroundEffect(){
	if(isRegisteredFrame(camSurroundReg)){
		viewAngle += cameraSurroundStep;
		if(viewAngle >= 6.28)
			viewAngle = viewAngle - 6.28;
	}
}
void AnimationVariables::BackgroundColorEffect(){
	if(isRegisteredFrame(bgColorReg)){
		// Color Changing
		if((bgColor.r += 0.3) > 1) bgColor.r -= 1;
		if((bgColor.g += 0.2) > 1) bgColor.g -= 1;
		if((bgColor.b += 0.1) > 1) bgColor.b -= 1;
	}else{
		// Black White Flash
		if(bgColor.r == 0) {
			//glDisable(GL_LIGHT0);
			bgColor.r = bgColor.g = bgColor.b = 0.8;
		}
		else{ 
			//glEnable(GL_LIGHT0);
			bgColor.r = bgColor.g = bgColor.b = 0;
		}
	}

}
void AnimationVariables::ZoomEffect(){
	if(isRegisteredFrame(zoomReg))	
		zoom = true;
	else
		zoom = false;
}
void AnimationVariables::LightEffect(){
	if(isRegisteredFrame(lightColorReg)){
		// Color Changing
		if((ltColor[0] += 0.3) > 1) ltColor[0] -= 1;
		if((ltColor[1] += 0.2) > 1) ltColor[1] -= 1;
		if((ltColor[2] += 0.1) > 1) ltColor[2] -= 1;
	}else{
		ltColor[0] = 1.0;
		ltColor[1] = 1.0;
		ltColor[2] = 1.0;
		ltColor[3] = 1.0;
	}
}