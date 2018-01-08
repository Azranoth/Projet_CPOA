#ifndef CSG_TREE_H
#define CSG_TREE_H

//#include "image2grey.h"
#include "CsgNode.h"
#include "CsgOperation.h"
#include "CsgPrimitive.h"
#include "CsgPolygon.h"
#include "CsgDisk.h"

#include <vector>
#include <map>
#include <utility>


class foncteur_searchNode{
public:
    foncteur_searchNode(){}
    bool operator()(CsgNode* n, int id){ if(id == n->getId()) return true; else return false; }
};


class CsgTree {

protected:
    std::set<CsgNode*> _roots;
    std::set<CsgNode*> _leafs;
    std::map<int,CsgNode*> _map;

public:
    CsgTree(){
        _roots = std::set<CsgNode*>();
        _leafs = std::set<CsgNode*>();
        _map = std::map<int, CsgNode*>();
    }
/*
    void displayRoots(){
        std::set<CsgNode*>::iterator it;
        CsgNode node;
        for(it = _roots.begin(); it != _roots.end(); ++it){
            node = (*it);
            std::cout << "prout " << node.getId() << std::endl;
        }
    }
*/
    std::set<CsgNode*> getRoots(){ return _roots; }
    std::set<CsgNode*> getLeafs(){ return _leafs; }

    void clear();

    void addPrimitive(CsgPrimitive* p);

    void joinPrimitive(CsgNode* p1, CsgNode* p2);

    void joinPrimitive(Operation op, CsgNode* p1, CsgNode* p2);

    void unlinkChildren(CsgNode* node);

    CsgNode* searchNode(int id);





};




#endif
