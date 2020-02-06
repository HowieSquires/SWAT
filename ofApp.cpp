#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//Page settings
		ofBackground(255, 255, 204);
		ofSetFrameRate(60);
		ofSetColor(0);
		pageID = 'h';
	//Pause icon
		pauseState = "||";
	//Fonts
		mainTXT.load("3DHandDrawns.ttf", 65);
		subTXT.load("3DHandDrawns.ttf", 20);
		captionTXT.load("3DHandDrawns.ttf", 15);
	//Buttons - Home page
		playBtn.setup("Play", ofGetWidth()/2-250, 400);
		helpBtn.setup("Help", ofGetWidth() / 2-50, 600);
		quitBtn.setup("Quit", ofGetWidth() / 2-250, 800);
	//Help page
		backBtn.setup("Back", 10, 10);
	//In game
		pauseBtn.setup(pauseState, ofGetWidth() - 110, ofGetHeight() - 100);
	//Pause menu
		pResumeBtn.setup("Resume", ofGetWidth() / 2 - 320, ofGetHeight() / 2 - 200);
		pRestartBtn.setup("Restart", ofGetWidth() / 2 - 230, ofGetHeight() / 2);
		pHomeBtn.setup("Home", ofGetWidth() / 2 - 320, ofGetHeight() / 2 + 200);
	//End game
		eHomeBtn.setup("Home", ofGetWidth() / 2 - subTXT.stringWidth("Home"), ofGetHeight() - (subTXT.stringHeight("Home")+40));
	
}

//==============================================================
//Update game
void ofApp::update() {
	switch (pageID) {
	//Play game
	case 'p':
		//If game isn't paused update game process
		if (!isPaused) {
			sw.update(isPaused);
		}
		//if health in game is less than 10%, end and change to exit page
		if (sw.health < 10) {
			sw.endGame();
			pageID = 'e';
		}
		break;
	}
}

//==============================================================
//Draw pages
void ofApp::draw() {
	switch (pageID) {
	//home
	case 'h':
		mainTXT.drawString("SWAT", (ofGetWidth()/2)-(mainTXT.stringWidth("SWAT")/2), 200);
		playBtn.drawBtn();
		helpBtn.drawBtn();
		quitBtn.drawBtn();
		ofSetColor(0);
		captionTXT.drawString("game by Squirrel Tails", ofGetWidth()-(captionTXT.stringWidth("game by Squirrel Tails")+10), ofGetHeight()- (captionTXT.stringHeight("game by Squirrel Tails")));
		break;
	//instructions
	case 'i':
		backBtn.drawBtn();
		ofSetColor(0);
		mainTXT.drawString("Help", (ofGetWidth() / 2) - (mainTXT.stringWidth("Help") / 2), 200);
		subTXT.drawString("1 - Click Play! \n\n\n2 - Stop the flies \neating your hotdog! \n\n\n3 - Keep your hotdog \nas long as possible!", ofGetWidth()/2 -(subTXT.stringWidth("3 - Keep your hotdog ")/2), 400);
		captionTXT.drawString("(pssst... Click the flies to kill them!)", (ofGetWidth() / 2) - (captionTXT.stringWidth("(pssst... Click the flies to kill them!)") / 2), ofGetHeight() - (captionTXT.stringHeight("(pssst... Click the flies to kill them!)")));
		break;
	//play
	case 'p':
		//Draw game world and pause button
		sw.draw();
		pauseBtn.drawBtn();
		//If game is paused draw pause menu
		if (isPaused) {
			ofSetColor(0);
			ofDrawRectRounded(ofGetWidth() / 2 - 405, ofGetHeight() / 2 - 455, 810, 910, 25);
			ofSetColor(255, 255, 230);
			ofDrawRectRounded(ofGetWidth() / 2 - 400, ofGetHeight() / 2 - 450, 800, 900, 25);
			ofSetColor(0);
			subTXT.drawString("Paused", ofGetWidth() / 2 - subTXT.stringWidth("Paused") / 2, ofGetHeight() / 2 - 380);
			pHomeBtn.drawBtn();
			pRestartBtn.drawBtn();
			pResumeBtn.drawBtn();
		}
		break;
	//exit
	case 'e':
		ofSetColor(0);
		mainTXT.drawString("Game Over", (ofGetWidth() / 2) - (mainTXT.stringWidth("Game Over") / 2), 200);
		subTXT.drawString("Your Stats-", (ofGetWidth() / 2) - (subTXT.stringWidth("Your Stats-") / 2), 350);
		captionTXT.drawString("Flies Killed: " + to_string(sw.fliesKilled), (ofGetWidth() / 2) - (captionTXT.stringWidth("Flies Killed: ") / 2-50), 500);
		captionTXT.drawString("Time Survived: " + to_string(sw.seconds), (ofGetWidth() / 2) - (captionTXT.stringWidth("Time Survived: ") / 2+50), 650);
		captionTXT.drawString("Total Score: " + to_string((sw.fliesKilled*sw.seconds)), (ofGetWidth() / 2) - (captionTXT.stringWidth("Total Score: ") / 2-50), 800);
		eHomeBtn.drawBtn();
		break;
	default:

		break;
	}
}

//==============================================================
//Act on mouse clicks
void ofApp::mousePressed(int x, int y, int button) {
	//page specific buttons
	switch (pageID) {
		//Home page
	case 'h':
		//Play button pressed
		if (playBtn.btnRect.inside(x, y)) {
			pageID = 'p';
			//GameWorld setup
			sw.setup();
		}
		//Help button pressed
		if (helpBtn.btnRect.inside(x, y)) {
			pageID = 'i';
		}
		//Quit button pressed
		if (quitBtn.btnRect.inside(x, y)) {
			std::exit(0);
		}
		break;
		//Instructions page
	case 'i':
		//Back button pressed
		if (backBtn.btnRect.inside(x, y)) {
			pageID = 'h';
		}
		break;
		//Play game
	case 'p':
		//Pause button pressed
		if (pauseBtn.btnRect.inside(x, y)) {
			//Check if game isn't paused
			if (!isPaused) {
				isPaused = true;
				pauseState = "|>";
				sw.update(isPaused);
			}
			//Check if game is paused
			else if (isPaused) {
				isPaused = false;
				pauseState = "||";

			}
			//Redraw pause button according to play or paused
			pauseBtn.setup(pauseState, ofGetWidth() - 110, ofGetHeight() - 100);
		}
		//Act on Pause menu buttons only if game is paused
		if (isPaused) {
			//Home button and reset settings
			if (pHomeBtn.btnRect.inside(x, y)) {
				sw.endGame();
				isPaused = false;
				pauseState = "||";
				pauseBtn.setup(pauseState, ofGetWidth() - 110, ofGetHeight() - 100);
				pageID = 'h';
			}
			//Restart button and reset settings
			if (pRestartBtn.btnRect.inside(x, y)) {
				sw.setup();
				sw.update(isPaused);
				isPaused = false;
				pauseState = "||";
				pauseBtn.setup(pauseState, ofGetWidth() - 110, ofGetHeight() - 100);
			}
			//Resume button
			if (pResumeBtn.btnRect.inside(x, y)) {
				isPaused = false;
				pauseState = "||";
				pauseBtn.setup(pauseState, ofGetWidth() - 110, ofGetHeight() - 100);
			}
		}
		break;
	//Exit page
	case 'e':
		//Home button
		if (eHomeBtn.btnRect.inside(x, y)) {
			pageID = 'h';
		}
		break;
	}
}