#ifndef IMAGE2GREY_H
#define IMAGE2GREY_H

#include <chrono>
#include <ctime>
#include <fstream>

#include "image2d.h"

class Image2Grey : public Image2D<unsigned char> {
public:

    // CONSTRUCTEURS
    Image2Grey(const int x, const int y) { Image2D<unsigned char>(x,y); }
    Image2Grey(const int x, const int y, unsigned char *input) { Image2D<unsigned char>(x,y,input); }

    void exportToPGM();
    Image2Grey subSampling();
    Image2Grey threshold(const int val);

};

#endif // IMAGE2GREY_H
