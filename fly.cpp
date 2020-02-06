#include "fly.h"

void Fly::setup(float flyRad, float flySpeed) {
	//Make fly spawn at random point around the screen
	side = ofRandom(1, 5);
	if (side == 1) { //Top
		yPos = -150;
		xPos = ofRandom(-150, ofGetWidth() + 150);
	}
	else if (side == 2) { //Right
		yPos = ofRandom(-150, ofGetHeight() + 150);
		xPos = ofGetWidth() + 150;
	}
	else if (side == 3) { //Bottom
		yPos = ofGetHeight() + 150;
		xPos = ofRandom(-150, ofGetWidth() + 150);
	}
	else if (side == 4) { //Left
		yPos = ofRandom(-150, ofGetHeight() + 150);
		xPos = -150;
	}

	//Set fly size and speed according to variable from SwatWorld to increase difficulty
	size = flyRad;
	speed = flySpeed;
}

//Update flies
void Fly::update() {
	//Make fly move towards center 
	//https://stackoverflow.com/questions/7621482/as3-make-enemy-move-towards-mouse
	//First, find the distance between the enemy and your mouse.
	xDistance = xPos - ofGetWidth() / 2;
	yDistance = yPos - ofGetHeight() / 2;
	//Then, find the rotation needed to point the enemy towards the mouse.
	rotation = atan2(yDistance, xDistance);
	//And lastly, here is what you want to put inside your tweenIt function to move the enemy towards the mouse(at 3 pixels per function call)
	xPos -= speed * cos(rotation);
	yPos -= speed * sin(rotation);	
}

//Redraw flies 
void Fly::draw() {
	ofSetColor(0);
	ofDrawCircle(xPos, yPos, size);
}
