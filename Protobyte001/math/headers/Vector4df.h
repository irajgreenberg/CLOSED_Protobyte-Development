//
//  Vector4df.h
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

#ifndef Protobyte_Library_V01_Vector4df_h
#define Protobyte_Library_V01_Vector4df_h

#include <string.h>
#include <iostream>

class Vector4df {
    
    // overloaded << operator
    // declared friend function to allow access to private data fields
    friend std::ostream& operator<<(std::ostream& output, const Vector4df& vec);
    
private:
    float vals[4];
    
    
public:
    float x, y, z, w;
    
    Vector4df();
    Vector4df(float vals[4]);
    Vector4df(float x, float y, float z, float w);
    
    ~Vector4df();
    
    Vector4df operator*(const float val);
    Vector4df& operator*=(const float val);
    Vector4df operator+(const Vector4df& v);
    Vector4df& operator+=(const Vector4df& v);
    Vector4df operator/(const float val);
    Vector4df& operator/=(const float val);
    Vector4df operator-(const Vector4df& v);
    Vector4df& operator-=(const Vector4df& v);
    
    Vector4df& setTo(float x, float y, float z, float w);
    void inv();
    
};


#endif
