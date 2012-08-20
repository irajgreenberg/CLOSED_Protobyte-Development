//
//  Vector3df.h
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

#ifndef Protobyte_Library_V01_Vector3df_h
#define Protobyte_Library_V01_Vector3df_h

#include <string.h>
#include <iostream>

class Vector3df {
    
    // overloaded << operator
    // declared friend function to allow access to private data fields
    friend std::ostream& operator<<(std::ostream& output, const Vector3df& vec);
    
public:
    float x, y, z;
    
    static int totalVectorCount;
    
    // constructor
    Vector3df(float x=0.0f, float y=0.0f, float z=0.0f);
    
    // destructor
    ~Vector3df();
    
    // copy constructor
    Vector3df (const Vector3df& vec);
    
    // assignment op
     Vector3df& operator=(const Vector3df& vec);
    
    // overloaded ops
    bool operator==(const Vector3df &v) const;
    Vector3df& operator+=(const Vector3df& v);
    Vector3df& operator-=(const Vector3df& v);
    Vector3df& operator*=(const Vector3df& v);
    Vector3df& operator/=(const Vector3df& v);
    
    /* binary operators should be made as general NON-member functions
    Vector3df operator+(const Vector3df& v);
    Vector3df operator-(const Vector3df& v);
    Vector3df operator*(const Vector3df& v);
    Vector3df operator/(const Vector3df& v);
     */
    
    // basic methods
    void add(const Vector3df& v);
    void inv();
    void sub(const Vector3df& v);
    void mult(float val);
    void div(float val);
    void setTo(const Vector3df& v); 
    float mag();
    void normalize();
    float angle(const Vector3df& v);
    float dot(const Vector3df& v);
    void cross(const Vector3df& v, Vector3df& vCross);
    float dist(const Vector3df& v);
    
    Vector3df& RotateAroundAxis(float theta, const Vector3df& axis);
    
    
    // getter/setter functions
    float getX();
    void setX(float x);
    float getY() const;
    void setY(float y);
    float getZ();
    void setZ(float z);
    
    float getNormX();
    void setNormX(float normX);
    float getNormY();
    void setNormY(float normY);
    float getNormZ();
    void setNormZ(float normZ);
    
    
    // static functions
    static void setTo(Vector3df& v1, const Vector3df& v2);
    static Vector3df sub(Vector3df& v1, const Vector3df& v2); 
    static Vector3df add(Vector3df& v1, float val);
    static Vector3df mult(Vector3df& v1, float val);
    
    
    
private:
    
    float normX, normY, normZ;
    
    /*//eventually use:
     union { // anonymous struct
     float v3[3];
     struct {
     float x;
     float y;
     float z;
     };
     };*/
};


#endif
