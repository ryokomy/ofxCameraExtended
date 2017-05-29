#pragma once

#include "ofMain.h"
#include "ofxCameraExtended.h"

class ofApp : public ofBaseApp{
    
    ofxCameraExtended::EasyCamera easy_cam;
    ofxCameraExtended::OrbitCamera orbit_cam;
    ofxCameraExtended::MorphCamera morph_cam;
    ofxCameraExtended::FixedCamera fixed_cam;
    ofxCameraExtended::FollowCamera follow_cam;
    float near = 0.01;
    float far = 10000;

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
