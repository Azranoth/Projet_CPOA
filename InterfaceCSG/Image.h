/**
 * @author Nathan URBAIN
 * @date 12/09/2017
 */

#ifndef IMAGE_H
#define IMAGE_H

/**
 * @class Image
 * @brief Classe template definissant une image
 * @privatesection
 *      {Image} Operator=,
 * @protectedsection
 *      @property {int} largeur
 *      @property {int} hauteur
 *      @property {T*} data, tableau de données
 */
template <typename T>
class Image{
    public :
        inline Image(int l, int h){
            largeur=l;
            hauteur=h;
            data = T[l*h];
        }
        ~Image();

    protected :
        int largeur;
        int hauteur;
        T* data;

    private :
        Image(Image const &);
        Image& operator=(Image const &);
}

#endif
