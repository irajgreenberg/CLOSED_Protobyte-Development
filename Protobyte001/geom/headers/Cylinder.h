//
//  Cylinder.h
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

#ifndef Protobyte_Library_V01_Cylinder_h
#define Protobyte_Library_V01_Cylinder_h

#include "Geom3d.h"
#include "Vector3df.h"
#include "Dimension3d.h"
#include "TriFace3d.h"
#include "ProtoSetup.h"
#include "ProtoUtils.h"

class Cylinder: public Geom3d {
    
private:
    void init();
    void createVertices();
    void createIndices();
    
public:
    Cylinder();
    Cylinder(int detail);
    Cylinder(Vector3df loc, Dimension3d dim, int detail);
    ~Cylinder();
    
   
    
};


#endif
