#ifndef EDGE_H
#define EDGE_H
#include <stdexcept>

class Edge {
private:
    int src;
    int dest;
    int weight;

public:
    Edge() : src(0), dest(0), weight(0) {}
    Edge(int src, int dest, int w);

    int getWeight() const;
    int getSrc() const;
    int getDest() const;

    void setWeight(int w);

    bool operator==(const Edge& other) const;
};

#endif // EDGE_H
