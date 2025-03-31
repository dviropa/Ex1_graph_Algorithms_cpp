// inerNode.h
#ifndef INERNODE_H
#define INERNODE_H

#include "Edge.h"
#include <climits>
#include <iostream>

namespace graph {

class inerNode {
public:
    Edge e;
    inerNode* next;

    explicit inerNode(const Edge& edge) : e(edge), next(nullptr) {}

    void addinerNode(const Edge& edge) {
        inerNode* temp = this;
        while (temp != nullptr) {
            if (temp->e == edge) {
                temp->e.setWeight(edge.getWeight());
                return;
            }
            if (temp->next == nullptr) break;
            temp = temp->next;
        }
        temp->next = new inerNode(edge);
    }

    void removeinerNode(const Edge& edge) {
        inerNode* curr = this;
        inerNode* prev = nullptr;

        if (curr->e == edge) {
            if (curr->next) {
                inerNode* toDelete = curr->next;
                curr->e = toDelete->e;
                curr->next = toDelete->next;
                delete toDelete;
            }
            return;
        }

        while (curr != nullptr && !(curr->e == edge)) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != nullptr) {
            prev->next = curr->next;
            delete curr;
        }
    }

    int get_weight(int u, int v) {
        inerNode* temp = this;
        while (temp != nullptr) {
            if ((temp->e.getSrc() == u && temp->e.getDest() == v) ||
                (temp->e.getSrc() == v && temp->e.getDest() == u)) {
                return temp->e.getWeight();
            }
            temp = temp->next;
        }
        return INT_MAX; // Edge not found
    }

    void printEdges() const {
        const inerNode* temp = this;
        while (temp != nullptr) {
            std::cout << "(" << temp->e.getSrc() << "->" << temp->e.getDest()
                      << ", w=" << temp->e.getWeight() << ") -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }

    ~inerNode() {
        inerNode* curr = next;
        while (curr) {
            inerNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

} // namespace graph

#endif // INERNODE_H