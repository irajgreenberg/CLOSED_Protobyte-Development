//
//  TriFace3d.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include <iostream>
#include "TriFace3d.h"
#include "ProtoSetup.h"

TriFace3d::TriFace3d():
loc(Vector3df()), v1(Vector3df()), v2(Vector3df()), v3(Vector3df()){
    init();
}

TriFace3d::TriFace3d(Vector3df v1, Vector3df v2, Vector3df v3):
loc(Vector3df()), v1(v1), v2(v2), v3(v3) {
    init();
}

TriFace3d::TriFace3d(Vector3df loc, Vector3df v1, Vector3df v2, Vector3df v3):
loc(loc), v1(v1), v2(v2), v3(v3) {
    init();
}
TriFace3d::TriFace3d(Vector3df* v1_p, Vector3df* v2_p, Vector3df* v3_p):
v1(*v1_p), v2(*v2_p), v3(*v3_p) {
    init();
}


TriFace3d::~TriFace3d(){
}


bool TriFace3d::operator==(const TriFace3d& f){
    if (f.v1 == v1 && f.v2 == v2 && f.v3 == v3){
        return 1;
    }
    return 0;
}

// general methods

void TriFace3d::init(){
    float x = (v1.getX() + v2.getX() + v3.getX())/3;
    float y = (v1.getY() + v2.getY() + v3.getY())/3;
    float z = (v1.getZ() + v2.getZ() + v3.getZ())/3;
    center = Vector3df(x, y, z);
    
    makeSurfNorm();
}

// changes the state of param n
void TriFace3d::normal(Vector3df& n){
    Vector3df a = Vector3df::sub(v2, v1);
    Vector3df b = Vector3df::sub(v3, v1);
    a.cross(b, n);
}

void TriFace3d::makeSurfNorm(){
    // order for clockwise facing
    Vector3df a = Vector3df::sub(v3, v1);
    Vector3df b = Vector3df::sub(v2, v1);
    b.cross(a, n);
    n.normalize();
    
    // initialize vertex normals with surfcace normal
    vecNorms[0] = vecNorms[1] = vecNorms[2] = n; // in case no vertex Normals set
}

Vector3df TriFace3d::getNorm() {
    return n;
}

void TriFace3d::setVertexNorms(Vector3df vn1, Vector3df vn2, Vector3df vn3) {
    vecNorms[0]=vn1;
    vecNorms[1]=vn2;
    vecNorms[2]=vn3;
}




void TriFace3d::display(){
    glPushMatrix();
    glTranslatef(loc.getX(), loc.getY(), loc.getZ());
    glBegin(GL_TRIANGLES);
    glNormal3f(vecNorms[0].getX(), vecNorms[0].getY(), vecNorms[0].getZ());
    glVertex3f(v1.getX(), v1.getY(), v1.getZ());
    glNormal3f(vecNorms[1].getX(), vecNorms[1].getY(), vecNorms[1].getZ());
    glVertex3f(v2.getX(), v2.getY(), v2.getZ());
    glNormal3f(vecNorms[2].getX(), vecNorms[2].getY(), vecNorms[2].getZ());
    glVertex3f(v3.getX(), v3.getY(), v3.getZ());
    glEnd();
    glPopMatrix();
}

/*void TriFace3d::display(){
 std::cout << "v1.getNormX() = "<< v1.getNormX() << std::endl;
 std::cout << "v1.getNormY() = "<< v1.getNormY() << std::endl;
 std::cout << "v1.getNormZ() = "<< v1.getNormZ() << std::endl;
 glPushMatrix();
 glTranslatef(loc.getX(), loc.getY(), loc.getZ());
 glBegin(GL_TRIANGLES);
 glNormal3f(v1.getNormX(), v1.getNormY(), v1.getNormZ());
 glVertex3f(v1.getX(), v1.getY(), v1.getZ());
 glNormal3f(v2.getNormX(), v2.getNormY(), v2.getNormZ());
 glVertex3f(v2.getX(), v2.getY(), v2.getZ());
 glNormal3f(v3.getNormX(), v3.getNormY(), v3.getNormZ());
 glVertex3f(v3.getX(), v3.getY(), v3.getZ());
 glEnd();
 glPopMatrix();
 }*/


void TriFace3d::displayNorm(float len){
    // only draw if length is greater than 0
    glColor3f(.4, .4, .7);
    if (n.mag()>0){
        glPushMatrix();
        glTranslatef(loc.getX(), loc.getY(), loc.getZ());
        glBegin(GL_LINES);
        glVertex3f(center.getX(), center.getY(), center.getZ());
        glVertex3f(center.getX()+n.getX()*len, center.getY()+n.getY()*len, center.getZ()+n.getZ()*len);
        glEnd();
        glPopMatrix();
    }
}


// setters/getters
void TriFace3d::setV1(Vector3df v1){
    this->v1 = v1;
}
Vector3df TriFace3d::getV1(){
    return v1;
}

void TriFace3d::setV2(Vector3df v2){
    this->v2 = v2;
}
Vector3df TriFace3d::getV2(){
    return v2;
}

void TriFace3d::setV3(Vector3df v3){
    this->v3 = v3;
}
Vector3df TriFace3d::getV3(){
    return v3;
}

// return pointers
Vector3df* TriFace3d::getV1_p(){
    return &v1;
}

Vector3df* TriFace3d::getV2_p(){
    return &v2;
}

Vector3df* TriFace3d::getV3_p(){
    return &v3;
}




