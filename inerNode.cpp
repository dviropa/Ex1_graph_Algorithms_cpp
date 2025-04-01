// inerNode.h
#include "inerNode.h"
#include "Edge.h"
#include <climits>
#include <iostream>

namespace graph {


    inerNode::inerNode(const Edge& edge) : e(edge), next(nullptr) {}

    void inerNode::addinerNode(const Edge& edge) {
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

    void inerNode::removeinerNode(const Edge& edge) {
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

    int inerNode::get_weight(int u, int v) {
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

    void inerNode::printEdges() const {
        const inerNode* temp = this;
        while (temp != nullptr) {
            std::cout << "(" << temp->e.getSrc() << "->" << temp->e.getDest()
                      << ", w=" << temp->e.getWeight() << ") -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }

    inerNode::~inerNode() {
        inerNode* curr = next;
        while (curr) {
            inerNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};
 // namespace graph
