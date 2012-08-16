//
//  Particle.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/30/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Particle.h"
#include <iostream>


Particle::Particle(){
    
}

Particle::Particle(Vector3df loc = Vector3df(0,0,0)){
    dim = Dimension3d(1, 1, 1);
    spd = Vector3df(0,0,0);
    init();
}

Particle::Particle(Vector3df loc, Dimension3d dim):
loc(loc), dim(dim) {
    spd = Vector3df(0,0,0);
    imageIO = NULL;
    init();  
}

Particle::Particle(Vector3df loc, Dimension3d dim, Vector3df spd):
loc(loc), dim(dim), spd(spd) {
    imageIO = NULL;
    init();   
}

/*Particle::Particle(Vector3df loc, Dimension3d dim, Vector3df spd, std::string textureName):
loc(loc), dim(dim), spd(spd), textureName(textureName) {
    int w = dim.w;
    int h = dim.h;
    imageIO = new ImageIO(textureName, w, h);
    init();
}

Particle::Particle(Vector3df loc, Dimension3d dim, Vector3df spd, std::string textureName, float alpha):
loc(loc), dim(dim), spd(spd), textureName(textureName), alpha(alpha){
    int w = dim.w;
    int h = dim.h;
    imageIO = new ImageIO(textureName, w, h);
    init();
}*/

/*Particle::Particle(Vector3df loc, Dimension3d dim, Vector3df spd, char* textureName):
loc(loc), dim(dim), spd(spd), textureName(textureName) {
    int w = dim.w;
    int h = dim.h;
    imageIO = new ImageIO(textureName, w, h);
    init();
}

Particle::Particle(Vector3df loc, Dimension3d dim, Vector3df spd, char* textureName, float alpha):
loc(loc), dim(dim), spd(spd), textureName(textureName), alpha(alpha){
    int w = dim.w;
    int h = dim.h;
    imageIO = new ImageIO(textureName, w, h);
    init();
}
*/

Particle::Particle(Vector3df loc, Dimension3d dim, Vector3df spd, GLuint* texture, int textW, int textH, float alpha):
loc(loc), dim(dim), spd(spd), texture(texture), textW(textW), textH(textH), alpha(alpha){
    imageIO = NULL;
    init();
}

Particle::~Particle(){
    //delete imageIO;
}


void Particle::init() {
    isAlive = false;
    initLoc = loc;
    
    //texture = imageIO->getTexture();
    jitter = Vector3df(0,0,0);
    /* int w = dim.w;
    int h = dim.h;
    texture = ImageIO::getTextureImg(textureName, w, h);
    std::cout << "texture name = " << textureName << std::endl;
    */
}

void Particle::display(){
    glEnable(GL_TEXTURE_2D);
    
    glColor4f(.6, .6, .8, alpha);
    
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE );
	//glTexEnvf(GL_TEXTURE_ENV,GL_COMBINE_RGB,GL_MODULATE);
	//glTexEnvf(GL_TEXTURE_ENV,GL_SRC0_RGB,GL_PRIMARY_COLOR);
	//glTexEnvf(GL_TEXTURE_ENV,GL_OPERAND0_RGB,GL_SRC_COLOR);
	//glTexEnvf(GL_TEXTURE_ENV,GL_SRC1_RGB,GL_TEXTURE);
	//glTexEnvf(GL_TEXTURE_ENV,GL_OPERAND1_RGB,GL_SRC_COLOR);
    
    
    

    
    
    glPushMatrix();
    glTranslatef(loc.x, loc.y, loc.z);
    glScalef(dim.w, dim.h, dim.d);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3f(-.5, -.5, 0);
    glTexCoord2d(1, 0);
    glVertex3f(.5, -.5, 0);
    glTexCoord2d(1, 1);
    glVertex3f(.5, .5, 0);
    glTexCoord2d(0, 1);
    glVertex3f(-.5, .5, 0);
    glEnd();
    glPopMatrix();
    
    glDisable(GL_TEXTURE_2D);
}


// getters & setters
void Particle::setSpd(Vector3df spd){
    this->spd = spd;
    
}
Vector3df Particle::getSpd(){
    return spd;
    
}

void Particle::setMass(float mass){
    this->mass = mass;
    
}
float Particle::getMass(){
    return mass;
    
}

void Particle::setLifeTime(float lifeTime) {
    this->lifeTime = lifeTime;
}

float Particle::getLifeTime() {
    return lifeTime;
}

void Particle::setJitter(Vector3df jitter) {
    this->jitter = jitter;
}
Vector3df Particle::getJitter() {
    return jitter;
}

void Particle::setTexture(GLuint* texture){
    this->texture = texture;
}

void Particle::setAlpha(float alpha) {
    this->alpha = alpha;
}

float Particle::getAlpha() {
    return alpha;
}

void Particle::setAgeInSeconds(int ageInSeconds){
    this->ageInSeconds = ageInSeconds;
}

int Particle::getAgeInSeconds(){
    return ageInSeconds;
}

void Particle::setDistanceTraveled(float distanceTraveled) {
    this->distTraveled = distTraveled;
}

float Particle::getDistanceTraveled() {
    return distTraveled;
}


void Particle::setIsAlive(bool isAlive) {
    this->isAlive = isAlive;
}

bool Particle::getIsAlive() {
    return isAlive;
}

void Particle::setInitLoc(Vector3df initLoc){
    this->initLoc = initLoc;
}

Vector3df Particle::getInitLoc() {
    return initLoc;
}


void Particle::setTextureName(std::string textureName){
    this->textureName = textureName;
    
}
std::string Particle::getTextureName(){
    return textureName;
}