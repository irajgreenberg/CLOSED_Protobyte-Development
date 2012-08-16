//
//  Shape2d.h
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

#ifndef Protobyte_Library_V01_Shape2d_h
#define Protobyte_Library_V01_Shape2d_h

// Vector2df loc, Dimension2d dim need to create these classes
#include "Point2d.h"
#include "Curve3d.h" // create Curve2d class
//#include "geomFunctions.h"
#include <vector>

class Shape2d {
    
public:
    Shape2d();
    //Shape2d(Curve3d* contours, int* curveLens, int arrLen);
    Shape2d(Curve3d* contour);
    //~Shape2d();
    
    //void setContour(Curve3d& contour);
    
    void display();
    
    
private:
    int* curveLens;
    int cntrlPtsLen;
    int arrLen;
    //Curve3d contour;
    //Vector3df* vecs;
    int vecsCount;
    std::vector <Vector3df> vecs;
    
    void init();
    void tessellate();
    
    
};

#endif
