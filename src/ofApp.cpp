#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	config.loadFile("config.xml");
	string streamKey = config.getValue("config:streamkey", "");

	ofLog() << "Using stream key " << streamKey;

    int fps = 30;
	ofSetFrameRate(fps);
    currentFrame.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
	//liveStreamer.setup(currentFrame.getWidth(), currentFrame.getHeight(), fps, streamKey);

	radius = 100;
	isGrowing = true;
	isClicked = false;
}

//--------------------------------------------------------------
void ofApp::update(){

	if (radius >= MAX_RADIUS) {
		isGrowing = false;
	}
	else if (radius < MIN_RADIUS) {
		isGrowing = true;
	}

	if (isGrowing) {
		radius += GROW_SPEED;
	}
	else {
		radius -= GROW_SPEED;
	}

    currentFrame.begin();
    drawFrame();
    currentFrame.end();

    //currentFrame.readToPixels(currentFramePixels);
	//liveStreamer.addFrame(currentFramePixels);

}

//--------------------------------------------------------------
void ofApp::drawFrame(){

	ofBackground(0);

	if (isClicked) {
		ofSetColor(ofColor(255.0,100.0,100.0));
	}
	else {
		ofSetColor(255);
	}

	ofDrawCircle(
		glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2), 
		radius);

}

void ofApp::draw(){
    currentFrame.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	isClicked = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	isClicked = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
