#pragma once

#include "ofMain.h"
#include "ofxVideoRecorder.h"

class LiveStreamer {

public:

    int width;
    int height;
    int fps;

    int gop;
	int gopMin;
	string quality = "ultrafast";
	string cbr = "1000k";
    int audioRate = 44100;
    string streamKey;

	ofxVideoRecorder videoRecorder;

public:

    void setup(int width, int height, int fps, string streamKey);

    bool addFrame(ofPixels pixels);

};