//
//  Toroid.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include <iostream>
#include "Toroid.h"

// constructors
Toroid::Toroid(){
    dim = Dimension3d(0,0,0);
    segs = 3; 
    detail = 3;
    innerRadius = .3;
    outerRadious = .75;
    init();
}

Toroid::Toroid(Dimension3d dim):
Geom3d(dim, 3), segs(3), innerRadius(.3), outerRadious(.75) {
    init();
}

Toroid::Toroid(Dimension3d dim, int detail, int segs):
Geom3d(dim, detail), segs(segs), innerRadius(.3), outerRadious(.75){
    init();
}

Toroid::Toroid(Dimension3d dim, int detail, int segs, float innerRadius, float outerRadious):
Geom3d(dim, detail), segs(segs), innerRadius(innerRadius), outerRadious(outerRadious){
    init();
}

// destructor
Toroid::~Toroid(){
}

// copy constructor
Toroid::Toroid(const Toroid& toroid_src){
    dim =  toroid_src.dim;
    segs =  toroid_src.segs;
    detail =  toroid_src.detail;
    innerRadius = toroid_src.innerRadius;
    outerRadious = toroid_src.outerRadious;
}

// overloaded assignemnt operator
// copy constructor
Toroid& Toroid::operator = (const Toroid& toroid_src){
    dim =  toroid_src.dim;
    segs =  toroid_src.segs;
    detail =  toroid_src.detail;
    innerRadius = toroid_src.innerRadius;
    outerRadious = toroid_src.outerRadious;
    return *this;
}


void Toroid::init(){
    vertCount = detail * segs;
    triFaceCount = vertCount*2;
    
    indicesCount = triFaceCount*3;
    
    allocateMemory();
    createVertices();
    createIndices();
    createFaces();
    createVertexNormals();
    createCoords();
}

void Toroid::createVertices(){
    float phi = 0.0;
    for (int i=0; i<segs; i++){
        float theta = 0.0;
        for (int j=0; j<detail; j++){
            
            float x = outerRadious + cosf(theta)*innerRadius;
            float y = sinf(theta)*innerRadius;
            float z = 0;
            
            verts[i*detail+j] = Vector3df(z*sinf(phi) + x*cosf(phi), y, z*cosf(phi) - x*sinf(phi));
            theta += M_PI*2.0/detail;
        }
        phi += M_PI*2.0/segs;
    }
}

void Toroid::createIndices(){
   // int indicesCounter = 0;
    for (int i=0; i<segs; i++){
        for (int j=0; j<detail; j++){
            if (i<segs-1){
                if (j<detail-1){
                    // indices[indicesCounter++] = detail*i + j;
                    // indices[indicesCounter++] = detail*(i+1) + j;
                    // indices[indicesCounter++] = detail*(i+1) + j+1;
                    inds.push_back(Tuple3d(detail*i + j, detail*(i+1) + j, detail*(i+1) + j+1));
                    
                    // indices[indicesCounter++] = detail*i + j;
                    // indices[indicesCounter++] = detail*(i+1) + j+1;
                    // indices[indicesCounter++] = detail*i + j+1;
                    inds.push_back(Tuple3d(detail*i + j, detail*(i+1) + j+1, detail*i + j+1));
                } else {
                    // indices[indicesCounter++] = detail*i + j;
                    // indices[indicesCounter++] = detail*(i+1) + j;
                    // indices[indicesCounter++] = detail*(i+1);
                    inds.push_back(Tuple3d(detail*i + j, detail*(i+1) + j, detail*(i+1)));
                    
                    // indices[indicesCounter++] = detail*i + j;
                    // indices[indicesCounter++] = detail*(i+1);
                    // indices[indicesCounter++] = detail*i;
                    inds.push_back(Tuple3d(detail*i + j, detail*(i+1), detail*i));
                }
            } else {
                if (j<detail-1){
                    // indices[indicesCounter++] = detail*i + j;
                    // indices[indicesCounter++] = j;
                    // indices[indicesCounter++] = j+1;
                    inds.push_back(Tuple3d(detail*i + j, j, j+1));
                    
                    // indices[indicesCounter++] = detail*i + j;
                    // indices[indicesCounter++] = j+1;
                    // indices[indicesCounter++] = detail*i + j+1;
                    inds.push_back(Tuple3d(detail*i + j, j+1, detail*i + j+1));
                } else {
                    // indices[indicesCounter++] = detail*i + j;
                    // indices[indicesCounter++] = j;
                    // indices[indicesCounter++] = 0;
                    inds.push_back(Tuple3d(detail*i + j, j, 0));
                    
                    // indices[indicesCounter++] = detail*i + j;
                    // indices[indicesCounter++] = 0;
                    // indices[indicesCounter++] = detail*i;
                    inds.push_back(Tuple3d(detail*i + j, 0, detail*i));
                }
            }
        }
    }
    for (int i=0; i<indicesCount; i++){
        // std::cout<< "indices = "<< indices[i] << std::endl;
    }
}

