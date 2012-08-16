//
//  Emitter.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/30/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include <iostream>
#include "Emitter.h"

Emitter::Emitter(){
}

/**
 * partial constructor with multiple particles
 */
Emitter::Emitter(Vector3df loc, std::vector<Particle> parts):
loc(loc), parts(parts) {
    particleCount = (int)parts.size();
}

/**
 * full constructor with multiple particles
 */
Emitter::Emitter(Vector3df loc, std::vector<Particle> parts, float birthRate, 
                 Vector3df emissionVec, Vector3df emissionSpd, float sprayRadius, bool isContinous):
loc(loc), parts(parts), birthRate(birthRate), emissionVec(emissionVec), emissionSpd(emissionSpd), sprayRadius(sprayRadius), isContinous(isContinous) {
    particleCount = (int)parts.size();
    init();
}

/**
 * full constructor with single particle, as template
 */
Emitter::Emitter(Vector3df loc, Particle part, int particleCount, float birthRate, 
                 Vector3df emissionVec, Vector3df emissionSpd, float sprayRadius, bool isContinous):
loc(loc), part(part), particleCount(particleCount), birthRate(birthRate), emissionVec(emissionVec), emissionSpd(emissionSpd), sprayRadius(sprayRadius), isContinous(isContinous) {
    
    // convert to unit direction
    emissionVec.normalize();
    // mult unit vector by magnitude
    emissionVec *= emissionSpd;
    
    // add emitter location to particle's current location (which is probably 0,0,0)
    part.loc += loc;
    //part.loc.y +=.9;
    
    // fill Particle vector with Particle template copies
    //push_back copies
    for(int i=0; i<particleCount; i++){
        parts.push_back(part);
        parts[i].dim = Dimension3d(getRand(part.dim.w),getRand(part.dim.w), getRand(part.dim.w));
    }
    init();
}

void Emitter::setLoc(Vector3df loc){
    this->loc = loc;
    for(int i=0; i<particleCount; i++){
        parts[i].loc += loc;
    }
}

Vector3df Emitter::getLoc(){
    return loc;
}


void Emitter::init(){
    liveParticleCount = 0;
    //fadeAlpha = 1.0;
}

void Emitter::setParticles(std::vector <Particle> parts){
    this->parts = parts;
}
std::vector <Particle> Emitter::getParticles(){
    return parts;
}
Particle* Emitter::getParticleArray(){
    return (&parts[0]);
}
void Emitter::start(){
    isRunning = true;
    //run();
}
void Emitter::stop(){
    isRunning = false;
}

void Emitter::run(){
    if (isRunning){
        
        //std::cout << "particleCount = " << particleCount<< std::endl;
        //std::cout << "birthRate = " << birthRate<< std::endl;
        // uses dynamic sentinal value
        for(int i=0; i<(int)liveParticleCount; i++){
            
            Vector3df vel;
            
            /*vel.x = parts[i].getSpd().x + emissionVec.x + getRand(-sprayRadius, sprayRadius);
             vel.y = parts[i].getSpd().y + emissionVec.y + getRand(-sprayRadius, sprayRadius);
             vel.z = parts[i].getSpd().z + emissionVec.z + getRand(-sprayRadius, sprayRadius);*/
            
            float jitterX = parts[i].getJitter().x;
            float jitterY = parts[i].getJitter().y;
            //std::cout << "jitterX = " << jitterX << std::endl;
            //std::cout << "jitterY = " << jitterY << std::endl;
            
            vel.x = parts[i].getSpd().x + emissionVec.x + getRand(-jitterX, jitterX);
            vel.y = parts[i].getSpd().y + emissionVec.y;
            vel.z = 0;//parts[i].getSpd().z + emissionVec.z + getRand(-jitterX, jitterX);
            
            
            parts[i].loc += vel;
            
            
            if (!parts[i].getIsAlive()){
                //parts[i].setAgeInSeconds(time(NULL));
                parts[i].setDistanceTraveled(parts[i].loc.y);
                parts[i].setIsAlive(true);
                //std::cout << "parts[i].loc.y = " << parts[i].loc.y << std::endl;
            }
            
            //float currentAge = time(NULL)-parts[i].getAgeInSeconds();
            
            //std::cout << "distTravled = " << parts[i].loc.y- parts[i].getDistanceTraveled()<< std::endl;
            float deltaY = parts[i].loc.y-parts[i].getDistanceTraveled();
            
            
            // fade smoke
            float dynamicAlpha = .2-(deltaY)*.135;
            parts[i].setAlpha(dynamicAlpha);
            
            // scale smoke
            float dynamicScale = deltaY*.0006;
            parts[i].dim.w += dynamicScale;
            parts[i].dim.h += dynamicScale;
            
            
            // increase jitter
            float dynamicJitter = (deltaY*deltaY)*.003;
            parts[i].setJitter(Vector3df(dynamicJitter, dynamicJitter, 0));
            //parts[i].dim.d += (parts[i].loc.y-parts[i].getDistanceTraveled())*.001;
            
            //std::cout << " parts[i].setAlpha() = " <<  parts[i].getAlpha() << std::endl;
            // draw smoke
            parts[i].display();
            
            if  (parts[i].getAlpha()<0){
                parts[i].loc = loc;
                parts[i].setAlpha(.2);
                parts[i].setJitter(Vector3df(0,0,0));
                parts[i].dim = Dimension3d(0,0,0);
                parts[i].setIsAlive(false);
            }
        }
        
        //gettimeofday();
        // increment liveParticleCount by birthRate
        // if current particle count is less than particleCount
        if (liveParticleCount < particleCount - birthRate) {
            liveParticleCount += birthRate;
            // std::cout << "liveParticleCount = " << liveParticleCount << std::endl;
        }
    }
}


void Emitter::setSprayRadius(float sprayRadius){
    this->sprayRadius = sprayRadius;
}

float Emitter::getSprayRadius(){
    return sprayRadius;
    
}

void Emitter::setBirthRate(float birthRate){
    this->birthRate = birthRate;
}

float Emitter::getBirthRate(){
    return birthRate;
}

void Emitter::setLiveParticleCount(int liveParticleCount){
    this->liveParticleCount = liveParticleCount;
}

int Emitter::getLiveParticleCount(){
    return liveParticleCount;
}

void Emitter::setEmissionVec(Vector3df emissionVec){
    this->emissionVec = emissionVec;
}
Vector3df Emitter::getEmissionVec(){
    return emissionVec;
}
void Emitter::setEmissionSpd(Vector3df emissionSpd){
    this->emissionSpd = emissionSpd;
}
Vector3df Emitter::getEmissionSpd(){
    return emissionSpd;
}

void Emitter::setIsContinous(bool isContinous){
    this->isContinous = isContinous;
}
bool Emitter::getIsContinous() {
    return isContinous;
}
