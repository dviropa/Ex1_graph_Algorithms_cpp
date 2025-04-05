//#dvir.opa@gmail.com
// auterNode.h
#ifndef AUTERNODE_H
#define AUTERNODE_H

#include "inerNode.h"
#include "auterNode.h"
#include <iostream>
#include <climits>  
namespace graph {

        auterNode::auterNode(int n) : num(n), l(nullptr), next(nullptr) {}

void auterNode::addEdge(const Edge& e) {
    if (!l) {
        l = new inerNode(e);
    } else {
        l->addinerNode(e);
    }
}

int auterNode::get_weight(int u, int v) {
    inerNode* temp1 = this->l;
    while (temp1 != nullptr) {
        int w = temp1->get_weight(u, v);
        if (w != INT_MAX) {
            return w;
        }
        temp1 = temp1->next;
    }
    return INT_MAX;
}


        void auterNode::printEdges() const {
            std::cout << "Node " << num << ": ";
            if (l) l->printEdges();
            else std::cout << "No edges\n";
        }

 auterNode::~auterNode() {
    inerNode* curr = l;
    while (curr) {
        inerNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}


        bool auterNode::operator==(const auterNode &other) const{
            if (this->num != other.num) return false;

            int count1 = 0, count2 = 0;
            inerNode* temp1 = this->l;
            while (temp1) {
                count1++;
                temp1 = temp1->next;
            }
            inerNode* temp2 = other.l;
            while (temp2) {
                count2++;
                temp2 = temp2->next;
            }
            if (count1 != count2) return false;

            temp1 = this->l;
            while (temp1) {
                bool found = false;
                temp2 = other.l;
                while (temp2) {
                    if (temp1->e == temp2->e&&temp1->e.getWeight() == temp2->e.getWeight()) {
                        found = true;
                        break;
                    }
                    temp2 = temp2->next;
                }
                if (!found) return false;
                temp1 = temp1->next;
            }
            return true;
        }

    };

  

#endif
