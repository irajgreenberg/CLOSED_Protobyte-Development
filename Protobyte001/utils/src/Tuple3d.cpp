//
//  Tuple3d.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include <iostream>
#include "Tuple3d.h"

Tuple3d::Tuple3d() {}

Tuple3d::Tuple3d(unsigned short elem0, unsigned short elem1, unsigned short elem2):
Tuple2d(elem0, elem1), elem2(elem2) { }

// overloaded << operator for outputting field values in objects
std::ostream& operator<<(std::ostream& output, const Tuple3d& t) {
    output << "(" <<  t.elem0 << ", " << t.elem1 <<", " << t.elem2 <<")";
    return output;
}

