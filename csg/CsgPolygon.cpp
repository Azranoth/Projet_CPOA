#include "CsgPolygon.h"



bool CsgPolygon::isPointInsidePrimitive(Vec2f& point){

    int i, j;
    bool inside = false;
    for(i = 0, j = this->getVerticesNumber() - 1; i < this->getVerticesNumber(); j = i++){
        if( (this->getVertices()[i][1] > point[1] != this->getVertices()[j][1] > point[1])
             && ( point[0] < ( (this->getVertices()[j][0]-this->getVertices()[i][0])*(point[1]-this->getVertices()[i][1]) / (this->getVertices()[j][1]-this->getVertices()[i][1]) + this->getVertices()[i][0]) )){

            inside = !inside;

        }
    }
    return inside;

}


void CsgPolygon::ApplyMatToVertices(){

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

    // Update des coordonnées de tous les sommets
    for(int i=0; i<this->getVerticesNumber(); i++){

        coords[0] = (this->_mat * this->getVertices()[i])[0];
        coords[1] = (this->_mat * this->getVertices()[i])[1];
        this->_transformedVertices[i] = Vec2f(coords);
    }
    // Si la primitive est fille d'un noeud opération -> update de la Bbox du parent
    if(this->getParent() != nullptr){
        if(dynamic_cast<CsgOperation*>(this->getParent()) != nullptr){
            dynamic_cast<CsgOperation*>(this->getParent())->updateBbox();
        }
    }
}


bool CsgPolygon::intersectBbox(Vec2f& p){

}

bool CsgPolygon::intersect(Vec2f& p){

}

