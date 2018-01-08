#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "matrix33d.h"
#include <cmath>


class BoundingBox {
private:
    Vec2f _leftBottomCorner;
    Vec2f _rightTopCorner;
    bool _isEmpty;

public:
    inline BoundingBox(){
        _leftBottomCorner = Vec2f();
        _rightTopCorner = Vec2f();
        _isEmpty = true;
    }

    inline BoundingBox(const Vec2f v1, const Vec2f v2){
        _leftBottomCorner = v1;
        _rightTopCorner = v2;
        if(_leftBottomCorner==_rightTopCorner){
            _isEmpty = true;
        }
        else
            _isEmpty = false;
    }

    Vec2f getLeftBottom(){
        return _leftBottomCorner;
    }

    Vec2f getRightTop(){
        return _rightTopCorner;
    }

    bool isEmpty(){
        return _isEmpty;
    }

    Vec2f getLeftTop(){
        double input[2] = {_leftBottomCorner[0], _rightTopCorner[1]};
        return Vec2f(input);
    }

    Vec2f getRightBottom(){
        double input[2] = {_rightTopCorner[0], _leftBottomCorner[1]};
        return Vec2f(input);
    }

    void setLeftBottom(const Vec2f vec){
        _leftBottomCorner = vec;
    }

    void setRightTop(const Vec2f vec){
        _rightTopCorner = vec;
    }

    // SURCHARGE D'OPERATEURS
    bool operator==(BoundingBox& box){
        if(getLeftBottom() == box.getLeftBottom() && getRightTop() == box.getRightTop())
            return true;
        else
            return false;
    }
        // Union
    BoundingBox operator+(BoundingBox& box){
        double temp1, temp2;
        Vec2f thisLeftBottom = getLeftBottom();
        Vec2f boxLeftBottom = box.getLeftBottom();
        Vec2f thisRightTop = getRightTop();
        Vec2f boxRightTop = box.getRightTop();

        if(thisLeftBottom[0] < boxLeftBottom[0])
            temp1 = thisLeftBottom[0];
        else
            temp1 = boxLeftBottom[0];
        if(thisLeftBottom[1] < boxLeftBottom[1])
            temp2 = thisLeftBottom[1];
        else
            temp2 = boxLeftBottom[1];
        double array1[2] = {temp1, temp2};
        Vec2f new_LeftBottom = Vec2f(array1);

        if(thisRightTop[0] > boxRightTop[0])
            temp1 = thisRightTop[0];
        else
            temp1 = boxRightTop[0];
        if(thisRightTop[1] > boxRightTop[1])
            temp2 = thisRightTop[1];
        else
            temp2 = boxRightTop[1];
        double array2[2] = {temp1, temp2};
        Vec2f new_RightTop = Vec2f(array2);

        BoundingBox res = BoundingBox(new_LeftBottom, new_RightTop);

        return res;
    }

        // Intersection
    BoundingBox operator^(BoundingBox& box){
        double temp1, temp2;

        Vec2f thisLeftBottom = getLeftBottom();
        Vec2f boxLeftBottom = box.getLeftBottom();
        Vec2f thisRightTop = getRightTop();
        Vec2f boxRightTop = box.getRightTop();

        if( (thisRightTop[0] < boxLeftBottom[0] && thisRightTop[1] < boxLeftBottom[1])
            || (boxRightTop[0] < thisLeftBottom[0] && boxRightTop[1] < thisLeftBottom[1]) ){

            return BoundingBox();
        }

        else{
            if(thisLeftBottom[0] > boxLeftBottom[0])
                temp1 = thisLeftBottom[0];
            else
                temp1 = boxLeftBottom[0];
            if(thisLeftBottom[1] > boxLeftBottom[1])
                temp2 = thisLeftBottom[1];
            else
                temp2 = boxLeftBottom[1];
            double array1[2] = {temp1, temp2};
            Vec2f new_LeftBottom = Vec2f(array1);

            if(thisRightTop[0] < boxRightTop[0])
                temp1 = thisRightTop[0];
            else
                temp1 = boxRightTop[0];
            if(thisRightTop[1] < boxRightTop[1])
                temp2 = thisRightTop[1];
            else
                temp2 = boxRightTop[1];
            double array2[2] = {temp1, temp2};
            Vec2f new_RightTop = Vec2f(array2);

            return BoundingBox(new_LeftBottom, new_RightTop);
        }
    }
        //Différence
    BoundingBox operator-(BoundingBox& box){
        Vec2f newRightTop;
        Vec2f newLeftBottom;
        double temp1, temp2, array[2];

        if(box.isBoxIncluded(*this) || (isEmpty() && box.isEmpty())){
            std::cout << "prout\n";
            return BoundingBox();
        }

        else{

            Vec2f thisLeftBottom = getLeftBottom();
            Vec2f boxLeftBottom = box.getLeftBottom();
            Vec2f thisRightTop = getRightTop();
            Vec2f boxRightTop = box.getRightTop();

            double maxDistX = std::max(std::abs(boxLeftBottom[0] - thisLeftBottom[0]) , std::abs(boxRightTop[0] - thisRightTop[0]));
            double maxDistY = std::max(std::abs(boxRightTop[1] - thisRightTop[1]) , std::abs(boxLeftBottom[1] - thisLeftBottom[1]));



            if(maxDistX >= maxDistY){

                if(std::abs(boxLeftBottom[0] - thisLeftBottom[0]) <= std::abs(boxRightTop[0] - thisRightTop[0])){
                    temp1 = boxRightTop[0];
                    temp2 = thisLeftBottom[1];
                    array[0] = temp1; array[1] = temp2;
                    newLeftBottom = Vec2f(array);

                    newRightTop = getRightTop();
                }
                else{
                    newLeftBottom = getLeftBottom();

                    temp1 = boxRightTop[0];
                    temp2 = thisRightTop[1];
                    array[0] = temp1; array[1] = temp2;
                    newRightTop = Vec2f(array);
                }
            }
            else{
                if(std::abs(boxLeftBottom[1] - thisLeftBottom[1]) <= std::abs(boxRightTop[1] - thisRightTop[1])){
                    temp1 = thisLeftBottom[0];
                    temp2 = boxRightTop[1];
                    array[0] = temp1; array[1] = temp2;
                    newLeftBottom = Vec2f(array);

                    newRightTop = getRightTop();
                }
                else{
                    newLeftBottom = getLeftBottom();

                    temp1 = thisRightTop[0];
                    temp2 = boxLeftBottom[1];
                    array[0] = temp1; array[1] = temp2;
                    newRightTop = Vec2f(array);
                }
            }
            return BoundingBox(newLeftBottom, newRightTop);
        }
    }


    // Autres fonctions
    Vec2f getCenter();

    BoundingBox applyTransformationMat(Matrix33d& mat);

    bool isPointInside(Vec2f& pt);

    bool isBoxIncluded(BoundingBox& box2);

    void addPoint(Vec2f& pt);


};

#endif
