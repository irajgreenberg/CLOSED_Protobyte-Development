//
//  Surface2d.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/18/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Surface2d.h"
#include <iostream>




float tempTheta = 0.0;

Surface2d::Surface2d(){
    
}

Surface2d::Surface2d(Vector3df loc, Curve3d* perimeter, int perimeterLen):
loc(loc), perimeter(perimeter), perimeterLen(perimeterLen) {
    vecs = perimeter->getVertices();
    vecsOrig = perimeter->getVertices();
   // std::cout << "vecs size = " << vecs.size() << std::endl;
    
    //std::cout << "vecs["<< i << "] = " << vecs[i] << std::endl;
    
    cntrlPtCount = perimeter->getControlPtsLength();
    interpDetail = perimeter->getInterpDetail();
   // std::cout << "cntrlPtCount size = " << cntrlPtCount << std::endl;
    init();
}

Surface2d::Surface2d(Vector3df loc, Curve3d* perimeter, int perimeterLen, std::string textureName):
loc(loc), perimeter(perimeter), perimeterLen(perimeterLen), textureName(textureName) {
    vecs = perimeter->getVertices();
    vecsOrig = perimeter->getVertices();
   // std::cout << "vecs size = " << vecs.size() << std::endl;
    
    //std::cout << "vecs["<< i << "] = " << vecs[i] << std::endl;
    
    cntrlPtCount = perimeter->getControlPtsLength();
    interpDetail = perimeter->getInterpDetail();
   // std::cout << "cntrlPtCount size = " << cntrlPtCount << std::endl;
    init();
}

Surface2d::Surface2d(Vector3df loc, Curve3d* perimeter, int perimeterLen, GLuint* texture, int textW, int textH):
loc(loc), perimeter(perimeter), perimeterLen(perimeterLen), texture(texture), textW(textW), textH(textH) {
    vecs = perimeter->getVertices();
    vecsOrig = perimeter->getVertices();
    // std::cout << "vecs size = " << vecs.size() << std::endl;
    
    //std::cout << "vecs["<< i << "] = " << vecs[i] << std::endl;
    
    cntrlPtCount = perimeter->getControlPtsLength();
    interpDetail = perimeter->getInterpDetail();
    // std::cout << "cntrlPtCount size = " << cntrlPtCount << std::endl;
    init();
}




Surface2d::~Surface2d(){
    
}



void Surface2d::init(){
    
    int w = 256;
    int h = 256;

    //texture = ImageIO::getTextureImg(textureName, w, h);
    //texture = ImageIO::getTextureImg2(textureName2);

    
   // map vertex values to 0.0-1.0
    static Vector3df textureScaleFactor;
    float xMin=0.0, xMax = 0.0;
    float yMin=0.0, yMax = 0.0;
    xMin = xMax = vecs[0].x;
    yMin = yMax = vecs[0].y;
    // perimeter vBalls
    for (int i=0; i<vecs.size(); i++){
        //std::cout << "vecs["<< i << "] = " << vecs[i] << std::endl;
        if (vecs[i].x<xMin) xMin=vecs[i].x;
        if (vecs[i].y<yMin) yMin=vecs[i].y;
        if (vecs[i].x>xMax) xMax=vecs[i].x;
        if (vecs[i].y>yMax) yMax=vecs[i].y;
    }
    
    float dx = xMax-xMin;
    float dy = yMax-yMin;
    textureScaleFactor.x  = 1.0/dx;
    textureScaleFactor.y  = 1.0/dy;
    
    for (int i=0; i<vecs.size(); i++){
        Vector3df v = vecs[i];
        v += (Vector3df(fabs(xMin), fabs(yMin), 0));
        v *= textureScaleFactor;
        
        texCoords.push_back(v);
        
    }
    
}


void Surface2d::setLoc(Vector3df& loc){
    this->loc = loc;
}


Vector3df Surface2d::getLoc(){
    return loc;
}

// this jitters for Amnesty candle project - need to make this general purpose class
void Surface2d::display(){
    
    //glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    glPushMatrix();
    glTranslatef(loc.x, loc.y + getRand(.001), loc.z);
    glScalef(dim.w + getRand(.1), dim.h + getRand(.2), dim.d); // easy flickering
    glEnable(GL_TEXTURE_2D);
    
    glColor4f(1, 1, 1, getRand(.9, 1.0)); // not currently doing anything with GL_REPLACE mode
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    glBegin(GL_POLYGON);
    for (int i=0; i<vecs.size(); i++){
        
        glTexCoord2d(texCoords[i].x, texCoords[i].y);
        glVertex3f(vecs[i].x, vecs[i].y, 0);
        //std::cout << "texCoords[i] = " << (texCoords[i].x) << ", " << (texCoords[i].y) << std::endl;
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    //std::cout << "" << std::endl;
    
   
    
    /*
     glBegin(GL_POINTS);
    //int index = vBalls.size()-20;
    //glVertex3f(vBalls[index].getPos().x, vBalls[index].getPos().y, 0);
    for (int i=0; i<vecs.size(); i++){
        if (i==0) glColor4f(1.0, .6, 0, 1);
        else glColor4f(.5, 0, .7, 1);
        glVertex3f(vecs[i].x, vecs[i].y, 0);
    }
    glEnd();
     */
    
    
    //glPopAttrib();
    
    
    
}

void Surface2d::move(Vector3df& nudge){
    int index = interpDetail*3 + 3;
    std::cout<<"index = "<<index<<std::endl;
    float freq = getRand(PI/360, PI/30);
    float amp = getRand(.01, .1);
    vecs[index].y = vecsOrig[index].y + sin(tempTheta)*amp;
    vecs[index+1].y = vecsOrig[index+1].y + sin(tempTheta)*amp;
    
    vecs[index-1].y = vecsOrig[index-1].y + sin(tempTheta)*amp*.9;
    vecs[index-2].y = vecsOrig[index-2].y + sin(tempTheta)*amp*.7;
    vecs[index-3].y = vecsOrig[index-3].y + sin(tempTheta)*amp*.5;
    
    vecs[index+2].y = vecsOrig[index+2].y + sin(tempTheta)*amp*.9;
    vecs[index+3].y = vecsOrig[index+3].y + sin(tempTheta)*amp*.7;
    vecs[index+4].y = vecsOrig[index+4].y + sin(tempTheta)*amp*.5;
    
    //vecs[index-2].x = vecsOrig[index-2].x + cos(tempTheta)*amp*.2;
    
    // vecs[index+2].x = vecsOrig[index+2].x - cos(tempTheta)*amp*1.4;
   /* if (cos(tempTheta)*amp*1.4 > 0){
        vecs[index-2].x = vecsOrig[index-2].x + cos(tempTheta)*amp*.2;
        vecs[index-3].x = vecsOrig[index-3].x + cos(tempTheta)*amp*.2;
        vecs[index-4].x = vecsOrig[index-4].x + cos(tempTheta)*amp*.2;
        vecs[index-5].x = vecsOrig[index-5].x + cos(tempTheta)*amp*.2;
        
        vecs[index+2].x = vecsOrig[index+2].x - cos(tempTheta)*amp*1.5;
        vecs[index+3].x = vecsOrig[index+3].x - cos(tempTheta)*amp*2.9;
        vecs[index+4].x = vecsOrig[index+4].x - cos(tempTheta)*amp*2.9;
        vecs[index+5].x = vecsOrig[index+5].x - cos(tempTheta)*amp*2.9;
        //vecs[index+2].x = vecsOrig[index+2].x + cos(tempTheta)*amp*.2;
    }*/
    
    
    
    
    tempTheta += freq;
    
}
