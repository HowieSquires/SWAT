#pragma once
//Load including files
#include "ofMain.h"
#include "Button.h"
#include "SwatWorld.h"
#include <string>

using namespace std;

class ofApp : public ofBaseApp {

public:
	//Premade functions
		void setup();
		void update();
		void draw();
		void mousePressed(int x, int y, int button);

	//My variables
		//Determine page setting
		char pageID;
		//Load fonts
		ofTrueTypeFont mainTXT, captionTXT, subTXT;
		//Create Buttons
		Button playBtn, helpBtn, quitBtn, backBtn, pauseBtn, pResumeBtn, pRestartBtn, pHomeBtn, eHomeBtn;
		//Check if game is paused
		bool isPaused;
		//Draw pause icon
		string pauseState;

	//Make game world
		SwatWorld sw;
};
