//#dvir.opa@gmail.com
#pragma once
#include "Edge.h"
#include "inerNode.h"
#include <stdexcept>

namespace graph {


class auterNode {
public:
    int num;
    inerNode* l;
    auterNode* next;

    explicit auterNode(int n);

    void addEdge(const Edge& e);
    void removeEdge(const Edge& e);
    void printEdges() const;
    int get_weight(int u, int v);

    ~auterNode();
    bool operator==(const auterNode& other) const;

};
}