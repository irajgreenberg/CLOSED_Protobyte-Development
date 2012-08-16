//
//  Shape2d.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Shape2d.h"
#include <iostream>

Shape2d::Shape2d(){  }


/*Shape2d::Shape2d(Curve3d* contours, int* curveLens, int arrLen):
 contours(contours), curveLens(curveLens), arrLen(arrLen){
 for (int i=0; i<arrLen; i++){
 std::vector <Vector3df> tempVecs = contours[i].getVertices();
 for (int j=0; j<curveLens[i]; j++){
 // only check for reudendancy after 1st curve vertices have been added
 if (i>0){
 if (tempVecs[j] == vecs[vecs.size()-1]){
 // do nothing if last and next vertex are equal
 } else {
 vecs.push_back(tempVecs[j]);
 }
 } else {
 // add 1st curve vertices
 vecs.push_back(tempVecs[j]);
 }
 
 }
 }
 //tessellate();
 }*/

Shape2d::Shape2d(Curve3d* contour) {
    vecs = contour->getVertices();
}




//Shape2d::~Shape2d() { 

//}


void Shape2d::init(){
}

void Shape2d::display(){
    GLUtesselatorObj* tessObj = gluNewTess(); 
    
    // dynamically allocate memory for 2D array
    double** pts = 0;
    int ptsLen = (int)vecs.size();
    
    pts = new double* [ptsLen];
    
    for(int i=0; i<ptsLen; i++){
        pts[i] = new double[3];
    }
    
    for(int i=0; i<ptsLen; i++){
        pts[i][0] = vecs[i].x;
        pts[i][1] = vecs[i].y;
        pts[i][2] = 0;
      // std::cout << "pts = " << pts[i][0]<< ", " << pts[i][1]<< ", " <<pts[i][2]<<std::endl;
    }
    
    gluTessCallback(tessObj, GLU_TESS_BEGIN, (void (CALLBACK *)())tessBeginCB);
    gluTessCallback(tessObj, GLU_TESS_END, (void (CALLBACK *)())tessEndCB);
    gluTessCallback(tessObj, GLU_TESS_VERTEX, (void (CALLBACK *)())tessVertexCB);
    
    
    // Begin drawing
    gluTessBeginPolygon(tessObj, NULL);
    gluTessBeginContour(tessObj);
    
    // Draw all points
    for (int i=0; i<ptsLen; i++){ 
        gluTessVertex(tessObj, pts[i], pts[i]); // Draw one Vertex.
    }
    
    // Finish drawing
    gluTessEndContour(tessObj);
    gluTessEndPolygon(tessObj);
    
    // Delete the Tesselator Object
    gluDeleteTess(tessObj);
    
    // clean up memory
    for( int i = 0 ; i < 3 ; i++ ) {
        delete []pts[i] ;
    }
    delete [] pts ;
    
    
}


/**
 * requires array of curves
 */
/*void Shape2d::setContour(Curve3d& contour) {
 this->contour = contour;
 }*/


