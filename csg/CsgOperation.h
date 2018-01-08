#ifndef CSG_OPERATION_H
#define CSG_OPERATION_H

#include "CsgNode.h"
#include "CsgPrimitive.h"
#include "CsgDisk.h"
#include "CsgPolygon.h"

enum Operation { Union, Intersection, Difference };

class CsgOperation : public virtual CsgNode {

protected:
    Operation _op;
public:
    CsgOperation():CsgNode(){}
    CsgOperation(Operation op, CsgNode* parent, CsgNode* left, CsgNode* right) : CsgNode(parent, left, right){
        _op = op;
        _left->setParent(dynamic_cast<CsgNode*>(this));
        _right->setParent(dynamic_cast<CsgNode*>(this));
        updateBbox();
    }

    void setOp(Operation op) { _op = op; }


    void updateBbox();

    bool intersectBbox(Vec2f& p);

    bool intersect(Vec2f& p);


};

#endif
