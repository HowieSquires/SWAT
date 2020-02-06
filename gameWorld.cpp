#include "gameWorld.h"

void GameWorld::setup() {
	fliesKilled = 0;
	health = 100;
	seconds = 0;

	startTime = ofGetElapsedTimef();
}

void GameWorld::update() {
	float tick = ofGetElapsedTimef() - startTime;
	//do something every second
	if (tick > 1) {
		startTime = ofGetElapsedTimef();
		seconds--;
	}
}

void GameWorld::draw() {
	subTXT.drawString("Flies killed: ", 10, 50);
	subTXT.drawString("Time: ", ofGetWidth() / 2 - subTXT.stringWidth("Time: ") / 2, 50);
	subTXT.drawString("Health: ", ofGetWidth() - (subTXT.stringWidth("Health: ") + 60), 50);
	if (pauseBtn.btnRect.inside(ofGetMouseX(), ofGetMouseY())) { pauseBtn.txtCol.set(120); }
	else { pauseBtn.txtCol.set(0); }
	pauseBtn.drawBtn();

}

void GameWorld::mousePressed(int x, int y, int button) {
	fliesKilled++;
}


void GameWorld::endGame() {

}