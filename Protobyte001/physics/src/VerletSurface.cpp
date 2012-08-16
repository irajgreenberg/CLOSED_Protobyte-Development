//
//  VerletSurface.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/4/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "VerletSurface.h"
#include <iostream>


static float xMin = 0;
static float yMin = 0;
static Vector3df textureScaleFactor;

VerletSurface::VerletSurface(){
    
}

VerletSurface::VerletSurface(Vector3df loc, Curve3d* perimeter, int perimeterLen):
loc(loc), perimeter(perimeter), perimeterLen(perimeterLen), isAnchored(false){
   vecs = perimeter->getVertices();
    init();
}

// no spline bridge between curve segs using this.
/*VerletSurface::VerletSurface(Vector3df loc, Curve3d** perimeters, int perims, int* perimLens):
loc(loc), perimeters(perimeters) {
    int vertexLen = 0;
    for (int i=0; i<perims; i++){
        vertexLen += perimLens[i];
    }
    perimeter = new Spline3d[vertexLen];
    int counter = 0;
    for (int i=0; i<perims; i++){
        for (int j=0; j<perimLens[i]; j++){
            perimeter[counter++] = perimeters[i][j];
        }
    }
    vecs = perimeter->getVertices();
    delete [] perimeter;
 
    init();
}*/

VerletSurface::VerletSurface(Vector3df loc, Curve3d* perimeter, int perimeterLen, bool isAnchored):
loc(loc), perimeter(perimeter), perimeterLen(perimeterLen), isAnchored(isAnchored){
    vecs = perimeter->getVertices();
    init();
}

//VerletSurface::VerletSurface();
VerletSurface::~VerletSurface() {
    //delete vSticks;
    //delete  vBalls;
}

void VerletSurface::init() {
    
    
    /* For texture mapping
     glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
     
     glGenTextures(1, &texName);
     glBindTexture(GL_TEXTURE_2D, texName);
     
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, 
     GL_NEAREST);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
     GL_NEAREST);
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, 
     checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, 
     checkImage);
     */
    
    
    
    
    int w = 1256;
    int h = 256;
    //texture = ImageIO::getTextureImg("/Users/iragreenberg/Desktop/flame5.png", w, h);
    
    
    
    
    xMin = 2;
    yMin = 2;
    // perimeter vBalls
    for (int i=0; i<vecs.size(); i++){
         vBalls.push_back(VerletBall(vecs[i]));
        
        //std::cout << "vecs["<< i << "] = " << vecs[i] << std::endl;
        if (vecs[i].x<xMin) xMin=vecs[i].x;
        if (vecs[i].y<yMin) yMin=vecs[i].y;
        
        textureScaleFactor.x =  1.0/abs(xMin*2);
        textureScaleFactor.y =  1.0/abs(yMin*2);
       
       
        
        Vector3df v = vecs[i];
        v += (Vector3df(abs(xMin), abs(yMin), 0));
        v *= textureScaleFactor;
        
        texCoords.push_back(v);
        //std::cout << "vBalls["<< i << "] = " << (vBalls[i].getPos()) << std::endl;
    }
    
    Tuple2df t;
    // perimeter vSticks
    for (int i=0; i<vecs.size(); i++){
        
        if (i<12 || i > vecs.size()-6){
            t = Tuple2df(1,1);
        } else {
            t = Tuple2df(1,1);
        }
        //t = Tuple2df(getRand(.85, 1.0), getRand(.85, 1.0));
        
        if (i < vecs.size()-1){
            vSticks.push_back(VerletStick(&vBalls[i], &vBalls[i+1], .5, t));
        } else {
            vSticks.push_back(VerletStick(&vBalls[i], &vBalls[0], .5, t));        
        }
        
    }
    
    
    // internal vSticks
    t = Tuple2df(1, 1);
    for (int i=0; i<vBalls.size()/2; i++){
        if (i%2==0){
           // t = Tuple2df(1,1);
        } else {
           // t = Tuple2df(1,1);
        }
        
        vSticks.push_back(VerletStick(&vBalls[i], &vBalls[vBalls.size()/2+i], .5));
    }
    
    
    
}

void VerletSurface::verlet() {
    for (int i=0; i<vBalls.size(); i++){
        vBalls[i].verlet();
    }
    
    for (int i=0; i<vSticks.size(); i++){
        vSticks[i].constrainLen();
    }
}

void VerletSurface::render() {
    for (int i=0; i<vSticks.size(); i++){
        //vSticks[i].render();
    }
    
    for (int i=0; i<vBalls.size(); i++){
        //vBalls[i].render();
    }
    
    glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //mix with light
    
    // Projection plane
    //GLfloat zPlane[] = { 0.0f, 0.0f, 1.0f, 0.0f };
    //glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    //glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    //glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    //glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    //glTexGenfv(GL_S, GL_OBJECT_PLANE, zPlane);
    //glTexGenfv(GL_T, GL_OBJECT_PLANE, zPlane);
    
    
    //glEnable(GL_TEXTURE_GEN_S);
    //glEnable(GL_TEXTURE_GEN_T);
    glEnable(GL_TEXTURE_2D);
    
    
    
    
    
    
    //GLfloat sPlane[4] = {0.0, 0.0, 1.0, 0.0};
    //GLfloat tPlane[4] = {0.0, 0.0, 1.0, 0.0}; 
    //glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
    //glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
    //glTexGenfv(GL_S, GL_EYE_PLANE, sPlane);
    //glTexGenfv(GL_T, GL_EYE_PLANE, tPlane);
    //glEnable(GL_TEXTURE_GEN_S);
    //glEnable(GL_TEXTURE_GEN_T);
    // glEnable(GL_TEXTURE_2D);
    
    
    
    
    
    
   // std::cout << "abs(xMin) = " << abs(xMin) << std::endl;
   // std::cout << "abs(yMin) = " << abs(yMin) << std::endl;
    glBegin(GL_POLYGON);
    for (int i=0; i<vBalls.size(); i++){
        //glTexCoord2d(texCoords[i].x+fabs(xMin), (texCoords[i].y+fabs(yMin))*.65);
        glTexCoord2d(texCoords[i].x, texCoords[i].y+.07);
        glVertex3f(vBalls[i].getPos().x, vBalls[i].getPos().y, 0);
        
        //std::cout << "xMin = " << fabs(xMin) << std::endl;
        //std::cout << "texCoords[i] = " << (texCoords[i].x) << ", " << (texCoords[i].y) << std::endl;
    }
    glEnd();
    //std::cout << "" << std::endl;
    
    glDisable(GL_TEXTURE_2D);
    //glDisable(GL_TEXTURE_GEN_S);
    //glDisable(GL_TEXTURE_GEN_T);
    
    glBegin(GL_POINTS);
    //int index = vBalls.size()-20;
    //glVertex3f(vBalls[index].getPos().x, vBalls[index].getPos().y, 0);
    for (int i=0; i<vBalls.size(); i++){
        if (i==0) glColor4f(1.0, .6, 0, 1);
        else glColor4f(.5, 0, .7, 1);
            glVertex3f(vBalls[i].getPos().x, vBalls[i].getPos().y, 0);
    }
    glEnd();
    
   
    for (int i=0; i<vSticks.size(); i++){
        //vSticks[i].render();
    }


    
    glPopAttrib();
}


void VerletSurface::move(Vector3df& nudge){
    nudge.y = vBalls[21].getPos().y;
    vBalls[21].setPos(nudge);
}

void VerletSurface::setLoc(Vector3df& loc){
    this->loc = loc;
}

Vector3df VerletSurface::getLoc(){
    return loc;
}