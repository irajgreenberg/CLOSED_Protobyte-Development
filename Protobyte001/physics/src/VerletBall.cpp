//
//  VerletBall.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/4/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "VerletBall.h"
#include <iostream>


VerletBall::VerletBall(){
}

VerletBall::VerletBall(Vector3df pos):
pos(pos), radius(.004) {
    posOld = pos;
}

VerletBall::VerletBall(Vector3df pos, float radius):
pos(pos), radius(radius) {
    posOld = pos;
}

void VerletBall::verlet() {
    Vector3df posTemp = pos;
    pos.x += (pos.x-posOld.x);
    pos.y += (pos.y-posOld.y);
    pos.z += (pos.z-posOld.z);
    posOld = posTemp;
}

void VerletBall::addPos(Vector3df& v){
    pos.add(v);
}

void VerletBall::subPos(Vector3df& v){
    pos.sub(v);
}

void VerletBall::render() {
    glPushMatrix();
    //glTranslatef(pos.x, pos.y, pos.z);
    glTranslatef(pos.x, pos.y, pos.z);
    glutSolidSphere(radius*2, 12, 12);
    //std::cout << "radius*2 = " << (radius*2) << std::endl;
    glPopMatrix();
}

 Vector3df VerletBall::getPos() {
    return  pos;
}

void  VerletBall::setPos(const Vector3df pos){
    this->pos = pos;
}

