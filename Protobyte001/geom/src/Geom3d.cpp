//
//  Geom3d.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include <iostream>
#include "Geom3d.h"


//constructors
Geom3d::Geom3d(){
    geomInit();
}

Geom3d::Geom3d(Vector3df loc):
loc(loc){
    geomInit();
}

Geom3d::Geom3d(Dimension3d dim):
dim(dim){
    geomInit();
}

Geom3d::Geom3d(int detail):
detail(detail){
    geomInit();
}

Geom3d::Geom3d(Vector3df loc, Dimension3d dim):
loc(loc), dim(dim){
    geomInit();
}

Geom3d::Geom3d(Vector3df loc, int detail):
loc(loc), detail(detail){
    geomInit();
}

Geom3d::Geom3d(Dimension3d dim, int detail):
dim(dim), detail(detail){
    geomInit();
}


Geom3d::Geom3d(Vector3df loc, Dimension3d dim, int detail):
loc(loc), dim(dim), detail(detail){
    geomInit();
}

// destructor
Geom3d::~Geom3d(){
    // free heap memory
    delete [] vertNormCoords;
    delete [] vertCoords;
    delete [] indices;
    delete [] faces;
    delete [] vertNorms;
    delete [] verts;
}

// may be overridden
// pure virutal 
//void Geom3d::init();


void Geom3d::geomInit(){
    isAnimatable = false;
    indicesCounter = 0;
    
}

void Geom3d::allocateMemory(){
    // heap memory allocation
    verts = new Vector3df[vertCount];
    vertNorms = new Vector3df[vertCount];
    faces = new TriFace3d[triFaceCount];
    indices = new GLushort[triFaceCount*3];
    vertCoords = new GLfloat[vertCount*3];
    vertNormCoords = new GLfloat[vertCount*3];
}

// overrides virtual method in base class
void Geom3d::createVertices(){
    // create vertices
    float w = .5;
    float h = w;
    float d = w;
    float x1 = -w/2.0;
    float x2 = w/2.0;
    float y = 0;
    float z = 0;
    
    // cap terminals
    verts[0] = Vector3df(x1, y, z);
    verts[vertCount-1] = Vector3df(x2, y, z);
    
    // create verts (end caps)
    float theta = 0.0;
    for (int i=1; i<=detail; i++){
        // front cap
        verts[i] = Vector3df(x1, sinf(theta)*h, cosf(theta)*d);
        // back cap
        verts[detail + i] = Vector3df(x2, sinf(theta)*h, cosf(theta)*d);
        theta += M_PI*2/detail; // wind ccw
    }
}

// overrides virtual method in base class
void Geom3d::createIndices(){
    int indicesCounter = 0;
    // create cap faces
    for (int i=1; i<=detail; i++){
        // left cap 
        if (i < detail){ // face count for left cap
            indices[indicesCounter++] = i+1;
            indices[indicesCounter++] = 0;
            indices[indicesCounter++] = i;
            inds.push_back(Tuple3d(i+1, 0, i));
        } else {
            indices[indicesCounter++] = 1;
            indices[indicesCounter++] = 0;
            indices[indicesCounter++] = i;
            inds.push_back(Tuple3d(1, 0, i));
        }
    }
    
    // right cap
    for (int i=detail+1; i<vertCount-1; i++){
        // left cap 
        if (i < vertCount-2){ // face count for left cap
            indices[indicesCounter++] = i;
            indices[indicesCounter++] = vertCount-1;
            indices[indicesCounter++] = i+1;
            inds.push_back(Tuple3d(i, vertCount-1, i+1));
        } else {
            indices[indicesCounter++] = i;
            indices[indicesCounter++] = vertCount-1;
            indices[indicesCounter++] = detail+1;
            inds.push_back(Tuple3d(i, vertCount-1, detail+1));
        }
    }
    
    // body
    for (int i=1; i<=detail; i++){
        if (i < detail){
            indices[indicesCounter++] = i;
            indices[indicesCounter++] = detail+i;
            indices[indicesCounter++] = detail+i+1;
            inds.push_back(Tuple3d(i, detail+i, detail+i+1));
            indices[indicesCounter++] = i;
            indices[indicesCounter++] = detail+i+1;
            indices[indicesCounter++] = i+1;
            inds.push_back(Tuple3d(i, detail+i+1, i+1));
        } else {
            indices[indicesCounter++] = i;
            indices[indicesCounter++] = detail+i;
            indices[indicesCounter++] = detail+1;
            inds.push_back(Tuple3d(i, detail+i, detail+1));
            indices[indicesCounter++] = i;
            indices[indicesCounter++] = detail+1;
            indices[indicesCounter++] = 1;
            inds.push_back(Tuple3d(i, detail+1, 1));
        }
    }
}


void Geom3d::createFaces(){
    // create faces
    for (int i=0, j=0; i<triFaceCount; i++, j+=3){
        //faces[i] = TriFace3d (verts[indices[j]], verts[indices[j+1]], verts[indices[j+2]]);
        faces[i] = TriFace3d (verts[inds[i].elem0], verts[inds[i].elem1], verts[inds[i].elem2]);
    }
    // std::cout << "face Count = " << triFaceCount << std::endl;
    
    
    //sort faces 
    for (int i=0; i<triFaceCount; i++) {
        for (int j=i+1; j<triFaceCount; j++) {
            if (faces[j].getNorm().z < faces[i].getNorm().z){
                TriFace3d t = faces[i];
                faces[i] = faces[j];
                faces[j] = t;
            }
        }
    }
    
    /* for (int i=0; i<triFaceCount; i++) {
     std::cout << "faces["<<i<<"].getNorm().z = " << faces[i].getNorm().z << std::endl;
     } */
    
    
}





void Geom3d::createVertexNormals(){
    // create vertex normals
    for (int i=0; i<vertCount; i++){
        Vector3df n;
        int nCounter = 0;
        for (int j=0; j<triFaceCount; j++){
            Vector3df a = faces[j].getV1();
            Vector3df b = faces[j].getV2();
            Vector3df c = faces[j].getV3();
            if (verts[i] == a || verts[i] == b || verts[i] == c){
                n.add(faces[j].getNorm());
                nCounter++;
            }
        }
        n.div(nCounter);
        vertNorms[i] = n;
        //std::cout << " vertNorms["<<i<<"] = " <<  vertNorms[i] << std::endl;
    }
}

void Geom3d::createCoords() {
    // create coords
    for (int i=0, j=0; i<vertCount; i++, j+=3){
        vertCoords[j] = verts[i].getX();
        vertCoords[j+1] = verts[i].getY();
        vertCoords[j+2] = verts[i].getZ();
        
        vertNormCoords[j] = vertNorms[i].getX();
        vertNormCoords[j+1] = vertNorms[i].getY();
        vertNormCoords[j+2] = vertNorms[i].getZ();
    }
    
    for (int i=0, j=0; i<inds.size(); i++, j+=3){
        indices[j] = inds[i].elem0;
        indices[j+1] = inds[i].elem1;
        indices[j+2] = inds[i].elem2;
    }
    
}

void Geom3d::display(){
    
    // using stride example
    /*glVertexPointer(3, GL_FLOAT, sizeof(vertex), &myQuad[0].x);
     glColorPointer(3, GL_FLOAT, sizeof(vertex), &myQuad[0].r);
     glTexCoordPointer(2, GL_FLOAT, sizeof(vertex), &myQuad[0].s);*/
    
    // activate and specify pointer to arrays
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertCoords);
    glNormalPointer(GL_FLOAT, 0, vertNormCoords);
    
    glPushMatrix();
    glTranslatef(loc.x, loc.y, loc.z);
    glScalef(dim.getW(), dim.getH(), dim.getD());
    if (isAnimatable){
        glDrawElements(GL_TRIANGLES, indicesCounter, GL_UNSIGNED_SHORT, indices);
        if (indicesCounter < indicesCount-9){
            indicesCounter+=9;
        }
    } else {
        glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_SHORT, indices);
    }
    glPopMatrix();
    // deactivate arrays after drawing
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void Geom3d::displayNorm(float len){
    for (int i=0; i<triFaceCount; i++){
        faces[i].displayNorm(len);
    }
}

// setters & getters
void Geom3d::setLoc(Vector3df loc){
    this->loc = loc;
}
Vector3df Geom3d::getLoc(){
    return loc;
}

void Geom3d::setDim(Dimension3d dim){
    this->dim = dim;
    
}
Dimension3d Geom3d::getDim(){
    return dim;
}

void Geom3d::setIsAnimatable(bool isAnimatable) {
    this->isAnimatable = isAnimatable;
}
