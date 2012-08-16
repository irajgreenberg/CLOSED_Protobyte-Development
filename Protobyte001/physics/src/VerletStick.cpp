//
//  VerletStick::VerletStick.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/4/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "VerletStick.h"
#include <iostream>


VerletStick::VerletStick() {
}

VerletStick::VerletStick(VerletBall* b1, VerletBall* b2):
b1(b1), b2(b2), tension(.005), constrainVal(Tuple2df(1.0, 1.0)) {
    init();
}

VerletStick::VerletStick(VerletBall* b1, VerletBall* b2, float tension):
b1(b1), b2(b2), tension(tension), constrainVal(Tuple2df(1.0, 1.0)) {
    init();
}

VerletStick::VerletStick(VerletBall* b1, VerletBall* b2, float tension, Tuple2df constrainVal):
b1(b1), b2(b2), tension(tension), constrainVal(constrainVal)  {
    init();
}

void VerletStick::init(){
    vecOrig  = Vector3df(b2->getPos().x-b1->getPos().x, 
                         b2->getPos().y-b1->getPos().y, 
                         b2->getPos().z-b1->getPos().z);
    
    len = vecOrig.mag();
    constrainLoopCount = 3; // default
}


void VerletStick::setConstrainLoopCount(unsigned int constrainLoopCount){
    this->constrainLoopCount = constrainLoopCount;
}


void VerletStick::constrainLen() {
    for (int i=0; i<constrainLoopCount; i++) {
        Vector3df delta = Vector3df(b2->getPos().x-b1->getPos().x, 
                                    b2->getPos().y-b1->getPos().y, 
                                    b2->getPos().z-b1->getPos().z);
        
        float deltaLength = delta.mag();
        float difference = ((deltaLength - len) / deltaLength);
        
        // nudge positiviely
        Vector3df vPos(delta.x * (constrainVal.elem0 * tension * difference),
                       delta.y * (constrainVal.elem0 * tension * difference),
                       delta.z * (constrainVal.elem0 * tension * difference) );
        b1->addPos(vPos);
        
        // nudge negatively
        Vector3df vNeg(delta.x * (constrainVal.elem1 * tension * difference),
                       delta.y * (constrainVal.elem1 * tension * difference),
                       delta.z * (constrainVal.elem1 * tension * difference) );
        b2->subPos(vNeg);
        
        
        /*std::cout << "b1.getPos() = " << b1.getPos() << std::endl;
         std::cout << "vNeg = " << vNeg << std::endl;
         std::cout << "deltaLength = " << deltaLength << std::endl;
         std::cout << "difference = " << difference << std::endl;*/
        
    }
}



void VerletStick::render() {
    glBegin(GL_LINES);
    glVertex3f(b1->getPos().x, b1->getPos().y, b1->getPos().z);
    glVertex3f(b2->getPos().x, b2->getPos().y, b2->getPos().z);
    glEnd();
}

VerletBall* VerletStick::getVerletBall1() {
    return b1;
}


VerletBall* VerletStick::getVerletBall2() {
    return b2;
}

void VerletStick::setVBalls(VerletBall* b1, VerletBall* b2){
    this->b1 = b1;
    this->b2 = b2;
}

void VerletStick::setTension(float tension){
    this->tension = tension;
}



