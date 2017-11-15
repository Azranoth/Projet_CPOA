#ifndef IMAGE2RGB_H
#define IMAGE2RGB_H

// SOURCES
#include "image2grey.h"

/**
 * @brief The Image2RGB class
 *
 * Hérite d'Image2D
 *
 * Image 2D de vecteurs 3 composés d'unsigned char. Contient les données d'une image RGB.
 */
class Image2RGB : public Image2D<Vec3uc>
{
public:
    Image2RGB(const int width, const int height) : Image2D<Vec3uc>(width, height){}
    Image2RGB(const int width, const int height, Vec3uc *input) : Image2D<Vec3uc>(width,height,input){}

    /**
     * @brief exportToPPM
     *
     * Exporte les données contenues dans l'image 2D courante dans un fichier .pgm ASCII
     */
    void exportToPPM();

    /**
     * @brief importPPM
     * @param filename
     *
     * Importe les données d'un fichier .pgm ASCII dans l'image2D courante
     */
    void importPPM(const std::string filename);



};

#endif // IMAGE2RGB_H
