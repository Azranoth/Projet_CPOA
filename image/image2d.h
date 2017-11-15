#ifndef IMAGE2D_H
#define IMAGE2D_H

// SOURCES
#include "matrix33d.h"

/**
 * class Image2D
 * Contient les données des pixels d'une image de taille _w*_h dans un tableau dynamique de type T
 *
 * _imgData : tableau de données de type T
 * _w : largeur de l'image
 * _h : hauteur de l'image
 *
 **/
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
       /* for(int i = 0; i < _w; i++){
            for(int j = 0; j < _h; j++){
                (*this)(i,j) = T(0);
            }
        }*/
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
    /**
     * @brief width
     * @return largeur de l'image
     */
    int width() const {return _w;}

    /**
     * @brief height
     * @return hauteur de l'image
     */
    int height() const {return _h;}

    /**
     * @brief getData
     * @return tableau de données des pixels
     */
    T* getData() const {return _imgData;}

    // AFFECTATION

    /**
     * @brief setPixel
     * @param x
     * @param y
     * @param value
     *
     * Affecte la valeur value au pixel (x,y) du tableau _imgData
     */
    void setPixel(const int x, const int y, const T& value){
        (*this)(x,y) = value;
    }

    /**
     * @brief setPixel
     * @param x
     * @param value
     *
     * Variante de setPixel, ou on attribue la valeur value à une case sans passer par l'opérateur surchargé ()
     */
    void setPixel(const int x, const T& value){
        _imgData[x] = value;
    }

    // FONCTIONS .cpp

    /**
     * @brief imgSwap
     * @param img
     *
     * Echange les données de l'image courante avec celles de l'image passée en paramètre
     */
    void imgSwap(Image2D<T> img);

    /**
     * @brief crop
     * @param origin_x
     * @param origin_y
     * @param width
     * @param height
     * @return Image2D de type T.
     *
     * Rogne une sous-image de l'image courante, de taille width*height & prenant son origine au point (origin_x, origin_y)
     */
    Image2D<T> crop(const int origin_x, const int origin_y, const int width, const int height);

};


#endif // IMAGE2D_H
