//
//  Matrix4d.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Matrix4d.h"
#include <iostream>



/*
 Matrix4d matrixScale(const double scl){
 // return
 
 }
 Matrix4d matrixScale(const Vector3df vScl){
 
 }
 Matrix4d matrixTranslate(const Vector3df trans){
 
 }
 Matrix4d matrixTranslate(const double x,const double y,const double z){
 
 }
 Matrix4d matrixRotate(const Vector3df axis,const double angle){
 
 
 }
 Matrix4d matrixRotate(const double azimuth,const double elevation){
 
 }
 */

// member methods
Matrix4d Matrix4d::mult(const Matrix4d& m){
    
    Matrix4d m2(m.c00*c00 + m.c01*c10 + m.c02*c20 + m.c03*c30,
                m.c00*c01 + m.c01*c11 + m.c02*c21 + m.c03*c31,
                m.c00*c02 + m.c01*c12 + m.c02*c22 + m.c03*c32,
                m.c00*c03 + m.c01*c13 + m.c02*c23 + m.c03*c33,
                
                // row 2
                m.c10*c00 + m.c11*c10 + m.c12*c20 + m.c13*c30,
                m.c10*c01 + m.c11*c11 + m.c12*c21 + m.c13*c31,
                m.c10*c02 + m.c11*c12 + m.c12*c22 + m.c13*c32,
                m.c10*c03 + m.c11*c13 + m.c12*c23 + m.c13*c33,
                
                // row 2
                m.c20*c00 + m.c21*c10 + m.c22*c20 + m.c23*c30,
                m.c20*c01 + m.c21*c11 + m.c22*c21 + m.c23*c31,
                m.c20*c02 + m.c21*c12 + m.c22*c22 + m.c23*c32,
                m.c20*c03 + m.c21*c13 + m.c22*c23 + m.c23*c33,
                
                // row 2
                m.c30*c00 + m.c31*c10 + m.c32*c20 + m.c33*c30,
                m.c30*c01 + m.c31*c11 + m.c32*c21 + m.c33*c31,
                m.c30*c02 + m.c31*c12 + m.c32*c22 + m.c33*c32,
                m.c30*c03 + m.c31*c13 + m.c32*c23 + m.c33*c33  );
    
    return m2;
    
}

void Matrix4d::rotateAroundAxis(Vector3df* vecs, const Vector3df ax, const double theta){
    
}


void Matrix4d::rotateX(Vector3df& vec, const double theta){
    double s = sin(theta);
    double c = cos(theta);
    Matrix4d xRot(1.0, 0, 0, 0,
                  0, c, s, 0, 
                  0, -s, c, 0,
                  0, 0, 0, 1.0 );
    multVec3d(vec, xRot);
}

void Matrix4d::rotateY(Vector3df& vec, const double theta){
    double s = sin(theta);
    double c = cos(theta);
    Matrix4d yRot(c, 0, -s, 0,
                  0, 1, 0, 0, 
                  s, 0, c, 0,
                  0, 0, 0, 1.0 );
    multVec3d(vec, yRot);
}

// FIX Still
//temp1.x = b.x*cos(-theta) - b.y*sin(-theta);
//temp1.y = b.x*sin(-theta) + b.y*cos(-theta);*/

void Matrix4d::rotateZ(Vector3df& vec, const double theta){
    double s = sin(theta);
    double c = cos(theta);
    Matrix4d zRot(c, -s, 0, 0,
                  s, c, 0, 0, 
                  0, 0, 0, 0,
                  0, 0, 0, 1.0 );
    multVec3d(vec, zRot);
    
}


void Matrix4d::rotateToXZPlane(Vector3df& v, Vector3df& u){
    
    double len = sqrt(u.y*u.y + u.z*u.z);
    
    Matrix4d xRot(1, 0, 0, 0,
                  0, v.z/len, -v.y/len, 0, 
                  0, v.y/len, v.z/len, 0,
                  0, 0, 0, 1.0 );
    multVec3d(v, xRot);
    
}

// transpostion of rotateToXZPlane Matrix
void Matrix4d::rotateFroXZPlane(Vector3df& v, Vector3df& u){
    
    double len = sqrt(u.y*u.y + u.z*u.z);
    
    Matrix4d xRot(1, 0, 0, 0,
                  0, v.z/len, v.y/len, 0, 
                  0, -v.y/len, v.z/len, 0,
                  0, 0, 0, 1.0 );
    multVec3d(v, xRot);
    
}



// static function, side effect to vec
void Matrix4d::rotateAroundAxis(Vector3df& vec, const Vector3df a, const double theta){
    // arbitrary axis rotation matrix
    /* for ribbon
     double c = cos(theta)*2;
     double s = sin(theta)*.5;
     */
    double c = cos(theta);
    double s = sin(theta);
    double t = 1.0-c;
    Matrix4d mRot(t*a.x*a.x+c, t*a.x*a.y-s*a.z, t*a.x*a.z+s*a.y, 0,
                  t*a.x*a.y+s*a.z, t*a.y*a.y+c, t*a.y*a.z-s*a.x, 0,
                  t*a.x*a.z-s*a.y, t*a.y*a.z+s*a.x, t*a.z*a.z+c, 0,
                  0, 0, 0, 1 );
    multVec3d(vec, mRot);
}

// static function,
// multiply vec reference arg by matrix 4d arg.
// side effect to vec
void Matrix4d::multVec3d(Vector3df& vec, Matrix4d& m){
    vec = Vector3df(
                    vec.x*m.c00 + vec.y*m.c01 + vec.z*m.c02,
                    vec.x*m.c10 + vec.y*m.c11 + vec.z*m.c12,
                    vec.x*m.c20 + vec.y*m.c21 + vec.z*m.c22  );
    
}



//non-member function
Matrix4d operator*(const Matrix4d& m1, const Matrix4d& m2){
    
    return Matrix4d(
                    // row 1
                    m1.c00*m2.c00 + m1.c01*m2.c10 + m1.c02*m2.c20 + m1.c03*m2.c30,
                    m1.c00*m2.c01 + m1.c01*m2.c11 + m1.c02*m2.c21 + m1.c03*m2.c31,
                    m1.c00*m2.c02 + m1.c01*m2.c12 + m1.c02*m2.c22 + m1.c03*m2.c32,
                    m1.c00*m2.c03 + m1.c01*m2.c13 + m1.c02*m2.c23 + m1.c03*m2.c33,
                    
                    // row 2
                    m1.c10*m2.c00 + m1.c11*m2.c10 + m1.c12*m2.c20 + m1.c13*m2.c30,
                    m1.c10*m2.c01 + m1.c11*m2.c11 + m1.c12*m2.c21 + m1.c13*m2.c31,
                    m1.c10*m2.c02 + m1.c11*m2.c12 + m1.c12*m2.c22 + m1.c13*m2.c32,
                    m1.c10*m2.c03 + m1.c11*m2.c13 + m1.c12*m2.c23 + m1.c13*m2.c33,
                    
                    // row 2
                    m1.c20*m2.c00 + m1.c21*m2.c10 + m1.c22*m2.c20 + m1.c23*m2.c30,
                    m1.c20*m2.c01 + m1.c21*m2.c11 + m1.c22*m2.c21 + m1.c23*m2.c31,
                    m1.c20*m2.c02 + m1.c21*m2.c12 + m1.c22*m2.c22 + m1.c23*m2.c32,
                    m1.c20*m2.c03 + m1.c21*m2.c13 + m1.c22*m2.c23 + m1.c23*m2.c33,
                    
                    // row 2
                    m1.c30*m2.c00 + m1.c31*m2.c10 + m1.c32*m2.c20 + m1.c33*m2.c30,
                    m1.c30*m2.c01 + m1.c31*m2.c11 + m1.c32*m2.c21 + m1.c33*m2.c31,
                    m1.c30*m2.c02 + m1.c31*m2.c12 + m1.c32*m2.c22 + m1.c33*m2.c32,
                    m1.c30*m2.c03 + m1.c31*m2.c13 + m1.c32*m2.c23 + m1.c33*m2.c33 
                    );
    
}

// overloaded << operator for outputting field values in objects
std::ostream& operator<<(std::ostream& output, const Matrix4d& vec) {
    //output << "(" <<  vec.x << ", " << vec.y <<", " << vec.z <<")";
    return output;
}



Matrix4d::Matrix4d(){
    
}

Matrix4d::Matrix4d(const Vector4df& c0, const Vector4df& c1, const Vector4df& c2, const Vector4df& c3) {
    c00 = vals[0] = c0.x;  c01 = vals[1] = c1.x;  c02 = vals[2] = c2.x; c03 = vals[3] = c3.x;  
    c10 = vals[4] = c0.y;  c11 = vals[5] = c1.y;  c12 = vals[6] = c2.y; c13 = vals[7] = c3.y;  
    c20 = vals[8] = c0.z;  c21 = vals[9] = c1.z;  c22 = vals[10] = c2.z; c23 = vals[11] = c3.z;  
    c30 = vals[12] = c0.w;  c31 = vals[13] = c1.w;  c32 = vals[14] = c2.w;  c33 = vals[15] = c3.w;  
    
}

Matrix4d::Matrix4d(const double vals[16]){
    for (int i=0; i<16; i++){
        this->vals[i] = vals[i];
    }
    
    c00 = vals[0];  c01 = vals[1];  c02 = vals[2]; c03 = vals[3];  
    c10 = vals[4];  c11 = vals[5];  c12 = vals[6]; c13 = vals[7];  
    c20 = vals[8];  c21 = vals[9];  c22 = vals[10]; c23 = vals[11];  
    c30 = vals[12];  c31 = vals[13];  c32 = vals[14];  c33 = vals[15];  
    
}

Matrix4d::Matrix4d(double c00, double c01, double c02, double c03, 
                   double c10, double c11, double c12, double c13, 
                   double c20, double c21, double c22, double c23, 
                   double c30, double c31, double c32, double c33):

c00(c00),c01(c01),c02(c02),c03(c03), 
c10(c10),c11(c11),c12(c12),c13(c13),
c20(c20),c21(c21),c22(c22),c23(c23),
c30(c30),c31(c31),c32(c32),c33(c33){
    
    vals[0] = c00; vals[1] = c01; vals[2] = c02; vals[3] = c03;
    vals[4] = c10; vals[5] = c11; vals[6] = c12; vals[7] = c13;
    vals[8] = c20; vals[9] = c21; vals[10] = c22; vals[11] = c23;
    vals[12] = c30; vals[13] = c31; vals[14] = c32; vals[15] = c33;
    
}

// ***still needs implementation
//Construct from OpenGL GL_MODELVIEW_MATRIX or GL_PROJECTION_MATRIX.
Matrix4d::Matrix4d (const unsigned int glMatrix){
    
}


// ***still needs implementation
Matrix4d::Matrix4d(const std::string &str){
    
}
//Construct from string

Matrix4d::~Matrix4d(){
    
}