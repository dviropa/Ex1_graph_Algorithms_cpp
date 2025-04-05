//#dvir.opa@gmail.com

#ifndef INERNODE_H
#define INERNODE_H
#include <stdexcept>

#include "Edge.h"

namespace graph {

    class inerNode {
    public:
        Edge e;
        inerNode* next;

        explicit inerNode(const Edge& edge);

        void addinerNode(const Edge& e);
        void printEdges() const;
        int get_weight(int u, int v);

        ~inerNode();
    };

}

#endif
