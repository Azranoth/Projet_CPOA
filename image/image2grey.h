#ifndef IMAGE2GREY_H
#define IMAGE2GREY_H

// LIBS
#include <chrono>
#include <ctime>
#include <fstream>
#include <sstream>
// SOURCES
#include "image2d.h"

/**
 * @brief The Image2Grey class
 *
 * Hérite de Image2D
 * Contient les données d'une image 2D en nuances de gris sous la forme d'un tableau d'unsigned char
 */
class Image2Grey : public Image2D<unsigned char> {
public:

    // CONSTRUCTEURS
    Image2Grey(const int x, const int y) : Image2D<unsigned char>(x,y){}
    Image2Grey(const int x, const int y, unsigned char *input) : Image2D<unsigned char>(x,y,input){}

    /**
     * @brief exportToPGM
     *
     * Exporte les données contenues dans l'image2D courante dans un fichier .pgm ASCII
     */
    void exportToPGM();

    /**
     * @brief importPGM
     * @param filename
     *
     * Importe les données d'un fichier .pgm ASCII dans l'image2D courante
     */
    void importPGM(const std::string filename);

    /**
     * @brief subSampling
     * @return Image2Grey
     *
     * Génère à partir de l'image2D courante un sous-échantillonnage de celle-ci
     */
    Image2Grey subSampling();

    /**
     * @brief threshold
     * @param val
     * @return Image2Grey
     *
     * Réalise un seuillage de l'image courante avec le paramètre val comme seuil
     */
    Image2Grey threshold(const int val);

    /**
     * @brief blur
     * @param m
     * @return Image2Grey
     *
     * Renvoie un lissage de l'image courante de degré m
     */
    Image2Grey blur(const unsigned char m);

};

#endif // IMAGE2GREY_H
