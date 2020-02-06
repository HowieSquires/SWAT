#include "SwatWorld.h"

void SwatWorld::setup() {
	//Listen for mouse clicks
	ofAddListener(ofEvents().mousePressed, this, &SwatWorld::mousePressed);
	//UI vars
	subTXT.load("3DHandDrawns.ttf", 20);

	//Game vars
	fliesKilled = 0;
	health = 100;
	seconds = 0;
	//Fly vars
	flyRad = 50;
	flySpeed = 2;
	flyCount = 0;
	numFlies = 0;
	checkRoundComplete = 0;
	//Hotdog vars
	hDogW = 660;
	hDogH = 334;
	hDog.setup(hDogW, hDogH);

	startTime = ofGetElapsedTimef();
}


void SwatWorld::update(bool isPaused) {
	float tick = ofGetElapsedTimef() - startTime;
	//Timer
	if (tick > 1) {
		startTime = ofGetElapsedTimef();
		seconds++;
	}

	//Create flies
	if (numFlies < 1) {
		cout << "flyRad: " << flyRad << endl;
		cout << "flySpeed: " << flySpeed << endl;
		cout << "flyCount: " << flyCount << endl;

		numFlies += flyCount;
		flies.resize(numFlies);
		for (int i = 1; i <= flyCount; i++) {
			flies[numFlies - i].setup(flyRad, flySpeed);
		}

		//Make flies harder for next round
		if (flyRad > 10) flyRad -= 1.5;
		if (flySpeed < 20) flySpeed += 0.1;
		flyCount++;
	}

	//Update flies
	for (int i = 0; i < flies.size(); i++) {
		flies[i].update();
	}

	//Update hotdog if flies hit
	for (int i = 0; i < flies.size(); i++) {
		if (((flies[i].xPos > hDog.xPos-hDog.width/2) && (flies[i].xPos < hDog.xPos + hDog.width / 2)) && ((flies[i].yPos > hDog.yPos-hDog.height / 2) && (flies[i].yPos < hDog.yPos + hDog.height / 2))) {
			//Remove survived fly
			flies.erase(flies.begin() + i);
			numFlies--;
			//Decrease hotdog health
			health -= 10;
			//Decrease hotdog size
			hDogW = hDogW * 0.9;
			hDogH = hDogH * 0.9;
			//Update
			hDog.update(hDogW, hDogH);	
		}
	}

	//update pause status from ofApp
	swPaused = isPaused;

	//Change this to a died display screen
	if (health < 10) {
		endGame();
	}
}

//Draw game world
void SwatWorld::draw() {
	//Draw hotdog object
	hDog.draw();
	//Game statistics
	ofSetColor(0);
	subTXT.drawString("Flies killed: " + to_string(fliesKilled), 10, 50);
	subTXT.drawString("Time: " + to_string(seconds), ofGetWidth() / 2 - subTXT.stringWidth("Time: ") / 2, 50);
	subTXT.drawString("Health: " + to_string(health) + "%", ofGetWidth() - (subTXT.stringWidth("Health: ") + 200), 50);
	//Draw flies in new positions
	for (int i = 0; i < flies.size(); i++) {
		flies[i].draw();
	}
}

//Mouse pressed within game play
void SwatWorld::mousePressed(ofMouseEventArgs& e) {
	//Check if game isn't paused
	if (!swPaused) {
		//Check whether a fly is clicked then kill it
		for (int i = 0; i < flies.size(); i++) {
			if (((e.x > flies[i].xPos - flies[i].size) && (e.x < flies[i].xPos + flies[i].size)) && ((e.y > flies[i].yPos - flies[i].size) && (e.y < flies[i].yPos + flies[i].size))) {
				flies.erase(flies.begin() + i);
				numFlies--;
				fliesKilled++;
			}
		}
	}
}

//End game when hotdog health is less than 10%
void SwatWorld::endGame() {
	//Remove remaining flies
	for (int i = 0; i < flies.size(); i++) {
		flies.erase(flies.begin() + i);
		numFlies--;
	}
	//Remove mouse click listener
	ofRemoveListener(ofEvents().mousePressed, this, &SwatWorld::mousePressed);
}
