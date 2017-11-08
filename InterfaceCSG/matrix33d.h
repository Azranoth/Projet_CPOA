#ifndef MATRIX33D
#define MATRIX33D

#include "Array.h"
#include "vector.h"

class Matrix33d {
protected:
    Array<double,3> matData[3];
public:
    // CONSTRUCTEURS
    Matrix33d(){
        //this->matData = Array<Array<double,3>,3>();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                this->matData[i]=Array<double,3>();
            }
        }
    }

    Matrix33d(const double input[3][3]){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                this->matData[i][j] = input[i][j];
            }
        }
    }

    Matrix33d(const Array<Array<double,3>,3> array){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                this->matData[i][j] = array[i][j];
            }
        }
    }

    // ACCESSEURS
    Array<double,3>& operator[](const int i){
        return this->matData[i];
    }

    Array<double,3> operator[](const int i) const{
        return this->matData[i];
    }

    // FONCTIONS
    Matrix33d inversion();

};
#endif // MATRICE33D
