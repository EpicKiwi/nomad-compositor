#pragma once

#include "ofMain.h"
#include "liveStreamer.h"
#include "ofxXmlSettings.h"

class ofApp : public ofBaseApp{

	protected:
		const int MAX_RADIUS = 300;
		const int MIN_RADIUS = 10;
		const int GROW_SPEED = 1;

	protected:

		ofxXmlSettings config;
		LiveStreamer liveStreamer;

		ofFbo currentFrame;
		ofPixels currentFramePixels;

		int radius;
		bool isGrowing;
		bool isClicked;

	public: 
		void drawFrame();

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
