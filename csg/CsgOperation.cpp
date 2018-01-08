#include "CsgOperation.h"

void CsgOperation::updateBbox(){
    if(this->getLeft() == nullptr){

        if(this->getRight() == nullptr)
            this->setBbox(BoundingBox());
        else
            this->setBbox(this->getRight()->getBbox());
    }
    else{
        if(this->getRight() == nullptr)
            this->setBbox((this->getLeft()->getBbox()));
        else{
            BoundingBox leftBbox = this->getLeft()->getBbox();
            BoundingBox rightBbox = this->getRight()->getBbox();
            switch(this->_op){
                case Union       : this->setBbox(leftBbox+rightBbox);
                                   break;
                case Intersection: this->setBbox(leftBbox^rightBbox);
                                   break;
                case Difference  : this->setBbox(leftBbox-rightBbox);
                                   break;
                default          : break;
            }
        }
    }
}

bool CsgOperation::intersectBbox(Vec2f& p){
    bool res = false;
    BoundingBox diffBbox;

    if( (this->getLeft() != nullptr) && (this->getRight() != nullptr) )
    {
        BoundingBox leftBbox = this->getLeft()->getBbox();
        BoundingBox rightBbox = this->getRight()->getBbox();
        switch(this->_op)
        {
            case Union:
                res = leftBbox.isPointInside(p) || rightBbox.isPointInside(p);
                break;

            case Intersection:
                res = leftBbox.isPointInside(p) && rightBbox.isPointInside(p);
                break;

            case Difference:
                diffBbox = leftBbox - rightBbox;
                res = diffBbox.isPointInside(p);
                break;
            default:
                break;
        }
    }
    else{
        if(this->getLeft() != nullptr)
            res = this->getLeft()->getBbox().isPointInside(p);
        else{
            if(this->getRight() != nullptr)
                res = this->getRight()->getBbox().isPointInside(p);
        }
    }
    return res;
}



bool CsgOperation::intersect(Vec2f& p){
    bool res = false;

    bool leftIntersect = false;
    bool rightIntersect = false;

    if(this->intersectBbox(p))
    {
        if( (this->getLeft() != nullptr) && (this->getRight() != nullptr) )
        {
            if(dynamic_cast<CsgDisk*>(this->getLeft()) != nullptr){
                leftIntersect = dynamic_cast<CsgDisk*>(this->getLeft())->intersect(p);
            }
            else {
                if(dynamic_cast<CsgPolygon*>(this->getLeft()) != nullptr)
                    leftIntersect = dynamic_cast<CsgPolygon*>(this->getLeft())->intersect(p);

                else {
                    if(dynamic_cast<CsgOperation*>(this->getLeft()) != nullptr)
                        leftIntersect = dynamic_cast<CsgOperation*>(this->getLeft())->intersect(p);
                }
            }
            if(dynamic_cast<CsgDisk*>(this->getRight()) != nullptr){
                rightIntersect = dynamic_cast<CsgDisk*>(this->getLeft())->intersect(p);
            }
            else {
                if(dynamic_cast<CsgPolygon*>(this->getRight()) != nullptr)
                    rightIntersect = dynamic_cast<CsgPolygon*>(this->getRight())->intersect(p);
                else {
                    if(dynamic_cast<CsgOperation*>(this->getRight()) != nullptr)
                        rightIntersect = dynamic_cast<CsgOperation*>(this->getRight())->intersect(p);
                }
            }
            switch(this->_op)
            {
                case Union:
                    res = leftIntersect || rightIntersect;
                    break;

                case Intersection:
                    res = leftIntersect && rightIntersect;
                    break;

                case Difference:
                    res = leftIntersect || rightIntersect;
                    break;

                default:
                    break;
            }
        }
        else{
            if(this->getLeft() != nullptr){

                if(dynamic_cast<CsgDisk*>(this->getLeft()) != nullptr)
                    leftIntersect = dynamic_cast<CsgDisk*>(this->getLeft())->intersect(p);

                else{
                    if(dynamic_cast<CsgPolygon*>(this->getLeft()) != nullptr)
                        leftIntersect = dynamic_cast<CsgPolygon*>(this->getLeft())->intersect(p);
                    else{
                        if(dynamic_cast<CsgOperation*>(this->getLeft()) != nullptr)
                           leftIntersect = dynamic_cast<CsgOperation*>(this->getLeft())->intersect(p);
                    }
                }
                res = leftIntersect;
            }

            else {
                if(this->getRight() != nullptr){

                    if(dynamic_cast<CsgDisk*>(this->getRight()) != nullptr)
                        rightIntersect = dynamic_cast<CsgDisk*>(this->getRight())->intersect(p);
                    else{
                        if(dynamic_cast<CsgPolygon*>(this->getRight()) != nullptr)
                            rightIntersect = dynamic_cast<CsgPolygon*>(this->getRight())->intersect(p);
                        else{
                            if(dynamic_cast<CsgOperation*>(this->getRight()) != nullptr)
                                rightIntersect = dynamic_cast<CsgOperation*>(this->getRight())->intersect(p);
                        }

                    }
                }
                res = rightIntersect;
            }
        }
    }
    return res;
}
