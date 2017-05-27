//
//  FixedCamera.cpp
//
//  Created by ryoheikomiyama on 2017/05/27.
//
//

#include "FixedCamera.h"

namespace ofxCameraExtended{

    FixedCamera::FixedCamera(){
        setPosition(-600, 300, 200);
        lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 1, 0));
    }
    
    FixedCamera::~FixedCamera(){}
    
    void FixedCamera::drawSelf(){
        ofPushMatrix();
        ofPushStyle();
        ofDrawSphere(getPosition(), 5);
        ofDrawBitmapString("FixedCamera", getPosition()+ofVec3f(1, 1, 1)*10);
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
