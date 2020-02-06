#pragma once
#include "ofMain.h"

//This is a class to create buttons for SWAT
class Button
{
public:
	//variables used to make the buttons
		ofRectangle btnRect;
		ofTrueTypeFont btnTXT;
		string text;
		ofColor txtCol;
		int xPos;
		int yPos;

	//called within ofApp.cpp -> setup() 
	void setup(string btnText, int x, int y);

	//Called to draw a button
	void drawBtn();
};