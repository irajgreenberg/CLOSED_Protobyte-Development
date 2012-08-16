//
//  ProtoSetup.h
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
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

#ifndef Protobyte_Library_V01_ProtoSetup_h
#define Protobyte_Library_V01_ProtoSetup_h

#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
// OS X
#include <AvailabilityMacros.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
//#include <OpenGL/glew.h>
#else
// windows
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
//#include <windows.h> // not sure if this should be here–from texture mapping example code
#define _USE_MATH_DEFINES // required for M_PI in windows
#endif

#define PI 3.14159265
const double GR_PI = 3.1415926535897932384626433832795;

#endif //Protobyte_Library_V01_ProtoSetup_h
