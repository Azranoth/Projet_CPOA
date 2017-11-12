#include "image2d.h"

template<typename T>
void Image2D<T>::imgSwap(Image2D<T> img){
    T temp_val;
    for(int i = 0; i < _w; i++){
        for(int j = 0; j < _h; j++){

            temp_val = this(i,j);
            setPixel(i,j,img(i,j));
            img.setPixel(i,j, temp_val);

        }
    }
}

template<typename T>
Image2D<T> Image2D<T>::crop(const int origin_x, const int origin_y, const int width, const int height){
    Image2D<T> cropped_image = Image2D<T>(width, height);
    for(int i = origin_x; i < origin_x+width; i++){
        for(int j = origin_y; j < origin_y+height; j++){
            cropped_image.setPixel((i - origin_x), (j-origin_y), this(i,j));
        }
    }
    return cropped_image;
}

