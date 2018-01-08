
#include "boundingbox.h"

Vec2f BoundingBox::getCenter(){
    double array[2] = { (this->getLeftBottom()[0]+this->getRightTop()[0])/2 , (this->getLeftBottom()[1]+this->getRightTop()[1])/2 };
    return Vec2f(array);
}

bool BoundingBox::isPointInside(Vec2f& pt){
    if(pt[0] >= this->getLeftBottom()[0] && pt[0] <= this->getRightTop()[0]
            && pt[1] >= this->getLeftBottom()[1] && pt[1] <= this->getRightTop()[1])
        return true;
    else
        return false;
}

bool BoundingBox::isBoxIncluded(BoundingBox& box2){
    Vec2f pt1 = box2.getLeftBottom();
    Vec2f pt2 = box2.getRightTop();
    if(this->isPointInside(pt1) && this->isPointInside(pt2))
        return true;
    else
        return false;
}

void BoundingBox::addPoint(Vec2f& pt){

   double temp_LBx, temp_LBy, temp_RTx, temp_RTy;
   double arrayLB[2], arrayRT[2];

   // Point à droite de la BoundingBox
   if(pt[0] > this->getRightTop()[0]){
       temp_RTx = pt[0];
       // Au-dessus
       if(pt[1] > this->getRightTop()[1]){
           temp_RTy = pt[1];
           arrayRT[0] = temp_RTx; arrayRT[1] = temp_RTy;
           this->setRightTop(Vec2f(arrayRT));
       }
       else{
           // En-dessous
           if(pt[1] < this->getLeftBottom()[1]){
               temp_LBy = pt[1];
               arrayRT[0] = temp_RTx; arrayRT[1] = this->getRightTop()[1];
               arrayLB[0] = this->getLeftBottom()[0]; arrayLB[1] = temp_LBy;
               this->setLeftBottom(Vec2f(arrayLB));
               this->setRightTop(Vec2f(arrayRT));
           }
           else{
               arrayRT[0] = temp_RTx; arrayRT[1] = this->getRightTop()[1];
               this->setRightTop(Vec2f(arrayRT));
           }
       }
   }

   else{

       // Point à gauche de la BoundingBox
       if(pt[0] < this->getLeftBottom()[0]){
           temp_LBx = pt[0];
           // Au-dessus
           if(pt[1] > this->getRightTop()[1]){
               temp_LBy = pt[1];
               arrayRT[0] = this->getRightTop()[0]; arrayRT[1] = temp_RTy;
               arrayLB[0] = temp_LBx; arrayLB[1] = this->getLeftBottom()[1];
               this->setRightTop(Vec2f(arrayRT));
               this->setLeftBottom(Vec2f(arrayLB));
           }
           else{
               //En-dessous
               if(pt[1] < this->getLeftBottom()[1]){
                   temp_LBy = pt[1];
                   arrayLB[0] = temp_LBx; arrayLB[1] = temp_LBy;
                   this->setLeftBottom(Vec2f(arrayLB));
               }
               else{
                   arrayLB[0] = temp_LBx; arrayLB[1] = this->getLeftBottom()[1];
                   this->setLeftBottom(Vec2f(arrayLB));
               }
           }
       }

       else{
           // Point juste au-dessus/en-dessous de la BoundingBox
           if(pt[1] > this->getRightTop()[1]){
               temp_RTy = pt[1];
               arrayRT[0] = this->getRightTop()[0]; arrayRT[1] = temp_RTy;
               this->setRightTop(Vec2f(arrayRT));
           }
           if(pt[1] < this->getLeftBottom()[1]){
               temp_LBy = pt[1];
               arrayLB[0] = this->getLeftBottom()[0]; arrayLB[1] = temp_LBy;
               this->setLeftBottom(Vec2f(arrayLB));
           }
       }
   }
}

BoundingBox BoundingBox::applyTransformationMat(Matrix33d& mat){
    Vec2f temp1 = this->getLeftBottom();
    Vec3f newLB_temp = mat*temp1;
    Vec2f newLB = Vec2f();
    newLB[0] = newLB_temp[0]; newLB[1] = newLB_temp[1];

    Vec3f newRT_temp = mat*this->getRightTop();
    Vec2f newRT = Vec2f();
    newRT[0] = newRT_temp[0]; newRT[1] = newRT_temp[1];

    return BoundingBox(newLB, newRT);
}
