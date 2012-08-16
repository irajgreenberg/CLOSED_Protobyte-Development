//
//  Dimension3d.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Dimension3d.h"
#include <iostream>


Dimension3d::Dimension3d():
w(1), h(1), d(1){ // initialize to unit size
    // std::cout << "in Dimension3d default constructor" << std::endl;

}

Dimension3d::Dimension3d(float w, float h, float d):
w(w), h(h), d(d){
    // std::cout << "in Dimension3d overloaded constructor" << std::endl;
}

// overloaded << operator for outputting field values in objects
std::ostream& operator<<(std::ostream& output, const Dimension3d& dim) {
    output << "(" <<  dim.w << ", " << dim.h <<", " << dim.d <<")";
    return output;
}

float Dimension3d::getW() {
    return w;
}
void Dimension3d::setW(float w){
    this->w = w;
}

float Dimension3d::getH() {
    return h;
}

void Dimension3d::setH(float h) {
    this->h = h;
}

float Dimension3d::getD() {
    return d;
}

void Dimension3d::setD(float d) {
    this->d = d;
}

