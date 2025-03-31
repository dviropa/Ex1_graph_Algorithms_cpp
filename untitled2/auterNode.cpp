// auterNode.h
#ifndef AUTERNODE_H
#define AUTERNODE_H

#include "inerNode.h"
#include <iostream>

namespace graph {

    class auterNode {
    public:
        int num;
        inerNode* l;
        auterNode* next;




        explicit auterNode(int n) : num(n), l(nullptr), next(nullptr) {}

        void addEdge(const Edge& e) {
            if (!l) l = new inerNode(e);
            else l->addinerNode(e);
        }

        void removeEdge(const Edge& e) {
            if (l) l->removeinerNode(e);
        }

        int get_weight(int u, int v) {
            if (l) return l->get_weight(u, v);
            return INT_MAX;
        }

        void printEdges() const {
            std::cout << "Node " << num << ": ";
            if (l) l->printEdges();
            else std::cout << "No edges\n";
        }

        ~auterNode() {
            delete l;
            if (next) delete next;
        }
        bool auterNode::operator==(const auterNode& other) const {
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

} // namespace graph

#endif // AUTERNODE_H
