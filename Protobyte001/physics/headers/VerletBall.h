//
//  VerletBall.h
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/4/11.
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

#ifndef Protobyte_Library_V01_VerletBall_h
#define Protobyte_Library_V01_VerletBall_h

#include "Vector3df.h"
#include "ProtoSetup.h"


class VerletBall {
    
private:
    
    /**
     * Position vector fields
     */
    Vector3df pos, posOld;
    
    /**
     * VerletBall size for optional render method
     */
    float radius;
    
public:
    
    /**
     * constructors
     */
    VerletBall();
    VerletBall(Vector3df pos);    
    VerletBall(Vector3df pos, float radius);    
    
    /**
     * increment VerletBall postion by delta pos-posOld
     */
    void verlet();    
    
    /**
     * Increment VerletBall Position
     */
    void addPos(Vector3df& v);
    
    /**
     * Decrement VerletBall Position
     */
    void subPos(Vector3df& v);

    /**
     * draw VerletBall
     */
    void render();
    
    /**
     * return copy of pos
     */
    Vector3df getPos();
    
    /**
     * set pos through const reference
     */
    void setPos(const Vector3df pos);

};

#endif
