//
//  Rect2d.h
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/8/11.
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

#ifndef Protobyte_Library_V01_Rect2d_h
#define Protobyte_Library_V01_Rect2d_h

#include "Vector3df.h"

class Rect2d {
    
public:
    
    Vector3df left, top, right, bottom;
    Vector3df bounds[4];
    
    Rect2d();
    Rect2d(Vector3df left, Vector3df top, Vector3df right, Vector3df bottom);
    Rect2d(Vector3df bounds[]);
    
};

#endif
