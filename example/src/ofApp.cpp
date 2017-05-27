#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest();
    // use centi meter scale
    // easy_cam
    easy_cam.setNearClip(near);
    easy_cam.setFarClip(far);
    easy_cam.setDistance(800);
    easy_cam.orbit(45, -15, 800);
    // orbit_cam
    orbit_cam.setNearClip(near);
    orbit_cam.setFarClip(far);
    // morph_cam
    morph_cam.setNearClip(near);
    morph_cam.setFarClip(far);
    // fixed_cam
    fixed_cam.setNearClip(near);
    fixed_cam.setFarClip(far);
}

//--------------------------------------------------------------
void ofApp::update(){
    orbit_cam.update();
    morph_cam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    easy_cam.begin();
    
    ofDrawGrid(50, 20);
    
    ofPushStyle();
    ofSetLineWidth(3);
    ofSetColor(255, 0, 0);
    ofDrawArrow(ofVec3f(0, 0, 0), ofVec3f(100, 0, 0));
    ofSetColor(0, 255, 0);
    ofDrawArrow(ofVec3f(0, 0, 0), ofVec3f(0, 100, 0));
    ofSetColor(0, 0, 255);
    ofDrawArrow(ofVec3f(0, 0, 0), ofVec3f(0, 0, 100));
    ofPopStyle();
    
    orbit_cam.drawSelf();
    morph_cam.drawSelf();
    fixed_cam.drawSelf();
    
    easy_cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='m'){
        ofNode target_node;
        target_node.setPosition(300, 200, 400);
        target_node.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 100, 0));
        morph_cam.startMorph(target_node);
    }
    if(key=='M'){
        ofNode target_node;
        target_node.setPosition(-100, 200, -300);
        target_node.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 100, 0));
        morph_cam.startMorph(target_node);
    }
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
