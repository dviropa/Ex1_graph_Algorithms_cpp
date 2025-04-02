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
            if (!l) l = new inerNode(e);
            else{
                inerNode* temp1 = this->l;
            while (temp1->next!=nullptr) {
              temp1 = temp1->next;
                }
                l->addinerNode(e);
            }
        }

        
        void auterNode::removeEdge(const Edge& e) {
            if (l) l->removeinerNode(e);
        }

        int auterNode::get_weight(int u, int v) {
            inerNode* temp1 = this->l;
            while (temp1->next!=nullptr) {
              temp1 = temp1->next;
            }

            return temp1->get_weight(u, v);
        }

        void auterNode::printEdges() const {
            std::cout << "Node " << num << ": ";
            if (l) l->printEdges();
            else std::cout << "No edges\n";
        }

        auterNode::~auterNode() {
            delete l;
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
                    if (temp1->e == temp2->e) {
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

  

#endif // AUTERNODE_H
