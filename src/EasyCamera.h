//
//  EasyCamera.h
//
//  Created by ryoheikomiyama on 2017/05/27.
//
//
#pragma once

#include "ofMain.h"

namespace ofxCameraExtended{

    class EasyCamera : public ofEasyCam{
        
    public:
        EasyCamera();
        ~EasyCamera();
        void update();
        //void setPosition(ofVec3f pos); // have bug
        //void setPosition(float x, float y, float z); // have bug
        void drawSelf();
        
    };

}
