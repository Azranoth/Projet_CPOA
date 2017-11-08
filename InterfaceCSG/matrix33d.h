#ifndef MATRIX33D
#define MATRIX33D

#include "Array.h"
#include "vector.h"

class Matrix33d : public Array<Vec3i,3> {

public:
    // CONSTRUCTEURS
    Matrix33d(){
        double input[3] = {double(0), double(0), double(0)};
        for(int i = 0; i < 3; i++){
            this->data[i] = Array<Double,3>(input);
        }
    }

    Matrix33d(const double input[3][3]){
        for(int i = 0; i < 3; i++){
            this->data[i] = Array<Double,3>(input[i]);
        }
    }

    Matrix33d(const Array<Array<double,3>,3> array){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                this->data[i].data[j] = array.data[i].data[j];
            }
        }
    }

    // ACCESSEURS
    double& operator[][](const int i, const int j){
        return this->data[i].data[j];
    }

    double operator[][](const int i, const int j) const{
        return this->data[i].data[j];
    }

};
#endif // MATRICE33D
