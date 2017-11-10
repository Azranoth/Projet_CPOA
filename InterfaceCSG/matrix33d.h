#ifndef MATRIX33D
#define MATRIX33D



#include "Array.h"
#include "vector.h"

class Matrix33d {
protected:
    Array<double,3> matData[3];

public:
    // CONSTRUCTEURS
    inline Matrix33d(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                this->matData[i]=Array<double,3>();
            }
        }
    }

    inline Matrix33d(const double input[3][3]){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                this->matData[i][j] = input[i][j];
            }
        }
    }

    inline Matrix33d(const Array<double,3> array[3]){
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

    // AFFICHAGE
    void display(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                std::cout << matData[i][j] << " | ";
            }
            std::cout << "\n";
        }
    }

    // OPERATEURS
    Matrix33d operator*(const Matrix33d mat){
        double sum;
        Matrix33d matRes = Matrix33d();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    sum = matRes[i][j] + matData[i][k] * mat[k][j];
                    matRes[i][j] = sum;
                }
            }
        }
        return matRes;
    }

    Vec3f operator*(const Vec2f& vec){
        Vec3f converted = Vec3f();
        converted[0] = vec[0]; converted[1] = vec[1]; converted[2] = 1;
        Vec3f resVec = Vec3f();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                resVec[i] += converted[j]*matData[i][j];

            }
        }
        return resVec;
    }

    void operator=(const Matrix33d& mat){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                matData[i][j] = mat[i][j];
            }
        }
    }

    // FONCTIONS
    Matrix33d inversion();

    // FONCTIONS DE GENERATION DE MATRICES DE TRANSFORMATION

    static Matrix33d rotation(const double angle){
        double tab_rotation[3][3] = { { cos(angle), -sin(angle), 0 } , { sin(angle), cos(angle), 0 } , { 0, 0, 1 } };
        Matrix33d trsf_rotation = Matrix33d(tab_rotation);
        return trsf_rotation;
    }

    static Matrix33d translation(const double translate_x, const double translate_y){
         double tab_translation[3][3] = { { 1, 0, translate_x } , { 0, 1, translate_y } , { 0, 0, 1 } };
        Matrix33d trsf_translation = Matrix33d(tab_translation);
        return trsf_translation;
    }

    static Matrix33d scaling(const double scale){
        double tab_scaling[3][3] = { { scale, 0, 0 } , { 0, scale, 0 } , { 0, 0, scale } };
        Matrix33d trsf_scaling = Matrix33d(tab_scaling);
        return trsf_scaling;
    }
    // TRANSFORMATION SETTERS
    static void setRotation(Matrix33d& mat, const double angle){
        mat = rotation(angle);
    }

    static void setTranslation(Matrix33d& mat, const double x, const double y){
        mat = translation(x,y);
    }

    static void setScaling(Matrix33d& mat, const double scale){
        mat = scaling(scale);
    }

    // TRANSFORMATION APPLYER
    static void applyTransformation(Matrix33d& dest_mat, Matrix33d transf_mat){
        dest_mat = (transf_mat*dest_mat);
    }
};

// MULTIPLICATION D'UNE MATRICE PAR UN Vec3f
/*
Matrix33d operator*(Vec3f& vec, const Matrix33d& mat){
    Matrix33d matRes = Matrix33d();
    double sum;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++)
                sum = matRes[i][j] + vec[i] * mat[k][j];
                matRes[i][j] = sum;
        }
    }
    return matRes;
}
*/
#endif // MATRICE33D
