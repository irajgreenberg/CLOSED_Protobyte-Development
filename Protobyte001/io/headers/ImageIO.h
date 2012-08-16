//
//  ImageIO.h
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/13/11.
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

#ifndef Protobyte_Library_V01_ImageIO_h
#define Protobyte_Library_V01_ImageIO_h

#include <string.h>
#include "png.h"
#include "ProtoSetup.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
//#include "FreeImage.h"




class ImageIO {

private:

    std::string fileName;
    //std::string fileName2;
    int width, height;
    GLuint texture;
    GLuint textureID;


public:
    ImageIO();
    ImageIO(std::string fileName);
    ImageIO(std::string fileName, int& width, int& height);
    GLuint init();

    static const int PNG = 0;
    static const int JPG = 1;
    static const int RAW = 2;
    static const int BMP = 3;

    static const int TEXTURE_LOAD_ERROR = 0;

    GLuint getTexture();
    int getWidth();
    int getHeight();


    //static GLuint getTextureImg(const std::string filename, int &width, int &height);
    //static GLuint getTextureImg(const std::string filename, int &width, int &height, int fileType);

    //static GLuint getTextureImg2(const std::string filename2);


};


#endif
