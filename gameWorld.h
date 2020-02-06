#pragma once
#include "ofMain.h"
#include <vector>

class GameWorld {
public:
	int seconds, health, fliesKilled;
	//start time for timer 
	float startTime;

	void setup();
	void update();
	void draw();

	void mousePressed(int x, int y, int button);

	void endGame();
};