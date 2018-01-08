#include "CsgTree.h"

void CsgTree::clear(){

    std::map<int, CsgNode*>::iterator it_map;
    for(it_map = this->_map.begin(); it_map != this->_map.end(); it_map++){
        delete((*it_map).second);
        this->_map.erase((*it_map).first);
    }

    this->getLeafs().clear();
    this->getRoots().clear();
}

void CsgTree::addPrimitive(CsgPrimitive *p){
    if(p != nullptr){
        this->_roots.insert(p);
        this->_map.insert(std::make_pair(p->getId(), p));
    }
}

void CsgTree::joinPrimitive(CsgNode* p1, CsgNode* p2){
    if(p1 != nullptr && p2 != nullptr){
        CsgOperation newNode = CsgOperation(Union, nullptr, p1, p2);

        if(p1->getLeft() == nullptr && p1->getRight() == nullptr)
            this->_leafs.insert(p1);
        if(p2->getLeft() == nullptr && p2->getRight() == nullptr)
            this->_leafs.insert(p2);

        // Retirer p1 et p2 de la liste des racines de l'arbre
        std::set<CsgNode*>::iterator it;
        foncteur_searchNode func_search;
        for(it = this->_roots.begin(); it != this->_roots.end(); ++it){
            if (func_search(*it, p1->getId()) || func_search(*it, p2->getId())){
                it = _roots.erase(it);
            }
        }

        this->_roots.insert(&newNode);
        this->_map.insert(std::make_pair(newNode.getId(), &newNode));
    }

}

void CsgTree::joinPrimitive(Operation op, CsgNode* p1, CsgNode* p2){
    if(p1 != nullptr && p2 != nullptr){
        CsgOperation newNode = CsgOperation(op, nullptr, p1, p2);

        if(p1->getLeft() == nullptr && p1->getRight() == nullptr)
            this->_leafs.insert(p1);
        if(p2->getLeft() == nullptr && p2->getRight() == nullptr)
            this->_leafs.insert(p2);

        // Retirer p1 et p2 de la liste des racines de l'arbre
        std::set<CsgNode*>::iterator it;
        foncteur_searchNode func_search;
        for(it = this->_roots.begin(); it != this->_roots.end(); ++it){
            if (func_search(*it, p1->getId()) || func_search(*it, p2->getId())){
                it = _roots.erase(it);
            }
        }

        this->_roots.insert(&newNode);
        this->_map.insert(std::make_pair(newNode.getId(), &newNode));
    }
}

void CsgTree::unlinkChildren(CsgNode* node){
    if(node != nullptr){
        CsgNode* leftChild = node->getLeft();
        CsgNode* rightChild = node->getRight();
        // Supprimer le noeud du std::map
        this->_map.erase(this->_map.find(node->getId()));

        // Le supprimer également des set de racines & de feuilles si il y est présent
        foncteur_searchNode func_search;
        std::set<CsgNode*>::iterator it;
        for(it = this->_roots.begin(); it != this->_roots.end(); ++it){
            if(func_search(*it, node->getId()))
                it = this->_roots.erase(it);
        }
        for(it = this->_leafs.begin(); it != this->_leafs.end(); ++it){
            if(func_search(*it, node->getId()))
                it = this->_roots.erase(it);
        }
        delete(node);

        this->_roots.insert(leftChild);
        this->_roots.insert(rightChild);
    }

}


CsgNode* CsgTree::searchNode(int id){
    foncteur_searchNode func_search;
    std::set<CsgNode*>::iterator it;
    for(it = this->_roots.begin(); it != this->_roots.end(); ++it){
        if(func_search(*it, id))
            return *it;
    }
    for(it = this->_leafs.begin(); it != this->_leafs.end(); ++it){
        if(func_search(*it, id))
            return *it;
    }
    return nullptr;
}

