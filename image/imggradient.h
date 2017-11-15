#ifndef IMGGRADIENT
#define IMGGRADIENT

#include "image2grey.h"

class GradientSobel {

public:
    Image2D<Vec2f> gradient33(const Image2Grey& img_in);

};

#endif // IMGGRADIENT

