//
//  ProtoUtils.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//


#include "ProtoSetup.h"
#include "ProtoUtils.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>


// for determining frame rate
time_t timeIn = time (NULL);
float frameRate, frameCount;

float getRand() {
    float min = 0.0;
    float max = 1.0;
    float range=(max-min);
    return (min+range*rand()/((float)RAND_MAX + 1.0));
}

float getRand(float mx) {
    float min = 0.0;
    float max = mx;
    float range=(max-min);
    return (min+range*rand()/((float)RAND_MAX + 1.0));
}

float getRand(float min, float max) {
    float range=(max-min);
    return (min+range*rand()/((float)RAND_MAX + 1.0));
}

float getDist(float x1, float y1, float x2, float y2){
    float dx = x2-x1;
    float dy = y2-y1;
    float dist = sqrt(dx*dx + dy*dy);
    return dist;
}

float getFrameRate(){
    frameCount++;
    int timeSeg = int(time(NULL) - timeIn);
    if (timeSeg == 1){
        frameRate = frameCount/timeSeg;
        timeIn = int(time(NULL));
        frameCount = 1;
    }
    return frameRate; 
}

void printFrameRate(){
    frameCount++;
    int timeSeg = int(time(NULL) - timeIn);
    if (timeSeg == 1){
        frameRate = frameCount/timeSeg;
        timeIn = int(time(NULL));
        frameCount = 1;
    }
    std::cout << "frameRate = " <<  frameRate << " fps" << std::endl; 
}

// get screen values when picking
bool isPicked(float pickX, float pickY, float& x, float& y, float& z){
    
    double winX;
    double winY;
    double winZ;
    double modelMatrix[16];
    double projectionMatrix[16];
    int view[4];
    glGetDoublev(GL_MODELVIEW_MATRIX, modelMatrix);
    glGetDoublev(GL_PROJECTION_MATRIX, projectionMatrix);
    glGetIntegerv(GL_VIEWPORT, view);
    gluProject(x, y, z, modelMatrix, projectionMatrix, view, &winX, &winY, &winZ);
    
    std::cout << "x = " << x << std::endl;
    std::cout << "winX = " << winX << std::endl;
    
    /*if (getDist(pickX, winX, pickY, winY) < 5){
     return true;
     }*/
    
    return false;
}