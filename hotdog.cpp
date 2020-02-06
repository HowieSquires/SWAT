#include "hotdog.h"

//Setup Hotdog variables
void Hotdog::setup(float hdWidth, float hdHeight) {
	//Load hotdog image 
	hotdogImg.load("sHotdog.png");
	//Set image center
	hotdogImg.setAnchorPercent(0.5, 0.5);

	//Set hotdog variables
	width = hdWidth;
	height = hdHeight;
	xPos = ofGetWidth() / 2;
	yPos = ofGetHeight() / 2;
}

//Update hotdog size if flies collide
void Hotdog::update(float hdWidth, float hdHeight) {
	width = hdWidth;
	height = hdHeight;
}

//Redraw hotdog according to new size
void Hotdog::draw() {
	ofSetColor(255);
	hotdogImg.draw(xPos, yPos, width, height);
}
