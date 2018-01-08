#ifndef CSG_NODE_H
#define CSG_NODE_H

#include "boundingbox.h"


class CsgNode {

protected:
    static int NB_NODES;
protected:
    int _nodeId;
    std::string _label;
    CsgNode* _parent;
    CsgNode* _left;
    CsgNode* _right;
    BoundingBox _bbox;

public:
    CsgNode(){
        _parent = nullptr;
        _left = nullptr;
        _right = nullptr;
        _bbox = BoundingBox();

        _nodeId = ++NB_NODES;
    }

    CsgNode(CsgNode* parent){
        _parent = parent;
        _left = nullptr;
        _right = nullptr;
        _bbox = BoundingBox();

        _nodeId = ++NB_NODES;
    }

    CsgNode(CsgNode* parent, CsgNode* left, CsgNode* right){
        _parent = parent;
        _left = left;
        _right = right;

        _nodeId = ++NB_NODES;
    }

    int getId(){ return _nodeId; }

    CsgNode* getParent(){ return _parent; }

    CsgNode* getLeft(){ return _left; }

    CsgNode* getRight(){ return _right; }

    BoundingBox getBbox(){ return _bbox; }

    void setLabel(std::string label){ _label = label; }

    void setParent(CsgNode* newParent){ _parent = newParent; }

    void setLeft(CsgNode* newLeft){ _left = newLeft; }

    void setRight(CsgNode* newRight){ _right = newRight; }

    void setBbox(BoundingBox bbox){ _bbox = bbox; }

    // Autres fonctions
    void swapLeftRight();

    virtual bool intersect(Vec2f& p) = 0;
    virtual bool intersectBbox(Vec2f& p) = 0;
};


#endif
