//
//  Dimension3d.h
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

#ifndef Protobyte_Library_V01_Dimension3d_h
#define Protobyte_Library_V01_Dimension3d_h


#include <iostream>

class Dimension3d{
    
    friend std::ostream& operator<<(std::ostream& output, const Dimension3d& dim);
    
private:
    
    
public:
    float w, h, d;
    
    
    Dimension3d();
    Dimension3d(float w, float h, float d);
    
    float getW();
    void setW(float w);
    
    float getH();
    void setH(float h);
    
    float getD();
    void setD(float d);
    
};


#endif
