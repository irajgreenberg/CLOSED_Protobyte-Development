//
//  Geom3d.h
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

#ifndef Protobyte_Library_V01_Geom3d_h
#define Protobyte_Library_V01_Geom3d_h


#include "ProtoSetup.h"
#include "ProtoUtils.h"
#include "Dimension3d.h"
#include <cmath>
#include "Vector3df.h"
#include "TriFace3d.h"
#include <vector>
#include "Tuple3d.h"



class Geom3d {
    
protected:
    Vector3df loc;
    Dimension3d dim;
    int detail;
    
    // standard members in base class
    Vector3df* verts;
    Vector3df* vertNorms;
    int vertCount, triFaceCount, indicesCount;
    TriFace3d* faces;
    std::vector<Tuple3d> inds;
    
    // for glDrawElements
    GLushort* indices;
    GLfloat* vertCoords;
    GLfloat* vertNormCoords; 
    
    // for real time drawin of geometry
    bool isAnimatable;
    int indicesCounter;
    
    
    //====================================
    // methods called internally
    //====================================
    // some stuff needed by all subclasses
    void geomInit();
    
    // These MUST be overridden
    virtual void init() = 0; 
    virtual void createVertices() = 0;
    virtual void createIndices() = 0;
    
    // These CAN be overridden, but not necessary
    virtual void allocateMemory();
    virtual void createFaces();
    virtual void createVertexNormals();
    virtual void createCoords();
    
    
public:
    // constructors
    Geom3d();
    Geom3d(Vector3df loc);
    Geom3d(Dimension3d dim);
    Geom3d(int detail);
    Geom3d(Vector3df loc, Dimension3d dim);
    Geom3d(Vector3df loc, int detail);
    Geom3d(Dimension3d dim, int detail);
    Geom3d(Vector3df loc, Dimension3d dim, int detail);
    
    
    void setLoc(Vector3df loc);
    Vector3df getLoc();
    
    void setDim(Dimension3d dim);
    Dimension3d getDim();
    
    
    // destructor
    virtual ~Geom3d();
    
    // direclty called by subclass objs - doesn't get overridden
    void display();
    void displayNorm(float len = .1);
    
    void setIsAnimatable(bool isAnimatable);
};



#endif
