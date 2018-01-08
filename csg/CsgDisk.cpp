
#include "CsgDisk.h"


void CsgDisk::ApplyMatToVertices(){

    double coords[2];
    // Update de la Bbox
    Vec2f newBboxLB = this->getBbox().getLeftBottom();
    Vec2f newBboxRT = this->getBbox().getRightTop();
    coords[0] = (this->_mat * newBboxLB)[0];
    coords[1] = (this->_mat * newBboxLB)[1];
    newBboxLB = Vec2f(coords);
    this->getBbox().setLeftBottom(newBboxLB);
    coords[0] = (this->_mat * newBboxRT)[0];
    coords[1] = (this->_mat * newBboxRT)[1];
    newBboxRT = Vec2f(coords);
    this->getBbox().setRightTop(newBboxRT);

    // Update du centre
    coords[0] = (this->getMat()*this->getCenter())[0];
    coords[1] = (this->getMat()*this->getCenter())[1];
    this->_center = Vec2f(coords);

    // Update du rayon -> calcul de la distance entre le centre updated & un point du cercle updated
        // Point le plus à gauche du cercle
    coords[0] = this->getCenter()[0];
    coords[1] = this->getCenter()[1] - this->_radius;
    Vec2f updatedPoint = Vec2f(coords);
    coords[0] = (this->getMat()*updatedPoint)[0];
    coords[1] = (this->getMat()*updatedPoint)[1];
    updatedPoint = Vec2f(coords);
    this->_radius = std::sqrt( std::pow((updatedPoint[0] - this->getCenter()[0]), 2)
                                + std::pow((updatedPoint[1] - this->getCenter()[1]), 2) );


    // Si le disque est fils d'un noeud opération -> update de la Bbox du parent
    if(this->getParent() != nullptr){
        if(dynamic_cast<CsgOperation*>(this->getParent()) != nullptr){
            dynamic_cast<CsgOperation*>(this->getParent())->updateBbox();
        }
    }
}



bool CsgDisk::intersectBbox(Vec2f& p){

}

bool CsgDisk::intersect(Vec2f& p){

}
