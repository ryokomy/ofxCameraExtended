//
//  FixedCamera.h
//
//  Created by ryoheikomiyama on 2017/05/27.
//
//
#pragma once

#include "ofMain.h"
#include "ofxEasing.h"

namespace ofxCameraExtended{

    class FixedCamera : public ofCamera{
        
    public:
        FixedCamera();
        ~FixedCamera();
        void drawSelf();
        
    };

}
