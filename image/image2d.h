#ifndef IMAGE2D_H
#define IMAGE2D_H

#include "matrix33d.h"


template<typename T>
class Image2D {
protected:
    T *_imgData;
    int _w;
    int _h;
public:

    // CONSTRUCTEURS
    inline Image2D(int width, int height){
        _w = width; _h = height;
        _imgData = new T[_w*_h];
        for(int i = 0; i < _w; i++){
            for(int j = 0; j < _h; j++){
                (*this)(i,j) = T(0);
            }
        }
    }

    inline Image2D(int width, int height, const T* input){
        _w = width; _h = height;
        _imgData = new T[_w*_h];
        for(int i = 0; i < _w*_h; i++){
            _imgData[i] = input[i];
        }
    }
    // DESTRUCTEUR
    ~Image2D(){
        delete [] _imgData;
    }

    // OPERATEURS
    T& operator()(const int x, const int y){
        return _imgData[x+y*_w];
    }
    T operator()(const int x, const int y) const {
        return _imgData[x+y*_w];
    }

    // ACCESSEURS
    int width() const {return _w;}
    int height() const {return _h;}
    T* getData() const {return _imgData;}

    // AFFECTATION
    void setPixel(const int x, const int y, const T& value){
        (*this)(x,y) = value;
    }
    void setPixel(const int x, const T& value){
        _imgData[x] = value;
    }

    // FONCTIONS .cpp
    void imgSwap(Image2D<T> img);
    Image2D<T> crop(const int origin_x, const int origin_y, const int width, const int height);

};


#endif // IMAGE2D_H
