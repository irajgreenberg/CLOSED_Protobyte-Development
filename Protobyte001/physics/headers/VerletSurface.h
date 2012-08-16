//
//  VerletSurface.h
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/4/11.
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

#ifndef Protobyte_Library_V01_VerletSurface_h
#define Protobyte_Library_V01_VerletSurface_h

#include "VerletBall.h"
#include "VerletStick.h"
#include "Curve3d.h"
#include "Spline3d.h"
//#include "ImageIO.h"
#include "ProtoUtils.h"


class VerletSurface {
    
public:
    VerletSurface();
    VerletSurface(Vector3df loc, Curve3d* perimeter, int perimeterLen);
    //VerletSurface(Vector3df loc, Curve3d** perimeters, int perims, int* perimLens);
    VerletSurface(Vector3df loc, Curve3d* perimeter, int perimeterLen, bool isAnchored);
    //VerletSurface();
    ~VerletSurface();
    void init();
    void setLoc(Vector3df& loc);
    Vector3df getLoc();
    
    void verlet();
    void render();
    void move(Vector3df& nudge);
    
    
    // for texture
    GLuint texture;
    
private:
    Vector3df loc;
    
    // passing single spline
    int perimeterLen;
    Curve3d* perimeter; // deallocated in calling class
    
    // passing array of splines
    Curve3d** perimeters; // deallocated in calling class
    
    bool isAnchored;
    
    std::vector<Vector3df> vecs;
    std::vector<VerletBall> vBalls; // deallocated in destructor
    std::vector<VerletStick> vSticks; // deallocated in destructor
    std::vector<Vector3df> texCoords;

    
    
};

#endif
