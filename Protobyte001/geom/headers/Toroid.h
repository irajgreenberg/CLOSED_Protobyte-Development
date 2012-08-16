//
//  Toroid.h
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

#ifndef Protobyte_Library_V01_Toroid_h
#define Protobyte_Library_V01_Toroid_h

#include "Toroid.h"
#include "Geom3d.h"


class Toroid: public Geom3d {
    
private:
    int segs;
    float innerRadius, outerRadious;
    void init();
    void createVertices();
    void createIndices();
    
public:
    // constructors
    Toroid();
    Toroid(Dimension3d dim);
    Toroid(Dimension3d dim, int detail, int segs);
    Toroid(Dimension3d dim, int detail, int segs, float innerRadius, float outerRadious);
    
    // destructor - called when object goes out of scope
    // overrides default implementation
    ~Toroid();
    
    //=============================================================================
    // Copy Constructor, called by defaullt when:
    // • instantiating one object (i.e. it doesn't exit yet)and initializing it 
    //   with values from another object.
    
    // Example:
    // toroid t2; // calls Toroid default constructor
    // toroid t1 = t2; // calls Toroid copy constructor
    
    // • passing an object by value.
    // • returning an object from a function by value.
    //=============================================================================
    Toroid(const Toroid& toroid_src);
    
    
    //=============================================================================
    // Assignment Operator, called by default when:
    // assignment between 2 objects that both exist
    //=============================================================================
    Toroid& operator= (const Toroid& toroid_src);
    
};



#endif
