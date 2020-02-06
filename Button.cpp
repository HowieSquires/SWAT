#include "Button.h"

void Button::setup(string btnText, int x, int y) {
	//load font
	btnTXT.load("3DHandDrawns.ttf", 34);
	txtCol.set(0); 
	//button text, xPos, yPos from the passed value
	text = btnText;
	xPos = x;
	yPos = y;
	//sets the area of the ofRectangle
	btnRect.set(xPos, yPos, btnTXT.stringWidth(text), btnTXT.stringHeight(text));
}

void Button::drawBtn() {
	//Sets the font color if mouse is hovering over it
	if (btnRect.inside(ofGetMouseX(), ofGetMouseY())) {ofSetColor(120); }
	else { ofSetColor(0); }
	//Draws a string for the button
	btnTXT.drawString(text, xPos, yPos + (btnTXT.stringHeight(text) / 2));
}