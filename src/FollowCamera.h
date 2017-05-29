//
//  FollowCamera.h
//
//  Created by ryoheikomiyama on 2017/05/28.
//
//
#pragma once

#include "ofMain.h"
#include "ofxEasing.h"

namespace ofxCameraExtended{

    class FollowCamera : public ofCamera{
        
        float speed_average;
        
        // ofGetElapsedTimef
        float start_time;
        float end_time;
        float current_time;
        // 0 - 1
        float start_out = 0;
        float end_out = 1;
        float current_out = 0;
        // position
        ofVec3f start_pos;
        ofVec3f end_pos;
        ofVec3f current_pos;
        // quaternion
        ofQuaternion start_qua;
        ofQuaternion end_qua;
        ofQuaternion current_qua;
        
        ofNode* p_target_node = NULL;
        bool isEasing = false;
        
    public:
        FollowCamera();
        ~FollowCamera();
        void update();
        void startFollow(ofNode* p_target_node);
        void resetFollow();
        void updatePosQua();
        void drawSelf();
    };

}
