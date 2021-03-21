#include "liveStreamer.h"

void LiveStreamer::setup(int width, int height, int fps, string streamKey){
    gop = fps * 2;
    gopMin = fps;

    videoRecorder.setupCustomOutput(
        width,
        height,
        fps,
        "-f flv -ac 2 -ar " + ofToString(audioRate) + " -vcodec libx264 -g \"" +  ofToString(gop) + "\" -keyint_min \"" + ofToString(gopMin) + "\" -b:v \"" + cbr + "\" -minrate \"" + cbr + "\" -maxrate \"" + cbr + "\" -pix_fmt yuv420p -preset \"" + quality + "\" -tune zerolatency -acodec aac -strict normal -bufsize \"" + cbr + "\" -threads 4 \"rtmp://mrs.contribute.live-video.net/app/" + streamKey + "\"",
        true);

	videoRecorder.start();

}

bool LiveStreamer::addFrame(ofPixels pixels){
    bool success = videoRecorder.addFrame(pixels);
	if (!success) {
		ofLogWarning("This frame was not added!");
	}

	if (videoRecorder.hasVideoError()) {
		ofLogWarning("The video recorder failed to write some frames!");
	}

	if (videoRecorder.hasAudioError()) {
		ofLogWarning("The video recorder failed to write some audio samples!");
	}

    return success;
}