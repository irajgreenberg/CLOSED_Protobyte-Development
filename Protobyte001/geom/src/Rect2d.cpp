//
//  Rect2d.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/8/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Rect2d.h"
#include <iostream>


Rect2d::Rect2d(){
    left = top = right = bottom = Vector3df(0,0,0);
    bounds[0] = left;
    bounds[1] = top;
    bounds[2] = right;
    bounds[3] = bottom;
    
}

Rect2d::Rect2d(Vector3df left, Vector3df top, Vector3df right, Vector3df bottom):
left(left), top(top), right(right), bottom(bottom) {
    bounds[0] = left;
    bounds[1] = top;
    bounds[2] = right;
    bounds[3] = bottom;
}

Rect2d::Rect2d(Vector3df bounds[4]){
    left = this->bounds[0] = bounds[0];
    top = this->bounds[1] = bounds[1];
    right = this->bounds[2] = bounds[2];
    bottom = this->bounds[3] = bounds[3];
}
