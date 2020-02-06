#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {
	//Setup the GL context
	ofGLFWWindowSettings settings;
	settings.width = 1920;
	settings.height = 1080;
	settings.resizable = false;
	ofCreateWindow(settings);
								
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}