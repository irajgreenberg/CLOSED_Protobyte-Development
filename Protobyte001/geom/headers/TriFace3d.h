//
//  TriFace3d.h
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

#ifndef Protobyte_Library_V01_TriFace3d_h
#define Protobyte_Library_V01_TriFace3d_h

#include <string.h>
#include <iostream>
#include "Vector3df.h"
//#include "Face3d.h"

class TriFace3d {
    
    
    // overloaded << operator
    // declared friend function to allow access to private data fields
    friend std::ostream& operator<<(std::ostream& output, const TriFace3d& face);
private:
    Vector3df loc, v1, v2, v3, n, center;
    Vector3df vecNorms[3];
    
public:
    TriFace3d();
    TriFace3d(Vector3df v1, Vector3df v2, Vector3df v3);
    TriFace3d(Vector3df loc, Vector3df v1, Vector3df v2, Vector3df v3);
    
    TriFace3d(Vector3df* v1_p, Vector3df* v2_p, Vector3df* v3_p);
    
    ~TriFace3d();
    
    bool operator==(const TriFace3d& f);
    
    void init();
    void makeSurfNorm();
    void normal(Vector3df& n); // not sure I want to keep this around–thinking...
    void display();
    void displayNorm(float len = 1.1); // default value fo lazy normal viewers
    Vector3df getNorm();
    
    void setVertexNorms(Vector3df vn1, Vector3df vn2, Vector3df vn3);
    
    // setters/getters
    Vector3df getV1();
    void setV1(Vector3df v1);
    
    Vector3df getV2();
    void setV2(Vector3df v2);
    
    Vector3df getV3();
    void setV3(Vector3df v3);
    
    // using pointers
    Vector3df* getV1_p();
    void setV1(Vector3df* v1_p);
    
    Vector3df* getV2_p();
    void setV2(Vector3df* v2_p);
    
    Vector3df* getV3_p();
    void setV3(Vector3df* v3_p);
    
    
};

#endif
