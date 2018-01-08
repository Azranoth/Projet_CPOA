#ifndef CSG_PRIMITIVE_H
#define CSG_PRIMITIVE_H

#include "CsgNode.h"
#include "CsgOperation.h"


#include <math.h>


const double pi = std::atan(1.0)*4;

class CsgPrimitive : public virtual CsgNode {

protected:
    Matrix33d _mat;
    Matrix33d _invertedMat;
    Vec2f _center;

public:
    CsgPrimitive():CsgNode(){ _mat = Matrix33d::identity(); _center = Vec2f(); }
    CsgPrimitive(CsgNode* parent, Vec2f& center, Matrix33d mat):CsgNode(parent){ _mat = mat; _invertedMat = mat.inversion(); _center = center; }


    void rotatePrimitive(const double angle){
        _mat = Matrix33d::rotation(angle)*_mat;
        _invertedMat = _mat.inversion();
    }

    void translatePrimitive(const double x, const double y){
        _mat = Matrix33d::translation(x,y)*_mat;
        _invertedMat = _mat.inversion();
    }

    void scalePrimitive(const double scale){
        _mat = Matrix33d::scaling(scale)*_mat;
        _invertedMat = _mat.inversion();
    }

    void transformPrimitive(Matrix33d& mat){
        _mat = mat * _mat;
        _invertedMat = _mat.inversion();
    }

    Matrix33d getMat(){ return _mat; }

    Vec2f getCenter(){ return _center; }

    // Autres fonctions
    bool isPointInsidePrimtive(Vec2f& point);

    virtual void ApplyMatToVertices() = 0;

    virtual bool intersectBbox(Vec2f& p) = 0;

    virtual bool intersect(Vec2f& p) = 0;

};

#endif
