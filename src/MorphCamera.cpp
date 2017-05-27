//
//  MorphCamera.cpp
//
//  Created by ryoheikomiyama on 2017/05/22.
//
//

#include "MorphCamera.h"

namespace ofxCameraExtended{

    MorphCamera::MorphCamera(){
        setPosition(300, 200, 300);
        lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 1, 0));
        target_node.setPosition(0, 0, 0);
        target_node.lookAt(ofVec3f(0, 0, 1), ofVec3f(0, 1, 0));
    }
    
    MorphCamera::~MorphCamera(){
        
    }
    
    void MorphCamera::update(){
        if(ofGetFrameNum()%90==0){
            ofNode tn;
            float boxsize = 800;
            tn.setPosition(ofRandom(-boxsize, boxsize), ofRandom(-boxsize, boxsize), ofRandom(-boxsize, boxsize));
            tn.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 1, 0));
            startMorph(tn);
        }
        
        if(isEasing){
            // easing
            current_time = ofGetElapsedTimef();
            current_out = ofxeasing::map_clamp(current_time, start_time, end_time, start_out, end_out, &ofxeasing::quad::easeInOut);
            
            // update parameters
            current_pos = start_pos + (end_pos-start_pos)*current_out;
            current_qua.slerp(current_out, start_qua, end_qua);
            setPosition(current_pos);
            setOrientation(current_qua);
        }
        
        if(end_time < ofGetElapsedTimef()) isEasing = false;
    }
    
    void MorphCamera::startMorph(ofNode target_node){
        this->target_node = target_node;
        // init parameters
        start_pos = getPosition();
        end_pos = target_node.getPosition();
        start_qua = getOrientationQuat();
        end_qua = target_node.getOrientationQuat();
        float duration = 1;
        start_time = ofGetElapsedTimef();
        end_time = start_time + duration;
        
        isEasing = true;
    }
    
    void MorphCamera::drawSelf(){
        ofPushMatrix();
        ofPushStyle();
        ofDrawSphere(getPosition(), 5);
        ofDrawBitmapString("MorphCamera", getPosition()+ofVec3f(1, 1, 1)*10);
        float arrowsize = 50;
        ofSetColor(255, 0, 0);
        ofDrawArrow(getPosition(), getPosition()-getSideDir()*arrowsize);
        ofSetColor(0, 255, 0);
        ofDrawArrow(getPosition(), getPosition()+getUpDir()*arrowsize);
        ofSetColor(0, 0, 255);
        ofDrawArrow(getPosition(), getPosition()+getLookAtDir()*arrowsize);
        ofPopStyle();
        ofPopMatrix();
    }
    
}
