//
//  Matrix4d.h
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


// Inspired/Based on:
// http://www.nigels.com/glt/doc/class_matrix.html
// and
// http://www.terathon.com/c4engine/doco/Math/Matrix4D.html



#ifndef Protobyte_Library_V01_Matrix4d_h
#define Protobyte_Library_V01_Matrix4d_h

#include "Vector3df.h"
#include "Vector4df.h"
#include "Dimension3d.h"
#include "ProtoSetup.h"
#include <math.h>



class Matrix4d{
    
    /*Matrix4d matrixScale(const double scl);
     Matrix4d matrixScale(const Vector3df vScl);
     Matrix4d matrixTranslate(const Vector3df trans);
     Matrix4d matrixTranslate(const double x,const double y,const double z);
     Matrix4d matrixRotate(const Vector3df axis,const double angle);
     Matrix4d matrixRotate(const double azimuth,const double elevation);*/
    
    //friend Matrix4d matrixOrient(const Vector3df &x,const Vector3df &y,const Vector3df &z);
    //friend Matrix4d matrixOrient(const Vector3df &direction,const Vector3df &up);
    
    friend std::ostream &operator<<(std::ostream &os,const Matrix4d &m);
    //friend std::istream &operator>>(std::istream &is,      Matrix4d &m);
    
private:
    
    double vals[16];
    
public:
    
    double   c00,  c01,  c02,  c03, 
    c10,  c11,  c12,  c13, 
    c20,  c21,  c22,  c23, 
    c30,  c31,  c32,  c33;
    
    Matrix4d();
    Matrix4d(const Vector4df& c1, const Vector4df& c2, const Vector4df& c3, const Vector4df& c4);
    Matrix4d(const double *vals);
    Matrix4d(double c00, double c01, double c02, double c03, 
             double c10, double c11, double c12, double c13, 
             double c20, double c21, double c22, double c23, 
             double c30, double c31, double c32, double c33);
    Matrix4d (const unsigned int glMatrix);
 	//Construct from OpenGL GL_MODELVIEW_MATRIX or GL_PROJECTION_MATRIX.
    
 	Matrix4d(const std::string &str);
 	//Construct from string
    
    ~Matrix4d();
    
    // member functions
    Matrix4d mult(const Matrix4d& m);
    void rotateAroundAxis(Vector3df* vecs, const Vector3df axis, const double theta);
    
    // static methods
    static void rotateAroundAxis(Vector3df& vec, const Vector3df axis, const double theta);
    static void rotateX(Vector3df& vec, const double theta);
    static void rotateY(Vector3df& vec, const double theta);
    static void rotateZ(Vector3df& vec, const double theta);
    static void rotateToXZPlane(Vector3df& v, Vector3df& u); // align axis to plane
    static void rotateFroXZPlane(Vector3df& v, Vector3df& u); // inverse function
    static void rotate(Vector3df& vec, Vector3df& thetas);
    static void multVec3d(Vector3df& vec, Matrix4d& m);
    
    
};

// non-member operations/functions
Matrix4d operator*(const Matrix4d& m1, const Matrix4d& m2);

#endif
