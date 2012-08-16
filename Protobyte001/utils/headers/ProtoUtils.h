//
//  ProtoUtils.h
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//
// Library Usage:
// This work is licensed under the Creative Commons 
// Attribution-NonCommercial-ShareAlike 3.0 Unported License. 
// To view a copy of this license, visit 
// http://creativecommons.org/licenses/by-nc-sa/3.0/ 
// or send a letter to Creative Commons, 
// 444 Castro Street, Suite 900, 
// Mountain View, California, 94041, USA.
//

#ifndef Protobyte_Library_V01_ProtoUtils_h
#define Protobyte_Library_V01_ProtoUtils_h

float getRand(); // between  0-1
float getRand(float mx); // between 0-max
float getRand(float min, float max);
float getDist(float x1, float y1, float x2, float y2);
bool isPicked(float pickX, float pickY, float& x, float& y, float& z);
float getFrameRate();
void printFrameRate();


struct Color4f {
    float r;
    float g;
    float b;
    float a;
};

struct Point2D {
    float x;
    float y;
};

struct Point3D {
    float x;
    float y;
    float z;
};

#endif
