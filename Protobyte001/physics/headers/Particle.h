//
//  Particle.h
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

#ifndef Protobyte_Library_V01_Particle_h
#define Protobyte_Library_V01_Particle_h

#include "ProtoSetup.h"
#include "ProtoUtils.h"
#include "Vector3df.h"
#include "Dimension3d.h"
#include "ImageIO.h"


class Particle {
    
    
private:
    
    Vector3df spd;
    float mass;
    float lifeTime;
    Vector3df jitter;
    float alpha;
    
    bool isAlive;
    /**
     * keeps track of how long the particle has been alive in milliseconds
     */
    int ageInSeconds;
    float distTraveled;
    
    Vector3df initLoc;
    
    // for texture
    ImageIO* imageIO;
    //std::string textureName;
    std::string textureName;
    GLuint* texture;
    int textW, textH;
    
    
public:
    
    Vector3df loc;
    Dimension3d dim;
    
    // constuctors
    Particle();
    Particle(Vector3df loc);
    Particle(Vector3df loc, Dimension3d dim);
    Particle(Vector3df loc, Dimension3d dim, Vector3df spd);
    
    Particle(Vector3df loc, Dimension3d dim, Vector3df spd, std::string textureName);
    Particle(Vector3df loc, Dimension3d dim, Vector3df spd, std::string textureName, float alpha);

    
    
    Particle(Vector3df loc, Dimension3d dim, Vector3df spd, GLuint* texture, int textW, int textH, float alpha);
   
    ~Particle();
    
    void init();
    void display();
    
    // getters & setters
    void setSpd(Vector3df spd);
    Vector3df getSpd();
    
    void setMass(float mass);
    float getMass();
    
    void setLifeTime(float lifeTime);
    float getLifeTime();
    
    void setJitter(Vector3df jitter);
    Vector3df getJitter();
    
    void setTexture(GLuint* texture);
    
    void setAlpha(float alpha);
    float getAlpha();
    
    void setAgeInSeconds(int ageInSeconds);
    int getAgeInSeconds();
    
    void setDistanceTraveled(float distTraveled);
    float getDistanceTraveled();
    
    void setIsAlive(bool isAlive);
    bool getIsAlive();
    
    void setInitLoc(Vector3df initLoc);
    Vector3df getInitLoc();
    
   void setTextureName(std::string textureName);
   std::string getTextureName();
    
    
};

#endif
