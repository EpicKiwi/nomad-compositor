#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	ofGLFWWindowSettings settings;

	settings.resizable = false;
	settings.setSize(1260,720);
	settings.title = "Twitch OpenFrameworks Lab";

	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
	shared_ptr<ofApp> mainApp(new ofApp());

	ofRunApp(mainWindow,mainApp);
	ofRunMainLoop();

}
