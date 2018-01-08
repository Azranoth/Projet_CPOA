
#include "CsgNode.h"

int CsgNode::NB_NODES = 0;

void CsgNode::swapLeftRight(){
    CsgNode* temp = this->getLeft();
    this->setLeft(this->getRight());
    this->setRight(temp);
}
