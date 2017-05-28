//
//  EasyCamera.cpp
//
//  Created by ryoheikomiyama on 2017/05/27.
//
//

#include "EasyCamera.h"

namespace ofxCameraExtended{

    EasyCamera::EasyCamera(){
        setDistance(800);
        orbit(-45, 15, 100);
        lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 1, 0));
    }
    
    EasyCamera::~EasyCamera(){}
    
    void EasyCamera::update(){
        begin();
        end();
    }
    
    
//    void EasyCamera::setPosition(ofVec3f pos){
//        float radius = pos.length();
//        float longitude = atan(pos.x/pos.z)/(2*PI)*360;
//        float latitude = atan(-pos.y/pos.z)/(2*PI)*360;
//        orbit(longitude, latitude, radius);
//    }
//    
//    void EasyCamera::setPosition(float x, float y, float z){
//        float radius = sqrt(x*x+y*y+z*z);
//        float longitude = atan(x/z)/(2*PI)*360;
//        float latitude = atan(-y/z)/(2*PI)*360;
//        orbit(longitude, latitude, radius);
//    }
    
    void EasyCamera::drawSelf(){
        ofPushMatrix();
        ofPushStyle();
        ofDrawSphere(getPosition(), 5);
        ofDrawBitmapString("EasyCamera", getPosition()+ofVec3f(1, 1, 1)*10);
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
