#pragma once
//Include necessary game files
#include "ofMain.h"
#include "math.h"

//Build fly object
class Fly {
public:
	//Fly functions
	void setup(float flyRad, float flySpeed);
	void draw();
	void update();
	
	//Fly variables
	int size;
	float xPos, yPos;

private:
	//Private fly variables don't need accessing
	int side, speed;
	float xDistance, yDistance, rotation;
};
