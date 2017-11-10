#include "matrix33d.h"

Matrix33d Matrix33d::inversion(){

    double det = matData[0][0]*matData[1][1]*matData[2][2] +
            matData[0][1]*matData[1][2]*matData[2][0] +
            matData[0][2]*matData[1][0]*matData[2][1] -
            matData[0][2]*matData[1][1]*matData[2][0] -
            matData[0][0]*matData[1][2]*matData[2][1] -
            matData[0][1]*matData[1][0]*matData[2][2];

    if(det == 0){
        std::cout << "DETERMINANT NUL\n";
        exit(1);
    }

    double tab_invert[3][3];

    tab_invert[0][0] =  (matData[1][1]*matData[2][2] - matData[1][2]*matData[2][1]) / det;
    tab_invert[1][0] = -(matData[1][0]*matData[2][2] - matData[2][0]*matData[1][2]) / det;
    tab_invert[2][0] =  (matData[1][0]*matData[2][1] - matData[2][0]*matData[1][1]) / det;

    tab_invert[0][1] = -(matData[0][1]*matData[2][2] - matData[2][1]*matData[0][2]) / det;
    tab_invert[1][1] =  (matData[0][0]*matData[2][2] - matData[2][0]*matData[0][2]) / det;
    tab_invert[2][1] = -(matData[0][0]*matData[2][1] - matData[2][0]*matData[0][1]) / det;

    tab_invert[0][2] =  (matData[0][1]*matData[1][2] - matData[1][1]*matData[0][2]) / det;
    tab_invert[1][2] = -(matData[0][0]*matData[1][2] - matData[1][0]*matData[0][2]) / det;
    tab_invert[2][2] =  (matData[0][0]*matData[1][1] - matData[1][0]*matData[0][1]) / det;

    Matrix33d invert = Matrix33d(tab_invert);
    return invert;
}











