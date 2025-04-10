//#dvir.opa@gmail.com
#include "Edge.h"

Edge::Edge(int src, int dest, int w) {
    this->src = src;
    this->dest = dest;
    this->weight = w;
}

int Edge::getSrc() const {
    return src;
}

int Edge::getDest() const {
    return dest;
}

int Edge::getWeight() const {
    return weight;
}

void Edge::setWeight(int w) {
    this->weight = w;
}

bool Edge::operator==(const Edge& other) const {
    return (src == other.src && dest == other.dest) ||
           (src == other.dest && dest == other.src);
}