#ifndef CSG_DISK_H
#define CSG_DISK_H

#include "CsgOperation.h"

class CsgDisk : public CsgPrimitive {
protected:
    double _radius;
public:
    CsgDisk():CsgPrimitive(){
        double array[2] = {-0.5, -0.5};
        Vec2f LB = Vec2f(array);
        double array2[2] = {0.5, 0.5};
        Vec2f RT = Vec2f(array2);
        setBbox(BoundingBox(LB, RT));
    }
    CsgDisk(CsgNode* parent, Vec2f& center, Matrix33d mat, double rad):CsgPrimitive(parent, center, mat){

        _radius = rad;
        double array[2] = {-rad, -rad};
        Vec2f LB = Vec2f(array);
        double array2[2] = {rad, rad};
        Vec2f RT = Vec2f(array2);

        setBbox(BoundingBox(LB, RT));
    }

    void ApplyMatToVertices();

    bool intersectBbox(Vec2f& p);

    bool intersect(Vec2f& p);
};

#endif
