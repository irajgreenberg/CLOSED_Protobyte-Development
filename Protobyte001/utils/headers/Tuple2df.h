//
//  Tuple2df.h
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/15/11.
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

#ifndef Protobyte_Library_V01_Tuple2df_h
#define Protobyte_Library_V01_Tuple2df_h

#include <iostream>

class Tuple2df{
    
    
public:
    float elem0, elem1;
    
    Tuple2df();
    Tuple2df(float elem0, float elem1);
    
    
    
    // overloaded << operator
    // declared friend function to allow access to private data fields
    friend std::ostream& operator<<(std::ostream& output, const Tuple2df& vec);
};

#endif
