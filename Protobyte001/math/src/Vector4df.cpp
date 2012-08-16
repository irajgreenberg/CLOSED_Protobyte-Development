//
//  Vector4df.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Vector4df.h"
#include <iostream>


std::ostream& operator<<(std::ostream& output, const Vector4df& vec){
    output << "(" <<  vec.x << ", " << vec.y <<", " << vec.z <<", " << vec.w <<")";
    return output;
    
}

Vector4df::Vector4df(){
    
}

Vector4df::Vector4df(float vals[4]){
    this->vals[0] = x = vals[0];
    this->vals[1] = y = vals[1];
    this->vals[2] = z = vals[2];
    this->vals[3] = w = vals[3];
    
}

Vector4df::Vector4df(float x, float y, float z, float w){
    this->x = vals[0] = x;
    this->y = vals[1] = y;
    this->z = vals[2] = z;
    this->w = vals[3] = w;
}

Vector4df::~Vector4df(){
    
}

Vector4df Vector4df::operator*(const float val){
    return Vector4df(x * val, y * val, z * val, w * val);
}

Vector4df& Vector4df::operator*=(const float val){
    x *= val; 
    y *= val; 
    z *= val; 
    w *= val;
    
    return *this;
}


Vector4df Vector4df::operator+(const Vector4df& v){
    return Vector4df(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vector4df& Vector4df::operator+=(const Vector4df& v){
    x += v.x; 
    y += v.y; 
    z += v.z; 
    w += v.w;
    
    return *this;
}

Vector4df Vector4df::operator/(const float val){
    return Vector4df(x / val, y / val, z / val, w / val);
}

Vector4df& Vector4df::operator/=(const float val){
    x /= val; 
    y /= val; 
    z /= val; 
    w /= val;
    
    return *this;
}


Vector4df Vector4df::operator-(const Vector4df& v){
    return Vector4df(x - v.x, y - v.y, z - v.z, w - v.w);
}

Vector4df& Vector4df::operator-=(const Vector4df& v){
    x -= v.x; 
    y -= v.y; 
    z -= v.z; 
    w -= v.w;
    
    return *this;
}

Vector4df& Vector4df::setTo(float x, float y, float z, float w){
    this->x = x; 
    this->y = y; 
    this->z = z; 
    this->w = w;
    
    return *this;
}

void Vector4df::inv(){
    x *= -1; 
    y *= -1; 
    z *= -1; 
    w *= -1;
}

