//
//  OrbitCamera.h
//
//  Created by ryoheikomiyama on 2017/05/21.
//
//
#pragma once

#include "ofMain.h"

namespace ofxCameraExtended{

    class OrbitCamera : public ofCamera{
        float longitude; // [degree]
        float latitude; // [degree]
        float radius; // [cm]
        float speed_longitude; // [degree/s]
        float speed_latitude; // [degree/s]
        ofNode target_node; // orbit center
        
        float last_updated_time;
        
    public:
        OrbitCamera();
        ~OrbitCamera();
        void update();
        void drawSelf();
        
        void setLongitude(float longitude){this->longitude = longitude;}
        float getLongitude(){return longitude;}
        void setLatitude(float latitude){this->latitude = latitude;}
        float getLatitude(){return latitude;}
        void setRadius(float radius){this->radius = radius;}
        float getRadius(){return radius;}
        void setLongitudeSpeed(float speed_longitude){this->speed_longitude = speed_longitude;}
        float getLongitudeSpeed(){return speed_longitude;}
        void setLatitudeSpeed(float speed_latitude){this->speed_latitude = speed_latitude;}
        float getLatitudeSpeed(){return speed_latitude;}
        void setTargetPosition(ofVec3f pos){this->target_node.setPosition(pos);}
        ofVec3f getTargetPosition(){return this->target_node.getPosition();}
        
        void setParameters(float longitude, float latitude, float radius, float speed_longitude, float speed_latitude);
        
    };

}
