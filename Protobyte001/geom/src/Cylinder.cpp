//
//  Cylinder.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include <iostream>
#include "Cylinder.h"
#include <math.h>


Cylinder::Cylinder():
Geom3d(0) {
    init();
}

Cylinder::Cylinder(int detail):
Geom3d(detail){
    init();
}

Cylinder::Cylinder(Vector3df loc, Dimension3d dim, int detail):
Geom3d(loc, dim, detail){
    init();
}

Cylinder::~Cylinder(){
}


// overrides virtual method in base class
void Cylinder::init(){
    vertCount = detail*2 + 2;
    int bodyFaceCount = detail*2;
    int capFaceCount = detail*2;
    triFaceCount = bodyFaceCount + capFaceCount;
    
    indicesCount = triFaceCount*3;
    allocateMemory();
    createVertices();
    createIndices();
    createFaces();
    createVertexNormals();
    createCoords();
}


// overrides virtual method in base class
void Cylinder::createVertices(){
    // create vertices
    //float w = .5;
    //float h = w;
    //float d = w;
    float y1 = -dim.h/2.0;
    float y2 = dim.h/2.0;
    //float y = 0;
    //float z = 0;
    
    
    // cap terminals
    verts[0] = Vector3df(loc.x, y1, loc.z);
    verts[vertCount-1] = Vector3df(loc.x, y2, loc.z);
    
    // create verts (end caps)
   // y rotation
    float theta1 = 0, theta2 = 0.0;
    for (int i=1; i<=detail; i++){
        // front cap
        verts[i] = Vector3df(sin(theta1)*dim.w, y1, cos(theta1)*dim.d);
        // back cap
        verts[detail + i] = Vector3df(sin(theta1)*dim.w, y2, cos(theta1)*dim.d);
        theta1 += M_PI*2/detail; // wind ccw top
        theta2 -= M_PI*2/detail; // wind ccw bottom
    }
}

// overrides virtual method in base class
void Cylinder::createIndices(){
    //int indicesCounter = 0;
    // create cap faces
    for (int i=1; i<=detail; i++){
        // top cap 
        if (i < detail){ // face count for left cap
            inds.push_back(Tuple3d(i+1, 0, i));
        } else {
            inds.push_back(Tuple3d(1, 0, i));
        }
    }
    
    // bottom cap
    for (int i=detail+1; i<vertCount-1; i++){
        // left cap 
        if (i < vertCount-2){ // face count for left cap
            inds.push_back(Tuple3d(i, vertCount-1, i+1));
        } else {
            inds.push_back(Tuple3d(i, vertCount-1, detail+1));
        }
    }
    
    // body
    for (int i=1; i<=detail; i++){
        if (i < detail){
            // tri 1
            inds.push_back(Tuple3d(i, detail+i, detail+i+1));
            // tri 2
            inds.push_back(Tuple3d(i, detail+i+1, i+1));
        } else {
             // tri 1
            inds.push_back(Tuple3d(i, detail+i, detail+1));
             // tri 2
            inds.push_back(Tuple3d(i, detail+1, 1));
        }
    }
}


