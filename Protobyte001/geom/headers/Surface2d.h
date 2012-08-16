//
//  Surface2d.h
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/18/11.
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

#ifndef Protobyte_Library_V01_Surface2d_h
#define Protobyte_Library_V01_Surface2d_h

#include "VerletBall.h"
#include "VerletStick.h"
#include "Curve3d.h"
#include "Spline3d.h"
#include "ImageIO.h"
#include "ProtoUtils.h"

class Surface2d{
    
public:
    Surface2d();
    Surface2d(Vector3df loc, Curve3d* perimeter, int perimeterLen);
    Surface2d(Vector3df loc, Curve3d* perimeter, int perimeterLen, std::string textureName);
    Surface2d(Vector3df loc, Curve3d* perimeter, int perimeterLen, GLuint* texture, int textW, int textH);
    ~Surface2d();
    
    void init();
    void setLoc(Vector3df& loc);
    Vector3df getLoc();
    
    void display();
    void move(Vector3df& nudge);
    
    
    // for texture
    GLuint* texture;
    int textW, textH;
    
private:
    Vector3df loc;
    Dimension3d dim;
    
    // passing single spline
    int perimeterLen;
    Curve3d* perimeter; // deallocated in calling class
    int cntrlPtCount;
    int interpDetail;
    std::string textureName;
    
    
    std::vector<Vector3df> vecs;
    std::vector<Vector3df> vecsOrig;
    std::vector<Vector3df> texCoords;
    
};

#endif
