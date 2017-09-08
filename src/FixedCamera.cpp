//
//  FixedCamera.cpp
//
//  Created by ryoheikomiyama on 2017/05/27.
//
//

#include "FixedCamera.h"

namespace ofxCameraExtended{

    FixedCamera::FixedCamera(){
        setPosition(-300, 300*1.6, 200);
        lookAt(ofVec3f(300, 300/2.0, 0), ofVec3f(0, 1, 0));
    }
    
    FixedCamera::~FixedCamera(){}
    
    void FixedCamera::drawSelf(){
        ofPushMatrix();
        ofPushStyle();
        ofDrawSphere(getPosition(), 0.05);
        ofDrawBitmapString("FixedCamera", getPosition()+ofVec3f(1, 1, 1)*0.1);
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
