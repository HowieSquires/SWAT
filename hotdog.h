#pragma once
#pragma once
#include "ofMain.h"

class Hotdog {
public:
	//Hotdog functions
	void setup(float hdWidth, float hdHeight);
	void draw();
	void update(float hdWidth, float hdHeight);

	//Hotdog variables
	float width, height;
	int xPos, yPos;
	ofImage hotdogImg;
};

