//
//  Point3d.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/3/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Point3d.h"
#include <iostream>

Point3d::Point3d():
Point2d(0.0, 0.0), z(0.0) { }

Point3d::Point3d(float x, float y, float z):
Point2d(x, y), z(z) { }