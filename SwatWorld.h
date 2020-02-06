#pragma once
//Include game files necessary
#include "ofMain.h"
#include "Button.h"
#include "fly.h"
#include "hotdog.h"
#include <vector>

class SwatWorld {
public:
	//Game stats
	int seconds, health, fliesKilled;
	bool swPaused;

	//Fly data
	vector<Fly> flies;
	int numFlies, flyCount, checkRoundComplete;
	float flyTime, flyRad, flySpeed;

	//Hotdog data
	Hotdog hDog;
	float hDogH, hDogW;

	//Start time for timer 
	float startTime;

	//Fonts
	ofTrueTypeFont subTXT;

	//Functions
	void setup();
	void update(bool isPaused);
	void draw();

	void mousePressed(ofMouseEventArgs& e);

	void endGame();
};
