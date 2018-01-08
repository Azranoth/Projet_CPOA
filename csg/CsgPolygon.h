#ifndef CSG_POLYGON_H
#define CSG_POLYGON_H

#include "CsgOperation.h"


#include <algorithm>
#include <set>

class CsgPolygon : public virtual CsgPrimitive {
protected:
    int _nbVertices;
    std::vector<Vec2f> _vertices;   // Coordonnées initiales des sommets
    std::vector<Vec2f> _transformedVertices; // Coordonnées des sommets après application de la matrice de transformation du noeud
    Vec2f _center;

public:
    // Constructeurs
    CsgPolygon():CsgPrimitive(){ _nbVertices = 3; }
    CsgPolygon(CsgNode* parent, Vec2f& center, Matrix33d mat, int nbVertices):CsgPrimitive(parent, center, mat){
        _nbVertices = nbVertices;

        Vec2f LB = Vec2f();
        LB[0] = _center[0] - 0.5;
        LB[1] = _center[1] - 0.5;

        Vec2f RT = Vec2f();
        RT[0] = _center[0] + 0.5;
        RT[1] = _center[1] + 0.5;
        this->setBbox(BoundingBox( LB, RT ));

        double coords[2];
        for(int i = 0; i<_nbVertices; i++){
                coords[0] = (_center[0] + std::cos((2*i*M_PI)/_nbVertices))/2;
                coords[1] = (_center[1] + std::sin((2*i*M_PI)/_nbVertices))/2;
                _vertices.push_back(Vec2f(coords));
        }
    }
    // Getters
    int getVerticesNumber(){ return _nbVertices; }

    std::vector<Vec2f> getVertices(){ return _vertices; }

    std::vector<Vec2f> getTransformedVertices(){ return _transformedVertices; }

    bool isPointInsidePrimitive(Vec2f &point);

    void ApplyMatToVertices();

    bool intersectBbox(Vec2f& p);

    bool intersect(Vec2f& p);

};

#endif
