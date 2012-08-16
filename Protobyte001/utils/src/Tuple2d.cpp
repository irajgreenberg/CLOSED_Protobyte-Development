//
//  Tuple2d.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/5/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include <iostream>
#include "Tuple2d.h"

Tuple2d::Tuple2d() {}

Tuple2d::Tuple2d(unsigned short elem0, unsigned short elem1):
elem0(elem0), elem1(elem1) { }

// overloaded << operator for outputting field values in objects
std::ostream& operator<<(std::ostream& output, const Tuple2d& t) {
    output << "(" <<  t.elem0 << ", " << t.elem1 <<")";
    return output;
}
