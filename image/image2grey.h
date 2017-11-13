#ifndef IMAGE2GREY_H
#define IMAGE2GREY_H

#include <chrono>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>

#include "image2d.h"

class Image2Grey : public Image2D<unsigned char> {
public:

    // CONSTRUCTEURS
    Image2Grey(const int x, const int y) : Image2D<unsigned char>(x,y){}
    Image2Grey(const int x, const int y, unsigned char *input) : Image2D<unsigned char>(x,y,input){}

    void exportToPGM();
    void importPGM(const std::string filename);
    Image2Grey subSampling();
    Image2Grey threshold(const int val);

};

#endif // IMAGE2GREY_H
