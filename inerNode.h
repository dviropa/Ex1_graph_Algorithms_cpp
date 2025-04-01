#ifndef INERNODE_H
#define INERNODE_H
#include <stdexcept>

#include "Edge.h"

namespace graph {

    class inerNode {
    public:
        Edge e;
        inerNode* next;

        // קונסטרקטור
        explicit inerNode(const Edge& edge);

        // פעולות על הרשימה
        void addinerNode(const Edge& e);
        void removeinerNode(const Edge& e);
        void printEdges() const;
        int get_weight(int u, int v);

        // דסטרקטור
        ~inerNode();
    };

} // namespace graph

#endif // INERNODE_H
