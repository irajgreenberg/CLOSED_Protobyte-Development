//
//  Tuple2df.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/15/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Tuple2df.h"

Tuple2df::Tuple2df() {
    
}

Tuple2df::Tuple2df(float elem0, float elem1):
elem0(elem0), elem1(elem1) {
    
}

// overloaded << operator for outputting field values in objects
std::ostream& operator<<(std::ostream& output, const Tuple2df& t) {
    output << "(" <<  t.elem0 << ", " << t.elem1 <<")";
    return output;
}
