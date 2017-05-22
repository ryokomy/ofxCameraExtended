#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest();
    // meter scale
    easy_cam.setNearClip(0.01);
    easy_cam.setFarClip(100);
    easy_cam.setDistance(8);
    easy_cam.orbit(45, -15, 6);
    orbit_cam.setNearClip(0.01);
    orbit_cam.setFarClip(100);
}

//--------------------------------------------------------------
void ofApp::update(){
    orbit_cam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    easy_cam.begin();
    
    ofDrawGrid(0.5, 10);
    
    ofPushStyle();
    ofSetLineWidth(3);
    ofSetColor(255, 0, 0);
    ofDrawArrow(ofVec3f(0, 0, 0), ofVec3f(1, 0, 0));
    ofSetColor(0, 255, 0);
    ofDrawArrow(ofVec3f(0, 0, 0), ofVec3f(0, 1, 0));
    ofSetColor(0, 0, 255);
    ofDrawArrow(ofVec3f(0, 0, 0), ofVec3f(0, 0, 1));
    ofPopStyle();
    
    orbit_cam.drawSelf();
    easy_cam.end();
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
