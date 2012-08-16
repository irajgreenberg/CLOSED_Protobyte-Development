//
//  Point3d.h
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/3/11.
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

#ifndef Protobyte_Library_V01_Point3d_h
#define Protobyte_Library_V01_Point3d_h

#include "Point2d.h"

class Point3d: public Point2d {
    
public:
    float z;
    
    Point3d();
    Point3d( float x, float y, float z);
    
    
};

#endif
