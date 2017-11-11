#ifndef IMAGE2D_H
#define IMAGE2D_H

#include "matrix33d.h"


template<typename T, int W, int H>  //  W : width; H : Height
class Image2D
{
protected:
    T *imgData;
public:
    inline Image2D(const T input[W][H]){
        imgData = new T[W][H];
        for(int i = 0; i < W; i++){
            for(int j = 0; j < H; j++){
                imgData[i][j] = input[i][j];
            }
        }
    }
};

#endif // IMAGE2D_H
