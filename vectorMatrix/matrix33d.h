#ifndef MATRIX33D
#define MATRIX33D


// SOURCES
#include "vector.h"

/**
 * @brief The Matrix33d class
 *
 * Représente une matrice 3x3 de double sous la forme d'un tableau statique de 3 arrays contenant chacun 3 double
 */
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
    /**
     * @brief display
     *
     * Affiche la matrice33 courante sur la sortie standard
     */
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

    // MULTIPLICATION D'UNE MATRICE PAR UN Vec2f
    Vec3f operator*(const Vec2f& vec){
        Vec3f converted = Vec3f();
        converted[0] = vec[0]; converted[1] = vec[1]; converted[2] = 0;
        Vec3f resVec = Vec3f();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                resVec[i] += converted[j]*matData[i][j];

            }
        }
        return resVec;
    }

    // MULTIPLICATION D'UNE MATRICE PAR UN Vec3f
    Vec3f operator*(const Vec3f& vec){
        Vec3f vecRes;
        double sum;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++)
                    sum = vecRes[i] + vec[i] * matData[k][j];
                    vecRes[i] = sum;
            }
        }
        return vecRes;
    }

    void operator=(const Matrix33d& mat){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                matData[i][j] = mat[i][j];
            }
        }
    }

    // FONCTIONS
    /**
     * @brief inversion
     * @return Matrix33d
     *
     * Renvoie l'inverse de la matrice33 courante
     */
    Matrix33d inversion();

    // FONCTION IDENTITE
    /**
     * @brief identity
     * @return Matrix33d
     *
     * Renvoie la matrice 3x3 identité
     */
    static Matrix33d identity(){
        double tab[3][3] = { {1.0, 0.0, 0.0} , {0.0, 1.0, 0.0} , {0.0, 0.0, 1.0} };
        Matrix33d mat = Matrix33d(tab);
        return mat;
    }

    // FONCTIONS DE GENERATION DE MATRICES DE TRANSFORMATION

    /**
     * @brief rotation
     * @param angle
     * @return Matrix33d
     *
     * Renvoie une matrice de rotation d'angle "angle" passé en paramètre
     */
    static Matrix33d rotation(const double angle){
        double tab_rotation[3][3] = { { cos(angle), -sin(angle), 0 } , { sin(angle), cos(angle), 0 } , { 0, 0, 1 } };
        Matrix33d trsf_rotation = Matrix33d(tab_rotation);
        return trsf_rotation;
    }

    /**
     * @brief translation
     * @param translate_x
     * @param translate_y
     * @return Matrix33d
     *
     * Renvoie une matrice de translation (translate_x, translate_y)
     */
    static Matrix33d translation(const double translate_x, const double translate_y){
         double tab_translation[3][3] = { { 1, 0, translate_x } , { 0, 1, translate_y } , { 0, 0, 1 } };
        Matrix33d trsf_translation = Matrix33d(tab_translation);
        return trsf_translation;
    }

    /**
     * @brief scaling
     * @param scale
     * @return Matrix33d
     *
     * Renvoie une matrice d'homothétie d'échelle scale
     */
    static Matrix33d scaling(const double scale){
        double tab_scaling[3][3] = { { scale, 0, 0 } , { 0, scale, 0 } , { 0, 0, scale } };
        Matrix33d trsf_scaling = Matrix33d(tab_scaling);
        return trsf_scaling;
    }
    // TRANSFORMATION SETTERS
    /**
     * @brief setRotation
     * @param mat
     * @param angle
     *
     * Transforme une matrice mat en une matrice de rotation d'angle "angle"
     */
    static void setRotation(Matrix33d& mat, const double angle){
        mat = rotation(angle);
    }

    /**
     * @brief setTranslation
     * @param mat
     * @param x
     * @param y
     *
     * Transforme une matrice mat en une matrice de translation (x,y)
     */
    static void setTranslation(Matrix33d& mat, const double x, const double y){
        mat = translation(x,y);
    }

    /**
     * @brief setScaling
     * @param mat
     * @param scale
     *
     * Transforme une matrice mat en une matrice d'homothétie d'échelle scale
     */
    static void setScaling(Matrix33d& mat, const double scale){
        mat = scaling(scale);
    }

    // TRANSFORMATION APPLYER
    /**
     * @brief applyTransformation
     * @param dest_mat
     * @param transf_mat
     *
     * Applique une matrice de transformation transf_mat sur une matrice dest_mat
     */
    static void applyTransformation(Matrix33d& dest_mat, Matrix33d& transf_mat){
        dest_mat = (transf_mat*dest_mat);
    }
};




#endif // MATRICE33D
