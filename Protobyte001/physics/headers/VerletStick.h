//
//  VerletStick.h
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

#ifndef Protobyte_Library_V01_VerletStick_h
#define Protobyte_Library_V01_VerletStick_h

#include "VerletBall.h"
#include "Tuple2d.h"
#include "Tuple2df.h"

class VerletStick {
    
private:
    VerletBall* b1;
    VerletBall* b2;
    Vector3df vecOrig;
    float len;
    float tension; // works with constrainLoopCount to control springing
    unsigned int constrainLoopCount; // Number of loop iterations during constrain
    //Tuple2d constrainVal; // allows anchoring of balls
    Tuple2df constrainVal; // allows anchoring of balls
    
public:
    /**
     *Constructors
     */
    VerletStick();
    VerletStick(VerletBall* b1, VerletBall* b2);
    VerletStick(VerletBall* b1, VerletBall* b2, float tension);
    //VerletStick(VerletBall* b1, VerletBall* b2, float tension, Tuple2d constrainVal);
    VerletStick(VerletBall* b1, VerletBall* b2, float tension, Tuple2df constrainVal);
    
    /**
     * Initialize constructor common fields
     */
    void init();
    
    
    /**
     * Position vector fields
     */
    void constrainLen();    
    
    /**
     * Optional draw Verlet Stick
     */
    void render(); 
    
    /**
     * Controls the number of loop iterations
     * which impacts springing along with tension
     */
    void setConstrainLoopCount(unsigned int constrainLoopCount);
    
    /**
     * Return pointer to Verlet Ball 1
     */
    VerletBall* getVerletBall1();
    
    /**
     * Return pointer to Verlet Ball 2
     */
    VerletBall* getVerletBall2();
    
    void setVBalls(VerletBall* b1, VerletBall* b2);
    
    void setTension(float tension);
    
};

#endif
