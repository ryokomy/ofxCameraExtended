#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest();
    // use meter scale
    // easy_cam
    easy_cam.setNearClip(nearclip);
    easy_cam.setFarClip(farclip);
    easy_cam.setDistance(8);
    easy_cam.orbit(45, -15, 8);
    // orbit_cam
    orbit_cam.setNearClip(nearclip);
    orbit_cam.setFarClip(farclip);
    // morph_cam
    morph_cam.setNearClip(nearclip);
    morph_cam.setFarClip(farclip);
    // fixed_cam
    fixed_cam.setNearClip(nearclip);
    fixed_cam.setFarClip(farclip);
    // follow_cam
    follow_cam.setNearClip(nearclip);
    follow_cam.setFarClip(farclip);
}

//--------------------------------------------------------------
void ofApp::update(){
    // auto morphing
    if(ofGetFrameNum()%90==0){
        ofNode tn;
        float boxsize = 8;
        tn.setPosition(ofRandom(-boxsize, boxsize), ofRandom(-boxsize, boxsize), ofRandom(-boxsize, boxsize));
        tn.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 1, 0));
        morph_cam.startMorph(tn);
    }

    easy_cam.update();
    orbit_cam.update();
    morph_cam.update();
    follow_cam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    easy_cam.begin();
    
    ofDrawGrid(0.5, 20);
    
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
    morph_cam.drawSelf();
    fixed_cam.drawSelf();
    follow_cam.drawSelf();
    
    easy_cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='0'){
        follow_cam.resetFollow();
    }
    if(key=='1'){
        follow_cam.startFollow((ofNode*)&orbit_cam);
    }
    if(key=='2'){
        follow_cam.startFollow((ofNode*)&morph_cam);
    }
    if(key=='3'){
        follow_cam.startFollow((ofNode*)&fixed_cam);
    }
    if(key=='4'){
        follow_cam.startFollow((ofNode*)&easy_cam);
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
