#include "matrix33d.h"

Matrix33d::inversion(){

    double det = this[0,0]*this[1,1]*this[2][2] +
            this[0][1]*this[1][2]*this[2][0] +
            this[0][2]*this[1][0]*this[2][1] -
            this[0][2]*this[1][1]*this[2][0] -
            this[0][0]*this[1][2]*this[2][1] -
            this[0][1]*this[1][0]*this[2][2];

    if(det == 0){
        return nullptr;
    }

    int tab_invert[3][3];

    tab_invert[0][0] =  (M[1][1]*M[2][2] - M[1][2]*M[2][1]) / det;
    tab_invert[1][0] = -(M[1][0]*M[2][2] - M[2][0]*M[1][2]) / det;
    tab_invert[2][0] =  (M[1][0]*M[2][1] - M[2][0]*M[1][1]) / det;

    tab_invert[0][1] = -(M[0][1]*M[2][2] - M[2][1]*M[0][2]) / det;
    tab_invert[1][1] =  (M[0][0]*M[2][2] - M[2][0]*M[0][2]) / det;
    tab_invert[2][1] = -(M[0][0]*M[2][1] - M[2][0]*M[0][1]) / det;

    tab_invert[0][2] =  (M[0][1]*M[1][2] - M[1][1]*M[0][2]) / det;
    tab_invert[1][2] = -(M[0][0]*M[1][2] - M[1][0]*M[0][2]) / det;
    tab_invert[2][2] =  (M[0][0]*M[1][1] - M[1][0]*M[0][1]) / det;

    Matrix33d invert = Matrix33d(tab_invert);
    return invert;
}


