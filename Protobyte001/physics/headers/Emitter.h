//
//  Emitter.h
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/30/11.
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

#ifndef Protobyte_Library_V01_Emitter_h
#define Protobyte_Library_V01_Emitter_h

#include "ProtoUtils.h"
#include <vector>
#include "Particle.h"
#include "Vector3df.h"
#include <time.h>

class Emitter{
    
public:
    
    Emitter();
    
    /**
     * partial constructor with multiple particles
     */
    Emitter(Vector3df loc, std::vector<Particle> parts);
    
    /**
     * full constructor with multiple particles
     */    
    Emitter(Vector3df loc, std::vector<Particle> parts, float birthRate, 
            Vector3df emissionVec, Vector3df emissionSpd, float sprayRadius, bool isContinous);
    
    /**
     * full constructor with single particle, as template
     */
    Emitter(Vector3df loc, Particle part, int particleCount, float birthRate, 
            Vector3df emissionVec, Vector3df emissionSpd, float sprayRadius, bool isContinous);
    
    void init();
    void setParticles(std::vector <Particle> parts);
    std::vector <Particle> getParticles();
    Particle* getParticleArray();
    void start();
    void stop();
    void run();
    void setLoc(Vector3df loc);
    Vector3df getLoc();
    void setSprayRadius(float sprayRadius);
    float getSprayRadius();
    void setBirthRate(float birthRate);
    float getBirthRate();
    void setLiveParticleCount(int liveParticleCount);
    int getLiveParticleCount();
    void setEmissionVec(Vector3df emissionVec);
    Vector3df getEmissionVec();
    void setEmissionSpd(Vector3df emissionSpd);
    Vector3df getEmissionSpd();
    void setIsContinous(bool isContinous);
    bool getIsContinous();
    
    Vector3df loc;

private:
    Particle part;
    int particleCount;
    std::vector<Particle> parts;
    float birthRate;
    float liveParticleCount;
    Vector3df emissionVec;
    Vector3df emissionSpd;
    float sprayRadius;
    bool isRunning;
    bool isContinous;
    
    // for alpha
    //float alphaFade;
};

#endif
