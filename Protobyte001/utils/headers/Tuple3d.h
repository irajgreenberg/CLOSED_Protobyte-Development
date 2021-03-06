//
//  Tuple3d.h
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

#ifndef Protobyte_Library_V01_Tuple3d_h
#define Protobyte_Library_V01_Tuple3d_h

#include "Tuple2d.h"

class Tuple3d: public Tuple2d{
    
    // overloaded << operator
    // declared friend function to allow access to private data fields
    friend std::ostream& operator<<(std::ostream& output, const Tuple3d& vec);
    
    
public:
    Tuple3d();
    Tuple3d(unsigned short elem0, unsigned short elem1, unsigned short elem2);
    
    unsigned short elem2;
    
};

#endif
