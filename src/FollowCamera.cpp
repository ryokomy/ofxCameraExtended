//
//  FollowCamera.cpp
//
//  Created by ryoheikomiyama on 2017/05/28.
//
//

#include "FollowCamera.h"

namespace ofxCameraExtended{

    FollowCamera::FollowCamera(){
        setPosition(-6, -5, 2);
        lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 1, 0));
    }
    
    FollowCamera::~FollowCamera(){
        
    }
    
    void FollowCamera::update(){
        if(isEasing){
            // update pos
            start_pos = getPosition() - (p_target_node->getPosition()-getPosition())/(1-current_out)*current_out;
            end_pos = p_target_node->getPosition();
            // update qua
            start_qua.slerp(-current_out/(1-current_out), getOrientationQuat(), p_target_node->getOrientationQuat());
            end_qua = p_target_node->getOrientationQuat();
            
            // easing
            current_time = ofGetElapsedTimef();
            current_out = ofxeasing::map_clamp(current_time, start_time, end_time, start_out, end_out, &ofxeasing::quad::easeInOut);
            
            // update parameters
            current_pos = start_pos + (end_pos-start_pos)*current_out;
            current_qua.slerp(current_out, start_qua, end_qua);
            setPosition(current_pos);
            setOrientation(current_qua);
        }
        else{
            if(p_target_node!=NULL){
                setPosition(p_target_node->getPosition());
                setOrientation(p_target_node->getOrientationQuat());
            }
        }
        
        if(end_time < ofGetElapsedTimef()){
            isEasing = false;
            current_out = 0;
        }
    }
    
    void FollowCamera::startFollow(ofNode* p_target_node){
        this->p_target_node = p_target_node;
        // init parameters
        start_pos = getPosition();
        end_pos = p_target_node->getPosition();
        start_qua = getOrientationQuat();
        end_qua = p_target_node->getOrientationQuat();
        float duration = 1;
        start_time = ofGetElapsedTimef();
        end_time = start_time + duration;
        
        isEasing = true;
    }
    
    void FollowCamera::resetFollow(){
        p_target_node = NULL;
        isEasing = false;
    }
    
    void FollowCamera::drawSelf(){
        ofPushMatrix();
        ofPushStyle();
        ofDrawSphere(getPosition(), 0.05);
        ofDrawBitmapString("Follow", getPosition()+ofVec3f(1, 1, 1)*0.1);
        float arrowsize = 0.5;
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
